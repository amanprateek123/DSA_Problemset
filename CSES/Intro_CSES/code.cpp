#include <bits/stdc++.h>
 
#define ar array
#define ll long long int
#define loop(i, a, b) for (int i = a; i < b;i++)
#define loopRev(i, a, b) for (int i = a; i > b;i--)
#define vi vector<int>
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
    int n;
    cin>>n;
    int m;
    cin >> m;
    vector<string> price;
    vector<string> trans;
    for(int i=0;i<n+1;i++){
       string s;
       getline(cin, s);
       trans.push_back(s);
    }
    for(int i=0;i<m;i++){
       string s;
       getline(cin, s);
       price.push_back(s);
    }
    map<string, int> mp;
    map<string, pair<int, int>> disco;
    for (auto it : price)
    {
      string s = it;
      int i = 0;
      while(s[i] != ':'){
        i++;
      }
      s = it.substr(0, i);
      string p = it.substr(i + 2);
      mp[s] = stoi(p);
    }
    int ans = 0;
    string curr = "";
    int amt = INT_MAX;
    int dis = 0;
    for (auto it : trans)
    {
      if(it[0] == 's'){
        int i = 5;
        while(it[i] != ','){
          i++;
        }
        string item = it.substr(5, i - 5);
        string pri = it.substr(i + 2);
        int q = stoi(pri);
        if(disco.find(item) != disco.end()){
           if(q <= disco[item].first){
             ans += q * (mp[item] - disco[item].second);
           }
           else {
             ans += disco[item].first * (mp[item] - disco[item].second) + ((q - disco[item].first) * mp[item]);
           }
        }
        else {
          ans += mp[item] * q;
        }
      }
      else if(it[9] == 's'){
        int i = 15;
        while(it[i] != ','){
          i++;
        }
        string item = it.substr(15, i - 15);
        i = i + 2;
        int j = i;
        while (it[i] != ',')
        {
          i++;
        }
        string disc = it.substr(j, i - j);
        string maxc = it.substr(i + 2);
        curr = item;
        amt = stoi(maxc);
        dis = stoi(disc);
        disco[item] = {amt, dis};
      }
      else{
        string item = "";
        for (int i = 13; i < it.size(); i++)
        {
          item += it[i];
        }
        disco.erase(item);
      }
    }
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
