#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    int N;
    string s;

    cin >> N;

    for(int i = 0; i < N; i ++)
    {
        cin >> s;
        string key = s;

        auto item = m.find(key);

        if (item != m.end())  // 찾음
            item->second ++;
        
        else // 없음
            m.insert(make_pair(s, 1));
    }

    vector<pair<string, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), [](pair<string, int>  a, pair<string, int>  b)
    {
        if (a.second != b.second)
        	return a.second > b.second;
        
        else 
        	return a < b;
        
    });

    cout << v[0].first;

    return 0;
}