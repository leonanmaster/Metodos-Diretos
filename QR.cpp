#include "bits/stdc++.h"

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

struct DecomposicaoQR {
    Matrix Q;
    Matrix R;
};

Matrix identidade(int n) {
    Matrix I(n, Vector(n, 0.0));
    for (int i = 0; i < n; i++) I[i][i] = 1.0;
    return I;
}

Matrix matmul(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, Vector(n, 0.0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

Matrix transpose(const Matrix& A) {
    int n = A.size();
    Matrix T(n, Vector(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            T[j][i] = A[i][j];
    return T;
}

double dot(const Vector& a, const Vector& b) {
    double s = 0;
    for (size_t i = 0; i < a.size(); ++i) s += a[i] * b[i];
    return s;
}

double norm(const Vector& v) {
    return sqrt(dot(v, v));
}

Matrix outer(const Vector& v) {
    int n = v.size();
    Matrix result(n, Vector(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = v[i] * v[j];
    return result;
}

void printMatrix(const Matrix& A, const std::string& nome) {
    std::cout << nome << ":\n";
    for (const auto& row : A) {
        for (double val : row) {
            std::cout << std::fixed << std::setprecision(4) << std::setw(8) << val;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

DecomposicaoQR decomposicaoQR_Householder(Matrix A) {
    int n = A.size();
    Matrix R = A;
    Matrix Q = identidade(n);

    for (int k = 0; k < n; ++k) {
        Vector x(n - k);
        for (int i = k; i < n; ++i) {
            x[i - k] = R[i][k];
        }

        double alpha = -copysign(norm(x), x[0]);
        Vector e(n - k, 0.0);
        e[0] = 1.0;

        Vector v(n - k);
        for (int i = 0; i < n - k; ++i) {
            v[i] = x[i] - alpha * e[i];
        }
        double vnorm = norm(v);
        if (vnorm > 1e-12) { //evita divisão por zero
            for (double& vi : v) {
                vi /= vnorm;
            }
        }

        Matrix Hk = identidade(n);
        Matrix Hv = outer(v);
        for (int i = 0; i < n - k; ++i) {
            for (int j = 0; j < n - k; ++j) {
                Hk[i + k][j + k] -= 2.0 * Hv[i][j];
            }
        }

        R = matmul(Hk, R);
        Q = matmul(Q, transpose(Hk)); 
    }

    return {Q, R};
}

DecomposicaoQR decomposicaoQR_Givens(Matrix A) {
    int n = A.size();
    Matrix R = A;
    Matrix Q = identidade(n);

    for (int j = 0; j < n; ++j) {
        for (int i = j + 1; i < n; ++i) {
            double a = R[j][j];
            double b = R[i][j];

            if (std::abs(b) < 1e-12) continue; //já é zero, não precisa rotacionar

            double r = sqrt(a * a + b * b);
            double c = a / r;
            double s = -b / r;

            // matriz de rotação de Givens G
            Matrix G = identidade(n);
            G[j][j] = c;
            G[i][i] = c;
            G[j][i] = s;
            G[i][j] = -s;
            
            R = matmul(G, R);
            Q = matmul(Q, transpose(G)); // Q acumula as transposições
        }
    }

    return {Q, R};
}

DecomposicaoQR decomposicaoQR_GramSchmidt(Matrix A) {
    int n = A.size();
    Matrix Q(n, Vector(n, 0.0));
    Matrix R(n, Vector(n, 0.0));
    Matrix V = transpose(A); 

    for (int i = 0; i < n; ++i) {
        Vector u = V[i];
        for (int j = 0; j < i; ++j) {
            double proj_coeff = dot(V[i], Q[j]);
            R[j][i] = proj_coeff;
            for(int k=0; k < n; ++k) {
                u[k] -= proj_coeff * Q[j][k];
            }
        }
        double norm_u = norm(u);
        R[i][i] = norm_u;
        if (norm_u > 1e-12) { //evita divisão por zero
            for(int k=0; k < n; ++k) {
                Q[i][k] = u[k] / norm_u;
            }
        }
    }

    return {transpose(Q), R};
}