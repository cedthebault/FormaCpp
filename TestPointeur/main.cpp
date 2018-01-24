#include <iostream>

using namespace std;

int main()
{
//i n t i ,  pi , k ;
//i =3;
//p i = &i ; // p i p o i n t e s u r i
//k = ( p i )+5; // i d e n t i q u e `a : k=i+5
//( p i ) = k+2; // i d e n t i q u e `a : i = k+2
//( p i )++;
//// i c i , i =11, k=8

int i,*pi,k;
i=3;
pi=&i;
k=(*pi)+5;
(*pi)=k+2;
(*pi)++;

cout<<"i:"<<i<<endl;
cout<<"&i:"<<&i<<endl;
cout<<"pi:"<<pi<<endl;
cout<<"*pi:"<<*pi<<endl;
cout<<"&pi:"<<&pi<<endl;
cout<<"k:"<<k<<endl;
cout<<"&k:"<<&k<<endl;
}
