#include <iostream>
#include <set>

using namespace std;

/*
 * ____ Node ____
 */
class Node {
    int value;
    Node *left{nullptr}, *right{nullptr};

public:
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    Node() {}
    
    explicit Node(int value) : value(value) {}
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||           Getter and Setter           ||
     * -------------------------------------------
     * -------------------------------------------
     */
    [[nodiscard]] int getValue() const {
        return value;
    }
    
    void setValue(int value) {
        this->value = value;
    }
    
    Node *getLeft() const {
        return left;
    }
    
    void setLeft(Node *left) {
        Node::left = left;
    }
    
    Node *getRight() const {
        return right;
    }
    
    void setRight(Node *right) {
        Node::right = right;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    
    void insert_bst(int &v) {
        //  value of node != v
        if (v < this->value) {
            if (this->left == nullptr) {
                this->left = new Node(v);
            } else {
                this->left->insert_bst(v);
            }
        } else {
            if (this->right == nullptr) {
                this->right = new Node(v);
            } else {
                this->right->insert_bst(v);
            }
        }
    }
};


/*
 * ____ Other Function ____
 */

void printPreOrder(const Node *node) {
    if (node == nullptr) return;
    
    // 1. print data of node
    //  current node
    cout << node->getValue() << " ";
    
    // 2. child
    // left  ->  right
    printPreOrder(node->getLeft());
    printPreOrder(node->getRight());
}



/*
 * ____ Binary Seach Tree ____
 */
class BinarySeachTree {
    Node *root{nullptr};
    set<int> exists;

public:
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    BinarySeachTree() {}
    
    explicit BinarySeachTree(Node *root) : root(root) {}
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||           Getter and Setter           ||
     * -------------------------------------------
     * -------------------------------------------
     */
    [[nodiscard]] Node *getRoot() const {
        return root;
    }
    
    void setRoot(Node *root) {
        BinarySeachTree::root = root;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    void insret(int &v) {
        if (exists.find(v) != exists.end()) {
            return;
        }
        
        if (root == nullptr) {
            root = new Node(v);
            exists.insert(v);
            return;
        }
        
        if (v < root->getValue()) {
            if (root->getLeft() == nullptr) {
                root->setLeft(new Node(v));
                exists.insert(v);
            } else {
                root->getLeft()->insert_bst(v);
            }
        } else {
            if (root->getRight() == nullptr) {
                root->setRight(new Node(v));
                exists.insert(v);
            } else {
                root->getRight()->insert_bst(v);
            }
        }
        
        exists.insert(v);
    }
};

int main() {
    BinarySeachTree tree;
    string cmd;
    
    do {
        cin >> cmd;
        
        if (cmd == "insert") {
            int value;
            cin >> value;
            
            tree.insret(value);
        }
        
    } while (cmd != "#");
    
    printPreOrder(tree.getRoot());
    
    return 0;
}
