#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001];
vector<int> graph[1001];

void dfs(int x) { 
    visited[x] = true;
    cout << x << " ";

    for(int i = 0; i < graph[x].size(); i ++) { 
        int y = graph[x].at(i);
        if(!visited[y])
            dfs(y);
    }
}

void bfs(int start) { 
    for(int i = 1; i <= 1000; i ++) { 
        visited[i] = false;
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) { // 큐가 빌 때까지
        int x = q.front();
        q.pop();
        cout << x << " ";

        for(int i = 0; i < graph[x].size(); i ++) { 
            int y = graph[x].at(i);
            if(!visited[y]) { 
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {

	// 정점의 개수 N(1 ≤ N ≤ 1,000)
	// 간선의 개수 M(1 ≤ M ≤ 10,000)
	// 탐색을 시작할 정점의 번호 V 

    int n, m, v;
    cin >> n >> m >> v;

    for(int i = 0; i < m; i ++) { 
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x); // 양방향 연결
    }

    // 낮은 번호부터 오도록 오름차순 정렬
    for(int i = 1; i <= n; i ++) { 
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;

    bfs(v);
    cout << endl;

    return 0;
}