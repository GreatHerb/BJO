#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

bool compare(Point a, Point b)
{
    if(a.y == b.y)
        return a.x < b.x;
    
    return a.y < b.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<Point> v(N);

    for(int i = 0; i < N; i ++)
        cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), compare);

    for(const auto a : v)
        cout << a.x << " " << a.y << "\n";
    
    return 0;
}