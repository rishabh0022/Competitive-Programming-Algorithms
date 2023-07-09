//dijkstra
        int INF=1000000000;
        vector<int> dist((1<<n)+1,INF);
        dist[source]=0;
        priority_queue<pair<int,int> , vector<pair<int, int > >,greater<pair<int,int> > >pq;// stores {dist,node}
        p.first=0;// intializing source distance =0
        p.second=source;
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
 
