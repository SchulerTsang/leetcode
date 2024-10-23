#include <unordered_map>
#include <iostream>

using std::unordered_map;

// //定义内部类Node表
// class Node {
// public:
//     int key;
//     int value;
//     Node *prev;
//     Node *next;

//     Node(int key = 0, int value = 0) :key(key), value(value) {}
// };

class LRUCache {
//定义内部类Node表
class Node {
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key = 0, int value = 0) :key(key), value(value) {}
};

private:
    int capacity;
    Node *dummy;
    unordered_map<int, Node *> key_node;

    // 将node从双向链表中逻辑删除
    void remove(Node *node) {
        if (node == nullptr || node->prev == nullptr || node->next == nullptr) {
            throw std::runtime_error("Remove node error");
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 根据key在哈希表中查找并返回对应的链表节点，
    // 并将该节点移动到链表头部
    Node *getNode(int key) {
        auto it = key_node.find(key);
        if (it == key_node.end())
            return nullptr;

        // 将该节点移动到头部
        Node *node = it->second;
        remove(node);
        pushFront(node);

        return node;
    }

    // 在链表头添加一个节点
    void pushFront(Node *node) {
        node->next = dummy->next;
        node->prev = dummy;
        node->prev->next = node;
        node->next->prev = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node()){
        dummy->prev = dummy;
        dummy->next = dummy;
    }
    
    int get(int key) {
        Node *node = getNode(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        // 查找是否已存在，若已存在更新对应的值为value，
        // 并将该节点放到哨兵后的第一个节点
        Node *node = getNode(key);
        if (node) {
            node->value = value;
            return;
        }

        // 创建新节点
        Node *newNode = new Node(key, value);
        key_node[key] = newNode;
        pushFront(newNode);
        if (key_node.size() > capacity) {
            // 容量超出预设大小，删除链表尾部节点
            Node *leastRecentlyUsed = dummy->prev;
            key_node.erase(key_node.find(leastRecentlyUsed->key));
            remove(leastRecentlyUsed);
            delete leastRecentlyUsed;
            leastRecentlyUsed = nullptr;
        }
    }

    void printDoubleList() {
        Node *cur = dummy;
        std::cout << "double list begin:" << std::endl;
        while (cur->next != dummy) {
            std::cout << cur->key << " " << cur->value << std::endl;
            cur = cur->next;
        }
        std::cout << "double list end" << std::endl;
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */