#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    string sol1 = s1 + s2;
    string sol2 = s2 + s1;
    
    answer = stoi(sol1) > stoi(sol2) ? stoi(sol1) : stoi(sol2);
    
    return answer;
}