// O(n*log(n))
// responde query offline
// DSU on tree - maluquisse

int n, tam[200005], cnt[200005], cor[200005];
vi v[200005], g[200005];

void root(int a,int p=1){
    for(auto x : v[a]){
        if(x==p) continue;
        g[a].pb(x);
        root(x,a);
    }
}

void build(int a){
    tam[a]=1;
    for(auto &x : g[a]){
        build(x); tam[a]+=tam[x];
        if(tam[x]>tam[g[a][0]]) swap(x,g[a][0]);
    }
}

void join(int a,int num,int dont){
    cnt[cor[a]]+=num;
    
    for(int i=dont;i<sz(g[a]);i++) join(g[a][i],num,0);
}

void solve(int a,int keep=0){
    for(int i=sz(g[a])-1;i>=0;i--) solve(g[a][i],!i);
    join(a,1,1);
    
    // Nesse ponto o vetor cnt conta quantas vértices de cada cor existem na subtree de a

    if(!keep) join(a,-1,0);
}