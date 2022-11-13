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
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    if(x>=y){
      if(!(x&1)){
          ans += x * x;
          ans -= y;
          ans++;
      }
      else {
          ans += (x - 1) * (x - 1) + 1;
          ans += y;
          ans--;
      }
    }
    else {
      if((y&1)){
          ans += y * y;
          ans -= x;
          ans++;
      }
      else {
          ans += (y - 1) * (y - 1) + 1;
          ans += x;
          ans--;
      }
    }

    cout << ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    int tc = 1;
    cin >> tc;
    loop(t,0,tc){
        solve();
    }
}