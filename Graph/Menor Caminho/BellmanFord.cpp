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
