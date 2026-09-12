#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;

class RoomAllocator {
    unordered_map<ll, ll> nextRoom;

    // x 이상에서 비어있는 첫 번째 방 탐색
    ll findRoom(ll x) {
        auto it = nextRoom.find(x);
        if (it == nextRoom.end()) {
            return x;
        }
        return it->second = findRoom(it->second);
    }

public:
    RoomAllocator(size_t count) {
        nextRoom.reserve(count * 2);
    }

    ll insert(ll request) {
        ll room = findRoom(request);

        // 이 방은 사용했으므로 다음부터 room + 1 이후를 탐색
        nextRoom[room] = findRoom(room + 1);
        return room;
    }
};

vector<ll> solution(ll k, vector<ll> room_number) {
    RoomAllocator allocator(room_number.size());
    vector<ll> allocated;

    allocated.reserve(room_number.size());
    for (ll room : room_number) {
        allocated.push_back(allocator.insert(room));
    }
    return allocated;
}