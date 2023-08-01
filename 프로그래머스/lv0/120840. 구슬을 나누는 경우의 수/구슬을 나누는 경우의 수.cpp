#include <string>
#include <vector>
using namespace std;

long Combination(int n, int r)
{
    long sum = 1;
    for (int i = 1; i < r + 1; i++) {
        sum = (sum * n) / i;
        n --;
    }
    return sum;
}

int solution(int balls, int share) {
    return Combination(balls, share);
}