#include "bits/stdc++.h"
#include "triangular.hpp"

using namespace std;

struct Troca {
    int colunaA;
    int colunaB;
};

vector<double> eliminacaoGauss(vector<vector<double>> A, vector<double> b)
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
        
        if (pontColuna == k && pontLinha != k){ // mesma coisa do pivoteamento parcial
            swap(A[k], A[pontLinha]);
            swap(b[k], b[pontLinha]);
        } 
        else if(pontColuna != k){ // troca de coluna
            for(int x = k; x < tam; x++){
                swap(A[x][pontColuna], A[x][k]);
                Troca atual = {pontColuna, k};
                trocas.push_back(atual); // vetor de troca atualizado
            }
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

    // aqui devo desfazer as trocas  do pivoteamento total
    for (int i = trocas.size() - 1; i >= 0; i--){
        swap(sol[trocas[i].colunaA], sol[trocas[i].colunaB]);
    }

    return  sol;
}
