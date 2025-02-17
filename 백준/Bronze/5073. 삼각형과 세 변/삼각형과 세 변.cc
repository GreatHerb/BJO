#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {

    int a, b, c;
    set<int> s;

    while (true)
    {
        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0)
            break;

        int max_side = max({a, b, c}); 
        int sum_of_others = a + b + c - max_side; 

        if (sum_of_others > max_side){
            s.insert(a);
            s.insert(b);
            s.insert(c);

            if(s.size() == 1)
                cout << "Equilateral" << endl;
            
            else if(s.size() == 2)
                cout << "Isosceles" << endl;

            else
                cout << "Scalene" << endl;
            
            s.clear();
        }

        else
            cout << "Invalid" << endl;

    }
    
    return 0;
}