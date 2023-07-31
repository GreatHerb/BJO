#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int i = 0;
    
    while(true) {
        if(i >= arr.size())
            break;
        
        if(stk.empty()) {
            stk.push_back(arr[i]);
            i ++;
        }
        
        else { // 원소가 있는 경우
            if(stk.back() < arr[i]) {
                stk.push_back(arr[i]);
                i ++;
            }
            
            else
                stk.pop_back();
        }
    }
    
    return stk;
}