ll binpow(ll a,ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans=(ans*a)%mod;
		a=(a*a)%mod; e>>=1;
    }
    return ans;
}

int gcdExtended(int a,int b,int& x,int& y){
    if(!a){
        x=0; y=1;
        return b;
    }

    int x1, y1;
    int gcd=gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1; y=x1;

    return gcd;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) { // for Ax + By = C
    g = gcdExtended(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

ll inv_mod(ll a,ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}

void number_factors_sieve(){
    int prime[MAXN];
    for(int i=2;i<=(int)2e6;i++){
        if(!prime[i]){
            for(int j=2;j*i<=(int)2e6;j++){
                for(int k=2;k<=30;k++){
                    if((i*j)%binpow(i,k)){
                        if(!prime[i*j])
                            prime[i*j]=k;
                        else
                            prime[i*j]*=k;
                        break;
                    }
                }
            }
        }
    }
}

ll binomial(ll x,ll k) {
    double res=1;
    for(int i=1;i<=k;i++) res=(res*(x-k+i))/i;
    return (ll)(res+0.01);
}

ll sum(ll X){// Soma de 1 até N
    return ((((X%mod)*((X+1)%mod))%mod)*inv_mod(2,mod))%mod;
}

ll sum_of_divisors_from1_toN(ll N){

    ll l=1, r, k, ans=0;
    while(l<=N){
        k=N/l; r=N/k; k%=mod;
        ans=(ans+(((sum(r)-sum(l-1)+mod)%mod+mod)*k)%mod)%mod;
        l=r+1;
    }
    
    return ans;
}

struct Congruence {
    ll a, m;
};

ll CRT(vector<Congruence> congruences) {
    ll M = 1;

    for (auto congruence : congruences)  M *= congruence.m;

    ll solution = 0;
    for (auto congruence : congruences) {
        ll M_i = M / congruence.m;
        ll N_i = inv_mod(M_i, congruence.m);
        solution = (solution + ((congruence.a * M_i) % M)*N_i)%M;
    }
    return solution;
}