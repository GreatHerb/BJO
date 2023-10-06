#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, N, M;
    cin >> T;

    unordered_set<int> s1;

    for(int i = 0; i < T; i ++)
    {
        s1.clear(); // 수첩 초기화

        cin >> N;
        int num;

        for(int j = 0; j < N; j ++)
        {
            cin >> num;
            s1.insert(num);
        }

        cin >> M;

        for(int j = 0; j < M; j ++)
        {
            cin >> num;
            auto it = s1.find(num);

            if(it != s1.end())
                cout << "1 \n";
            else
                cout << "0 \n";
        }
    }

    return 0;   
}