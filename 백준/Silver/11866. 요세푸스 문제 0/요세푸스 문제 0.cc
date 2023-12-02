#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> v(N, 0);
    for(int i = 1; i <= N; i++)
        v[i - 1] = i;
    
    vector<int> result;

    int index = 0;  // 제거될 사람의 인덱스

    while(!v.empty())
    {
        index += K - 1;
        if(index >= v.size()) 
            index %= v.size();

        result.push_back(v[index]);  
        v.erase(v.begin() + index);  
    }

    cout << "<";
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if(i != result.size() - 1)
            cout << ", ";
    }
    cout << ">";

    return 0;
}
