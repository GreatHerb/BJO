#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{   
    int N; char Game; string id;
    cin >> N >> Game;

    unordered_set<string> name;

    for(int i = 0; i < N; i++) {
        cin >> id;
        name.insert(id);
    }

    switch (Game) {
        case 'Y':
            cout << name.size() << endl;
            break;

        case 'F':
            cout << name.size() / 2 << endl;
            break;
        
        case 'O':
            cout << name.size() / 3 << endl;
            break;

        default:
            break;
    }

    return 0;
}