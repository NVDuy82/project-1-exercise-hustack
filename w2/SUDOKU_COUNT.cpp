#include <iostream>

using namespace std;

int a[9][9];
int res = 0;

inline bool isValid(int x, int y) {
    for (int i = 0; i < 9; ++i) {
        if (i != x && a[i][y] == a[x][y]) return false;
        if (i != y && a[x][i] == a[x][y]) return false;
    }
    
    int start_i = x - x % 3;
    int start_j = y - y % 3;
    
    for (int i = start_i; i < start_i + 3; ++i) {
        for (int j = start_j; j < start_j + 3; ++j) {
            if ((i != x && j != y) && a[i][j] == a[x][y]) return false;
        }
    }
    
    return true;
}

struct position {
    int x, y;
    
    position(int x, int y) : x(x), y(y) {}
    
    bool isLast() const {
        return (x == 8 && y == 8);
    }
    
    bool isValidPos() const {
        return isValid(x, y);
    }
    
    int getValue() const {
        return a[x][y];
    }
    
    void setValue(const int &v) const {
        a[x][y] = v;
    }
    
    friend position operator + (position &p, const int &v) {
        int _y = p.y + v;
        int _x = p.x + _y / 9;
        _y %= 9;
        return {_x, _y};
    }
    
    friend position operator + (const int &v, position &p) {
        return p + v;
    }
    
    friend void operator += (position &p, const int &v) {
        p = p + v;
    }
    
    friend position operator++ (position &p) {
        p += 1;
        return p;
    }
    
    friend ostream & operator << (ostream &os, const position p) {
        os << "[" << p.x << ", " << p.y << "]";
        return os;
    }
};

inline void input() {
    for (auto & i : a) {
        for (int & j : i) {
            cin >> j;
        }
    }
}

inline void increase(int &x, int &y) {
    if (x == 8 && y == 8) {
        ++res;
    } else if (++y == 9) {
        ++x;
        y = 0;
    }
}

void find(position p) {
    while (!p.isLast() && p.getValue() != 0) {
        ++p;
    }
    if (p.isLast() && p.getValue() != 0) {
        ++res;
    } else {
        for (int i = 1; i < 10; ++i) {
            p.setValue(i);
            
            if (p.isValidPos()) {
                if (p.isLast()) {
                    ++res;
                } else {
                    find(p+1);
                }
            }
        }
        
        p.setValue(0);
    }
}

int main() {
    input();
    find(position(0, 0));
    cout << res;
    
    return 0;
}
