int n, m, vis[200005], qtd;
vi v[200005], rv[200005], g[200005], o;
vector<ii> e;

void dfs1(int a){
    vis[a]=1;
    for(auto x : v[a]){
        if(vis[x]) continue;
        dfs1(x);
    }
    o.pb(a);
}

void dfs2(int a){
    vis[a]=qtd;
    for(auto x : rv[a]){
        if(vis[x]) continue;
        dfs2(x);
    }
}

void kosaraju(){
    for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i);
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=sz(o)-1;i>=0;i--) if(!vis[o[i]]){ qtd++; dfs2(o[i]); }

    for(auto x : e)
        if(vis[x.f]!=vis[x.s]) g[vis[x.f]].pb(vis[x.s]);
}

void entrada(){
    for(int i=1;i<=m;i++){
        int a, b; cin>>a>>b;
        v[a].pb(b); rv[b].pb(a); e.pb({a,b});
    }
}
