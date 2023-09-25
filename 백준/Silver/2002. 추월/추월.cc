#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, result = 0;
    cin >> N;
    string s;

    unordered_map<string, int> m;
    vector<string> v;

    for(int i = 0; i < N; i ++) // 터널에 들어가는 순서
    {
        cin >> s;
        m.insert(make_pair(s, i));
    }

    for(int i = 0; i < N; i ++) // 터널에서 나오는 순서
    {
        cin >> s;
        v.push_back(s);
    }

    // 추월을 했는지 확인하는 법
    //      1 2 3 4
    // ->   2 4 3 1  :  추월한 차의 수 = 2대

    for(int i = 0; i < N; i ++)
    {
        string ss = v[i];

        for (int j = i + 1; j < N; j++) // 현재 차량보다 뒤에 있는 차량과 비교
        {
            if (m[ss] > m[v[j]]) // 추월한 경우
            {
                result ++;
                break; // 이미 추월했으므로 다음 차량으로 넘어감
            }
        }
    }

    cout << result;
}