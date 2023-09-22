#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_set<int> cards;

    for (int i = 0; i < N; i ++) 
    {
        int card;
        cin >> card;
        cards.insert(card);
    }

    int M;
    cin >> M;

    vector<int> numbers(M);

    for (int i = 0; i < M; i ++) 
        cin >> numbers[i];

    vector<int> results(M, 0);

    for (int i = 0; i < M; i ++) 
        if (cards.find(numbers[i]) != cards.end()) 
            results[i] = 1;

    for (int i = 0; i < M; i ++) 
        cout << results[i] << ' ';

    return 0;
}
