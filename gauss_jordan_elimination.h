#include <bits/stdc++.h>
using namespace std;

void jordan_eli(vector<vector<double>>& mat);
void row_echelon(vector<vector<double>>& mat);

void gauss_elimination(){
    int n;
    cout << "Enter the number of variables : ";
    cin >> n;
    vector<vector<double>> mat(n, vector<double>(n+1));
    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n+1; ++j) {
            cin >> mat[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        int maxRow = k;
        for(int i = k + 1; i < n; i++){
            if (abs(mat[i][k]) > abs(mat[maxRow][k])) {
            maxRow = i;
            }
        }
        if(mat[maxRow][k]==0){
            cout << "No solution exist" << endl;
            exit(0);
        }
        if (maxRow != k) {
            swap(mat[k], mat[maxRow]);
        }
        for (int i = k + 1; i < n; i++) {
            double factor = mat[i][k] / mat[k][k];
            for (int j = k; j < n + 1; j++) {
                mat[i][j] -= factor * mat[k][j];
            }
        }
    }
    jordan_eli(mat);
}

void jordan_eli(vector<vector<double>>& mat){
    int n = mat.size();

    for(int k = n-1; k>0; k--){
        for(int r = 0; r<k; r++){
            double fA = mat[r][k];
            double fB = mat[r+1][k];

            for(int c = 0; c<n+1; c++){
                mat[r][c] = mat[r][c] * fB - mat[r+1][c] * fA;
            }
        }
    }
    row_echelon(mat);
}

void row_echelon(vector<vector<double>>& mat){
    int n = mat.size();
    vector<double> result;
    for(int i = 0; i<n; i++){
        mat[i][n] = mat[i][n] / mat[i][i];
        result.push_back(mat[i][n]);
        mat[i][i] = 1;
    }
    for(int i=0 ; i<n ; i++){
        cout << "Variable " << i+1 << " = " << result[i] << endl;
    }
}