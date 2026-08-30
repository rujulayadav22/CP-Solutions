#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;

    vector<int> skip;
    int p = 0;

    // Store numbers skipped between consecutive values
    for (int i = 0; i < n; i++) {
        if (a[i] > p) {
            for (int x = p + 1; x < a[i]; x++)
                skip.push_back(x);
        }
        p = a[i];
    }

    p = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == p) {
            if (j < skip.size())
                b[i] = skip[j++];
            else
                b[i] = 1000000;
        }
        else {
            b[i] = p;
        }

        p = a[i];
    }

    for (int x : b)
        cout << x << " ";

    return 0;
}