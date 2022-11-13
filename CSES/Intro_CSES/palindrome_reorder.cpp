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
    string s;
    cin >> s;
    ll n = s.size();
    map<char,ll> m;
    for(auto it: s){
        m[it]++;
    }
    ll odd = 0;
    for (auto it : m)
    {
        if(it.second & 1){
            odd++;
        }
    }
    if((!(n&1) && odd != 0) || (n&1 && odd != 1)){
        cout << "NO SOLUTION" << endl;
        return;
    }
    string a = "";
    string b = "";
    if(n&1){
        pair<char, ll> p;
        for(auto it: m){
            if(it.second & 1){
                p = it;
            }
            else{
                ll num = it.second / 2;
                while (num--){
                    a += it.first;
                    b += it.first;
                }
            }
        }
        ll num = p.second;
        while(num--){
            a += p.first;
        }
    }
    else{
        pair<char, ll> p;
        for(auto it: m){
            ll num = it.second / 2;
            while (num--){
              a += it.first;
              b += it.first;
            }
        }
    }
    reverse(b.begin(), b.end());
    string ans = a + b;
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