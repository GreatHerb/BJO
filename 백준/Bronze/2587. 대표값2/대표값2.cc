#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int sum = 0;

    for(int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;

        v.push_back(num);
        sum += num;
    }

    int ave = sum / 5;

    sort(v.begin(), v.end());

    cout << ave << endl << v[2] << endl;
    
    return 0;
}