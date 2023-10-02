#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long long card;
    map<long long, int> m;

    for(int i = 0; i < N; i ++)
    {
        cin >> card;
        auto item = m.find(card);

        if(item != m.end()) // 중복일 경우
            item->second ++;

        else
            m.insert(make_pair(card, 1));
    }

    long long max = -1;
    long long max_card;

    for(const auto& a : m)
    {
        if(a.second > max)
        {
            max = a.second;
            max_card = a.first;
        }
    }

    cout << max_card << "\n";
}