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

ll rec(vector<ll> a, int i, ll s, ll sum){
    if(i==-1){
        return abs((sum - s) - s);
    }
    return min(rec(a, i - 1, s + a[i], sum), rec(a, i - 1, s, sum));
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    loop(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << rec(a, n - 1, 0, sum) << endl;
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