#include <string>
#include <vector>
using namespace std;

bool isOpen(char c) {
    return c == '(' || c == '{' || c == '[';
}

char getPair(char c) {
    switch (c) {
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
    }
    return 0;
}

int solution(string s) {
    int cnt = 0, len = s.length();

    for (int offset = 0; offset < len; offset++) {
        vector<char> stack;
        bool isValid = true;

        for (int i = 0; i < len; i++) {
            char c = s[(i + offset) % len];

            if (isOpen(c)) {
                stack.push_back(c);
            }
            else {
                if (stack.empty() || stack.back() != getPair(c)) {
                    isValid = false;
                    break;
                }
                stack.pop_back();
            }
        }

        if (isValid && stack.empty()) {
            cnt++;            
        }
    }
    return cnt;
}