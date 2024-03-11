int timer=0;
class Solution {
public:

    void dfs(int node ,vector<int>&low,vector<int>&tin,vector<int>&parent,vector<vector<int>>&g,vector<vector<int>>&ans){
        timer++;
        tin[node]=timer;
        low[node]=timer;
           for(int child :g[node]){
               if(parent[child]==-1){
                   parent[child]=node;  
                   dfs(child,low,tin,parent,g,ans);
                   low[node]=min(low[child],low[node]);
                   if(low[child]>tin[node]){
                        ans.push_back({child,node});
                   }

               }
               else{
                   if(child!=parent[node]){
                       low[node]=min(low[node],tin[child]);
                   }
               }
           }
    }
    // connections is a list containing all the edges 
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        timer=0;
        int i;   
        // now create two vectors named low , and tin 
        vector<int>low(n,1000000);
        vector<int>tin(n,0);
        vector<int>parent(n,-1);
      
        vector<vector<int> > g(n);
        
        for(auto v : connections){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        parent[0]=0;
        vector<vector<int> >  ans;
        dfs(0,low,tin,parent,g,ans);
        
       
   
        
        return ans;
    }
};
