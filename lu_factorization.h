#include<iostream>
using namespace std;

void lu_factorization(){
    A:
    cout << "Enter the number of variables : ";
    int n;
    cin >> n;
    if(n == 2){
        double a11, a12, a21, a22;
        double l11, l12, l21, l22;
        double u11, u12, u21, u22;
        double v1, v2, x1, x2, y1, y2;
        cout << "Enter the coefficients of the equations in the following format(an an-1 an-2 ... a1 = b)" << endl;  
        cin >> a11 >> a12 >> v1;
        cin >> a21 >> a22 >> v2;
        u11 = a11;
        u12 = a12;
        l21 = a21 / u11;
        u22 = a22 - (l21 * u12);
        x1 = v1;
        x2 = v2 - (l21 * x1);
        y2 = x2 / u22;
        y1 = (x1 - (u12 * y2)) / u11;
        cout <<"x = " << y1 << endl << "y = "<< y2 << endl;
    }
    else if(n == 3){
        double a11, a12, a13, a21, a22, a23, a31, a32, a33;
        double l11, l12, l13, l21, l22, l23, l31, l32, l33;
        double u11, u12, u13, u21, u22, u23, u31, u32, u33;
        double v1, v2, v3, x1, x2, x3, y1, y2, y3;
        cout << "Enter the coefficients of the equations in the following format(an an-1 an-2 ... a1 = b)" << endl;
        cin >> a11 >> a12 >> a13 >> v1 >> a21 >> a22 >> a23 >> v2 >> a31 >> a32 >> a33 >> v3;
        u11 = a11;
        u12 = a12;
        u13 = a13;
        l21 = a21 / u11;
        u22 = a22 - (l21 * u12);
        u23 = a23 - (l21 * u13);
        l31 = a31 / u11;
        l32 = (a32 - (l31 * u12)) / u22;
        u33 = a33 - (l31 * u13) - (l32 * u23);
        x1 = v1;
        x2 = v2 - (l21 * x1);
        x3 = v3 - (l31 * x1) - (l32 * x2);
        y3 = x3 / u33;
        y2 = (x2 - (u23 * y3)) / u22;
        y1 = (x1 - (u12 * y2) - (u13 * y3)) / u11;
        cout <<"x = " << y1 << endl << "y = "<< y2 << endl << "z = " << y3 << endl;
    }
    else if(n == 4){
        double a11,a12,a13,a14,a21,a22,a23,a24,a31,a32,a33,a34,a41,a42,a43,a44;
        double l11,l12,l13,l14,l21,l22,l23,l24,l31,l32,l33,l34,l41,l42,l43,l44;
        double u11,u12,u13,u14,u21,u22,u23,u24,u31,u32,u33,u34,u41,u42,u43,u44;
        double v1,v2,v3,v4,x1,x2,x3,x4,y1,y2,y3,y4;
        cout << "Enter the coefficients of the equations in the following format(an an-1 an-2 ... a1 = b)" << endl;
        cin >> a11 >> a12 >> a13 >> a14 >> v1 >> a21 >> a22 >> a23 >> a24 >> v2 >> a31 >> a32 >> a33 >> a34 >> v3 >> a41 >> a42 >> a43 >> a44 >> v4;
        u11 = a11;
        u12 = a12;
        u13 = a13;
        u14 = a14;
        l21 = a21/u11;
        u22 = a22 - (l21*a12);
        u23 = a23 - (l21*a13);
        u24 = a24 - (l21*a14);
        l31 = (a31/a11);
        l32 = (a32- (l31*u12))/u22;
        u33 = a33 -(l31*u13) - (l32*u23);
        u34 = a34 - (l32*u24) - (l31*u14);
        l41 = a41/u11;
        l42 = (a42-(l41*u12))/u22;
        l43 = (a43 - (l42*u23)- (l41*u13))/u33;
        u44 = a44 - (l43*u34) - (l42*u24) - (l41*u14);
        x1 = v1;
        x2 = v2 - (v1*l21);
        x3 = v3 - (x2*l32) - (v1*l31);
        x4 = v4 - (x3*l43) - (x2*l42) - (v1*l41);
        y4 = x4/u44;
        y3 = (x3 - (y4*u34))/u33;
        y2 = (x2 - (u24*y4) - (u23*y3))/u22;
        y1 = (x1 - (u12*y2) - (u13*y3) -(u14*y4))/u11;
        cout <<"x = " << y1 << endl << "y = "<< y2 << endl << "z = " << y3 << endl << "w = " << y4 << endl;
    }
    else if(n == 1){
        double a11, v1;
        double l11, u11;
        double x1, y1;
        cout << "Enter the coefficients of the equations in the following format(an an-1 an-2 ... a1 = b)" << endl;
        cin >> a11 >> v1;
        u11 = a11;
        l11 = v1 / u11;
        x1 = l11;
        cout <<"x = " << x1 << endl;
    }
    else if(n >= 5){
        cout << "LU decomposition is not applicable for 5 variables. Please enter a number of variables between 1 and 4." << endl;
        goto A;
    }
}