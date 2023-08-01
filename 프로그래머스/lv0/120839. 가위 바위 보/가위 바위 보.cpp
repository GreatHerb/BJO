#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string rsp) {
    string answer = "";
    
    map<char, char> win = {
        {'2', '0'}, {'0', '5'}, {'5', '2'} 
    };
    
    for(int i = 0; i < rsp.length(); i ++) 
        answer += win[rsp[i]];
    
    return answer;
}