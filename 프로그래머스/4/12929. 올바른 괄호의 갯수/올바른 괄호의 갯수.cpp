#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(vector<unordered_set<string>> &sets, int depth) {
    for (const auto s1 : sets[depth - 1]) {
        sets[depth].insert("(" + s1 + ")");
    }
    
    for (int i = 1; i < depth; i++) {
        for (const auto s1 : sets[i]) {
            for (const auto s2 : sets[depth - i]) {
                sets[depth].insert(s1 + s2);
            }
        }
    }
}

int solution(int n) {
    vector<unordered_set<string>> sets(n + 1);
    
    sets[0].insert("");
    for (int i = 1; i <= n; i++) {
        dfs(sets, i);
    }
    return sets[n].size();
}