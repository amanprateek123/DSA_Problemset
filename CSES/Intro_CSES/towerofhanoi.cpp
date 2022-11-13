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

void dfs(int n,char a, char c, char b){
   if(n==0)
       return;
   dfs(n - 1, a, b, c);
   cout << a << " " << c << endl;
   dfs(n - 1, b, c, a);
}

void solve() {
    int n;
    cin>>n;
    cout << pow(2, n) - 1 << endl;
    dfs(n, '1', '3', '2');
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