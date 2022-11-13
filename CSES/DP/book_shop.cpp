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
    int n, x;
    cin >> n >> x;
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    vector<int> pr(n);
    vector<int> pa(n);
    loop(i, 0, n){
        cin >> pr[i];
    }
    loop(i,0,n){
        cin >> pa[i];
    }
    loop(i,1,n+1){
        loop(j,1,x+1){
            if(j - pr[i-1] >= 0){
                dp[i][j] = max(dp[i-1][j], pa[i-1] + dp[i - 1][j - pr[i-1]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][x];
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
