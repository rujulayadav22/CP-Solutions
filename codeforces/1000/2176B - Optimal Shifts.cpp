#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        // If already all 1s
        if (s.find('0') == string::npos) {
            cout << 0 << '\n';
            continue;
        }

        string x = s + s;

        int ans = 0;
        int cnt = 0;

        for (char c : x) {
            if (c == '0') {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }

        // A circular zero block cannot contain more than n zeros
        ans = min(ans, n);

        cout << ans << '\n';
    }

    return 0;
}
