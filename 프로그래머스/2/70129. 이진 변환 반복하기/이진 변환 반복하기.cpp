#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int bitCnt[2]{}; // [0]: 삭제된 0개수, [1]: 1의 개수
    
    if (s == "1") {
        return {0, 0};
    }
    
    for (int i = 0; i < s.length(); i++) {
        bitCnt[s[i] & 1]++;
    }

    int cnt = 1;
    while (bitCnt[1] != 1) {
        int oneCount = __builtin_popcount(bitCnt[1]);
        int zeroCnt = 32 - __builtin_clz(bitCnt[1]) - oneCount;
        bitCnt[0] += zeroCnt;
        bitCnt[1] = oneCount;
        cnt++;
    }
    return {cnt, bitCnt[0]};
}