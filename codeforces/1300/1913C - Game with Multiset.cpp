#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    // cnt[x] = number of elements equal to 2^x
    long long cnt[30] = {};

    while (m--) {
        int type;
        long long v;
        cin >> type >> v;

        if (type == 1) {
            // ADD v -> add 2^v
            cnt[v]++;
        }
        else {
            // GET v -> can we make sum v?
            long long w = v;

            for (int x = 29; x >= 0; x--) {
                long long value = (1LL << x);

                // How many copies of 2^x can we use?
                long long take = min(cnt[x], w / value);

                w -= take * value;
            }

            if (w == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}