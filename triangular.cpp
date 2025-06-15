#include "bits/stdc++.h"

using namespace std;

vector <double> triangularSup(vector<vector<double>> &A, vector<double> &b)
{
    int tam = b.size();
    vector<double> x (tam, 0.0);
    double soma = 0.0;
    
    for (int k = tam - 1; k >= 0; k--){
        soma = b[k];
        for (int j = k + 1; j < tam; j++){
            soma = soma - (A[k][j] * x[j]);
        }
        x[k] = soma / A[k][k];
    }
    return x;
}

vector <double> triangularInf(vector<vector<double>> &A, vector<double> &b)
{
    int tam = b.size();
    vector<double> x (tam, 0.0);
    double soma = 0.0;
    
    for (int k = 0; k <= tam-1; k++){
        soma = b[k];
        for (int j = 0; j <= k; j++){
            soma = soma - (A[k][j] * x[j]);
        }
        x[k] = soma / A[k][k];
    }

    return x;
}