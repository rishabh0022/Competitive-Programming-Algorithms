
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
#include <bits/stdc++.h>
#define pb push_back
#define int long long int
#define INF 10000000000000000
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
 int mod= 1e9 +7;
  int n;
  vector<vector<int> > g(1);
  vector<vector<int> > up(2e5 + 5, vector<int>(30,-1)); // up[i][j]-> denotes the 2^j ancestor of node i
  vector<int> tin(2e5+5,0);
  vector<int> tout(2e5 +5, 0);
  vector<int> dist(2e5 + 5);
  int tme=0;
  void dfs(int node){
    int i;
    tin[node]=tme;
    tme++;
       for(i=1;i<=29;i++){
         up[node][i]=up[up[node][i-1]][i-1];
       }
       for( int child : g[node]){
        if(up[child][0]==-1){
          up[child][0]=node;
          dist[child]=dist[node]+1;
          dfs(child);
        }
       }
       tout[node]=tme;
       tme++;
      
  }
bool check(int v, int u){
   if(tin[v]<=tin[u]  && tout[v]>=tout[u])return true;
   return false;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt=1;
   // cin>>tt;
   
    while(tt-->0){
    
    cin>>n;
      int q;
      cin>>q;
      
        g.resize(n+1);
   
       int i;
       for(i=2;i<=n;i++){
        int x;
        int y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
       }
       up[1][0]=1;
       dfs(1);
       int x,k;
      while(q-->0){
        
        cin>>x>>k;
        int orig=x;
        if(check(x,k))
        {
          cout<<(dist[k]-dist[x])<<'\n';
        }
        else if ( check(k,x)){
          cout<<dist[x]-dist[k]<<'\n';
        }  
        else{ 
          for(i=29;i>=0;i--){
             if(!check(up[x][i],k)){
              x=up[x][i];
             }
          }
         
          cout<<"LCA IS "<< up[x][0]<<'\n';
        }

      }
    
       
        
      
       
    
}
}
