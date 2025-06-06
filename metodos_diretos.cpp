#include "bits/stdc++.h"
#include "triangular.hpp"

using namespace std;


vector<double> eliminacaoGauss(vector<vector<double>> A, vector<double> b)
{
    int tam = b.size();
    double M = 0.0;

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
        else if(pontColuna != k){ 
            for(int x = k; x < tam; x++){
                swap(A[x][pontColuna], A[x][k]);
            }
            swap(A[k], A[pontLinha]);
            swap(b[k], b[pontLinha]);
        }

        // pivo atualizado, agora devo lidar com as consequencias da troca de colunas

        /* //pivoteamento parcial
        for (int x = k+1; x < tam; x++){ 
            if(fabs(A[x][k]) > fabs(A[k][k])){
                swap(A[x], A[k]);
                swap(b[x], b[k]);
            }
        }
        */

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
