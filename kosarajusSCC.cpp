#include<iostream>
#include<vector>
#include<queue>
#include<set>
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
#define INF 1000000
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
class SCC{
  // contains the implementation of kossaraju's algorithm for finding the scc's in the graph 
public: 
  vector<vector<int> > g;
  vector<vector<int> > g_t;
  vector< int > components;
  stack<int>st;
  int priority=0;
  int sz;
  vector<bool>vis;
  SCC(int n){
    g.resize(n+1);
    g_t.resize(n+1);
    components.resize(n+1);
    for(int i=1;i<=n;i++)components[i]=i;
    vis.resize(n+1,false);
    sz=n;
  }
  void add_edge(int a, int b){
    g[a].pb(b);
    g_t[b].pb(a);
   
  }

  void dfs1(int node){
    vis[node]=true;
    
    for(int x : g[node]){
      if(!vis[x]){
          dfs1(x);
      }
    }
    st.push(node);

  }

  void dfs2(int node){
        vis[node]=true;
        components[node]=priority;
       
       
        for(int y : g_t[node]){
      
          if(!vis[y]){
            vis[y]=true;
            dfs2(y);
          }
        }
  }
  void findSCC(){
      int i;
      for(i=1;i<=sz;i++){
        if(vis[i]==false){
          dfs1(i);
        }
      }
      for(i=1;i<=sz;i++)vis[i]=false;
     
      while(!st.empty()){
            int curr= st.top();
        
            st.pop();
            if(vis[curr]==false){
           
              priority = curr ;
            
              dfs2(curr);
            }
      }
      // now scc's are stored in the components 

      // time complexity of kossaraju's algorithm is O(V + E)
  }
   
};
vector<vector<int> >g1(1);
vector<bool>vis2(1e5 +5);
vector<int>coins(1e5 +5);
vector<int>dp(1e5+5);
void dfs3(int node){
   vis2[node]=true;
 for(int x : g1[node]){
      if(!vis2[x]){
          dfs3(x);
          dp[node]=max(dp[node],dp[x]);
      }
      else{
        dp[node]=max(dp[node],dp[x]);
      }
    
 }
   dp[node]+=coins[node];
 return ;
        
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
   // cin >> tt;

    while (tt-- > 0) {
      int n,m;
      cin>>n>>m;
      coins.resize(n+1);
      int k;
      vector<pair<int,int >  > edges;
      int i;
      for(i=1;i<=n;i++){
        cin>>k;
        coins[i]=k;
      }
      SCC scc(n);
      for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges.pb({a,b});
        scc.add_edge(a,b);
      }
      scc.findSCC();
      vector<int>comp =scc.components;
      
      g1.resize(n+1);
     vis2.resize(n+1,false);
      dp.resize(n+1,0);
      map<pair<int,int>, bool>mp;
      for(auto e : edges){
           if(comp[e.first]!=comp[e.second] && mp[{e.first,e.second}]==false){
            mp[{e.first,e.second}]=true;
            g1[comp[e.first]].pb(comp[e.second]);
           }
      }
      
      for(int x=1;x<=n;x++){
        if(x!=comp[x]){
          coins[comp[x]]+=coins[x];
        }
      }
      for(i=1;i<=n;i++){
        if(vis2[comp[i]]==false){
              dfs3(comp[i]);
        }
      } 
      int ans=-1;
      for(i=1;i<=n;i++){
        ans=max(ans,dp[comp[i]]);
      }
      cout<<ans<<'\n';

      // now g is just a DAG , with possibly multiple edges between two nodes we can use dp to solve the problem 
      // dp[i]-> maximum you can earn     
     
    }
}
