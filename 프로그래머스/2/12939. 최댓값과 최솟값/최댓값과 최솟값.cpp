#include <string>
#include <climits>
#include <algorithm>
using namespace std;

string solution(string s) {
    int m = INT_MAX, M = INT_MIN;
    
    for (int l = 0, r = 0; r <= s.length(); r++) {
        if (s[r] == ' ' || r == s.length()) {
            int num = stoi(s.substr(l, r - l));
            m = min(m, num);
            M = max(M, num);
            l = r + 1;
        }
    }
    return to_string(m) + " " + to_string(M);
}