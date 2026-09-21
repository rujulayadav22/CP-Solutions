#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, R, r;
    cin >> n >> R >> r;

    if (n == 1) {
        cout << (R >= r ? "YES" : "NO");
        return 0;
    }

    if (R < 2 * r) {
        cout << "NO";
        return 0;
    }

    double pi = acos(-1.0);

    double angle = asin((double)r / (R - r));

    if (n * angle <= pi + 1e-12)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}