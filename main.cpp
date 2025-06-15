#include "bits/stdc++.h"
#include "triangular.hpp"
#include "metodos_diretos.hpp"

using namespace std;

int main(){

    vector<vector<double>> A = {
        {1, 0, 1}, 
        {1, 1, 0}, 
        {2, 3, 1}};
    vector<double> b = {0, 1, 1};

    vector<double> sol = eliminacaoGauss(A, b);
    cout << sol[0] << " " << sol[1] << " " << sol[2]<< "\n";

    return 0;
}