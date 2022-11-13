#include <bits/stdc++.h>
 
#define ar array
#define ll long long
#define loop(i, a, b) for (int i = a; i < b;i++)
#define loopRev(i, a, b) for (int i = a; i > b;i--)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define mi map<int,int>
#define mii map<int, pair<int,int>>
#define pii pair<int,int>
#define minH priority_queue<int, vector<int>, greater<int>>
#define maxH priority_queue<int>
#define hell 1000000007 
#define endl "\n"
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    loop(i, 0, n)
    {
        cin >> a[i];
    }
    if (a[0] == 0) {
    fill(dp[0].begin(), dp[0].end(), 1);
  } else {
    dp[0][a[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] == 0) {
      for (int j = 1; j <= m; j++) {
	for (int k : {j-1,j,j+1}) {
	  if (k >= 1 && k <= m) {
	    (dp[i][j] += dp[i-1][k]) %= hell;
	  }
	}
      }
    } else {
      for (int k : {a[i]-1,a[i],a[i]+1}) {
	if (k >= 1 && k <= m) {
	  (dp[i][a[i]] += dp[i-1][k]) %= hell;
	}
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    (ans += dp[n-1][j]) %= hell;
  }
  cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    int tc = 1;
    // cin >> tc;
    loop(t,0,tc){
        solve();
    }
}
