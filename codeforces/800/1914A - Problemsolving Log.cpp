#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'A']++;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            // A needs 1 minute, B needs 2, ..., Z needs 26
            int required = i + 1;

            if (freq[i] >= required) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}