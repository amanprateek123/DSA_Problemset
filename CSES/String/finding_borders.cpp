// Word Combinations CSES Solution
#include <bits/stdc++.h>
 
#define ar array
#define ll long long int
#define loop(i, a, b) for (int i = a; i < b;i++)
#define loopRev(i, a, b) for (int i = a; i > b;i--)
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define mi map<int,int>
#define mii map<int, pair<int,int>>
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define minH priority_queue<int, vector<int>, greater<int>>
#define minP priority_queue<pii, vector<pii>, greater<pii>>
#define maxH priority_queue<int>
#define hell 1000000007
#define endl "\n"
using namespace std;


void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n;i++){
        int j = pi[i - 1];
        while(j>0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    int j = pi[n - 1];
    set<int> ans;
    while (j > 0)
    {
        ans.insert(j);
        j = pi[j - 1];
    }
    for(auto it: ans){
        cout << it << " ";
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
