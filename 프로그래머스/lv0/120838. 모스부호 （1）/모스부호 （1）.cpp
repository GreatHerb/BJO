#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string solution(string letter) {
    string answer = "";
    stringstream ss(letter);
    ss.str(letter);
    
    map<string, char> morse = {
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'},
        {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'},
        {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'},
        {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
        {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'},
        {"--..", 'z'}
    };
    
    string word;
    vector<string> words;
    
    // 스트림을 통해, 문자열을 공백 분리해 vector에 할당
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }
    
    for(int i = 0; i < words.size(); i ++) {
        answer += morse[words[i]];
    }
    
    return answer;
}