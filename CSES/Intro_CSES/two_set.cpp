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
    ll sum = n * (n+1) / 2;
    if(sum & 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll i = n;
    sum = sum / 2;
    unordered_set<int> s;
    while(sum >= i){
        s.insert(i);
        sum -= i;
        i--;
    }
    if(sum) s.insert(sum);
    cout << s.size() << endl;
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl
         << (n - s.size()) << endl;
    for (int j = 1; j <= n;j++){
        if(s.find(j) == s.end()){
            cout << j << " ";
        }
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