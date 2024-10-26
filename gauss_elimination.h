#include <bits/stdc++.h>
using namespace std;

void row_ech(vector<vector<double>>& mat);

void gauss_eli(){
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
    row_ech(mat);
}

void row_ech(vector<vector<double>>& mat){
    int n = mat.size();
    double a;
    for(int i=0 ; i<n ; i++){
        a = mat[i][i];
        for(int j = i; j<n+1; j++){
            mat[i][j]/=a;
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            mat[i][n] -= mat[i][j] * mat[j][n];
        }
    }
    vector<double> result;
    for(int i=0 ; i<n ; i++){
        result.push_back(mat[i][n]);
    }
    for(int i=0 ; i<n ; i++){
        cout << "Variable " << i+1 << " = " << result[i] << endl;
    }
}