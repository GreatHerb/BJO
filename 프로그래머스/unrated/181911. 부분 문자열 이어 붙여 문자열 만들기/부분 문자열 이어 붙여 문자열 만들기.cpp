#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    for(int i = 0; i < parts.size(); i ++) {
        int s = parts[i][0];
        int l = parts[i][1] - s + 1;
        string subStr = my_strings[i].substr(s, l);         
        answer += subStr;
    }
    
    return answer;
}