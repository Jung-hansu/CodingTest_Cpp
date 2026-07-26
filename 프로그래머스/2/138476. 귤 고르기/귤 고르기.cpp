#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> countBySize;
    vector<int> counts;
    int selectedCount = 0;
    int typeCount = 0;

    for (int size : tangerine) {
        countBySize[size]++;
    }
    
    counts.reserve(countBySize.size());
    for (const auto &[size, count] : countBySize) {
        counts.push_back(count);
    }

    // 개수가 많은 종류부터 선택
    sort(counts.begin(), counts.end(), greater<int>());
    for (int count : counts) {
        selectedCount += count;
        typeCount++;

        if (selectedCount >= k) {
            break;
        }
    }
    return typeCount;
}