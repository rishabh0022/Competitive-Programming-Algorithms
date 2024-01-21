     int n;
     cin>>n;
     vector<int>a(n);
      int i;
      for(i=0;i<n;i++)cin>>a[i];
      vector<int>dp(n,INF);
      // dp[i] -> denotes the smallest element at which length of lis i+1 ends at 
      dp[0]=a[0];
      for(i=0;i<n;i++){
          // find the largest  y such that dp[y]<a[i]
          // or find the smallest y such that dp[y]>=a[i]
          int low=0;
          int high=(i);
          if(dp[low]>=a[i]){
            dp[low]=a[i];
          }
          else{
            while(high-low>1){
              int mid= (high + low)/2;
              if(dp[mid]>=a[i]){
                high=mid;
              }
              else low= mid;
            }
            dp[high]=a[i];
          }
 
      }
      int ans=1;
      for(i=0;i<n;i++){
        if(dp[i]!=INF){
          ans= i+1;
        }
      }
      cout<<ans<<'\n';
 
     }
