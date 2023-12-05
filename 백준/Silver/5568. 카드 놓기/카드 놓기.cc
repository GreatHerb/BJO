#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, a;
    cin >> n >> k;

    vector<int> v;
    set<string> s;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    do
    {
        string res;
        for(int i = 0; i < k; i++)
            res += to_string(v[i]);
        s.insert(res);
    } while (next_permutation(v.begin(), v.end()));

    cout << s.size() << endl;

    return 0;
}