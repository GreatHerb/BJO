#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string name;
    bool out = false;

    int arr[26] = {0};
    // a : 0, b : 1, c : 2 ....

    for(int i = 0; i < N; i ++)
    {
        cin >> name;
        char first_name = name[0];
        arr[first_name - 97] ++; 
    }

    for(int i = 0; i < 26; i ++)
    {
        if(arr[i] >= 5)
        {
            cout << char(i + 97);
            out = true;
        }
    }

    if(!out)
        cout << "PREDAJA" << endl;
}