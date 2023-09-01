#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b, int n) {
    int diff_a = abs(a - n);
    int diff_b = abs(b - n);

    if (diff_a == diff_b) 
        return a > b; // 거리가 같을 경우 더 큰 수를 앞으로

    return diff_a < diff_b; // 거리가 작은 수를 앞으로
}

vector<int> solution(vector<int> numlist, int n) {
    sort(numlist.begin(), numlist.end(), [n](int a, int b) {
        return compare(a, b, n);
    });
    
    return numlist;
}
