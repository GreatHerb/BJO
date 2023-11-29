#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int main()
{
    map<string, long> m;
    m.insert({"black", 0});
    m.insert({"brown", 1});
    m.insert({"red", 2});
    m.insert({"orange", 3});
    m.insert({"yellow", 4});
    m.insert({"green", 5});
    m.insert({"blue", 6});
    m.insert({"violet", 7});
    m.insert({"grey", 8});
    m.insert({"white", 9});

    string color1, color2, color3;
    cin >> color1 >> color2 >> color3;

    long a = m[color1];
    long b = m[color2];
    long c = m[color3];

    long result = ((a * 10) + b) * (pow(10, c));

    cout << result << endl;

    return 0;
}