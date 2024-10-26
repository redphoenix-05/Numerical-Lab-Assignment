#include <iostream>
#include <cmath>
using namespace std;


double fn(double x,double y,int num) {
switch(num){
   case 1:
          return x-y;
          break;
   case 2:
          return 2*x+1;
          break;
   case 3:
          return sin(x);
          break;
   case 4:
          return cos(x);
          break;
   case 5:
          return x-y;
          break;

     }
}

void runge_Kutta(double x0,double y0,double h,double interval_2,int num)
{
    double x=x0;
    double y=y0;
    int n=(int)((interval_2-x0)/h);

    for (int i = 0; i <= n; ++i) {
        cout<<"x: "<<x<<" y: "<<y<<endl;

        double k1=h*fn(x,y,num);
        double k2=h*fn(x+0.5*h,y+0.5*k1,num);
        double k3=h*fn(x+0.5*h,y+0.5*k2,num);
        double k4=h*fn(x+h,y+k3,num);
        y+=(k1+2*k2+2*k3+k4)/6.0;
        x+=h;
    }
}

void r_k()
{
    double h,interval_2,y0,x0;
    h=0.1;
    x0=0;
    int num;
    cout<<"1.dy/dx=x+y"<<endl;
    cout<<"2.dy/dx=2*x+1"<<endl;
    cout<<"3.dy/dx=x-y"<<endl;
    cout<<"4.dy/dx=sin(x)"<<endl;
    cout<<"5.dy/dx=cos(x)"<<endl;
    cout<<"enter the number of equation: ";

    cin>>num;
    if(num==4){
         y0=0;
         interval_2=4*3.1416;
    }
    else if(num==5){
         y0=1;
         interval_2=4*3.1416;
    }
    else{
        y0=1;
        interval_2=10;
    }

    runge_Kutta(x0,y0,h,interval_2,num);
}