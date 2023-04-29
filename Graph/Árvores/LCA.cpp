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
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);


int n, tin[100005], tout[100005], timer, up[22][100005], dist[100005];
vi v[100005];

void dfs(int a,int p){
    timer++; tin[a]=timer; up[0][a]=p; dist[a]=1+dist[p];
    for(int i=1;i<22;i++) up[i][a]=up[i-1][up[i-1][a]];

    for(auto x : v[a]){
        if(x==p) continue;
        dfs(x,a);
    }

    timer++; tout[a]=timer;
}

int anc(int a,int b){
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}

int lca(int a,int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=21;i>=0;i--)
        if(!anc(up[i][a],b)) a=up[i][a];

    return up[0][a];
}

int upK(int a,int b){
    for(int i=21;i>=0;i--)
        if(b>=(1<<i)) b-=(1<<i), a=up[i][a];

    return a;
}

int main(){_

    return 0;
}