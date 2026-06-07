#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void getAnswer(unordered_set<int> &cases, const vector<vector<int>> &candidates, int checkBit, int depth) {
    if (depth == candidates.size()) {
        cases.insert(checkBit);
        return;
    }
    
    for (int uIdx : candidates[depth]) {
        if (!(checkBit & (1 << uIdx))) {
            getAnswer(cases, candidates, checkBit | (1 << uIdx), depth + 1);
        } 
    }
}

int solution(vector<string> userIds, vector<string> bannedIds) {
    vector<vector<int>> candidates(bannedIds.size());
    unordered_set<int> cases;
    
    for (int bIdx = 0; bIdx < bannedIds.size(); bIdx++) {
        for (int uIdx = 0; uIdx < userIds.size(); uIdx++) {
            if (bannedIds[bIdx].length() != userIds[uIdx].length()) continue;
            bool isMatched = true;
            
            for (int i = 0; i < bannedIds[bIdx].length(); i++) {
                if (bannedIds[bIdx][i] != '*' && bannedIds[bIdx][i] != userIds[uIdx][i]) {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched) {
                candidates[bIdx].push_back(uIdx);
            }
        }
    }
    
    getAnswer(cases, candidates, 0, 0);
    return cases.size();
}