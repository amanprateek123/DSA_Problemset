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

int ans = 0;
bool vis[7][7] = {false};

void dfs(string s, int i, int j, int a = 0){
    if(i==6 && j==0){
        if(a==48){
            ++ans;
        }
        return;
    }
    if (vis[i][j])
    {
        return;
    }
    cout << a << endl;
    vis[i][j] = true;
    if(s[a] == '?' || s[a] == 'U'){
        if (i > 0 && !vis[i - 1][j])
        {
            dfs(s, i - 1, j,a + 1);
        }
    }
    if(s[a] == '?' || s[a] == 'D'){
        if (i < 6 && !vis[i + 1][j])
        {
            dfs(s, i + 1, j,a + 1);
        }
    }
    if(s[a] == '?' || s[a] == 'L'){
        if (j > 0 && !vis[i][j - 1])
        {
            dfs(s, i, j - 1,a + 1);
        }
    }
    if(s[a] == '?' || s[a] == 'R'){
        if (j < 6 && !vis[i][j + 1])
        {
            dfs(s, i, j+1,a + 1);
        }
    }
    vis[i][j] = false;
}

void solve() {
    string s;
    cin >> s;
    vvi vis(7, vi(7, 0));
    dfs(s,0,0);
    cout << ans;
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