ll dp[12][110][2];
vector<int> v;

void digit(ll x){
    if(x==0) v.pb(0);
    while(x){
        v.pb(x%10);
        x/=10;
    }
}

ll ans(int id,int sum,int t){
    if(id==-1) return sum;
    if(dp[id][sum][t]!=-1) return dp[id][sum][t];

    ll resp=0;
    if(t)
        for(int i=0;i<=9;i++) resp=(resp+ans(id-1,sum+i,1))%mod;
    
    else
        for(int i=0;i<=v[id];i++) resp=(resp+ans(id-1,sum+i,i!=v[id]))%mod;

    return dp[id][sum][t]=resp;
} 
