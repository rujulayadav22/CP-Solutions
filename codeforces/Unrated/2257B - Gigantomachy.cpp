#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n), b(m);

        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        long long bea = a[0] + n - 1;
        long long ver = b[0] + m - 1;

        if (bea >= ver)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}