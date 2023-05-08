int nl, nr, m; // número de vértices
vi v[10005];
vi parL, parR, dist;

void bfs(){
    queue<int> q;

    for(int i=1;i<=nl;i++){
        if(!~parL[i]) q.push(i), dist[i]=0;
        else dist[i]=-1;
    }

    while(!q.empty()){
        int a=q.front(); q.pop();

        for(auto x : v[a]){
            if(~parR[x] && !~dist[parR[x]]){
                dist[parR[x]]=dist[a]+1;
                q.push(parR[x]);
            }
        }
    }

}

int dfs(int a){
    for(auto x : v[a]){
        if(!~parR[x]){
            parL[a]=x; parR[x]=a;
            return 1;
        }
    }

    for(auto x : v[a]){
        if(dist[parR[x]]==1+dist[a] && dfs(parR[x])){
            parL[a]=x; parR[x]=a;
            return 1;
        }
    }
    
    return 0;
}
// Para fazer minEdgeCover, basta adcionar o grafo reverso Nr->Nl e pegar todos os caras disjuntos (parL==-1 ou parR==-1)
// Lembrar de atualizar parR quando pegar parL

pair<vi,vi> minVertexCover(){ // Conjunto tal que para qualquer aresta do grafo, existe um vértice nesse conjunto que pertence a ela
    vi ansL, ansR;

    for(int i=1;i<=nl;i++){
        if(!~dist[i]) ansL.pb(i);
        else if(~parL[i]) ansR.pb(parL[i]);
    }

    return {ansL,ansR};
}

vector<ii> hopKarp(){
    int maxMatch=0, ok;
    vector<ii> ans;
    parL.assign(nl+2,-1); parR.assign(nr+2,-1); dist.resize(nl+2);

    while(true){
        ok=0;
        bfs();
        
        for(int i=1;i<=nl;i++)
            if(!~parL[i]) ok+=dfs(i);

        if(!ok) break;
        maxMatch+=ok;
    }

    for(int i=1;i<=nl;i++) 
        if(parL[i]!=-1) ans.pb({i,parL[i]});

    return ans;
}
