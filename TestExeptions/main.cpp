#include <iostream>
#include <vector>

using namespace std;

int valueAt(vector<int> t,int index){
    try{
        return t.at(index);
    }catch(const exception & e){
        cerr<<"::valueAt::";
        throw e;
    }
//    if(index>=)

}

int main()
{
    vector<int> tab(10);
    try{
        cout << valueAt(tab,2)<<endl;
        cout << valueAt(tab,15)<<endl;
    }catch(const exception & e){
        cerr << "Soushis !!!!!";
        cerr << e.what();
    }
    return 0;
}
