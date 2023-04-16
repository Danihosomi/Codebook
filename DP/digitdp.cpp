#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
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

int main(){_


    return 0;
}