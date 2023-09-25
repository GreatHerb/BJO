#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> s;
    string word;

    int N, M, result = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i ++)
    {
        cin >> word;
        s.insert(word);
    }

    for(int i = 0; i < M; i ++)
    {
        cin >> word;

        if (s.find(word) != s.end()) // 중복 된다 : 
            result ++;
    }

    cout << result;
}