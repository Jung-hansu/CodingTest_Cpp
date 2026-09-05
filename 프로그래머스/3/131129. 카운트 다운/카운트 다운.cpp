#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 싱글/불 및 더블/트리플로 낼 수 있는 점수 전처리
const int SB[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 50};
const int DT[] = {21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 51, 54, 57, 60};
const int DART_MAX = 100'001;

vector<int> solution(int target) {
    int total[DART_MAX]{};  // 총 다트 개수
    int single[DART_MAX]{}; // 싱글+불 개수
    
    // DP 배열 초기화
    fill(total + 1, total + target + 1, DART_MAX);
    for (const int score : SB) {
        total[score] = 1;
        single[score] = 1;
    }
    for (const int score : DT) {
        total[score] = 1;
    }
    
    // DP
    for (int i = 1; i <= target; i++) {
        if (total[i] != DART_MAX) continue;
        int minTotal = DART_MAX;
        int maxSingle = 0;
        
        for (const int sb : SB) {
            if (i <= sb) break;
            if (minTotal > total[i - sb] + 1 || (minTotal == total[i - sb] + 1 && maxSingle < single[i - sb] + 1)) {
                minTotal = total[i - sb] + 1;
                maxSingle = single[i - sb] + 1;
            }
        }
        
        for (const int dt : DT) {
            if (i <= dt) break;
            if (minTotal > total[i - dt] + 1 || (minTotal == total[i - dt] + 1 && maxSingle < single[i - dt])) {
                minTotal = total[i - dt] + 1;
                maxSingle = single[i - dt];
            }
        }
        
        total[i] = minTotal;
        single[i] = maxSingle;
    }
    return {total[target], single[target]};
}