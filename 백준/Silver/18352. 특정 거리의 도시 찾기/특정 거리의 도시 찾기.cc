#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300001
#define INF 987654321
using namespace std;

vector<int> graph[MAX];
int dist[MAX];

void bfs(int start) 
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < graph[current].size(); i++) 
        {
            int next = graph[current][i];
            if (dist[next] == INF) 
            {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) 
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    fill(dist, dist + MAX, INF); 
    bfs(X);

    vector<int> answer;

    for (int i = 1; i <= N; i++) 
    {
        if (dist[i] == K) 
            answer.push_back(i);
    }

    if (answer.empty()) 
        cout << -1 << '\n';
    
    else 
    {
        sort(answer.begin(), answer.end());

        for (int i = 0; i < answer.size(); i++) 
            cout << answer[i] << '\n';
    }

    return 0;
}
