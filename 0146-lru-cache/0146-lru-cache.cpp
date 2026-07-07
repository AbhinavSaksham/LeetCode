class LRUCache {
public:

    class Node { //create node 
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {  //assign base values to all
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> map; //create amp

    Node* head = new Node(-1, -1); //head is always assigned with -1 -1
    Node* tail = new Node(-1, -1); //tail is always assigned with -1 -1

    LRUCache(int capacity) {

        this->capacity = capacity; //check if your capacity has empty space
        map.clear();
        head->next = tail;
        tail->prev = head; //clear the node next to tail (least used)
    }

    int get(int key) { // find key in map

        if (map.find(key) == map.end())
            return -1;

        Node* node = map[key];    // if key doesn't exist
        deleteNode(node); // delete last usd node
        insertAfterNode(node); // insert as new node next to head(most recent)
        return node->value;
    }

    void put(int key, int value) {

        if (map.find(key) != map.end()) {

            Node* node = map[key];
            node->value = value;
            deleteNode(node);
            insertAfterNode(node);
        }

        else {

            if (map.size() == capacity) {

                Node* node = tail->prev;
                map.erase(node->key);
                deleteNode(node);
            }

            Node* node = new Node(key, value);
            map[key] = node;
            insertAfterNode(node);
        }
    }

    void deleteNode(Node* node) { //delete node fn

        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    void insertAfterNode(Node* node) { //insert new node fn

        Node* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        currAfterHead->prev = node;
        node->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */