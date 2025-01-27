class LRUCache {
  private:
    class Node{
        public:
        int key;
        int data;
        Node* next;
        Node* prev;
        
        Node(int key,int data){
        this->data = data;
        this->key = key;
        this->next = NULL;
        this->prev = NULL;
        }
    };
   
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int capacity;
    void add_After_Head(Node* insert){
        Node* cur_aft_hd = head->next;
        head->next = insert;
        insert->prev = head;
        insert->next = cur_aft_hd;
        cur_aft_hd->prev = insert;
    }
    void delete_node(Node* del){
        del->prev->next = del->next;
        del->next->prev = del->prev;
        del->next = NULL;
        del->prev = NULL;
    }
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity) {
        // code here
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        delete_node(node);
        add_After_Head(node);
        return node->data;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->data = value;
            delete_node(node);
            add_After_Head(node);
        }
        else{
            if(mp.size() == capacity){
                Node* node = tail->prev;
                mp.erase(node->key);
                delete_node(node);
                delete node;
            }
            Node* node = new Node(key,value);
            mp[key] = node;
            add_After_Head(node);
        }
    }
    ~LRUCache() {
        // Clean up memory
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */