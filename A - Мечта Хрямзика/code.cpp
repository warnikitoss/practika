#include <bits/stdc++.h>
using namespace std;
 
vector<int> z_function(const string& s) {
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string a, b;
    cin >> a >> b;
    int n = (int)a.size();
 
    if (a == b) {
        cout << 0 << '\n';
        return 0;
    }
 
    string combined = b + "#" + a + a.substr(0, n - 1);
    vector<int> z = z_function(combined);
 
    int offset = (int)b.size() + 1;
    int best = -1;
 
    for (int i = 1; i < n; ++i) {
        if (z[offset + i] >= n) {
            best = i;
        }
    }
 
    if (best == -1) {
        cout << -1 << '\n';
    } else {
        cout << n - best << '\n';
    }
 
    return 0;
}
