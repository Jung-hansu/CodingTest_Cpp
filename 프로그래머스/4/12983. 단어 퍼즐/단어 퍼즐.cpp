#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Trie {
    static constexpr int UNVISITED = -1;
    static constexpr int IMPOSSIBLE = -2;
    
    struct Node {
        Node *children[26]{};
        bool isTerminal = false;
    };
    Node *root;
    string target;
    int cache[20'000];
    
    int bottomUp(int idx) {
        if (idx == target.length()) {
            return 0;
        }
        
        // 캐시 활용
        if (cache[idx] != UNVISITED) {
            return cache[idx];
        }

        Node* node = root;
        int ret = INT_MAX;

        // 단어조각의 최대 길이인 5까지 확인
        for (int i = idx; i < target.length() && i < idx + 5; i++) {
            node = node->children[target[i] - 'a'];
            if (!node) break;

            if (node->isTerminal) {
                int next = bottomUp(i + 1);

                if (next != INT_MAX){
                    ret = min(ret, next + 1);
                }
            }
        }
        if (ret == INT_MAX) {
            cache[idx] = IMPOSSIBLE;
        }
        return cache[idx] = ret;
    }
    
public:
    Trie(vector<string> strs, string t): target(t) {
        root = new Node();
        fill(cache, cache + 20'000, UNVISITED);
        for (const string str : strs) {
            add(str);
        }
    }
    
    void add(string s) {
        Node *node = root;
        for (const char c : s) {
            if (!(node->children[c - 'a'])) {
                node->children[c - 'a'] = new Node();
            }
            node = node->children[c - 'a'];
        }
        node->isTerminal = true;
    }
    
    int getMinComb() {
        int minComb = bottomUp(0);
        return minComb == INT_MAX ? -1 : minComb;
    }
};

int solution(vector<string> strs, string t) {
    Trie trie(strs, t);
    return trie.getMinComb();
}