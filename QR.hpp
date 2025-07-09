#ifndef QR_HPP
#define QR_HPP

#include <vector>
#include <string>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

struct DecomposicaoQR {
    Matrix Q;
    Matrix R;
};

DecomposicaoQR decomposicaoQR_Householder(Matrix A);
DecomposicaoQR decomposicaoQR_Givens(Matrix A);
DecomposicaoQR decomposicaoQR_GramSchmidt(Matrix A);


Matrix identidade(int n);
Matrix matmul(const Matrix& A, const Matrix& B);
Matrix transpose(const Matrix& A);
double dot(const Vector& a, const Vector& b);
double norm(const Vector& v);
Matrix outer(const Vector& v);
void printMatrix(const Matrix& A, const std::string& nome);

#endif 