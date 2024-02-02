class LRUCache final {
private:
    unordered_map<int, const list<pair<const int, int>>::iterator> index{};
    list<pair<const int, int>> elements{};
    const size_t capacity{0};

public:
    inline LRUCache(const int capacity) noexcept : capacity(capacity) {}

    inline int get(const int key) noexcept {
        const auto iter{index.find(key)};
        if (iter == index.end())
            return -1;
        elements.splice(elements.cend(), elements, iter->second);
        return iter->second->second;
    }

    inline void put(const int key, const int value) noexcept {
        const auto iter{index.find(key)};
        if (iter != index.end()) {
            elements.splice(elements.cend(), elements, iter->second);
            iter->second->second = value;
        } else {
            if (index.size() >= capacity) {
                index.erase(elements.front().first);
                elements.pop_front();
            }
            elements.emplace_back(key, value);
            index.emplace(key, --elements.end());
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
