class Node{
    public:
        Node* next;
        Node* prev;
        int val;
        int key;
        Node(int k, int value){
            val = value;
            key = k;
            next = nullptr;
            prev = nullptr;
        }
};

class DoubleLinkedList{
    public:
        Node* front;
        Node* back;
        DoubleLinkedList(){
            front = back = nullptr;
        }
        void addFront(Node* node){
            if(front != nullptr){
                node->next = front;
                front->prev = node;
                front = node;    
            }
            else{
                front = back = node;    
            }
            front->prev = nullptr;
        }
        void removeBack(){
            Node* prev = back->prev;
            deleteNode(back);
            back = prev;
        }
        void deleteNode(Node* node){
            if (node->next == nullptr && node->prev == nullptr){
                back = front = nullptr;
            }
            if(node->prev != nullptr){
                node->prev->next = node->next;
            }else{
                if(front != nullptr){
                    front = front->next;
                    front->prev = nullptr;
                }
            }
            if(node->next != nullptr){
                node->next->prev = node->prev;                    
            }else{
                if(back != nullptr){
                    back = back->prev;
                    back->next = nullptr;
                }
            }
        }
        void moveNodeToFront(Node* node){
            deleteNode(node);
            addFront(node);
        }
};

class LRUCache {
public:
    unordered_map<int, Node*> cache;
    DoubleLinkedList* linkedList;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        linkedList = new DoubleLinkedList();
    }
    
    int get(int key) {
        if(cache.count(key)){
            linkedList->moveNodeToFront(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            cache[key]->val = value;
            linkedList->moveNodeToFront(cache[key]);
            return;
        }
        if(cache.size() == cap){
            cache.erase(linkedList->back->key); 
            linkedList->removeBack();
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        linkedList->addFront(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */