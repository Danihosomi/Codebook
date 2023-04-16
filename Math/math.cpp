#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define MAXN (int)2e6
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);


ll binpow(ll a,ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans=(ans*a)%mod;
		a=(a*a)%mod; e>>=1;
    }
    return ans;
}

ll mdc(ll A,ll B){
    if(B==0)
        return A;
    return mdc(B,A%B);
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

int main(){_


    return 0;
}