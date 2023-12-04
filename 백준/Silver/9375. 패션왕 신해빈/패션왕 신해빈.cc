#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int T, N;
    cin >> T;

    unordered_map<string, int> m;

    while(T > 0)
    {
        int result = 1;
        m.clear();
        cin >> N;

        string cloth, kind;

        // 입력받기
        for(int i = 0; i < N; i++)
        {
            cin >> cloth >> kind;
            auto item = m.find(kind);

            if(item != m.end()) // 존재
                item->second ++;
            
            else // 존재하지 않음
                m.insert({kind, 1});
        }

        for(auto a : m)
            result *= a.second + 1;
        
        cout << --result << "\n";

        T --;
    }

    return 0;
}