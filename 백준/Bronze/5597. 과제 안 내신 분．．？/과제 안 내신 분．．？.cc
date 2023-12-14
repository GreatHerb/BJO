#include <iostream>
using namespace std;

int main() {
    bool students[31] = {false, };
    for(int i = 1; i <= 30; i++)
        students[i] = true; 

    for(int i = 0; i < 28; i++) 
    {
        int n;
        cin >> n; 
        students[n] = false;
    }

    for(int i = 1; i <= 30; i++)
        if(students[i]) 
            cout << i << '\n';

    return 0;
}
