#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;

    string s, temp = "";
    int minusIndex = -1;
    bool hasMinus = false;

    cin >> s;

    for(int i = 0; i < s.length(); i ++)
    {
        if(s[i] == '+' || s[i] == '-') // 연산자 만남
        {
            v.push_back(temp); // 지금까지 받은 숫자 넣기
            string op = ""; 
            op += s[i];
            v.push_back(op); // 연산자 넣기 
            temp = ""; // temp 초기화
        }

        else
            temp += s[i];
    }

    v.push_back(temp); // 마지막 숫자 처리

    // 괄호 처리 - minus 존재하는지 확인
    for(int i = 1; i < v.size(); i += 2)
    {
        if(v[i] == "-") // -일 때
        {
            hasMinus = true;
            minusIndex = i;
            break;
        }
    }

    // 괄호 처리 2
    if(minusIndex != v.size() - 1 && hasMinus == true)
    {
        for(int i = minusIndex + 2; i < v.size(); i += 2)
        {
            if(v[i] == "+")
                v[i] = "-";
        }

    }

    // 연산
    int result = stoi(v[0]);

    for(int i = 1; i < v.size(); i += 2)
    {
        if(v[i] == "+") // + 연산자일 때
            result += stoi(v[i + 1]);

        else if(v[i] == "-") // - 연산자일 때
            result -= stoi(v[i + 1]);
    }

    cout << result;

    return 0;
}