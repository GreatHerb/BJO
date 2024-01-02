#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[502][502];
bool visited[502][502] = {false,};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int largestPic = 0;
int bfs_count = 0;
int pic_count = 0;

queue<pair<int,int>> q;

void bfs(int here, int there, int n, int m)
{
    pic_count = 0;    
    visited[here][there] = true;
    q.push(make_pair(here, there));

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nextHere = x + dx[i];
            int nextThere = y + dy[i];

            if(nextHere < 1 || nextHere > n || nextThere < 1 || nextThere > m)
                continue;

            if(visited[nextHere][nextThere] == true)
                continue;

            if(arr[nextHere][nextThere] == 0)
                continue;

            visited[nextHere][nextThere] = true;
            q.push(make_pair(nextHere, nextThere));
        }

        pic_count++;
    }

    if(largestPic < pic_count)
        largestPic = pic_count;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 그림 입력받기
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    // 탐색
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(arr[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j, n, m);
                bfs_count ++;
            }
        }
    }
    
    cout << bfs_count << endl << largestPic << endl;

    return 0;
}
