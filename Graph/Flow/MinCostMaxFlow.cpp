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
#define inf (int)1e9 // Lembrar de atualizar inf caso necessario
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7; 

struct aresta{
    int to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
    bool res; // se eh reversa
    ll cost; // custo da unidade de fluxo

    aresta(int to_, int rev_, int flow_, int cap_, ll cost_, bool res_)
    : to(to_), rev(rev_), flow(flow_), cap(cap_), res(res_), cost(cost_) {}
};

int n, s, t;
vi dist, par, parId;
vector<aresta> v[505];
priority_queue<ii,vector<ii>,greater<ii>> p;

vi spfa(){
    deque<int> d;
    vi vis(n+2,0);
    for(int i=0;i<sz(dist);i++) dist[i]=inf;

    dist[s]=0; d.pb(s); vis[s]=1;

    while(!d.empty()){
        int a=d.front(); d.pop_front(); vis[a]=0;

        for(auto x : v[a]){
            if (x.flow<x.cap && dist[a]+x.cost<dist[x.to]) {
                dist[x.to]=dist[a]+x.cost;
                if (vis[x.to]) continue;

                if (!d.empty() && dist[x.to]>dist[d.front()]) d.push_back(x.to);
                else d.push_front(x.to);
                vis[x.to] = true;
            }
        }
    }

    return dist;
}

int dijkstra(vi& pot){
    for(int i=0;i<sz(dist);i++) dist[i]=inf;
    dist[s]=0; p.push({0,s});

    while(!p.empty()){
        int a=p.top().s, d=p.top().f; p.pop();

        if(d>dist[a]) continue;
        
        for (int i=0;i<sz(v[a]);i++){
            aresta x = v[a][i];
            x.cost+=pot[a]-pot[x.to];
            if (x.flow<x.cap && dist[a]+x.cost<dist[x.to]) {
                dist[x.to]=dist[a]+x.cost;
                p.push({dist[x.to],x.to});
                parId[x.to] = i, par[x.to]=a;
            }
        }
    }

    return dist[t]<inf;
}

ii minCostMaxFlow(int qtdFlow){ // Na vdd é min cost de um fluxo de no minimo qtdFlow caso queira maxFlow basta jogar qtdFlow=INF
    vector<int> pot(n+2,0);
    par.resize(n+2); parId.resize(n+2); dist.resize(n+2);
    pot = spfa(); // Posso trocar qual algoritmo de menor caminho eu quero (SPFA cost<0 e Dijkstra cost>0)
    
    int totf=0, totcost=0; 

    while(totf<qtdFlow && dijkstra(pot)){
        for(int i=1;i<=n;i++)
            if(dist[i]<inf) pot[i]+=dist[i];
        
        int mnFlow=qtdFlow-totf, aux=t;
        while(aux!=s){
            mnFlow=min(mnFlow,v[par[aux]][parId[aux]].cap-v[par[aux]][parId[aux]].flow);
            aux=par[aux];
        }

        totcost+=pot[t]*mnFlow;
        totf+=mnFlow; aux=t;
        
        while(aux!=s){
            v[par[aux]][parId[aux]].flow += mnFlow;
            v[aux][v[par[aux]][parId[aux]].rev].flow -= mnFlow;
            aux = par[aux];
        }
    }

    return {totf,totcost};
}

vector<ii> recover(){
    vector<ii> ans;
    for(int i=1;i<=n;i++)
        for(auto x : v[i])
            if(x.flow==x.cap && !x.res) ans.pb({i,x.to});

    return ans;
}

void add(int x,int y,int w,ll cost){
    aresta a = aresta(y,sz(v[y]),0,w,cost,false);
    aresta b = aresta(x,sz(v[x]),0,0,-cost,true);
    v[x].pb(a);
    v[y].pb(b);
}

int main(){_

    return 0;
}