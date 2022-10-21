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

struct aresta{
    int x, y, capa, cost;
};

int n, dist[1005][1005], tot[1005][1005], ini, fim;
vi v[1005];
vector<aresta> ares;

void spfa(int ini,vi &d,vi &p){
    d.assign(n+5,inf); d[ini]=0;
    p.assign(n+5,-1);
    vi aux(n,0);
    queue<int> q; q.push(ini);

    while(!q.empty()){
        int u=q.front(); q.pop();
        aux[u]=0;
        for(auto a : v[u]){
            if(tot[u][a]>0 && d[a]>d[u]+dist[u][a]){
                d[a]=d[u]+dist[u][a]; p[a]=u;
                if(!aux[a]){
                    aux[a]=1;
                    q.push(a);
                }
            }
        }
    }
}

int minCostMaxFlow(int qtdFlow){ // Na vdd é min cost de um fluxo de no minimo qtdFlow caso queira maxFlow basta jogar qtdFlow=INF
    for(auto e : ares){
        v[e.x].pb(e.y);
        v[e.y].pb(e.x);
        dist[e.x][e.y]=e.cost;
        dist[e.y][e.x]=-e.cost;
        tot[e.x][e.y]=e.capa;
    }
    ll ans=0; int flow=0;

    vi d, p;
    while(flow<qtdFlow){
        spfa(ini,d,p);
        if(d[fim]==inf) break;

        int atual=fim, flowAtual=qtdFlow-flow;
        while(atual!=ini){
            flowAtual=min(flowAtual,tot[p[atual]][atual]);
            atual=p[atual];
        }

        flow+=flowAtual; ans+=flowAtual*d[fim]; atual=fim;
        while(atual!=ini){
            tot[p[atual]][atual]-=flowAtual;
            tot[atual][p[atual]]+=flowAtual;
            atual=p[atual];
        }
    }

    return (flow<qtdFlow ? -1 : ans);
}

int main(){_

    return 0;
}