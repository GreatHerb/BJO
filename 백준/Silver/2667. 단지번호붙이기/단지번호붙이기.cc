#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result;
int arr[27][27];
bool visited[27][27] = {false,};
int x[4] = {0, 0, -1, 1}; // 상 하 좌 우
int y[4] = {1, -1, 0, 0}; // 상 하 좌 우
int d_count = 0;

void dfs(int here, int there)
{
    visited[here][there] = true; // 방문처리
    d_count ++;

    // 상하좌우 탐색
    for(int i = 0; i < 4; i ++)
    {
        int nextHere = here + x[i];
        int nextThere = there + y[i];

        // 이미 방문했으면 skip
        if(visited[nextHere][nextThere] == true)
            continue;

        // 탐색할게 남아있으면 탐색한다
        if (arr[nextHere][nextThere] == 1)
            dfs(nextHere, nextThere);
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i ++)
    {
        string s;
        cin >> s;

        for(int j = 1; j <= N; j ++)
            arr[i][j] = s[j - 1] - '0';
    }

    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= N; j ++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                d_count = 0;
                dfs(i, j);
                result.push_back(d_count);
            }
        }
    }

    // 결과 처리 - 오름차순
    sort(result.begin(), result.end());

    // 결과 출력 
    cout << result.size() << "\n";

    for (auto a : result)
        cout << a << "\n";

    return 0;
}
