class SCC{

public: 
  vector<vector<int> > g;
  vector<vector<int> > g_t;
  vector< int > components;
  stack<int>st;
  int priority=0;
  int sz;
  vector<bool>vis;
  SCC(int n){
    g.clear();
    g_t.clear();
    components.clear();
    vis.clear();
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
     
 
  }
   
};
