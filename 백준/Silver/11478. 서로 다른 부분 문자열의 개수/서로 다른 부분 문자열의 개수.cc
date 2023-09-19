#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> result;
    string S, part;
    cin >> S;

    int size = S.size();

    for(int i = 0; i < size; i ++)
    {
        for(int j = 1; j <= size; j ++)
        {
            part = S.substr(i, j); // (i시작, j만큼)
            result.insert(part);
        }
    }

    cout << result. size();

    return 0;
}