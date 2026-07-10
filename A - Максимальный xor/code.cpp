#include <bits/stdc++.h>
using namespace std;
 
int n, k;
vector<int> a;
int ans = 0;
 
void dfs(int start, int depth, int cur_xor) {
    if (depth == k) {
        ans = max(ans, cur_xor);
        return;
    }
    for (int i = start; i < n; ++i) {
        dfs(i + 1, depth + 1, cur_xor ^ a[i]);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
 
    dfs(0, 0, 0);
    cout << ans << '\n';
 
    return 0;
}
