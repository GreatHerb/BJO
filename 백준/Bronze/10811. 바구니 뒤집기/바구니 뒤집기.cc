#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M; 

    vector<int> baskets(N);
    for(int i = 0; i < N; i++)
        baskets[i] = i + 1; 
    
    for(int i = 0; i < M; i++) 
    {
        int start, end;
        cin >> start >> end; 
        reverse(baskets.begin() + start - 1, baskets.begin() + end); 
    }

    for(int i = 0; i < N; i++)
        cout << baskets[i] << ' '; 
    return 0;
}
