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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll &v : a)
        cin >> v;
    
    if(n==1 && a[0] > x){
        cout << "0";
        return;
    }
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= x; j++)
        {
            if (j - a[i] >= 0)
            {
                dp[j] += dp[j - a[i]];
                dp[j] %= 1000000007;
            }
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
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
