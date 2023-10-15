#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

/*
 * ____ Node ____
 */
class Node {
private:
    int id;
    vector<Node*> children;

public:
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    explicit Node(int id) : id(id) {}
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    void insert(const int &u) {
        // if node does not exist yet
        for (auto const &child : children) {
            if (child->id == u) {
                return;
            }
        }
        
        children.push_back(new Node(u));
    }
    
    void insert(const Node &node) {
        // if node does not exist yet
        for (auto const &child : children) {
            if (child->id == node.id) {
                return;
            }
        }
        
        children.push_back(new Node(node.id));
    }
    
    void reset() {
        children.clear();
        children.shrink_to_fit();
    }
    
    int indexOf(const int &v) {
        for (int i = 0; i < children.size(); i++) {
            if (children[i]->id == v) {
                return i;
            }
        }
        
        return -1;
    }
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||           Getter and Setter           ||
     * -------------------------------------------
     * -------------------------------------------
     */
    
    [[nodiscard]] int getId() const {
        return id;
    }
    
    void setId(int id) {
        this->id = id;
    }
    
    [[nodiscard]] const vector<Node*> &getChildren() const {
        return children;
    }
    
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||               Operator                ||
     * -------------------------------------------
     * -------------------------------------------
     */
    friend bool operator==(const Node &node_1, const Node &node_2) {
        return node_1.id == node_2.id;
    }
    
    friend bool operator==(const Node &node, const int &v) {
        return node.id == v;
    }
    
    friend bool operator!=(const Node &node_1, const Node &node_2) {
        return node_1.id != node_2.id;
    }
    
    friend bool operator!=(const Node &node, const int &v) {
        return node.id != v;
    }
    
};



/*
 * ____ Other Function ____
 */

void printPreOrder(const Node &node) {
    // 1. print data of node
    //  current node
    cout << node.getId() << " ";
    
    // 2. child
    // left  ->  right
    for (auto &child: node.getChildren()) {
        printPreOrder(*child);
    }
}

void printPostOrder(const Node &node) {
    // 1. child
    // left  ->  right
    for (auto &child: node.getChildren()) {
        printPostOrder(*child);
    }
    
    // 2. print data of node
    //  current node
    cout << node.getId() << " ";
}

void printInOrder(const Node &node) {
    // 1. left child
    if (!node.getChildren().empty()) {
        printInOrder(*node.getChildren()[0]);
    }
    
    // 2. print data of node
    //  current node
    cout << node.getId() << " ";
    
    // 3. right child
    for (int i = 1; i < node.getChildren().size(); ++i) {
        printInOrder(*node.getChildren()[i]);
    }
}



/*
 * ____ Graph Tree ____
 */
class Graph {
    Node root;

public:
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||             Constructor               ||
     * -------------------------------------------
     * -------------------------------------------
     */
    Graph() : root(0) {}
    
    /* -------------------------------------------
     * -------------------------------------------
     * ||              Function                 ||
     * -------------------------------------------
     * -------------------------------------------
     */
    void make_root(Node &node) {
        root = node;
        root.reset();
    }
    
    void make_root(int &v) {
        root = Node(v);
    }
    
    [[nodiscard]] const Node &getRoot() const {
        return root;
    }
    
    void insert(int &u, int &v) {
        // insert with dfs algorithm
        
        // dfs algorithm
        stack<Node*> s;
        s.emplace(&root);
        
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            
            if (*node == v) {
                node->insert(u);
                return;
            }
            
            for (const auto &child : node->getChildren()) {
                s.push(child);
            }
        }
    }
    
    void inOrder() {
        printInOrder(root);
        cout << endl;
    }
    
    void preOrder() {
        printPreOrder(root);
        cout << endl;
    }
    
    void postOrder() {
        printPostOrder(root);
        cout << endl;
    }
};



int main() {
    Graph graph;
    string cmd;
    do {
        cin >> cmd;

        if (cmd == "MakeRoot") {
            int id;
            cin >> id;
            graph.make_root(id);
        } else if (cmd == "Insert") {
            int u, v;
            cin >> u >> v;
            graph.insert(u, v);
        } else {

            if (cmd == "PreOrder") {
                graph.preOrder();
            } else if (cmd == "InOrder") {
                graph.inOrder();
            } else if (cmd == "PostOrder") {
                graph.postOrder();
            }

        }
    } while (cmd != "*");
    
    return 0;
}
