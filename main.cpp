#include "bits/stdc++.h"
#include "triangular.hpp"
#include "metodos_diretos.hpp"
#include <iomanip> // para imprimir corretamente

using namespace std;

int main(){
       
    int n = 21;

    vector<vector<double>> A(n,vector<double>(n,0));
    vector<vector<double>> AInv(n,vector<double>(n,0));
    vector<double> b(n,0); 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = abs(i - j);
        }
    }

    for (int i = 0; i < n; i++){
        b[i] = i+1;
    }
    
    AInv = decLUInversa(A);

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

    cout << "1.1 - solução por gauss com pivoteamento parcial: " << "\n";
    for (int j = 0 ; j < n; j++){
        cout << sol1[j] << " ";
    }

    cout << "\n\n";

    vector<double> sol2 = eliminacaoGaussPT(A, b);

    cout << "1.2 - solução por gauss com pivoteamento total: " << "\n";
    for (int j = 0 ; j < n; j++){
        cout << sol2[j] << " ";
    }

    cout << "\n";

    vector<double> sol3 = decLU(A, b);

    cout << "3.1 - solução por LU: " << "\n";
    for (int j = 0 ; j < n; j++){
        cout << sol3[j] << " ";
    }
    
    cout << "\n\n";

    cout << "3.2 - A inversa pela LU: " << "\n";
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n; j++){
            cout << std::setw(8) << AInv[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    return 0;
}