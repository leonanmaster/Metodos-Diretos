#include "bits/stdc++.h"
#include "triangular.hpp"

using namespace std;

struct Troca 
{
    int colunaA;
    int colunaB;
};

vector<double> eliminacaoGaussPT(vector<vector<double>> A, vector<double> b)
{
    int tam = b.size();
    double M = 0.0;
    vector<Troca> trocas;

    for (int k = 0; k < tam - 1; k++){
        
        // pivoteamento total
        double pivoAtual = fabs(A[k][k]);
        int pontLinha = k;
        int pontColuna = k;
        
         for (int x = k; x < tam; x++){ // encontrando o maior valor
            for (int y = k; y < tam; y++){
                if (fabs(A[x][y]) > fabs(pivoAtual)){
                    pontLinha = x;
                    pontColuna = y;
                    pivoAtual = A[x][y];
                }
            }
        }
        
        if (pontLinha != k){ // mesma coisa do pivoteamento parcial
            swap(A[k], A[pontLinha]);
            swap(b[k], b[pontLinha]);
        } 
        
        if(pontColuna != k){ // troca de coluna
            for(int x = 0; x < tam; x++){
                swap(A[x][pontColuna], A[x][k]);
            }
            Troca atual = {pontColuna, k};
            trocas.push_back(atual); // vetor de troca atualizado
        }
        

        // eliminação de Gauss
        for (int i = k+1; i < tam; i++){ //atualiza valores da linha  
            M = A[i][k] / A[k][k];
            A[i][k] = 0.0; //evita erro de precisão, o calculo deve ser sempre igual a 0
            for (int j = k+1; j < tam; j++){ //atualiza os valores da linha que não estão abaixo do pivo
                A[i][j] = A[i][j] - (M * A[k][j]);
            }
            b[i] = b[i] - (M * b[k]);
        }

    }

    vector<double> sol = triangularSup(A, b);

    // aqui devo desfazer as trocas  do pivoteamento total
    for (int i = trocas.size() - 1; i >= 0; i--){
        swap(sol[trocas[i].colunaA], sol[trocas[i].colunaB]);
    }

    return  sol;
}

vector<double> eliminacaoGaussPP(vector<vector<double>> A, vector<double> b)
{
    int tam = b.size();
    double M = 0.0;

    for (int k = 0; k < tam - 1; k++){
        
        double pivoAtual = fabs(A[k][k]);
        int pontLinha = k;
        
        for (int x = k; x < tam; x++){ // encontrando o maior valor
            if (fabs(A[x][k]) > fabs(pivoAtual)){
                pontLinha = x;
                pivoAtual = A[x][k];
            }
        }
        
        
        if (pontLinha != k){ 
            swap(A[k], A[pontLinha]);
            swap(b[k], b[pontLinha]);
        } 

        // eliminação de Gauss
        for (int i = k+1; i < tam; i++){ //atualiza valores da linha  
            M = A[i][k] / A[k][k];
            A[i][k] = 0.0; //evita erro de precisão, o calculo deve ser sempre igual a 0
            for (int j = k+1; j < tam; j++){ //atualiza os valores da linha que não estão abaixo do pivo
                A[i][j] = A[i][j] - (M * A[k][j]);
            }
            b[i] = b[i] - (M * b[k]);
        }

    }

    vector<double> sol = triangularSup(A, b);

    return  sol;
}

vector<double> decLU(vector<vector<double>> A, vector<double> b)
{
    int tam = b.size();

    vector<int> p(tam,0);
    vector<Troca> trocas;

    for (int i = 0; i < tam; i++){
        p[i] = i;
    }

    double M = 0.0;
    for (int k = 0; k < tam - 1; k++){

        double pivoAtual = fabs(A[k][k]);
        int pontLinha = k;
        int pontColuna = k;
        
        for (int x = k; x < tam; x++){ // encontrando o maior valor
            for (int y = k; y < tam; y++){
                if (fabs(A[x][y]) > fabs(pivoAtual)){
                    pontLinha = x;
                    pontColuna = y;
                    pivoAtual = A[x][y];
                }
            }
        }

        // melhor usar a logica de trocas com vetores

        if (pontLinha != k){ // troca de linhas
            swap(A[k], A[pontLinha]);
            swap(p[k], p[pontLinha]);
            swap(b[k], b[pontLinha]);
        } 

        if(pontColuna != k){ // troca de coluna
            for(int x = 0; x < tam; x++){
                swap(A[x][pontColuna], A[x][k]);
            }
            Troca atual = {pontColuna, k};
            trocas.push_back(atual); 
        }

        for (int i = k+1; i < tam; i++){ //atualiza valores da linha  
            M = A[i][k] / A[k][k];
            A[i][k] = M;
            for (int j = k+1; j < tam; j++){ //atualiza os valores da linha que não estão abaixo do pivo
                A[i][j] = A[i][j] - (M * A[k][j]);
            }
        }
    }

    vector<double> y = triangularInfLU(A,b);
    vector<double> sol = triangularSup(A,y);

    // Desfazendo as trocas

    for (int i = trocas.size() - 1; i >= 0; i--){
        swap(sol[trocas[i].colunaA], sol[trocas[i].colunaB]);
    }

    cout << "\n";
    
    return sol; 
}

vector<vector<double>> decLUInversa(vector<vector<double>> A)
{
    int tam = A.size();

    vector<vector<double>> Inv(tam, vector<double>(tam, 0.0));

    for (int j = 0; j < tam; j++){
        vector<double> e(tam, 0.0);
        e[j] = 1.0;
        vector<double> colunaJ = decLU(A, e);
        for (int i = 0; i < tam; i++){
            Inv[i][j] = colunaJ[i];
        }
    }

    return Inv;
}