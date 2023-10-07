#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet
{
public:
    DisjointSet(int n) : _parent(n + 1), _rank(n + 2, 1)
    {
        for (int i = 0; i < n + 1; i++)
            _parent[i] = i;
    }

    // 니 대장이 누구니?
    int Find(int u)
    {
        if (u == _parent[u])
            return u;

        return _parent[u] = Find(_parent[u]);
    }

    // u와 v를 합친다
    void Merge(int u, int v)
    {
        u = Find(u);
        v = Find(v);

        if (u == v)
            return;

        if (_rank[u] > _rank[v])
            swap(u, v);

        // rank[u] <= rank[v] 보장됨
        _parent[u] = v;

        if (_rank[u] == _rank[v])
            _rank[v]++;
    }

private:
    vector<int> _parent;
    vector<int> _rank;
};

struct Vertex
{
    // int data;
};

vector<Vertex> vertices;
vector<vector<pair<int, int>>> adjacent; // 인접 행렬

struct CostEdge
{
    int cost;
    int u;
    int v;

    bool operator<(const CostEdge& other) const
    {
        return cost < other.cost;
    }
};

int Kruskal(vector<CostEdge>& selected)
{
    int ret = 0;

    selected.clear();

    vector<CostEdge> edges;

    for (int u = 0; u < adjacent.size(); u++)
    {
        for (int v = 0; v < adjacent[u].size(); v++)
        {
            if (u > adjacent[u][v].first) // 수정된 부분
                continue;

            int cost = adjacent[u][v].second;
            edges.push_back(CostEdge{ cost, u, adjacent[u][v].first }); // 수정된 부분
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet sets(vertices.size());

    for (CostEdge& edge : edges)
    {
        // 같은 그룹이면 스킵 (안 그러면 사이클 발생)
        if (sets.Find(edge.u) == sets.Find(edge.v))
            continue;

        // 두 그룹을 합친다
        sets.Merge(edge.u, edge.v);

        selected.push_back(edge);
        ret += edge.cost;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, a, b, c;
    cin >> V >> E;

    vertices.resize(V + 1); // 1부터 V까지 사용
    adjacent = vector<vector<pair<int, int>>>(V + 1); // 1부터 V까지 사용

    for (int i = 1; i <= E; i++) // 1부터 E까지 사용
    {
        cin >> a >> b >> c;
        adjacent[a].push_back({ b, c }); // 수정된 부분
        adjacent[b].push_back({ a, c }); // 수정된 부분
    }

    vector<CostEdge> selected;
    int result = Kruskal(selected);

    cout << result << endl;
}
