#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    int tmp[2] = {max(a, b), min(a, b)};
    
    for (int i = 0; tmp[0] && tmp[1]; i ^= 1) {
        tmp[i] %= tmp[i ^ 1];
    }
    return max(tmp[0], tmp[1]);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}