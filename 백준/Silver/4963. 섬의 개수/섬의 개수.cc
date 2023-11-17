#include <iostream>
#include <queue>
using namespace std;

int arr[52][52];
queue<pair<int, int>> q;
bool discoverd[52][52] = {false,};

int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1}; // 상 하 좌 우 우상 우하 좌상 좌하
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1}; // 상 하 좌 우 우상 우하 좌상 좌하

int island_count = 0;

void bfs(int here, int there)
{
    discoverd[here][there] = true;
    q.push(make_pair(here, there));

    while(q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i ++)
        {
            int nextHere = x + dx[i];
            int nextThere = y + dy[i];

            if(discoverd[nextHere][nextThere] == true)
                continue;
            
            if(arr[nextHere][nextThere] == 0)
                continue;
            
            discoverd[nextHere][nextThere] = true;
            q.push(make_pair(nextHere, nextThere));
        }
    } 
}

int main()
{
    int w, h;

    while(1)
    {
        cin >> w >> h;

        if(w == 0 && h == 0)
            break;
        
        // 입력 전 초기화
        q = queue<pair<int,int>>();
        island_count = 0;
        
        for(int i = 0; i < 52; i++)
        {
            for(int j = 0; j < 52; j++)
            {
                arr[i][j] = 0;
                discoverd[i][j] = false;
            }
        }
        
        // 입력 받기
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
                cin >> arr[i][j];
        }

        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                if(arr[i][j] == 1 && discoverd[i][j] == false)
                {
                    island_count ++;
                    bfs(i, j);
                }
            }
        }

        cout << island_count << "\n";
    }

    return 0;
}