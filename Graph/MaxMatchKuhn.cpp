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
#define INF (int)1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, K;
vi V[1001], vis, mt, used;

int try_kuhn(int X){
    if(vis[X]) return 0;
    vis[X]=1;

    for(auto v : V[X]){
        if(mt[v]==-1 || try_kuhn(mt[v])){
            mt[v]=X; return 1;
        }
    }

    return 0;
}

int main(){_

    mt.assign(K+2,-1);
    used.assign(N+2,0);
    for(int i=1;i<=N;i++){
        for(auto v : V[i]){
            if(mt[v]==-1){
                mt[v]=i;
                used[v]=1;
                true;
            }
        }
    }

    for(int i=1;i<=N;i++){
        if(used[i]) continue;
        vis.assign(N+2,0);
        try_kuhn(i);
    }

    for(int i=1;i<=K;i++){
        if(mt[i]!=-1)
            cout<<mt[i]<<' '<<i<<'\n';
    }

    return 0;
}