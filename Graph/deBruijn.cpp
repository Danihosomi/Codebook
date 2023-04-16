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
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n;
unordered_set<string> vis;
string resp="01";
vi e;

ll binpow(ll a,ll e){
    ll ans = 1;
    while(e){
        if(e&1LL) ans=(ans*a)%mod;
		a=(a*a)%mod, e>>=1;
    }
    return ans;
}

void dfs(string a){
    for(int i=0;i<2;i++){
        string x = a+resp[i];
        if(!vis.count(x)){
            vis.insert(x); dfs(x.substr(1)); e.pb(i);    
        }
    }
}

string deBruijn(){
    string ans=""; string ini= string(n-1,resp[0]);
    
    dfs(ini);

    int tam=binpow(2,n);
    for(int i=0;i<tam;i++) ans+=resp[e[i]];
    ans+=ini;

    return ans;
}

int main(){_

    return 0;
}