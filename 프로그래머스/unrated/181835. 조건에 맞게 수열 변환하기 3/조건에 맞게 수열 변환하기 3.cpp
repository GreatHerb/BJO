#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    for(int i = 0; i < arr.size(); i ++) {
        if(k % 2 != 0)
            // 홀수
            arr[i] *= k;
        else
            // 짝수
            arr[i] += k;
    }
    
    return arr;
}