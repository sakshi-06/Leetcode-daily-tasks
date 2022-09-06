class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;
            node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int capacity;
    unordered_map<int,node*> map;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(node* curNode){
        node* prevNode = curNode->prev;
        node* nextNode = curNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void addNode(node* curNode){
        curNode->next = head->next;
        curNode->prev = head;
        curNode->next->prev = curNode;
        head->next = curNode;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        node* curNode = map[key];
        int result = curNode->val;
        map.erase(key);
        deleteNode(curNode);
        addNode(curNode);
        map[key] = head->next;
        return result;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            node* curNode = map[key];
            map.erase(key);
            deleteNode(curNode);
        }
        if(map.size() == capacity){
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        map[key] = head->next;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */