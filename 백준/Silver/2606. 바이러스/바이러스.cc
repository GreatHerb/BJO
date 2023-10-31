#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;
vector<int> result;

void Dfs(int here)
{
	// 방문!
	visited[here] = true;
	result.push_back(here);

	// 모든 인접 정점을 순회한다
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}
}

int main()
{
    int com, link, x, y;
    cin >> com >> link;

    visited = vector<bool>(com, false);
    vertices.resize(com);
    adjacent = vector<vector<int>>(com + 1);

    for(int i = 0; i < link; i ++)
    {
        cin >> x >> y;
        adjacent[x].push_back(y);
		adjacent[y].push_back(x);
    }
 
	Dfs(1);
	cout << result.size() - 1 << endl;
}
