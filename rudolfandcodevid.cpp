#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int give_numericval(string s, int n){
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans=ans+(1<<(n-i-1));
        }
    }
    return ans;
}
int main(){
    int tt;
    cin>>tt;
    while(tt-->0){
        int n;
        int m;
        cin>>n>>m;
        string source;
        cin>>source;
        vector<vector<pair<long long int ,long long int> > > g((1<<n) +1);// g[i] will store{node_neighbour _to_i,wt of this node}
        vector<bool> vis((1<<n)+1,0);
        queue<long long int>q ;
        vector<vector<int > > med(m);// med[i] contains {recovery string,sideeffect string, days for recovery}
        int i;
        int d;
        for(i=0;i<m;i++){
            cin>>d;
            string recov;
            string sideff;
            cin>>recov>>sideff;
            med[i].push_back(give_numericval(recov,n));
            med[i].push_back(give_numericval(sideff,n));
            med[i].push_back(d);
        }
        pair<int, int> p;  
        long long int x;
            for(x=0;x<=(1<<n);x++){
                for(int i=0;i<m;i++){
                    p.first=((x&(~med[i][0]))|med[i][1]);// p.first contains node
                    p.second=med[i][2];//p.second contains the weight from the node x to p.first node
                    g[x].push_back(p); 
                }
            }
        //dijkstra
        int INF=1000000000;
        vector<int> dist((1<<n)+1,INF);
        int source_numerical=give_numericval(source,n);
        dist[source_numerical]=0;
        priority_queue<pair<int,int> , vector<pair<int, int > >,greater<pair<int,int> > >pq;// stores {dist,node}
        p.first=0;// intializing source distance =0
        p.second=source_numerical;
        pq.push(p);
        int j;
        pair<int,int>p2;
        while(!pq.empty()){
               p=pq.top();
               pq.pop();
               int curr_node=p.second;
               int sz_of_adj_currnode=g[curr_node].size();
               for(j=0;j<sz_of_adj_currnode;j++){
                      p2=g[curr_node][j];
                      int wt=p2.second;
                      int neighbour=p2.first;
                      if(dist[curr_node]+wt<dist[neighbour]){
                        dist[neighbour]=dist[curr_node]+wt;
                        p2.first=dist[neighbour];
                        p2.second=neighbour;
                        pq.push(p2);
                      }
               }
        }
        if(dist[0]==INF){
            cout<<-1<<'\n';
        }
        else{
            cout<<dist[0]<<'\n';
        }

        
    }
}