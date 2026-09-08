#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int easy = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                easy++;
        }

        // Need at least two easy problems
        if (easy < 2) {
            cout << -1 << '\n';
            continue;
        }

        int ans = a[0] + a[n - 1];

        cout << ans << '\n';
    }

    return 0;
}