//CPP 
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c = getchar();
    while (c != EOF) {
        if (isalpha(c)) {
            cout << (char)toupper(c);
        } else {
            cout << c;
        }
        c = getchar();
    }
}
