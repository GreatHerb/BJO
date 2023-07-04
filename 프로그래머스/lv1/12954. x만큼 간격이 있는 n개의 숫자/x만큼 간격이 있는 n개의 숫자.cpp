#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    answer.push_back(x);
    
    for(int i = 1; i < n; i ++) {
        int a = x * (i + 1);
        answer.push_back(a);
    }
    return answer;
}