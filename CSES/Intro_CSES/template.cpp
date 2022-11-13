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

void bubbleSort(vi &a, int n){
    int swapped = 1;
    for(int i=0;i<n && swapped;i++){
        swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped = 1;
            }
        }
    }
}

void selectionSort(vi &a, int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(i!=min) swap(a[i],a[min]);
    }
}

void insertionSort(vi &a, int n){
    int i,v;
    for(i=1;i<n;i++){
        v = a[i];
        int j = i;
        while(a[j-1]>v){
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

//Merge Sort

void Merge(vi &a,vi c, int i, int mid, int j){
    int l = i;
    int r = mid+1;
    int t = l;
    while(l<=mid && r<=j){
        if(a[l]<=a[r]){
            c[t] = a[l];
            l++;
            t++;
        }
        else{
            c[t] = a[r];
            t++;
            r++;
        }
    }
    while(l<=mid){
        c[t] = a[l];
        t++;
        l++;
    }
    while(r<=j){
        c[t] = a[r];
        t++;
        r++;
    }
    for(int k =i;k<=j;k++){
        a[k] = c[k];
    }
}

void MergeSort(vi &a,vi c, int i, int j){
  if(i<j){
      int mid = (j+i)/2;    
      MergeSort(a,c,i,mid);
      MergeSort(a,c,mid+1,j);
      Merge(a,c,i,mid,j);
  }
}

//Quick Sort

void quickSort(vi &a, int i, int j){
  
}

void solve(){
    int n;
    cin>>n;
    vi b(n);
    loop(i,0,n){
        cin>>b[i];
    }
    vi c(n);
    MergeSort(b, c,0,n-1);
    loop(i,0,n){
        cout<<b[i]<<" ";
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
