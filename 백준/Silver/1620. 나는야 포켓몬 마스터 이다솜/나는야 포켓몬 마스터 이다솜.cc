#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    string name, s;

    cin >> N >> M;

    unordered_map<string, int> m;
    unordered_map<int, string> m2;
    vector<string> v;

    for(int i = 0; i < N; i ++)
    {
        cin >> name;
        m.insert(make_pair(name, i + 1));
        m2.insert(make_pair(i + 1, name));
    }

    for(int i = 0; i < M; i ++)
    {
        cin >> s;
        v.push_back(s);
    }

    for(int i = 0; i < v.size(); i ++)
    {
        if(atoi(v[i].c_str()) == 0) // 포켓몬 이름일 경우
			cout << m[v[i]] << "\n";
		else // 도감번호일 경우
			cout << m2[atoi(v[i].c_str())] << "\n";
    }

    return 0;
}