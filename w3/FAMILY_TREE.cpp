#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Person {
    string name;
    vector<Person *> children;

public:
    Person() = default;
    
    explicit Person(string name) : name(name) {
        children.clear();
        children.shrink_to_fit();
    }
    
    void add_child(Person *child) {
        children.push_back(child);
    }
    
    [[nodiscard]] const string &getName() const {
        return name;
    }
    
    void setName(const string &name) {
        Person::name = name;
    }
    
    [[nodiscard]] const vector<Person *> &getChildren() const {
        return children;
    }
    
    void setChildren(const vector<Person *> &children) {
        Person::children = children;
    }
    
    int descendants() {
        int count = 0;
        for (auto child: children) {
            count += 1 + child->descendants();
        }
        return count;
    }
    
    int generation() {
        int count = 0;
        for (auto child: children) {
            count = max(count, 1 + child->generation());
        }
        return count;
    }
    
    friend ostream &operator<<(ostream &os, Person const& person) {
        os << person.name << " : " << &person << " : ";
        for (auto child: person.children) {
            os << child << " ";
        }
        return os;
    }
};

class FamilyTree {
    map<string, Person *> dict;

public:
    FamilyTree() = default;
    
    void add_person(Person *person) {
        dict[person->getName()] = person;
    }
    
    void add_person(const string &name) {
        if (dict.find(name) == dict.end()) {
            dict[name] = new Person(name);
        }
    }
    
    void add_child_parent(const string &child_name, const string &parent_name) {
        auto * child = new Person(child_name);
        auto * parent = new Person(parent_name);
        
        // create child
        if (dict.find(child_name) != dict.end()) {
            child = dict[child_name];
        } else {
            this->add_person(child);
        }
        
        // create parent
        if (dict.find(parent_name) != dict.end()) {
            parent = dict[parent_name];
        } else {
            this->add_person(parent);
        }
        
        // create relationship
        parent->add_child(child);
    }
    
    Person *find_person(const string &name) {
        if (dict.find(name) != dict.end()) {
            return dict[name];
        } else {
            return nullptr;
        }
    }
};

int main() {
    FamilyTree tree;
    string first, second;
    
    // input : information about child-parent : <child> and <parent>
    do {
        cin >> first;
        
        if (first == "***") {
            break;
        }
        
        cin >> second;
        
        tree.add_child_parent(first, second);
        
    } while (true);
    
    
    // two string <cmd> and <param>
    do {
        cin >> first;
        
        if (first == "***") {
            break;
        }
        
        cin >> second;
        Person *p = tree.find_person(second);
        
        if (first == "descendants") {
            cout << p->descendants() << endl;
        } else if (first == "generation") {
            cout << p->generation() << endl;
        }
        
    } while (true);
    
    
    return 0;
}
