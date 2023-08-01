#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for (auto intStr : intStrs) {
        string subStr = intStr.substr(s, l); 
        int num = stoi(subStr); 

        if (num > k) 
            answer.push_back(num); 
    }
    return answer;
}