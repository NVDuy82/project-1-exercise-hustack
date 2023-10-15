#include <iostream>
#include <set>

using namespace std;

class Node {
    int key{-1};
    Node *prev{nullptr}, *next{nullptr};

public:
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    Node() = default;
    
    explicit Node(int key) : key(key) {}
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Destructors               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    ~Node() {
        if (prev != nullptr && prev->getNext() == this) {
            prev->setNext(nullptr);
        }
        if (next != nullptr && next->getPrev() == this) {
            next->setPrev(nullptr);
        }
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||           Getter and Setter           ||
     * -------------------------------------------
     * -------------------------------------------
     */
    [[nodiscard]] int getKey() const {
        return key;
    }
    
    void setKey(int key) {
        Node::key = key;
    }
    
    [[nodiscard]] Node *getPrev() const {
        return prev;
    }
    
    void setPrev(Node *prev) {
        Node::prev = prev;
    }
    
    [[nodiscard]] Node *getNext() const {
        return next;
    }
    
    void setNext(Node *next) {
        Node::next = next;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    
};

class LinkedListManipulation {
    Node *head{nullptr}, *tail{nullptr};
    set<int> keys;

public:
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    LinkedListManipulation() = default;
    
    explicit LinkedListManipulation(Node *node) : head(node), tail(node) {
        keys.insert(node->getKey());
    }
    
    explicit LinkedListManipulation(int &v) {
        head = tail = new Node(v);
        keys.insert(v);
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Destructors               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    ~LinkedListManipulation() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->getNext();
            delete temp;
        }
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||           Getter and Setter           ||
     * -------------------------------------------
     * -------------------------------------------
     */
    [[nodiscard]] Node *getHead() const {
        return head;
    }
    
    void setHead(Node *head) {
        LinkedListManipulation::head = head;
    }
    
    [[nodiscard]] Node *getTail() const {
        return tail;
    }
    
    void setTail(Node *tail) {
        LinkedListManipulation::tail = tail;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||               Operator                ||
     * -------------------------------------------
     * -------------------------------------------
     */
    friend ostream &operator<<(ostream &os, const LinkedListManipulation &list) {
        Node *temp = list.head;
        while (temp!= nullptr) {
            os << temp->getKey() << " ";
            temp = temp->getNext();
        }
        return os;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    int size() {
        return keys.size();
    }
    
    bool empty() {
        return keys.empty();
    }
    
    bool contains(int key) {
        return keys.find(key) != keys.end();
    }
    
    /*
     *
     *            1         2         3         4         5         _
     *                                                             /^\
     *                                                              |
     *                                                              |
     *                                                           New Node
     */
    void add_last(int key) {
        Node *node = new Node(key);
        
        if (empty()) {
            head = tail = node;
            
            keys.insert(key);
            
        } else if (!this->contains(key)) {
            // <5> link <new node>
            tail->setNext(node);
            
            // <new node> link <5>
            node->setPrev(tail);
            
            // tail is <new node>
            tail = node;
            
            keys.insert(key);
        }
    }
    
    /*
     *
     *            _         1         2         3         4         5
     *           /^\
     *            |
     *            |
     *         New Node
     */
    void add_first(int key) {
        Node *node = new Node(key);
        
        if (this->empty()) {
            head = tail = node;
            
            keys.insert(key);
            
        } else if (!this->contains(key)) {
            // <1> link <new node>
            head->setPrev(node);
            
            // <new node> link <1>
            node->setNext(head);
            
            // head is <new node>
            head = node;
            
            keys.insert(key);
        }
    }
    
    
    /*
     *
     *            1         2         3         _         4         5
     *                               /^\       /^\
     *                                |         |
     *                                |         |
     *                                       New Node
     *                              < v >     < u >
     *                             current    after
     */
    void add_after(int &u, int &v) {
        Node *after = new Node(u);
        Node *current = nullptr;
        
        // if (u does not exist) || (v exists)  -->>  ok
        
        // check if (u exists) or (v does not exist)    AND    find v (current)
        {
            bool check_if_v_does_not_exist = true;
            
            Node *temp = head;
            while (temp != nullptr) {
                // check if (u exists)
                if (temp->getKey() == u) {
                    return;
                } else if (temp->getKey() == v) {
                    check_if_v_does_not_exist = false;
                    current = temp;
                }
                temp = temp->getNext();
            }
            
            if (check_if_v_does_not_exist) {
                return;
            }
        }
        
        // add u <*after> after v <current>
        
        //   <4> link < after  >
        //            <new node>
        current->getNext()->setPrev(after);
        
        //   < after  > link <4>
        //   <new node>
        after->setNext(current->getNext());
        
        //   <current> link < after  >
        //                  <new node>
        current->setNext(after);
        
        //   < after  > link <current>
        //   <new node>
        after->setPrev(current);
        
        keys.insert(u);
    }
    
    /*
     *
     *            1         2         _         3         4         5
     *                               /^\       /^\
     *                                |         |
     *                                |         |
     *                             New Node
     *                              < u >     < v >
     *                              before   current
     */
    void add_before(int &u, int &v) {
        Node *before = new Node(u);
        Node *current = nullptr;
        
        // if (u does not exist) || (v exists)  -->>  ok
        
        // check if (u exists) or (v does not exist)    AND    find v (current)
        {
            bool check_if_v_does_not_exist = true;
            
            Node *temp = head;
            while (temp != nullptr) {
                // check if (u exists)
                if (temp->getKey() == u) {
                    return;
                } else if (temp->getKey() == v) {
                    check_if_v_does_not_exist = false;
                    current = temp;
                }
                temp = temp->getNext();
            }
            
            if (check_if_v_does_not_exist) {
                return;
            }
        }
        
        // add u <*before> before v <current>
        
        //   <2> link < before >
        //            <new node>
        current->getPrev()->setNext(before);
        
        //   < before > link <2>
        //   <new node>
        before->setPrev(current->getPrev());
        
        //   <current> link < before >
        //                  <new node>
        current->setPrev(before);
        
        //   < before > link <current>
        //   <new node>
        before->setNext(current);
        
        keys.insert(u);
    }
    
    
    /*
     *
     *            1         2       ((3))       4         5
     *                               /^\
     *                                |
     *                                |
     *                              remove
     */
    void remove(int key) {
        Node *temp = head;
        
        // finding
        while (temp != nullptr) {
            if (temp->getKey() == key) {
                break;
            }
            temp = temp->getNext();
        }
        
        if (temp == nullptr) {
            return;
        }
        
        // removing
        
        // get info
        Node *prev = temp->getPrev();
        Node *next = temp->getNext();
        
        // handle prev
        if (prev != nullptr) {
            prev->setNext(next);
        } else {
            head = next;
        }
        
        // handle next
        if (next != nullptr) {
            next->setPrev(prev);
        } else {
            tail = prev;
        }
        
        // delete
        keys.erase(key);
        delete temp;
    }
    
    void reverse() {
        Node *temp = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        
        while (temp!= nullptr) {
            next = temp->getNext();
            temp->setNext(prev);
            temp->setPrev(next);
            prev = temp;
            temp = next;
        }
        
        head = prev;
    }
};

int main() {
    LinkedListManipulation linkedList;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        linkedList.add_last(v);
    }
    
    string cmd;
    do {
        cin >> cmd;
        if (cmd == "#") {
            break;
        }
        
        if (cmd == "addlast") {
            int k;
            cin >> k;
            linkedList.add_last(k);
        } else if (cmd == "addfirst") {
            int k;
            cin >> k;
            linkedList.add_first(k);
        } else if (cmd == "addafter") {
            int u, v;
            cin >> u >> v;
            linkedList.add_after(u, v);
        } else if (cmd == "addbefore") {
            int u, v;
            cin >> u >> v;
            linkedList.add_before(u, v);
        } else if (cmd == "remove") {
            int k;
            cin >> k;
            linkedList.remove(k);
        } else if (cmd == "reverse") {
            linkedList.reverse();
        }
        
    } while(true);
    
    cout << linkedList << endl;
    
    return 0;
}
