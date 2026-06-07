#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> gemSet;
    for (const string &gem : gems) {
        gemSet.insert(gem);
    }
    
    unordered_map<string, int> gemMap;
    pair<int, int> range = {0, 0};
    int gemSize = gemSet.size();
    int l = 0, r = 0, minRange = 100'000;
    
    while (r < gems.size()) {
        // 모든 보석을 포함할 때 까지 확장
        while (r < gems.size() && gemMap.size() < gemSize) {
            gemMap[gems[r++]]++;
        }
        // 더이상 모든 보석을 포함할 수 없으면 끝
        if (gemMap.size() < gemSize) break;
        
        // 모든 보석을 포함하는 최소 범위까지 축소
        while (l < r && gemMap[gems[l]] != 1) {
            gemMap[gems[l++]]--;
        }
        if (minRange > r - l) {
            minRange = r - l;
            range = {l + 1, r};
        }
        
        gemMap.erase(gems[l++]);
    }
    return {range.first, range.second};
}