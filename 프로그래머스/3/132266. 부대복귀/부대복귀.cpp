#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) {
    vector<vector<int>> adj(n + 1);
    vector<int> dists(n + 1, -1);
    queue<int> q;
    
    for (vector<int> road : roads) {
        adj[road[0]].push_back(road[1]);
        adj[road[1]].push_back(road[0]);
    }

    // BFS
    dists[dest] = 0;
    q.push(dest);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nearby : adj[cur]) {
            if (dists[nearby] < 0) {
                dists[nearby] = dists[cur] + 1;
                q.push(nearby);
            }
        }
    }
    
    // 최종 답 기록
    vector<int> answer(sources.size());
    for (int i = 0; i < sources.size(); i++) {
        answer[i] = dists[sources[i]];
    }
    return answer;
}