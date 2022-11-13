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

ll rec(vector<vector<char>> &a,int i, int j, int n, vector<vector<ll>> &dp){
    if(i==n-1 && j==n-1)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    if(i+1 < n && a[i+1][j] != '*'){
        ans += rec(a, i + 1, j, n, dp) % hell;
    }
    if(j+1 < n && a[i][j+1] != '*'){
        ans += rec(a, i, j + 1, n, dp) % hell;
    }
    return dp[i][j] = ans % hell;
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    vector<vector<char>> a(n, vector<char>(n));
    loop(i,0,n){
        loop(j,0,n){
            cin >> a[i][j];
        }
    }
    if(a[0][0] == '*' || a[n-1][n-1] == '*'){
        cout << "0";
        return;
    }
    cout << rec(a, 0, 0, n, dp);
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
