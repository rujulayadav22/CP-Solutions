#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            pq.push(x);
        }

        for (int i = 0; i < m; i++) {
            long long x;
            cin >> x;

            // Replace the smallest value
            pq.pop();
            pq.push(x);
        }

        long long ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        cout << ans << '\n';
    }

    return 0;
}