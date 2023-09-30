#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, string> m;
    vector<string> v;

    string name, state;  

    for(int i = 0; i < n; i ++)
    {
        cin >> name >> state;
        if(state == "leave")
            m.erase(name);
            
        else 
            m.insert(make_pair(name, state));
    }

    for(auto a : m)
        v.push_back(a.first);
    
    sort(v.rbegin(), v.rend());

    for(auto name : v)
        cout << name << "\n";
}