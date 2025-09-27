#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> name;              
    vector<pair<string, string>> events;             

    for (const string& line : record) {
        istringstream iss(line);
        string cmd, uid, nick;
        iss >> cmd >> uid;
        if (cmd == "Enter" || cmd == "Change") {
            iss >> nick;
            name[uid] = nick;                        
        }
        if (cmd == "Enter" || cmd == "Leave") {
            events.emplace_back(cmd, uid);          
        }
    }

    vector<string> answer;
    answer.reserve(events.size());
    for (const auto& [cmd, uid] : events) {
        const string& nick = name[uid];             
        if (cmd == "Enter")  answer.push_back(nick + "님이 들어왔습니다.");
        else                  answer.push_back(nick + "님이 나갔습니다.");
    }
    return answer;
}