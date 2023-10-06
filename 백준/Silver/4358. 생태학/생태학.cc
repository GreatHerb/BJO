#include <iostream>
#include <map>
using namespace std;

int main()
{
    int count = 0;
    string tree;
    map<string, double> m;

    while(1)
    {
        getline(cin, tree);
        if(tree == "")
            break;

        auto it = m.find(tree);
        if(it != m.end()) // 중복있음
            m[tree] ++;
        
        m.insert(make_pair(tree, 1.0));
        count ++;
    }

    //소수점 출력 범위 지정
	cout << fixed;
	cout.precision(4);

    for(auto a : m)
        cout << a.first << " " << (a.second / count) * 100 << endl;

    return 0;
}