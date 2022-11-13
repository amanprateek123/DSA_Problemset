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
    ll n;
    cin >> n;
    n--;
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    while(n--){
        vector<string> u = v;
        reverse(u.begin(), u.end());
        for (ll i = 0; i < v.size();i++)
        {
            v[i] = "0" + v[i];
        }
         for(ll i = 0; i < u.size();i++){
             u[i] = "1" + u[i];
         }
        v.insert(v.end(), u.begin(), u.end());
    }
    for(auto it: v){
        cout << it << endl;
    }
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