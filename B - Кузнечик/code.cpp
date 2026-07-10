#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    vector<int> dp(n + 1), pref(n + 1);
    dp[0] = 1;
    pref[0] = 1;
 
    for (int i = 1; i <= n; ++i) {
        long long val = pref[i - 1];
        if (i - k - 1 >= 0) val -= pref[i - k - 1];
        val %= MOD;
        if (val < 0) val += MOD;
        dp[i] = (int)val;
        pref[i] = pref[i - 1] + dp[i];
        if (pref[i] >= MOD) pref[i] -= MOD;
    }
 
    cout << dp[n] << '\n';
    return 0;
}
