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
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

struct aresta{ // Representa uma aresta
    int a, b;
    ll cap, flow;
};

int N, M, S, T, cont; // S inicio e T final
vector<aresta> E; // Arestas
vi V[10005], level, ptr;
queue<int> Q;

int bfs(){
    while(!Q.empty()){
        int X=Q.front(); Q.pop();
        for(auto id : V[X]){
            if((E[id].cap-E[id].flow<1) || (level[E[id].b]!=-1)) continue;
            level[E[id].b]=level[X]+1;
            Q.push(E[id].b);
        }
    }
    return level[T]!=-1;
}

ll dfs(int X,ll push){
    if(!push || X==T)
        return push;

    for(int& i=ptr[X];i<sz(V[X]);i++){
        int id=V[X][i];
        int u=E[id].b;
        if((level[X]+1!=level[u]) || (E[id].cap-E[id].flow<1)) continue;
        ll tr=dfs(u,min(push,E[id].cap-E[id].flow));
        if(tr==0) continue;
        E[id].flow+=tr;
        E[id^1].flow-=tr;
        return tr;
    }

    return 0;
}

ll dinic(){
    ll ans=0;
    level.resize(N+2); ptr.resize(N+2);

    while(true){
        fill(all(level),-1);
        level[S]=0;
        Q.push(S);
        if(!bfs()) break;
        fill(all(ptr),0);
        while(ll push=dfs(S,(ll)1e18))
            ans+=push;
    }

    return ans;
}

int main(){_
    cin>>N>>M;
    S=1; T=N;

    while(M--){
        int A, B, C; cin>>A>>B>>C;
        E.push_back({A,B,C});
        E.push_back({B,A,0});
        V[A].eb(cont);
        V[B].eb(cont+1);
        cont+=2;
    }

    cout<<dinic()<<'\n';

    return 0;
}