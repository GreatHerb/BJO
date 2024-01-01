#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    
    int dot = 2;

    while(N --)
        dot = dot * 2 - 1;
    
    cout << dot * dot;
    
    return 0;
}
