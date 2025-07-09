#include "bits/stdc++.h"
#include "triangular.hpp"
#include "metodos_diretos.hpp"
#include "QR.hpp"
#include <iomanip> // para imprimir corretamente

using namespace std;

int main(){
       
    int n = 21;

    vector<vector<double>> A(n,vector<double>(n,0));
    vector<vector<double>> AInv(n,vector<double>(n,0));
    vector<vector<double>> Cholesky(n,vector<double>(n,0));
    vector<double> b(n,0); 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = abs(i - j);
        }
    }

    for (int i = 0; i < n; i++){
        b[i] = i+1;
    }

    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n; j++){
            cout << std::setw(2) << A[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    
    for (int j = 0 ; j < n; j++){
        cout << std::setw(2) << b[j] << " ";
    }

    cout << "\n\n";

    cout << std::fixed << std::setprecision(4);

    vector<double> sol1 = eliminacaoGaussPP(A, b);

    cout << "1.1 - Solução por gauss com pivoteamento parcial: " << "\n";
    for (int j = 0 ; j < n; j++){
        cout << sol1[j] << " ";
    }

    cout << "\n\n";

    vector<double> sol2 = eliminacaoGaussPT(A, b);

    cout << "1.2 - Solução por gauss com pivoteamento total: " << "\n";
    for (int j = 0 ; j < n; j++){
        cout << sol2[j] << " ";
    }

    cout << "\n";

    vector<double> sol3 = decLU(A, b);

    cout << "3.1 - Solução por LU: " << "\n";
    for (int j = 0 ; j < n; j++){
        cout << sol3[j] << " ";
    }

    AInv = decLUInversa(A);    
    cout << "3.2 - A inversa pela LU: " << "\n";
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n; j++){
            cout << std::setw(7) << AInv[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    
    cout << "4 - Decomposição de Cholesky: " << "\n";
    Cholesky = cholesky(A);
    
    cout << "\n\n";

    cout << "5.1- Decomposição QR com Householder: " << "\n";
    DecomposicaoQR result_hh = decomposicaoQR_Householder(A);
    printMatrix(result_hh.Q, "Matriz Q (Householder)");
    printMatrix(result_hh.R, "Matriz R (Householder)");

    cout << "\n\n";

    cout << "5.2- Decomposição QR com Givens: " << "\n";
    DecomposicaoQR result_gv = decomposicaoQR_Givens(A);
    printMatrix(result_gv.Q, "Matriz Q (Givens)");
    printMatrix(result_gv.R, "Matriz R (Givens)");

    cout << "\n\n";

    cout << "5.3- Decomposição QR com Gram-Schmidt: " << "\n";
    DecomposicaoQR result_gs = decomposicaoQR_GramSchmidt(A);
    printMatrix(result_gs.Q, "Matriz Q (Gram-Schmidt)");
    printMatrix(result_gs.R, "Matriz R (Gram-Schmidt)");


    return 0;
}