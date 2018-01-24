#include <iostream>

using namespace std;

int factorielle(int n){
    if(n==1)
        return 1;
    else{
        return n*factorielle(n-1);
    }
}

double fibo(double n){
    if(n==0) return 0;
    if(n<=2) return 1;
    return fibo(n-1)+fibo(n-2);
}


int main()
{
    int n = 10;
    //cout << "Factorielle:" << endl << n << "!=" << factorielle(n) << endl;
    for(double i=0;i<=n;i++)
    cout << "Fibo("<< i << ")=" << fibo(i) << endl;
    return 0;
}
