#ifndef METODOS_DIRETOS_HPP
#define METODOS_DIRETOS_HPP

#include <vector> 
using namespace std;

vector<double> eliminacaoGaussPT(vector<vector<double>> A, vector<double> b);
vector<double> eliminacaoGaussPP(vector<vector<double>> A, vector<double> b);
vector<double> decLU(vector<vector<double>> A, vector<double> b);
vector<vector<double>> decLUInversa(vector<vector<double>> A);


#endif