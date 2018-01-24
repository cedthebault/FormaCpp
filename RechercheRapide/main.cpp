#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

int n;

int justePrix(int p,int iMin,int iMax,int essai=1){
//TODO : TEst variable statique;
cout<<"essai:"<<essai<<" "<<iMin<<"<="<<p<<"<="<<iMax<<endl;
if(p==n) return essai;
//+
if(p<n) return justePrix(p+round(1+(iMax-(p+1))/2),p+1,iMax,++essai);
//-
if(p>n) return justePrix(iMin+round(((p-1)-iMin)/2),iMin,p-1,++essai);
}


int main()
{
    int nmbMax=100000;
    srand(time(NULL));

    for(int i =0;i<50;i++){
        n = rand()%nmbMax;
        //n=1217;
        cout<<"n:"<<n<<endl;
        int essai=justePrix(nmbMax/2,0,nmbMax);
        cout<<"** essai:"<<essai<<endl;
    }
}
