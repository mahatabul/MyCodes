#include <bits/stdc++.h>
using namespace std;

#define N 3   // size of matrix

void LU_Decomposition(double A[N][N], double L[N][N], double U[N][N])
{
    for (int i = 0; i < N; i++)
    {
        // Upper triangular
        for (int k = i; k < N; k++)
        {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];

            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular
        for (int k = i; k < N; k++)
        {
            if (i == k)
                L[i][i] = 1;   // diagonal = 1
            else
            {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];

                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Forward substitution: LY = B
void forwardSub(double L[N][N], double B[N], double Y[N])
{
    for (int i = 0; i < N; i++)
    {
        Y[i] = B[i];
        for (int j = 0; j < i; j++)
            Y[i] -= L[i][j] * Y[j];
    }
}

// Backward substitution: UX = Y
void backwardSub(double U[N][N], double Y[N], double X[N])
{
    for (int i = N - 1; i >= 0; i--)
    {
        X[i] = Y[i];
        for (int j = i + 1; j < N; j++)
            X[i] -= U[i][j] * X[j];

        X[i] /= U[i][i];
    }
}

int main()
{
    double A[N][N] = {
        {2, -1, -2},
        {-4, 6, 3},
        {-4, -2, 8}
    };

    double B[N] = {-2, 9, -5};

    double L[N][N] = {0}, U[N][N] = {0};
    double Y[N], X[N];

    LU_Decomposition(A, L, U);
    forwardSub(L, B, Y);
    backwardSub(U, Y, X);

    cout << "Solution:\n";
    for (int i = 0; i < N; i++)
        cout << "x" << i + 1 << " = " << X[i] << endl;

    return 0;
}
