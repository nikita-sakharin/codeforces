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
        auto &[unused, value, frequency]{*nodeIter};
        const auto frequencyIter{frequencies.find(frequency)};
        auto &elements{frequencyIter->second},
            &newElements{frequencies[frequency + 1]};
        newElements.splice(newElements.cend(), elements, nodeIter);
        if (elements.empty()) {
            frequencies.erase(frequencyIter);
            if (minFrequency == frequency)
                minFrequency = frequency + 1;
        }
        ++frequency;
        return value;
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
        if (iter != index.end()) {
            get(iter->second) = value;
            return;
        }

        if (index.size() >= capacity) {
            auto frequencyIter{frequencies.find(minFrequency)};
            auto &elements{frequencyIter->second}, &newElements{frequencies[1]};
            index.erase(elements.front().key);
            elements.pop_front();
            newElements.emplace_back(key, value, 1);
            index.emplace(key, --newElements.end());
            if (elements.empty())
                frequencies.erase(frequencyIter);
        } else {
            auto &elements{frequencies[1]};
            elements.emplace_back(key, value, 1);
            index.emplace(key, --elements.end());
        }
        minFrequency = 1;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
