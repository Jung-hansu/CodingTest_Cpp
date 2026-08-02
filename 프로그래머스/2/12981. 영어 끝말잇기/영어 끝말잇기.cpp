#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> history;
    
    history.insert(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (words[i - 1].back() != words[i].front() || history.find(words[i]) != history.end()) {
            return {i % n + 1, i / n + 1};
        }
        history.insert(words[i]);
    }
    return {0, 0};
}