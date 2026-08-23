#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<ll, int>> getTop3(const vector<ll>& v) {
    vector<pair<ll, int>> top;

    for (int i = 0; i < (int)v.size(); i++) {
        top.push_back({v[i], i});
    }

    sort(top.rbegin(), top.rend());

    if (top.size() > 3)
        top.resize(3);

    return top;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n), c(n);

        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        for (auto &x : c) cin >> x;

        vector<pair<ll, int>> A = getTop3(a);
        vector<pair<ll, int>> B = getTop3(b);
        vector<pair<ll, int>> C = getTop3(c);

        ll ans = 0;

        for (auto [va, ia] : A) {
            for (auto [vb, ib] : B) {
                for (auto [vc, ic] : C) {

                    if (ia != ib && ib != ic && ia != ic) {
                        ans = max(ans, va + vb + vc);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}