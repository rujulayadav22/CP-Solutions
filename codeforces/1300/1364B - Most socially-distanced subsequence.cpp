#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> ans;

        // Always take the first element
        ans.push_back(p[0]);

        // Take only local maxima/minima
        for (int i = 1; i < n - 1; i++) {

            // local maximum
            if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
                ans.push_back(p[i]);
            }

            // local minimum
            else if (p[i] < p[i - 1] && p[i] < p[i + 1]) {
                ans.push_back(p[i]);
            }
        }

        // Always take the last element
        ans.push_back(p[n - 1]);

        cout << ans.size() << '\n';

        for (int x : ans) {
            cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}