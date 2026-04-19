#include <string>
using namespace std;

inline void toUpperCase(char &c) {if (c >= 'a' && c <= 'z') c -= 32; }
inline void toLowerCase(char &c) { if (c >= 'A' && c <= 'Z') c += 32; }

string solution(string s) {
    toUpperCase(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == ' ') toUpperCase(s[i]);
        else toLowerCase(s[i]);
    }
    return s;
}