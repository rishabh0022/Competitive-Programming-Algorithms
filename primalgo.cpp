#include<iostream>
#include<vector>
#include<queue>// by default by decreasing order 
#include<set>// by default multiset in increasing order
#include<stack>
#include<map>
#include <unordered_set> 
#include<algorithm>
#include <numeric>
#include<cstdlib>
#include <chrono>
#include <random>
#include <cstring>
#include<bitset>
#include<iomanip>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <cassert>
#define pb push_back
#define int long long int
#define INF 10000000000000000
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
int mod= 1e9 +7;
 
int n; 
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt=1;
   
   //cin>>tt;
   
    while(tt-->0){
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int> >  > g(n+1);
    int i;
    for(i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      g[a].pb({b,c});
      g[b].pb({a,c});
          }
 
  priority_queue<vector<int> > pq;
  pq.push({0,1,1});
  vector<int>parent(n+1);
  parent[1]=1;
  int sm=0;
  vector<bool>vis(n+1,false);
  vector<int>done;
  while(!pq.empty()){
    int wt = -pq.top()[0];
    int node= pq.top()[1];
   
    
    int parent1 = pq.top()[2];
   if(vis[node]==false) sm +=(wt);
    parent[node]=parent1;
    pq.pop();
        for(vector<int> v : g[node]){
          if(vis[v[0]]==false){
            pq.push({-v[1],v[0],node});
          }
        }
        vis[node]=true;
  }
  bool possible=true;
  for(i=1;i<=n;i++){
    if(parent[i]==0){
      possible=false;
      break;
    }
  }
  if(possible){
        cout<<sm<<' ';
  }
  else{
    cout<<"IMPOSSIBLE";
  }
 
 
 
 
 
 
       
}
}
