#include <iostream>
#include <unordered_set>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cd;
    
    while (true) {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        unordered_set<int> sanggunCD;

        for (int i = 0; i < N; i++) {
            cin >> cd;
            sanggunCD.insert(cd);
        }

        int count = 0;

        for (int i = 0; i < M; i++) {
            cin >> cd;
            auto it = sanggunCD.find(cd);

            if (it != sanggunCD.end())
                count++;
        }

        cout << count << "\n";
    }

    return 0;
}
