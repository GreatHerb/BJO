#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    if(price < 100000)
        return price;
    
    else if(price >= 100000 && price < 300000)
        return price *= 1 - 0.05;
    
    else if(price >= 300000 && price < 500000)
        return price *= 1 - 0.1;
    
    else
        return price *= 1 - 0.2;
}