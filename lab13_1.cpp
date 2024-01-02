#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double x[],int N,double y[]){
    for(int i=0;i<N;i++){
        y[0] += x[i];
    }
    y[0] /= N;
    for(int i=0;i<N;i++){
        y[1] += pow(x[i],2);
    }
    y[1] = sqrt((y[1]/N)-pow(y[0],2));
    y[2]=1;
    for(int i=0;i<N;i++){
        y[2] *= x[i];
    }
    y[2] = pow(y[2],1.0/N);
    for(int i=0;i<N;i++){
        y[3] += 1.0/x[i];
    }
    y[3] = N/y[3];
    for(int i=0;i<N;i++){
        if(x[i]>y[4]) y[4]=x[i];
    }
    y[5]=y[4];
    for(int i=0;i<N;i++){
        if(x[i]<y[5]) y[5]=x[i];
    }
}