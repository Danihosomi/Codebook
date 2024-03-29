// Miller Rabin de complexidade ~ log(n)
// 0 -> Composto
// 1 -> Primo
// Vai até 2^64

ll mul(ll a, ll b, ll MOD) {
	ll ret = a*b - (ll)((long double)1/MOD*a*b+0.5)*MOD;
	return ret < 0 ? ret+MOD : ret;
}

ll binpow(ll a,ll e,ll MOD){
    ll ans = 1;
    while(e){
        if(e&1) ans=mul(ans,a,MOD);
		a=mul(a,a,MOD); e/=2LL;
    }
    return ans;
} 

bool testP(ll x){
    if(x<2) return 0;
    if(x<=3) return 1;
    if(x%2==0) return 0;

    ll r = __builtin_ctzll(x - 1); ll d = (x>>r);
    for (ll p : {2, 325, 9375, 28178, 450775, 9780504, 795265022}){
        ll y = binpow(p,d,x);
        if(y==1 || y==x-1 || p%x==0) continue;

        for(int i=0;i<r-1;i++){
            y=mul(y,y,x);
            if(y==x-1) break;
        }
        
        if(y!=x-1) return 0;
    }

    return 1;
}

