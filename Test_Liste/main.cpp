#include <iostream>
#include <list>
using namespace std;

class test_list{
private:
    list<int> l;
    void displayList(){
        cout<<"Vide? "<<l.empty()<<" Taille:"<<l.size()<<" "<<endl;
        cout<<"Tetete "<<l.front()<<" Culcul:"<<l.back()<<" "<<endl;
    }
public:
    test_list(){
    cout<<"init"<<endl;
    }
    void runTest();
};

void test_list::runTest(){
    displayList();
    l.push_front(1);
    l.push_front(2);
    displayList();
    l.push_back(3);
    l.pop_front();
    displayList();
    l.pop_back();
    displayList();
}

int main()
{
    test_list test;
    test.runTest();
}
