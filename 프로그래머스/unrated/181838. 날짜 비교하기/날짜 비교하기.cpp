#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    int year1 = date1[0], month1 = date1[1], day1 = date1[2];
    int year2 = date2[0], month2 = date2[1], day2 = date2[2];
    
    // 연도가 먼저 비교
    if (year1 < year2) 
        return 1;
    
    else if (year1 > year2) 
        return 0;
    
    else {
        // 월 비교
        if (month1 < month2) 
            return 1;
        
        else if (month1 > month2)
            return 0;
        
        else {
            // 날짜를 비교
            if (day1 < day2)
                return 1;
            
            else if (day1 > day2)
                return 0;
            
            else
                // 같음
                return 0;
        }
    }
}