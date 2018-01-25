#include <iostream>

using namespace std;

template<class T> T * echanger(T *t, int index, int index_min)
{
    T c = t[index];
    t[index] = t[index_min];
    t[index_min] = c;
    return t;
}

template<class T>T * trier(T *tab,int l)
{
    int j, min;
    for(int i = 0; i < l-1; i++)
    {
        for(j = i; j < l; j++)
        {
            if(j == i)
                min = j;
            if(tab[j] < tab[min])
                min = j;
        }
        echanger(tab, i, min);
    }
    return tab;
}

template<class T> void init(T* t,int l){
    T j=10;
    for(int i=0;i<l;i++){
        t[i]=j--;
    }
}
void init(float* t,int l){
    float j=10.1;
    for(int i=0;i<l;i++){
        t[i]=j--;
    }
}
void init(int* t,int l){
    int j=10;
    for(int i=0;i<l;i++){
        t[i]=j--;
    }
}

template<class T> affiche(T* t,int l){
     cout<<"Tableau : ";
     for(int i=0;i<l;i++){
        cout<<t[i]<<" ";
     }
     cout<<endl;
}

int main()
{
    cout << "Hello world!" << endl;
    int siz=10;
    int tabI[siz];
    float tabF[siz];
    init(tabI,siz);
    init(tabF,siz);
    affiche(tabI,siz);
    affiche(tabF,siz);

    trier(tabI,siz);
    trier(tabF,siz);

    affiche(tabI,siz);
    affiche(tabF,siz);

    return 0;
}
