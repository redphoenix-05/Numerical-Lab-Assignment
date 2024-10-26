#include <iostream>
#include "jacobi_iterative_method.h"
#include "gauss_seidel_iterative_method.h"
#include "secant.h"
#include "lu_factorization.h"
#include "gauss_elimination.h"
#include "gauss_jordan_elimination.h"
#include "newton_raphson.h"
#include "matrix_inversion.h"
#include "bisection.h"
#include "false_position.h"
#include "r_k_method.h"
using namespace std;

int main(){
    int n;
    while(true){
        cout << "1. Linear Equations" << endl;
        cout << "2. Non-Linear Equations" << endl;
        cout << "3. Differential Equations" << endl;
        cout << "4. Matrix Inversion" << endl;
        cout << "Or press any number to exit" << endl;
        cout << "Enter the number of equation type you want to solve : ";
        int n;
        cin >> n;
        if(n == 1){
            cout << "Which method do you want to use to solve the linear equations?" << endl;
            cout << "1. Jacobi Iterative Method" << endl;
            cout << "2. Gauss-Seidel Method" << endl;
            cout << "3. Gauss Elimination" << endl;
            cout << "4. Gauss-Jordan Elimination" << endl;
            cout << "5. LU Factorization" << endl;
            A:
            cout << "Enter your choice : ";
            int choice;
            cin >> choice;
            if(choice == 1){
                jacobi();
            }
            else if(choice == 2){
                gauss_seidel();
            }
            else if(choice == 3){
                gauss_eli();
            }
            else if(choice == 4){
                gauss_elimination();
            }
            else if(choice == 5){
                lu_factorization();
            }
            else{
                cout << "Invalid choice. Choose Again." << endl;
                goto A;
            }
        }
        else if(n == 2){
            cout << "Which method do you want to use to solve the non-linear equations?" << endl;
            cout << "1. Bi-section Method" << endl;
            cout << "2. False Postion Method" << endl;
            cout << "3. Secant Method" << endl;
            cout << "4. Newton-Raphson Method" << endl;
            B:
            cout << "Enter your choice : ";
            int choice;
            cin >> choice;
            if(choice == 1){
                bisection();
            }
            else if(choice == 2){
                false_position();
            }
            else if(choice == 3){
                secant_method();
            }
            else if(choice == 4){
                newton_raphson_method();
            }
            else{
                cout << "Invalid choice. Choose Again." << endl;
                goto B;
            }
        }
        else if(n == 3){
            r_k();
        }
        else if(n == 4){
            matrix_inversion();
        }
        else{
            cout << "Thanks" << endl;
            break;
        }
        cout << endl << "-------------------------------------------------------------------------------------" << endl << endl;
    }
    return 0;
}