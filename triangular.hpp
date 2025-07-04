#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#include <vector>
using namespace std;

vector<double> triangularSup(vector<vector<double>>& A, vector<double>& b);
vector<double> triangularInfLU(vector<vector<double>>& A, vector<double>& b);
vector<double> triangularInf(vector<vector<double>>& A, vector<double>& b);
#endif // TRIANGULAR_H
