#include <map>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    map<string, int> mapOfWords;
    // Inserting data in map
    mapOfWords.insert(make_pair("earth", 1));
    mapOfWords.insert(make_pair("moon", 2));
    mapOfWords["sun"] = 3;
    // Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;
    // Iterate through all elements in map
    map<string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        cout<<it->first<<" :: "<<it->second<<endl;
        it++;
    }
    // Check if insertion is successful or not
    if(mapOfWords.insert(make_pair("earth", 1)).second == false)
    {
        cout<<"Element with key 'earth' not inserted because already existed"<<endl;
    }
    // Searching element in map by key.
    if(mapOfWords.find("sun") != mapOfWords.end())
        cout<<"word 'sun' found"<<endl;
    if(mapOfWords.find("mars") == mapOfWords.end())
        cout<<"word 'mars' not found"<<endl;
    return 0;
}
