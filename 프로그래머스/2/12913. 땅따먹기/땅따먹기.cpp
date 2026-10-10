#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int maxScore = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                maxScore = max(maxScore, land[i - 1][k]);
            }
            land[i][j] += maxScore;
        }
    }

    return *max_element(land.back().begin(), land.back().end());
}