#include <cstdio>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    // input and hash
    int hash;
    char c;
    getchar();
    for (int i = 0; i < n; ++i) {
        hash = 0;
        while (true) {
            c = getchar();
            if (c == '\n') break;
            hash = ((hash << 8) + (int)c) % m;
        }
        printf("%d\n", hash);
    }
    
    return 0;
}
