#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[1002][1002];
bool discoverd[1002][1002];
int dist[1002][1002];

int dx[4] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[4] = {1, -1, 0, 0}; // 상 하 좌 우

queue<pair<int,int>> q;

void bfs(int here, int there)
{
    discoverd[here][there] = true;
    dist[here][there] = 0;
    q.push(make_pair(here, there));

    while(q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nextHere = x + dx[i];
            int nextThere = y + dy[i];

            if(discoverd[nextHere][nextThere] == true)
                continue;
            
            if(arr[nextHere][nextThere] == 0)
                continue;
            
            discoverd[nextHere][nextThere] = true;
            q.push(make_pair(nextHere, nextThere));

            dist[nextHere][nextThere] = dist[x][y] + 1;
        }
    }
}

int main()
{
    int n, m, here, there;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];

            if(arr[i][j] == 2)
            {
                here = i;
                there = j;
            }
        }
    }

    bfs(here, there);

    // 방문할 수 없는 곳 처리
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dist[i][j] == 0 && arr[i][j] != 0)
                dist[i][j] = -1;
         }
    }

    dist[here][there] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << dist[i][j] << " ";
        cout << "\n";
    }

    return 0;
}