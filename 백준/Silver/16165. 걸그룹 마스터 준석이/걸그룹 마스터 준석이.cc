#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    string team, name;
    int m_count;

    map<string, string> m;
    vector<string> quiz_name;
    vector<int> quiz_num;

    int quiz = -1;
    // quiz = 1 -> 팀 이름 말하기
    // quiz = 0 -> 멤버 이름 말하기

    for(int i = 0; i < N; i ++) // 팀 채우기
    {
        cin >> team >> m_count;

        for(int j = 0; j < m_count; j ++)
        {
            cin >> name;
            m.insert(make_pair(name, team));
        }
    }

    for(int i = 0; i < M; i ++) // 퀴즈 채우기
    {
        cin >> name >> quiz;
        quiz_name.push_back(name);
        quiz_num.push_back(quiz);
    }

    for(int i = 0; i < M; i ++)
    {
        int quiznum = quiz_num[i];
        string quizname = quiz_name[i];

        if(quiznum == 1) // 팀 이름 말하기
            cout << m[quizname] << "\n";
        
        else // 멤버이름 말하기
        {
            for(const auto &a : m)
                if(a.second == quizname)
                    cout << a.first << "\n";
        }
        
    }

    return 0;
}