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

set<string> st;

void dfs(string s, int i, int n){
    if(i >= n-1){
        st.insert(s);
        return;
    }
    for (int j = i; j < n;j++){
        string r = s;
        swap(r[i], r[j]);
        dfs(r, i + 1, n);
    }
}

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    sort(a.begin(), a.end());
    dfs(a, 0, n);
    cout << (st.size()) << endl;
    for (auto it : st)
    {
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