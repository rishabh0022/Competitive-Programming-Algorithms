do {
  // do whatever you want to do with the permutation here 
      int s=0;
      int maxi=-INF;
        for (i=0;i<n;i++) {
            s=s+v[i]*(i+1);
            maxi=max(v[i]*(i+1),maxi);
        }
        if(ans<s-maxi){
            for(i=0;i<n;i++){
              ans1[i]=v[i];
            }
            ans=s-maxi;
        }
        
    } while (next_permutation(v.begin(), v.end()));
