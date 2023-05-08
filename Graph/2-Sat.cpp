int n, m, used[200005], vis[100005], comp[200005];
vi v[200005], rv[200005], ord;

void dfs1(int a){
    used[a]=1;
    for(auto x : v[a]) if(!used[x]) dfs1(x);
    ord.pb(a);
}

void dfs2(int a,int c){
    comp[a]=c;
    for(auto x : rv[a]) if(!comp[x]) dfs2(x,c);
}

int ans2Sat(){
    ord.clear();
    for(int i=1;i<=2*n;i++) if(!used[i]) dfs1(i);
    
    for(int i=0,j=1;i<2*n;i++){
        int x=ord[2*n-i-1];
        if(!comp[x]) dfs2(x,j++);
    }

    for(int i=1;i<=n;i++){
        if(comp[i]==comp[i+n]) return 0;
        vis[i]=(comp[i]>comp[i+n]);
    }

    return 1;
}

void addAresta(bool posa,int a,bool posb,int b){
    int nega=(posa ? a+n : a);
    int negb=(posb ? b+n : b);
    a=(nega>n ? a : a+n); b=(negb>n ? b : b+n);

    v[nega].pb(b);
    v[negb].pb(a);
    rv[b].pb(nega);
    rv[a].pb(negb);
}
