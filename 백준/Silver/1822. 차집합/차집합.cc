#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int A, B, num;
    cin >> A >> B;

    set<int> s;
    vector<int> v;

    for(int i = 0; i < A; i ++)
    {
        cin >> num;
        s.insert(num);
    }

    for(int i = 0; i < B; i ++)
    {
        cin >> num;
        v.push_back(num);
    }

    for(int i = 0; i < B; i ++)
    {
        auto it = s.find(v[i]);

        if(it != s.end()) // 중복 존재
            s.erase(it);
    }

    cout << s.size() << endl;
    
    for(const auto& n : s)
        cout << n << " ";

    return 0;
}