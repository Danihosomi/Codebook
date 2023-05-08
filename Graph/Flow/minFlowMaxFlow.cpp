// Ta td cagado
struct aresta{ // Representa uma aresta
    int a, b;
    ll cap, flow;
};

int n, m, S, T, cont, dist[10005]; // S inicio e T final
vector<aresta> e; // Arestas
vi v[10005], level, ptr;

int bfs(){
    queue<int> q; fill(all(level),-1); level[S]=0; q.push(S);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto id : v[x]){
            if((e[id].cap-e[id].flow<1) || (level[e[id].b]!=-1)) continue;
            level[e[id].b]=level[x]+1; q.push(e[id].b);
        }
    }
    return level[T]!=-1;
}

ll dfs(int x,ll push){
    if(!push || x==T) return push;

    for(int i=ptr[x];i<sz(v[x]);i++){
        int id=v[x][i], u=e[id].b;
        if((level[x]+1!=level[u]) || (e[id].cap-e[id].flow<1)) continue;

        ll tr=dfs(u,min(push,e[id].cap-e[id].flow)); if(tr==0) continue;
        e[id].flow+=tr; e[id^1].flow-=tr;
        return tr;
    }

    return 0;
}

ll dinic(int ini,int fim){
    S=ini; T=fim; ll ans=0; level.resize(n+2); ptr.resize(n+2);

    while(true){
        if(!bfs()) break;
        fill(all(ptr),0); while(ll push=dfs(S,(ll)1e18)) ans+=push;
    }

    return ans;
}

void add(int a,int b,ll maxcap){
    e.pb({a,b,maxcap}); e.pb({b,a,0});
    v[a].pb(cont); v[b].pb(cont+1);
    cont+=2; 
}

void addEdge(int a,int b,ll mincap,ll maxcap){
    dist[a]-=mincap; dist[b]+=mincap;
    e.pb({a,b,maxcap}); e.pb({b,a,0});
    v[a].pb(cont); v[b].pb(cont+1);
    cont+=2; 
}

int hasCirc(){
    ll cost=0;

    for(int i=1;i<=n;i++){
        if(dist[i]>0) cost+=dist[i], add(n+1,n,-dist[i]);;
        else add(i,n+1,-dist[i]);
    }

}

int hasFlow(int ini,int fim){
    add(fim,ini,inf); return hasCirc();
}

ll maxFlox(int ini,int fim){
    if(!hasFlow(ini,fim)) return -1;
    return dinic(ini,fim);
}
