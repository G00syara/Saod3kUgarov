#include <memory>
#include <string>
#include <vector>
using namespace std;

class Node {
private:
    vector<unique_ptr<Node>> nodes;
    char key;

public:
    int count = 0;

    Node() {
        this->key = ' ';
    }
    Node(char key) {
        this->key = key;
    }

    Node* add_node(const char key) {
        nodes.push_back(unique_ptr<Node>(new Node(key)));

        return nodes.back().get();
    }

    Node* find_node(const char key) {
        for (auto& x : nodes)
            if (x->key == key)
                return x.get();

        return NULL;
    }

    void increment() {
        count++;
    }
};

class PrefixTree {
private:
    Node root;
    int m_size = 0;

public:
    PrefixTree() {}

    void insert(string word) {
        auto last_node = &root;

        for (const auto& ch : word) {
            auto node = last_node->find_node(ch);

            if (node == NULL)
                last_node = last_node->add_node(ch);
            else
                last_node = node;
        }

        if (last_node->count == 0)
            m_size++;

        last_node->increment();
    }

    int find(string word) {
        auto last_node = &root;

        for (const auto& ch : word) {
            auto node = last_node->find_node(ch);

            if (node == NULL)
                return 0;
            else
                last_node = node;
        }

        return last_node->count;
    }

    int size() const {
        return m_size;
    }
};
