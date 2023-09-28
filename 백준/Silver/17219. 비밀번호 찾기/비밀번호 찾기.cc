#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<string> v;
    unordered_map<string, string> m;
    string site, pw;

    for(int i = 0; i < N; i ++)
    {
        cin >> site >> pw;
        m.insert(make_pair(site, pw));
    }

    for(int i = 0; i < M; i ++)
    {
        cin >> site;
        v.push_back(site);
    }

    for(int i = 0; i < v.size(); i ++)
        cout << m[v[i]] << "\n";
    
    return 0;
}