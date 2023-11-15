#include <iostream>
#include <vector>
using namespace std;

int arr[52][52] = {0,};
bool visited[52][52] = {false,};
int x[4] = {0, 0, -1, 1}; // 상 하 좌 우
int y[4] = {1, -1, 0, 0};

int dfs_count = 0;
vector<int> result; 

void dfs(int here, int there)
{
    visited[here][there] = true;
    dfs_count++;

    for(int i = 0; i < 4; i ++)
    {
        int nextHere = here + x[i];
        int nextThere = there + y[i];

        if(visited[nextHere][nextThere] == true)
            continue;
        
        if(arr[nextHere][nextThere] == 1)
            dfs(nextHere, nextThere);
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int T, M, N, K, X, Y;
    cin >> T;

    while(T > 0)
    {
        result.clear(); // 결과 초기화

        for(int i = 0; i < 52; i++) // 방문상태 초기화
        {
            for(int j = 0; j < 52; j++)
                visited[i][j] = false;
        }

        for(int i = 0; i < 52; i++) // 배열 초기화
        {
            for(int j = 0; j < 52; j ++)
                arr[i][j] = 0;
        }

        cin >> M >> N >> K;
        
        for(int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            arr[X + 1][Y + 1] = 1;
        }

        for(int i = 1; i <= M; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if (arr[i][j] == 1 && !visited[i][j])
                {
                    dfs_count = 0;
                    dfs(i, j);
                    result.push_back(dfs_count);
                }
            }
        }

        cout << result.size() << "\n";

        T--;
    }
    return 0;
}