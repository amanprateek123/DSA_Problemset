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

ll rec(int n, vector<ll> &dp){
    if(n==0)
        return 0;
    if(dp[n] != -1){
        return dp[n];
    }
    ll a = n;
    ll ans = INT_MAX;
    while (a > 0)
    {
        ll r = a % 10;
        a = a / 10;
        if(r == 0){
            continue;
        }
        ans = min(ans, rec(n - r, dp));
    }
    return dp[n] = 1 + ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> dp(n+1, -1);
    cout << rec(n, dp);
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
