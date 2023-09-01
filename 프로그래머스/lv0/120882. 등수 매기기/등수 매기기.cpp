#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    for (int i = 0; i < score.size(); ++i) {
        int ranking = 1;
        
        for (int j = 0; j < score.size(); ++j) {
            if ((score[i][0] + score[i][1]) < (score[j][0] + score[j][1])) 
                ranking++;
            
            else if ((score[i][0] + score[i][1]) == (score[j][0] + score[j][1])) 
                continue;
        }
        
        answer.push_back(ranking);
    }

    return answer;
}