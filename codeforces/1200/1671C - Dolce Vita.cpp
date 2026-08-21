#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long sum = 0;
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            sum += a[k - 1];

            // Even on day 0, k cheapest packs are too expensive
            if (sum > x)
                break;

            // Number of days (starting from day 0)
            // on which we can buy at least k packs
            long long days = (x - sum) / k + 1;

            ans += days;
        }

        cout << ans << '\n';
    }

    return 0;
}