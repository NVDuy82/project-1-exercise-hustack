#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

template <class T> class FibonacciHeap;

template <class T> class FibonacciHeapNode {
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Attributes                ||
     * -------------------------------------------
     * -------------------------------------------
     */
    T key;
    FibonacciHeapNode<T> *parent;
    FibonacciHeapNode<T> *child;
    FibonacciHeapNode<T> *left;
    FibonacciHeapNode<T> *right;
    int degree;
    bool marked;

public:
    friend class FibonacciHeap<T>;
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    explicit FibonacciHeapNode(T key) : key(key) {
        parent = nullptr;
        child = nullptr;
        left = this;
        right = this;
        degree = 0;
        marked = false;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||           Getter and Setter           ||
     * -------------------------------------------
     * -------------------------------------------
     */
    T getKey() const {
        return key;
    }
    
    void setKey(T key) {
        FibonacciHeapNode::key = key;
    }
    
    FibonacciHeapNode<T> *getParent() const {
        return parent;
    }
    
    void setParent(FibonacciHeapNode<T> *parent) {
        FibonacciHeapNode::parent = parent;
    }
    
    FibonacciHeapNode<T> *getChild() const {
        return child;
    }
    
    void setChild(FibonacciHeapNode<T> *child) {
        FibonacciHeapNode::child = child;
    }
    
    FibonacciHeapNode<T> *getLeft() const {
        return left;
    }
    
    void setLeft(FibonacciHeapNode<T> *left) {
        FibonacciHeapNode::left = left;
    }
    
    FibonacciHeapNode<T> *getRight() const {
        return right;
    }
    
    void setRight(FibonacciHeapNode<T> *right) {
        FibonacciHeapNode::right = right;
    }
    
    [[nodiscard]] int getDegree() const {
        return degree;
    }
    
    void setDegree(int degree) {
        FibonacciHeapNode::degree = degree;
    }
    
    [[nodiscard]] bool isMarked() const {
        return marked;
    }
    
    void setMarked(bool marked) {
        FibonacciHeapNode::marked = marked;
    }
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    void add_child(FibonacciHeapNode<T> *node) {
        node->parent = this;
        if (!this->child) {
            this->child = node;
            node->left = node;
            node->right = node;
        } else {
            node->left = this->child->left;
            node->right = this->child;
            this->child->left->right = node;
            this->child->left = node;
        }
        ++this->degree;
    }
    
    void remove_child(FibonacciHeapNode<T> *node) {
        if (this->child == node) {
            if (node->right == node) {
                this->child = nullptr;
            } else {
                this->child = node->right;
                node->right->left = node->left;
                node->left->right = node->right;
            }
        }
        node->parent = nullptr;
        node->left = node->right = node;
        --this->degree;
    }
};

template <class T> class FibonacciHeap {
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Attributes                ||
     * -------------------------------------------
     * -------------------------------------------
     */
    FibonacciHeapNode<T> *min_node;
    int num_of_nodes;

public:
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    FibonacciHeap() {
        this->min_node = nullptr;
        num_of_nodes = 0;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||           Getter and Setter           ||
     * -------------------------------------------
     * -------------------------------------------
     */
    FibonacciHeapNode<T> *getMinNode() const {
        return min_node;
    }
    
    [[nodiscard]] int getNumOfNodes() const {
        return num_of_nodes;
    }
    
    void setNumOfNodes(int numOfNodes) {
        num_of_nodes = numOfNodes;
    }
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    bool empty() {
        return this->min_node == 0;
    }
    
    void merge(FibonacciHeap<T> &other) {
        this->min_node = _merge(this->min_node, other.min_node);
        other.min_node = NULL;
    }
    
    T delete_minium() {
        FibonacciHeapNode<T> *min_node = this->min_node;
        this->min_node = _delete_minium(this->min_node);
        
        T res = min_node->key;
        delete min_node;
        return res;
    }
    
    FibonacciHeapNode<T> *insert(T key) {
        FibonacciHeapNode<T> *new_node = new FibonacciHeapNode<T>(key);
        min_node = _merge(min_node, new_node);
        return new_node;
    }
    
private:
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function (private)       ||
     * -------------------------------------------
     * -------------------------------------------
     */
    void _unMark_unParent_all(FibonacciHeapNode<T> * node) {
        if (node == NULL) return;
        
        FibonacciHeapNode<T> *start = node;
        do {
            node->marked = false;
            node->parent = NULL;
            
            node = node->right;
        } while (node != start);
    }
    
    FibonacciHeapNode<T> *_merge(FibonacciHeapNode<T> *a, FibonacciHeapNode<T> *b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        
        // if a_min > b_min then swap(a, b)
        if (a->getKey() > b->getKey()) {
            FibonacciHeapNode<T> *tmp = a;
            a = b;
            b = tmp;
        }
        
        FibonacciHeapNode<T> *a_right = a->right;
        FibonacciHeapNode<T> *b_left = b->left;
        
        a->right = b;
        b->left = a;
        a_right->left = b_left;
        b_left->right = a_right;
        
        return a;
    }
    
    FibonacciHeapNode<T> *_delete_minium(FibonacciHeapNode<T> *node) {
        // 1. Delete min, meld its children into root list
        
        _unMark_unParent_all(node->child);
        
        if (node->right == node) {
            node = node->child;
        } else {
            node->left->right = node->right;
            node->right->left = node->left;
            
            node = _merge(node->left, node->child);
        }
        
        if (node == NULL) return node;
        
        
        // 2. Consolidate trees so that no two roots have same rank
        
        FibonacciHeapNode<T> *rank[64] = {NULL};
        
        while(true) {
            if (rank[node->degree] == NULL) {
                rank[node->degree] = node;
                node = node->right;
            } else {
                FibonacciHeapNode<T> *temp = rank[node->degree];
                
                // stop
                if (temp == node) {
                    break;
                }
                
                // remove <node> from rank[]
                rank[node->degree] = NULL;
                // remove link to temp
                temp->right->left = temp->left;
                temp->left->right = temp->right;
                
                if (node->getKey() < temp->getKey()) {
                    // add <temp> to node.child()
                    node->add_child(temp);
                    
                } else {
                    // replace <node> by <temp>
                    if (node->right == node) {
                        temp->left = temp;
                        temp->right = temp;
                    } else {
                        node->right->left = temp;
                        node->left->right = temp;
                        temp->right = node->right;
                        temp->left = node->left;
                    }
                    
                    // add <node> to temp.child()
                    temp->add_child(node);
                    
                    node = temp;
                }
            }
        }
        
        
        // 3. Update min
        
        FibonacciHeapNode<T> *min_node = node;
        FibonacciHeapNode<T> *start = node;
        do {
            if (node->getKey() < min_node->getKey()) {
                min_node = node;
            }
            node = node->right;
        } while (node != start);
        
        return min_node;
    }
};

int dijkstra(unordered_map<int, vector<pair<int, int>>> neighbors, int source, int destination) {
    unordered_map<int, bool> finish;
    
    FibonacciHeap<pair<int, int>> heap;
    heap.insert({0, source});
    
    while (!heap.empty()) {
        pair<int, int> p = heap.delete_minium();
        
        if (finish[p.second]) {
            continue;
        }
        
        finish[p.second] = true;
        
        if (p.second == destination) {
            return p.first;
        }
        
        for (auto &neighbor : neighbors[p.second]) {
            if (!finish[neighbor.second]) {
                heap.insert({p.first + neighbor.first, neighbor.second});
            }
        }
    }
    
    return -1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    unordered_map<int, vector<pair<int, int>>> neighbors;
    
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        neighbors[u].emplace_back(w, v);
    }

    int s, t;
    scanf("%d%d", &s, &t);
    printf("%d", dijkstra(neighbors, s, t));

    return 0;
}
