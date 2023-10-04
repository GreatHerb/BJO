#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int N, M, element;
    cin >> N >> M;

    unordered_set<int> A, B;

    for(int i = 0; i < N; i ++)
    {
        cin >> element;
        A.insert(element);
    }

    for(int i = 0; i < M; i ++)
    {
        cin >> element;
        B.insert(element);
    }

    int count = A.size() + B.size();

    // A - B : A를 기준으로 B를 뺌
    for (const auto &value : B)
        if (A.find(value) != A.end()) // 중복 된다면
            count--;

    // B - A
    for (const auto &value : A)
        if (B.find(value) != B.end())
            count --;

    cout << count << "\n";

    return 0;
}