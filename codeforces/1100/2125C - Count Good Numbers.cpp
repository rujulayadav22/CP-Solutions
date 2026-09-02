#include <bits/stdc++.h>
using namespace std;

long long countGood(long long x) {
    if (x <= 0) return 0;

    long long blocks = x / 210;
    long long rem = x % 210;

    long long ans = blocks * 48;

    for (int i = 1; i <= rem; i++) {
        if (i % 2 != 0 &&
            i % 3 != 0 &&
            i % 5 != 0 &&
            i % 7 != 0) {
            ans++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long l, r;
        cin >> l >> r;

        cout << countGood(r) - countGood(l - 1) << '\n';
    }

    return 0;
}