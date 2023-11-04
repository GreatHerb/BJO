#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    // 초 조정
    B += C; 

    // 더해줄 시간 조정
    int p_hour = B / 60;

    // 초 보정
    B %= 60;

    // 시간 보정
    A += p_hour;
    A %= 24;

    cout << A << " " << B << endl ;
    return 0;
}