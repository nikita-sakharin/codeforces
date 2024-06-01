class LFUCache final {
private:
    using uint = unsigned;

    class Node final {
    public:
        int key{0}, value{0};
        uint frequency{0};
    };

    unordered_map<int, list<Node>::iterator> index{};
    unordered_map<uint, list<Node>> frequencies{};
    const size_t capacity{0};
    uint minFrequency{0};

    inline int &get(const list<Node>::iterator nodeIter) noexcept {
        auto &frequency{nodeIter->frequency};
        const auto frequencyIter{frequencies.find(frequency)};
        auto &elements{frequencyIter->second};

        ++frequency;
        auto &newElements{frequencies[frequency]};
        newElements.splice(newElements.cend(), elements, nodeIter);
        if (elements.empty()) {
            frequencies.erase(frequencyIter);
            minFrequency = frequency;
        }
        return nodeIter->value;
    }

public:
    inline LFUCache(const int capacity) noexcept : capacity(capacity) {}

    inline int get(const int key) noexcept {
        const auto iter{index.find(key)};
        if (iter == index.end())
            return -1;
        return get(iter->second);
    }

    inline void put(const int key, const int value) noexcept {
        const auto iter{index.find(key)};
        if (iter != index.end())
            get(iter->second) = value;
        else {
            if (index.size() >= capacity) {
                auto frequencyIter{frequencies.find(minFrequency)};
                auto &elements{frequencyIter->second};
                index.erase(elements.front().key);
                elements.pop_front();
                if (elements.empty())
                    frequencies.erase(frequencyIter);
            }
            minFrequency = 1;
            auto &elements{frequencies[minFrequency]};
            elements.emplace_back(key, value, minFrequency);
            index.emplace(key, --elements.end());
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
