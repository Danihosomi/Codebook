struct aresta{ // Representa uma aresta
    int a, b;
    ll cap, flow;
};

int n, m, S, T, cont; // S inicio e T final
vector<aresta> e; // Arestas
vi v[5015], level, ptr;

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

    for(int &i=ptr[x];i<sz(v[x]);i++){
        int id=v[x][i], u=e[id].b;
        if((level[x]+1!=level[u]) || (e[id].cap-e[id].flow<1)) continue;

        ll tr=dfs(u,min(push,e[id].cap-e[id].flow)); if(tr<=0) continue;
        e[id].flow+=tr; e[id^1].flow-=tr;
        return tr;
    }

    return 0;
}

ll dinic(int ini,int fim){
    S=ini; T=fim; ll ans=0; level.resize(n+1); ptr.resize(n+1);

    while(bfs()){
        fill(all(ptr),0); while(ll push=dfs(S,(ll)1e17)) ans+=push;
    }

    return ans;
}

void addEdge(int a,int b,ll capa){
    e.pb({a,b,capa}); e.pb({b,a,0}); // Se for biderecional cap(b,a)= capa
    v[a].pb(cont); v[b].pb(cont+1);
    cont+=2; 
}
// Min Vertex Cut - basta criar 2 vértices, um de entrada e outro de saida para cada vértice
// Após isso basta rodar o mincut
vector<pair<int, int>> getCut() { // Min-Cut Edge
	vector<pair<int, int>> cut;
	vector<int> st = {S}, vis(n+2,0);
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
