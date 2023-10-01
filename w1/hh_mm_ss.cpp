#include <iostream>

using namespace std;

/*
 * return -1 if not digit
 */
inline int checkDigitAndCalc(char c, int n) {
    int digit = (int) c - (int) '0';

    if (isdigit(c)) {
        return digit * n;
    } else {
        return -1;
    }
}

int main() {
    string s;
    cin >> s;

    if (s.length() != 8) {
        cout << "INCORRECT";
        return 0;
    }

    if (s[2] != ':' || s[5] != ':') {
        cout << "INCORRECT";
        return 0;
    }

    int res = 0;
    int a[] = {36000, 3600, 0, 600, 60, 0, 10, 1};
    for (int i = 0; i < 8; ++i) {
        if (i != 2 && i != 5) {
            int calc = checkDigitAndCalc(s[i], a[i]);
            if (calc != -1) {
                res += calc;
            } else {
                cout << "INCORRECT";
                return 0;
            }
        }
    }

    if (s[0] > '2' || (s[0] == '2' && s[1] > '3')) {
        cout << "INCORRECT";
        return 0;
    }

    if (s[3] > '5' || s[6] > '5') {
        cout << "INCORRECT";
        return 0;
    }

    cout << res;
    
    return 0;
}
