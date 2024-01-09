#include <iostream>
#include <unordered_map>
#include <queue>

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::queue<int>::iterator>> cacheMap;
    std::queue<int> keysQueue;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cacheMap.find(key);

        if (it != cacheMap.end()) {
            keysQueue.push(key);
            keysQueue.erase(it->second.second);
            it->second.second = keysQueue.end() - 1;
            return it->second.first;
        }

        return -1;
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);

        if (it != cacheMap.end()) {
            it->second.first = value;
            keysQueue.push(key);
            keysQueue.erase(it->second.second);
            it->second.second = keysQueue.end() - 1;
        } else {
            if (cacheMap.size() >= capacity) {
                int evictedKey = keysQueue.front();
                cacheMap.erase(evictedKey);
                keysQueue.pop();
            }

            keysQueue.push(key);
            auto iterator = keysQueue.end() - 1;
            cacheMap[key] = {value, iterator};
        }
    }
};

int main() {
    LRUCache lruCache(2);

    lruCache.put(1, 1);
    lruCache.put(2, 2);

    std::cout << lruCache.get(1) << std::endl;

    lruCache.put(3, 3);

    std::cout << lruCache.get(2) << std::endl;
    std::cout << lruCache.get(3) << std::endl;

    return 0;
}
