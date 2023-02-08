#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

// PollardRho de complexidade ~ (log(n)*n^(1/4))
// Fatora os número

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

ll rho(ll N){
    if(N==1 || testP(N)) return N;
    auto F = [N](ll x) {return mul(x,x,N)+1;};

    ll x=0, y=0, T=30, prod=2, Q, X=1;

    while(T%40 || __gcd<ll>(prod,N)==1){
        if(x==y) x=++X, y=F(x);
        Q=mul(prod,abs(x-y),N);
        if(Q) prod=Q;
        x=F(x), y=F(F(y)),T++;
    }

    return __gcd<ll>(prod,N);
}

vector<ll> factors(ll N){
    if(N==1) return {};
    if(testP(N)) return {N};

    ll d = rho(N);
    vector<ll> ansl = factors(d), ansr = factors(N/d);
    ansl.insert(ansl.end(),all(ansr));
    return ansl;
}


int main(){_



    return 0;
}