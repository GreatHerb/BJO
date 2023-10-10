#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    int avg = 0;

    for (int i = 0; i < n; i++) 
    {
        cin >> v[i];
        avg += v[i];
    }

    avg /= n;

    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) 
    {
        if (v[i] > avg + 1) 
            cnt1 += (v[i] - avg - 1);
        else if (v[i] < avg) 
            cnt2 += (avg - v[i]);
    }

    cout << max(cnt1, cnt2) << endl;

    return 0;
}
