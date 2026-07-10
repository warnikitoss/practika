#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
 
        long long best = 0;
        for (int i = 0; i <= 5; ++i) {
            for (int j = 0; j <= 5 - i; ++j) {
                for (int k = 0; k <= 5 - i - j; ++k) {
                    int sum = i + j + k;
                    if (sum > 5) continue;
                    long long cur = 1LL * (a + i) * (b + j) * (c + k);
                    best = max(best, cur);
                }
            }
        }
 
        cout << best << '\n';
    }
 
    return 0;
}
