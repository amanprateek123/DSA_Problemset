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

struct Node{
    Node *link[26];
    bool flag = false;

    bool isContain(char ch){
        return link[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        link[ch - 'a'] = node;
    }

    Node* get(char ch){
        return link[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }
};

class Trie{    
    public:
        Node* root;  

        Trie () {
          root = new Node();
        }

        void insert(string a){
          Node *node = root;
          int n = a.size();
          for (int i = 0; i < n; i++)
          {
              if (!node->isContain(a[i]))
              {
                  node->put(a[i], new Node());
              }
              node = node->get(a[i]);
          }
          node->setEnd();
        }
};

void solve(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    Trie trie;
    loop(i,0,n){
          string x;
          cin >> x;
          trie.insert(x);
    }
    int m = s.size();
    int dp[m+1];
    dp[m] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
          Node* node = trie.root;
          int ans = 0;
          for (int j = i; j < m;j++){
            if(!node->isContain(s[j]))
                break;
            node = node->get(s[j]);
            if(node->flag){
                ans = (ans + dp[j + 1] % hell) % hell;
            }
          }
          dp[i] = ans;
    }
    cout << dp[0] << endl;
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
