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
#define inf (ll) 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

struct aresta{
    int x, y;
    ll w;
};

int n, m, ini, fim;
ll dist[2505];
vector<aresta> v;

vi path(vi p){
    vi ans;
    if(dist[fim]==inf) return ans;

    for(int atual=fim;atual!=-1;atual=p[atual]) ans.pb(atual);
    reverse(all(ans));

    return ans;
}

void bellman(){
    vi p (n+5,-1);
    for(int i=1;i<=n;i++) dist[i]=inf;
    dist[ini]=0;

    while(true){
        int ok=0;
        for(auto a : v)
            if(dist[a.x]<inf && dist[a.y]>dist[a.x]+a.w){
                dist[a.y]=dist[a.x]+a.w; ok=1; p[a.y]=a.x;
            }  

        if(!ok) break;
    }

    path(p);
}

vi negativeCycle(){
    vi p(n+5,-1), ans;
    for(int i=1;i<=n;i++) dist[i]=inf;
    dist[ini]=0; int cycle=-1;

    for(int i=0;i<n;i++){
        cycle=-1;
        for(auto a : v)
            if(dist[a.x]<inf && dist[a.y]>dist[a.x]+a.w){ 
                dist[a.y]=max(-inf,dist[a.x]+a.w); p[a.y]=a.x; cycle=a.y;
            }  
    }
    
    if(cycle==-1) return ans;

    for(int i=0;i<n;i++) cycle=p[cycle];
    for(int atual=cycle;;atual=p[atual]){
        ans.pb(atual);
        if(atual==cycle && sz(ans)>1) break;
    }
    reverse(all(ans));

    return ans;
}

int main(){_

    int t = 1;
    //cin>>t;

    while(t--){

    }

    return 0;

}