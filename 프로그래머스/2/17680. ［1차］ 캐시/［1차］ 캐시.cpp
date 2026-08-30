#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string &toLower(string &s) {
    for (char &c : s) {
        c |= (1 << 5);
    }
    return s;
}

int solution(int cacheSize, vector<string> cities) {
    unordered_map<string, int> map;
    int l = 0, r = 0, total = 0;
    
    while (r < cities.size() && map.size() < cacheSize) {
        string &city = toLower(cities[r++]);
        total += 1 + 4 * !map[city]++;
    }
    
    while (r < cities.size()) {
        string &city = toLower(cities[r++]);
        total += 1 + 4 * !map[city]++;
        while (map.size() > cacheSize) {
            if (!--map[cities[l++]]) {
                map.erase(map.find(cities[l - 1]));
            }
        }
    }
    return total;
}