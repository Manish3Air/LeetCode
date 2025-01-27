class LFUCache {
private:
    class Node {
    public:
        int key, value, freq;
        Node* next;
        Node* prev;
        
        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1; // New nodes have a frequency of 1
            next = prev = nullptr;
        }
    };

    class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;
        
        DoublyLinkedList() {
            head = new Node(-1, -1); // Dummy head
            tail = new Node(-1, -1); // Dummy tail
            head->next = tail;
            tail->prev = head;
        }
        
        void addNode(Node* node) {
            Node* nextNode = head->next;
            head->next = node;
            node->prev = head;
            node->next = nextNode;
            nextNode->prev = node;
        }
        
        void removeNode(Node* node) {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        
        bool isEmpty() {
            return head->next == tail;
        }
    };

    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyToNode; // Key to Node mapping
    unordered_map<int, DoublyLinkedList*> freqToList; // Frequency to DLL mapping

    void updateFrequency(Node* node) {
        int freq = node->freq;
        freqToList[freq]->removeNode(node);

        // If the current frequency list is empty and was the minimum frequency, update `minFreq`
        if (freqToList[freq]->isEmpty() && freq == minFreq) {
            minFreq++;
        }

        node->freq++; // Increment the frequency
        if (freqToList.find(node->freq) == freqToList.end()) {
            freqToList[node->freq] = new DoublyLinkedList();
        }
        freqToList[node->freq]->addNode(node);
    }

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1; // Key not found
        }
        Node* node = keyToNode[key];
        updateFrequency(node); // Update frequency of the node
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            node->value = value; // Update value
            updateFrequency(node); // Update frequency
        } else {
            if (keyToNode.size() == capacity) {
                // Evict the least frequently used node
                Node* nodeToEvict = freqToList[minFreq]->tail->prev;
                freqToList[minFreq]->removeNode(nodeToEvict);
                keyToNode.erase(nodeToEvict->key);
                delete nodeToEvict;
            }
            
            // Add the new node
            Node* newNode = new Node(key, value);
            keyToNode[key] = newNode;
            if (freqToList.find(1) == freqToList.end()) {
                freqToList[1] = new DoublyLinkedList();
            }
            freqToList[1]->addNode(newNode);
            minFreq = 1; // Reset `minFreq` to 1 for the new node
        }
    }

    ~LFUCache() {
        for (auto& pair : keyToNode) {
            delete pair.second;
        }
        for (auto& pair : freqToList) {
            delete pair.second;
        }
    }
};