/*
Algoritmo de Kuhn ultra hiper rapidao
Tao forte quanto Hopcroft-Karp, apesar da complexidade desse ser em teoria menor
*/

int nl, nr;
vi v[1001], vis, ml, mr;

int dfs(int x){
    vis[x]=1;

    for(auto a : v[x]){
        if(!vis[a+nl]){
            vis[a+nl]=1;
            if(mr[a]==-1 || dfs(mr[a])){
                ml[x]=a; mr[a]=x; return 1;
            }
        }
    }

    return 0;
}

pair<vi,vi> minVertexCover(){
    vi minL, minR;

    for(int i=1;i<=nl+nr;i++) vis[i]=0;
    for(int i=1;i<=nl;i++) 
        if(ml[i]==-1) dfs(i);

    for(int i=1;i<=nl;i++) if(!vis[i]) minL.pb(i);
    for(int i=1;i<=nr;i++) if(vis[i+nl]) minR.pb(i);

    return {minL,minR};
}

vector<ii> kuhn(){
    vector<ii> ans; int ok=1;
    vis.resize(nl+nr+5);
    ml.assign(nl+2,-1); mr.assign(nr+2,-1);

    while(ok){
        ok=0;
        for(int i=1;i<=nr;i++) vis[nl+i]=0;
        for(int i=1;i<=nl;i++)
            if(ml[i]==-1 && dfs(i)) ok=1;
    }

    for(int i=1;i<=nl;i++)
        if(ml[i]!=-1) ans.pb({i,ml[i]});

    return ans;
}
