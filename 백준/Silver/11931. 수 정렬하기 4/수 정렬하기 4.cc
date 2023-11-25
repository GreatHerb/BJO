#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    vector<int> v;
    int n, num;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.rbegin(), v.rend());

    for(auto a : v)
        cout << a << "\n";
}