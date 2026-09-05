#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Trie {
    struct Node {
        Node *children[26]{};
        int childBit = 0; // 자식 유무 여부 빠른 검사용 비트
        bool isTerminal = false;
    } rootNode;
    
    Node *root = &rootNode;
    
public:
    void add(string word) {
        Node *node = root;
        
        for (const char &c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Node();
                node->childBit |= 1 << (c - 'a');
            }
            node = node->children[c - 'a'];
        }
        node->isTerminal = true;
    }
    
    int search(string word) {
        Node *node = root;
        int cnt = 1, wlen = word.length();
        
        for (int i = 0; i < wlen; i++) {
            node = node->children[word[i] - 'a'];
            // 분기점이 있다면 해당 길이 + 1만큼 추가 입력 필요
            if (__builtin_popcount(node->childBit) > 1 || (i < wlen - 1 && node->isTerminal)) {
                cnt = i + 2;
            }
        }
        // 다른 단어의 접두어라면 단어 길이만큼 타이핑 필요
        return node->childBit ? wlen : min(cnt, wlen);
    }
};

int solution(vector<string> words) {
    Trie trie;
    int cnt = 0;
    
    for (const auto &word : words) {
        trie.add(word);
    }
    
    for (const auto &word : words) {
        cnt += trie.search(word);
    }
    return cnt;
}