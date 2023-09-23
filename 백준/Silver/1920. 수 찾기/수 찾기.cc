#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    unordered_set<int> numbers;

    int N, num;
    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        cin >> num;
        numbers.insert(num);
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i ++)
    {
        cin >> num;

        if (numbers.find(num) != numbers.end()) // 중복 된다 : 1 출력
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}