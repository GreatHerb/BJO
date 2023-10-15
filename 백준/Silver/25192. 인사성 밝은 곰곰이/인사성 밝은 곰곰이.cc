#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, count = 0;
    cin >> N;

    set<string> s;

    for(int i = 0; i < N; i ++)
    {
        string name;
        cin >> name;

        if(name == "ENTER")
        {
            count += s.size();
            s.clear();
            continue;
        }

        s.insert(name);
    }

    count += s.size();
    cout << count;
        
    return 0;
}