#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;

const ll mod = 1e9 + 7;


int n, k;
vi v[1001], vis, mt, used;

int try_kuhn(int x){
    if(vis[x]) return 0;
    vis[x]=1;

    for(auto a : v[x]){
        if(mt[a]==-1 || try_kuhn(mt[a])){
            mt[a]=x; return 1;
        }
    }

    return 0;
}

int main(){_

    mt.assign(k+2,-1);
    used.assign(n+2,0);
    for(int i=1;i<=n;i++){
        for(auto x : v[i]){
            if(mt[x]==-1){
                mt[x]=i;
                used[i]=1;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        vis.assign(n+2,0);
        try_kuhn(i);
    }

    for(int i=1;i<=k;i++){
        if(mt[i]!=-1)
            cout<<mt[i]<<' '<<i<<'\n';
    }

    return 0;
}