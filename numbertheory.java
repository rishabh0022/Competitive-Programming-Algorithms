// function to calculate (a^b)%m in log b time 
    public static long binpow(long a, long b, long mod){
        if(b==0){
            return 1L;
        }
        if(b==1){
            return a%mod;
        }
        if(b%2==0){
            long ans= (binpow(a,b/2,mod)*binpow(a,b/2,mod))%mod;
            return ans;
        }
        long ans=(((binpow(a,(b-1)/2,mod)*binpow(a,(b-1)/2,mod))%mod)*(a%mod))%mod;
        return ans;
    }
