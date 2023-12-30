#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> family[101]; // 가족 관계
bool visited[101]; // 방문 여부
int relation[101]; // 각 번호 사이의 촌수를 저장

int bfs(int start, int end) 
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    relation[start] = 0;

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        if (current == end) 
            return relation[current];
        
        for (int i = 0; i < family[current].size(); i++) 
        {
            int next = family[current][i];
            if (!visited[next]) 
            {
                q.push(next);
                visited[next] = true;
                relation[next] = relation[current] + 1;
            }
        }
    }
    
    return -1; // 관계를 찾을 수 없는 경우
}

int main() 
{
    int n, m, x, y, start, end;
    cin >> n;
    cin >> start >> end;
    cin >> m;

    for (int i = 0; i < m; i++) 
    {
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x); // 양방향 관계를 위해 추가
    }

    int answer = bfs(start, end);
    cout << answer;

    return 0;
}
