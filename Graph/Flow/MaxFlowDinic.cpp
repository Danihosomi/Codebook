#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb push_back
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

int n, m, S, T, cont, vis[10005]; // S inicio e T final
vector<aresta> e; // Arestas
vi v[10005], level, ptr;
queue<int> q;

int bfs(){
    while(!q.empty()){
        int X=q.front(); q.pop();
        for(auto id : v[X]){
            if((e[id].cap-e[id].flow<1) || (level[e[id].b]!=-1)) continue;
            level[e[id].b]=level[X]+1;
            q.push(e[id].b);
        }
    }
    return level[T]!=-1;
}

ll dfs(int x,ll push){
    if(!push || x==T)
        return push;

    for(int& i=ptr[x];i<sz(v[x]);i++){
        int id=v[x][i];
        int u=e[id].b;
        if((level[x]+1!=level[u]) || (e[id].cap-e[id].flow<1)) continue;
        ll tr=dfs(u,min(push,e[id].cap-e[id].flow));
        if(tr==0) continue;
        e[id].flow+=tr;
        e[id^1].flow-=tr;
        return tr;
    }

    return 0;
}

ll dinic(){
    ll ans=0;
    level.resize(n+2); ptr.resize(n+2);

    while(true){
        fill(all(level),-1);
        level[S]=0;
        q.push(S);
        if(!bfs()) break;
        fill(all(ptr),0);
        while(ll push=dfs(S,(ll)1e18))
            ans+=push;
    }

    return ans;
}

void addEdge(int a,int b,ll capa){
    e.pb({a,b,capa});
    e.pb({b,a,0});
    v[a].pb(cont);
    v[b].pb(cont+1);
    cont+=2; 
}

vector<pair<int, int>> get_cut() {
	vector<pair<int, int>> cut;
	vector<int> st = {S};
	vis[S] = 1;
	while (st.size()) {
		int u = st.back(); st.pop_back();
		for (auto x : v[u]){ 
            aresta k=e[x];
            if (!vis[k.b] && k.flow < k.cap) vis[k.b] = 1, st.push_back(k.b);
        }
    }
	for (int i = 1; i <=n; i++) 
        for (auto x : v[i]){ 
            aresta k=e[x];
            if (vis[i] && !vis[k.b] && !(x%2)) cut.emplace_back(i, k.b);
        }
    
	return cut;
}

int main(){_
    S=1; T=n;

    return 0;
}