#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() { 
    queue<int> q;
    string str;
    do {
        cin >> str;
        if (str == "POP") {
            if (q.empty()) {
                cout << "NULL" << endl;
            } else {
                int temp = q.front();
                q.pop();
                cout << temp << endl;
            }
        } else if (str == "PUSH") {
            int temp;
            cin >> temp;
            q.push(temp);
        }
    } while (str != "#");
    return 0;
}
