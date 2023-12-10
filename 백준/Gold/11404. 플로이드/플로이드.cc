#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;
vector<vector<int>> D;

void Floyd(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (D[i][k] != INF && D[k][j] != INF) 
                {
                    if (D[i][j] == INF || D[i][k] + D[k][j] < D[i][j]) 
                        D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    D = vector<vector<int>>(n, vector<int>(n, INF));
    for(int i = 0; i < n; i ++)
        D[i][i] = 0;

    for (int i = 0; i < m; i++) 
    {
        int a, b, c;
        cin >> a >> b >> c;

        a--; 
        b--; 
        if (D[a][b] > c)
            D[a][b] = c;
    }

    Floyd(n);
    
    // 최단 경로 행렬 출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (D[i][j] == INF)
                cout << 0 << " ";
            else
                cout << D[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}
