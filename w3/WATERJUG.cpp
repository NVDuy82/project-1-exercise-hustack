#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct two_jug {
    int x, y;
    static int max_x, max_y;

    two_jug(int x, int y) : x(x), y(y) {}
    
    [[nodiscard]] two_jug empty_left() const {
        return {0, y};
    }
    
    [[nodiscard]] two_jug empty_right() const {
        return {x, 0};
    }

    [[nodiscard]] two_jug fill_left() const {
        return {max_x, y};
    }

    [[nodiscard]] two_jug fill_right() const {
        return {x, max_y};
    }

    [[nodiscard]] two_jug transfer_left() const {
        int transfer = min(max_x - x, y);
        return {x + transfer, y - transfer};
    }

    [[nodiscard]] two_jug transfer_right() const {
        int transfer = min(x, max_y - y);
        return {x - transfer, y + transfer};
    }

    [[nodiscard]] int litres() const {
        return x + y;
    }

    bool operator < (const two_jug& other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

int two_jug::max_x = 0;
int two_jug::max_y = 0;

struct state {
    two_jug t_jug;
    int step;

    state(const two_jug &tJug, int step) : t_jug(tJug), step(step) {}
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    two_jug::max_x = a;
    two_jug::max_y = b;
    
    two_jug start_two_jug(0, 0);
    state start_state(start_two_jug, -1);
    
    queue<state> q;
    map<two_jug, bool> added;
    
    q.push(start_state);
    added[start_state.t_jug] = true;
    
    
    // bfs
    while (!q.empty()) {
        state state_jug = q.front();
        q.pop();
        
        // correct
        if (state_jug.t_jug.litres() == c) {
            cout << state_jug.step << endl;
            return 0;
        }
        
        // check if
        if (state_jug.t_jug.x != two_jug::max_x) {
            // create new state
            state new_state(state_jug.t_jug.fill_left(), state_jug.step + 1);
            
            // push new state if not yet added
            if (!added[new_state.t_jug]) {
                q.push(new_state);
                added[new_state.t_jug] = true;
            }
        }
        
        // check if
        if (state_jug.t_jug.x != 0) {
            // create new state
            state new_state(state_jug.t_jug.empty_left(), state_jug.step + 1);
            
            // push new state if not yet added
            if (!added[new_state.t_jug]) {
                q.push(new_state);
                added[new_state.t_jug] = true;
            }
        }
        
        // check if
        if (state_jug.t_jug.y != two_jug::max_y) {
            // create new state
            state new_state(state_jug.t_jug.fill_right(), state_jug.step + 1);
            
            // push new state if not yet added
            if (!added[new_state.t_jug]) {
                q.push(new_state);
                added[new_state.t_jug] = true;
            }
        }
        
        // check if
        if (state_jug.t_jug.y != 0) {
            // create new state
            state new_state(state_jug.t_jug.empty_right(), state_jug.step + 1);
            
            // push new state if not yet added
            if (!added[new_state.t_jug]) {
                q.push(new_state);
                added[new_state.t_jug] = true;
            }
        }
        
        // check if
        if (state_jug.t_jug.x != two_jug::max_x && state_jug.t_jug.y != 0) {
            // create new state
            state new_state(state_jug.t_jug.transfer_left(), state_jug.step + 1);
            
            // push new state if not yet added
            if (!added[new_state.t_jug]) {
                q.push(new_state);
                added[new_state.t_jug] = true;
            }
        }
        
        // check if
        if (state_jug.t_jug.y != two_jug::max_y && state_jug.t_jug.x != 0) {
            // create new state
            state new_state(state_jug.t_jug.transfer_right(), state_jug.step + 1);
            
            // push new state if not yet added
            if (!added[new_state.t_jug]) {
                q.push(new_state);
                added[new_state.t_jug] = true;
            }
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}
