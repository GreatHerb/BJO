#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i = 0; i < queries.size(); i ++) {
        int min_index = queries[i][0]; // 최소 인덱스
        int max_index = queries[i][1]; // 최대 인덱스
        int standard = queries[i][2]; // 기준
        
        int min = 1000001;
        int result;
        
        for(int j = min_index; j <= max_index; j ++) {
            if(arr[j] < min && arr[j] > standard) {
                min = arr[j];
            }
        }
        
        result = min;
        
        if(min == 1000001)
            result = -1;
        
        answer.push_back(result);
    }
    return answer;
}