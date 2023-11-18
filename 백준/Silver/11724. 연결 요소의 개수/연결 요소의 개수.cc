#include <iostream>
#include <vector>
#include <algorithm> // 추가된 부분
using namespace std;

vector<vector<int>> adjacent;
vector<bool> visited;

void dfs(int here)
{
    visited[here] = true;

    for (int i = 0; i < adjacent[here].size(); i++) // 수정된 부분
    {
        int there = adjacent[here][i];
        if (!visited[there])
            dfs(there);
    }
}

vector<int> result;

void dfsAll(int N)
{
    visited = vector<bool>(N + 1, false); 
    
    for (int i = 1; i <= N; i++) 
    {
        if (!visited[i])
        {
            dfs(i);
            result.push_back(1);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    adjacent = vector<vector<int>>(N + 1);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x); 
    }

    dfsAll(N);

    cout << result.size() << "\n";

    return 0;
}
