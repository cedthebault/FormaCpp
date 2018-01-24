#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

//int main()
//{
//    int i=0;
//    //cout << i++ << endl;
//    char var1,var2;
//    cout << "Var1 puis Var2" <<endl;
//    cin>>var1>>var2;
//    cout<<var1<<endl;
//    cout<<var2<<endl;
//    return 0;
//}

void AfficherTab(const vector<int> T)
{
 for (int i=0 ; i< T.size() ; i++)
 cout << T[i] << " " ;
 cout<<endl;
}

void permute(int & a,int & b)
{int aux = b ;
b = a ;
a = aux ; }

int maxVector(vector<int> &T,int j){
 int maxT=0,indexMax=0,i=0;
 for(i=0;i<T.size()-1-j;i++){
    if(T[i]>=maxT){
        maxT=T[i];
        indexMax=i;
    }
 }
 return indexMax;
}

void trieSelection(vector<int> & T){
 int i=0,j=0;
 //cout<<"size of T:"<<T.size()<<endl;
 for(i=T.size()-1 ;i>0; i--){
    int indexMax=maxVector(T,j-1);
    //cout << "indexMax:" << indexMax <<",T[imax]="<<T[indexMax]<<endl;
    permute(T[indexMax],T[i]);
    //AfficherTab(T);
    j++;
 }

}

void trieBulle(vector<int> & T){
 int i=0,j=0,p=0;
 //cout<<"size of T:"<<T.size()<<endl;
 //for(i ;i<T.size(); i++){
  bool is=false;
 do{
    is=false;
    //cout<<i<<endl;
    for(j=0;j<T.size()-i-1;j++){
        if(T[j]>T[j+1]){
            permute(T[j],T[j+1]);
            is=true;
            p++;
            //AfficherTab(T);
        }

    }
    i++;
 }while(is);
 cout<<"Nmb de cycles:"<<i<<" Nmb permuts:"<<p<<endl;
}

void remplir(vector<int> & T,int nbElem){
 srand(time(NULL));
for(int i=0;i<nbElem;i++)
    T.push_back(rand()%5000);
}

int main()
{
// int tmp[] = { 1,5,8,6,15,2 };
// vector<int> T(tmp,tmp+sizeof(tmp)/sizeof(tmp[0]));
 vector<int> T;
 remplir(T,5);
 cout<<"Tableau Initial"<<endl;
 AfficherTab(T);
 //----------------
 //trieSelection(T);
 trieBulle(T);
 //----------------
 cout<<"Result"<<endl;
 AfficherTab(T);
 //cout<<"Expected : 1,2,5,6,8,15";
}
