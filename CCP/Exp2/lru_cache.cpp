#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = positions.find(key);
        if (it == positions.end()) {
            return -1;
        }

        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = positions.find(key);
        if (it != positions.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        if ((int)cache.size() == capacity) {
            auto last = prev(cache.end());
            positions.erase(last->first);
            cache.pop_back();
        }

        cache.emplace_front(key, value);
        positions[key] = cache.begin();
    }

private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> positions;
};

int main() {
    LRUCache cache(2);

    cout << "get(1) = " << cache.get(1) << endl;
    cache.put(1, 10);
    cache.put(2, 20);
    cout << "get(1) = " << cache.get(1) << endl;
    cache.put(3, 30);
    cout << "get(2) = " << cache.get(2) << endl;
    cache.put(4, 40);
    cout << "get(1) = " << cache.get(1) << endl;
    cout << "get(3) = " << cache.get(3) << endl;
    cout << "get(4) = " << cache.get(4) << endl;
    cout << "Time Complexity: get = O(1) average, put = O(1) average" << endl;

    return 0;
}