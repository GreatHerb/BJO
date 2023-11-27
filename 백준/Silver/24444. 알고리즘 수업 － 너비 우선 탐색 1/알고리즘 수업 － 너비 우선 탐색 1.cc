#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> arr[100001];
bool discovered[100002] = {false,};
queue<int> q;
int result[100001];
int cnt = 0;

void bfs(int here)
{
    q.push(here);
    discovered[here] = true;
    cnt ++;
    result[here] = cnt;

    while(!q.empty())
    {
        int next = q.front();
        q.pop();

        for (int i = 0; i < arr[next].size(); i++) 
        { 
			int temp = arr[next][i]; 
			if (!discovered[temp]) 
            { 
                cnt ++;
				result[temp] = cnt;
				q.push(temp); // 큐에 넣고
				discovered[temp] = true; // 방문처리
			}
		}
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R, x, y;
    cin >> N >> M >> R;

    for(int i = 0; i < M; i++)
    {
        cin >> x >> y;
        arr[x].push_back(y); 
		arr[y].push_back(x); 	
    }

    for (int i = 1; i <= N; i++) 
		sort(arr[i].begin(), arr[i].end());

    bfs(R);

    for(int i = 1; i <= N; i++)
        cout << result[i] << "\n";

    return 0;
}
