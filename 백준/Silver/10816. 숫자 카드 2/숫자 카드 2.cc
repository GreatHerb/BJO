#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<int, int> m;   
    int N, num;
    cin >> N;

    for(int i = 0; i < N; i ++)
    {
        int key;
        cin >> key;

        auto item = m.find(key);

        if (item != m.end()) // 존재
            item->second ++;
        
        else // 존재하지 않음
            m.insert(make_pair(key, 1));
    }

    vector<int> v;
    int M;
    cin >> M;

    for(int i = 0; i < M; i ++)
    {
        cin >> num;
        v.push_back(num);
    }

    for(int i = 0; i < v.size(); i ++)
    {
        int key = v[i];
        auto item = m.find(key);

        if (item != m.end()) // 존재
            cout << item->second << " ";
        
        else // 존재하지 않음
            cout << "0" << " ";
    }

    return 0;
}