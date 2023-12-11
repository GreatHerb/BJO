#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int count = N / 4;

    string result = "";

    for(int i = 0; i < count; i++)
        result += "long ";
    
    result += "int";

    cout << result << endl;

    return 0;
}