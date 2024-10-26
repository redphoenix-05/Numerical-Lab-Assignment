#include <bits/stdc++.h>
using namespace std;

bool Diagonal(vector<vector<float>>& eq,int n){
    for(int i=0; i<n; i++){
        int maxRow=i;
        for(int j=i+1; j<n; j++){
            if(fabs(eq[j][i]) > fabs(eq[maxRow][i])){
                maxRow=j;
            }
        }
        if(maxRow!=i){
            swap(eq[i],eq[maxRow]);
        }
        float sum=0;
        for(int j=0; j<n; j++){
            if(j!=i)
                sum +=fabs(eq[i][j]);
        }

        if(fabs(eq[i][i]) < sum){
            return false;
        }
    }
    return true;
}

float nextval(vector<float>& row, vector<float>& vars, int index, int n){
    float c=row[n];
    for(int i=0; i<n; i++){
        if (i!=index){
            c-=row[i]*vars[i];
        }
    }
    return c/row[index];
}

void gauss_seidel(){
    int n;
    cout<<"Enter the number of equations: ";
    cin>>n;

    vector<vector<float>>eq(n,vector<float>(n+1));
    vector<float>vars(n,0);
    float tolerance = 1e-5;
    int maxIterations = 1000;
    for(int i=0; i<n; i++){
        cout<<"Enter coefficients for equation " << i+1 << ":";
        for(int j=0; j<=n; j++){
            cin>>eq[i][j];
        }
    }
    if (!Diagonal(eq, n)) {
        cout<<"The matrix cannot be rearranged to be diagonally dominant. The method may not converge." << endl;
        return;
    }

    cout<<setprecision(6)<<fixed;
    int ct=1;
    bool flag=true;
    while(flag && ct<=maxIterations){
        flag=false;
        for(int i=0; i<n; i++){
            float newValue=nextval(eq[i],vars,i,n);
            if(fabs(newValue-vars[i])>tolerance) {
                flag=true;
            }
            vars[i]=newValue;
        }
        ct++;
    }


    for(int i=0; i<n; i++){
        cout<<"Variable " << i+1 <<"= "<<vars[i]<<endl;
    }
}
