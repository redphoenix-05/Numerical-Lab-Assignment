#include <bits/stdc++.h>
using namespace std;

void jordanEli(vector<vector<double>>& mat);

void matrix_inversion(){
    int n;
    cout<<"Enter the order of the matrix: ";
    cin>>n;

    vector<vector<double>>mat(n, vector<double>(2*n));
    cout<<"Enter matrix elements:\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
        for(int j=n; j<2*n; j++){
            if(i==j-n)
                mat[i][j]=1;
            else
                mat[i][j]=0;
        }
    }

    for(int k=0; k<n; k++){
        int maxRow=k;
        for(int i=k+1; i<n;i++){
            if(abs(mat[i][k])>abs(mat[maxRow][k])) {
                maxRow=i;
            }
        }
        if(mat[maxRow][k]==0){
            cout << "Inverse does not exist.It is a singular matrix"<<endl;
            return;
        }
        if(maxRow!=k){
            swap(mat[k],mat[maxRow]);
        }
        for(int i=k+1; i<n; i++){
            double factor=mat[i][k] / mat[k][k];
            for(int j=k; j<2*n; j++){
                mat[i][j]-=factor*mat[k][j];
            }
        }
    }

    jordanEli(mat);
    for(int i=0; i<n; i++){
        for (int j=n; j<2*n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}


void jordanEli(vector<vector<double>>& mat) {
    int n=mat.size();

    for(int k=n-1; k>=0; k--){
        for(int i=n; i<2*n; i++){
            mat[k][i]/= mat[k][k];
        }
        mat[k][k]=1;

        for(int r=0; r<k; r++){
            double factor=mat[r][k];
            for(int i=k; i<2*n; i++){
                mat[r][i]-=factor*mat[k][i];
            }
        }
    }
}
