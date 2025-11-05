#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<long> results;

    while(T--) {
        int N;
        cin >> N;
        vector<int> v;

        for(int i = 0; i < N; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        int mx = -1;
        long result = 0;
        for(int i = N - 1; i >= 0; i--) {
            mx = max(mx, v[i]);
            result += mx - v[i];
        }

        results.push_back(result);
    }

    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }

    return 0;
}