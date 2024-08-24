class LRUCache final {
private:
    class Node final {
    public:
        int key{0}, value{0};
    };

    unordered_map<int, list<Node>::iterator> index{};
    list<Node> elements{};
    const size_t capacity{0};

    inline int &get(const list<Node>::iterator nodeIter) noexcept {
        elements.splice(cend(elements), elements, nodeIter);
        return nodeIter->value;
    }

public:
    inline LRUCache(const int capacity) noexcept : capacity(capacity) {}

    inline int get(const int key) noexcept {
        const auto iter{index.find(key)};
        if (iter == end(index))
            return -1;
        return get(iter->second);
    }

    inline void put(const int key, const int value) noexcept {
        const auto iter{index.find(key)};
        if (iter != index.end()) {
            get(iter->second) = value;
            return;
        }

        if (index.size() >= capacity) {
            auto node{index.extract(elements.front().key)};
            node.key() = key;
            index.insert(move(node));
            elements.splice(cend(elements), elements, cbegin(elements));
            elements.back() = {key, value};
        } else {
            elements.emplace_back(key, value);
            index.emplace(key, --end(elements));
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
