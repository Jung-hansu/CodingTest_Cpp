#include <vector>
#include <bitset>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bitset<200>> networks;
    
    for (auto computer : computers) {
        bitset<200> network;
        
        // 네트워크 비트마스킹
        for (int i = 0; i < computer.size(); i++) {
            network.set(i, computer[i]);
        }

        auto it = networks.begin();
        while (it != networks.end()) {
            if ((network & *it).none()) {
                it++;
                continue;
            }
            // 네트워크가 겹치면 통합
            network |= *it;
            swap(*it, networks.back());
            networks.pop_back();
        }
        networks.push_back(network);
    }
    return networks.size();
}