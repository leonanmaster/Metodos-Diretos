#ifndef METODOS_DIRETOS_HPP
#define METODOS_DIRETOS_HPP

#include <vector> 
using namespace std;

vector<double> eliminacaoGauss(vector<vector<double>> A, vector<double> b);
vector<double> decLU(vector<vector<double>> A, vector<double> b);

#endif