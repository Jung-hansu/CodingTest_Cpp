#include <string>
using namespace std;

int solution(string s) {
    int stack[1'000'000];
    int top = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (!top || stack[top - 1] != s[i]) {
            stack[top++] = s[i];
        } else {
            top--;
        }
    }
    return !top;
}