#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> arr(T, 0);

    for (int i = 0; i < T; i++) {
        for(int j = 0; j < 10; j++) {
            int num;
            cin >> num;

            if(num % 2 == 1)
                arr[i] += num;
        }
    }

    for(int i = 0; i < T; i++) {
        cout << "#" << i + 1 << " " << arr[i] << endl;
    }

    return 0;
}