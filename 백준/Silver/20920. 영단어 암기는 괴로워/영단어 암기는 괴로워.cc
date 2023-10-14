#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> mp;

bool compare(const string& a, const string& b)
{
    if(mp[a] == mp[b] && a.size() == b.size())
        return a < b;
    
    else if(mp[a] == mp[b])
        return a.size() > b.size();
    
    return mp[a] > mp[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    vector<string> v;

    for(int i = 0; i < N; i ++)
    {
        string word;
        cin >> word;

        auto it = mp.find(word);

        if(word.length() >= M)
        {
            if(it == mp.end()) // 존재하지 않음
            {
                mp[word] = 0;
                v.push_back(word);
            }
        }
        mp[word] ++;
    }

    sort(v.begin(), v.end(), compare);

    for(const auto &a : v)
        cout << a << "\n";
    
    return 0;
}