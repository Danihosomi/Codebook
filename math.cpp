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

int prime[MAXN];

ll binpow(ll A,ll E){
    ll ans = 1;
    while(E){
        if(E&1) 
			ans=(ans*A)%mod;
        
		A=(A*A)%mod;
        E>>=1;
    }
    return ans;
}

ll mdc(ll A,ll B){
    if(B==0)
        return A;
    return mdc(B,A%B);
}

ll inv_mod(ll a,ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}

void number_factors_sieve(){
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

int main(){_


    return 0;
}