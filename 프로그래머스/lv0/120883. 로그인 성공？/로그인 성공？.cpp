#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    string keyToCheck = id_pw[0];
    map<string, string> myMap;
    
    for(int i = 0; i < db.size(); i ++) {
        string key = db[i][0];
        string value = db[i][1];
        
        myMap[key] = value;
    }
    
    if (myMap.find(keyToCheck) == myMap.end()) 
        answer = "fail";
    
    else {
        if (id_pw[1] == myMap[id_pw[0]]) 
            answer = "login";
        
        else 
            answer = "wrong pw";
    }
    
    return answer;
}