int N, S, T, pai[1000];
ll capacity[1000][1000];
vi V[1000];

ll bfs(){
    memset(pai,-1,sizeof(pai));
    pai[S]=-2;
    queue<pair<int,ll>> Q;
    Q.push({S,INF});

    while(!Q.empty()){
        ll atual, flow, new_flow;
        atual=Q.front().f; flow=Q.front().s;
        Q.pop();
        for(auto v : V[atual]){
            if(pai[v]==-1 && capacity[atual][v]>0){
                pai[v]=atual;
                new_flow=min(flow,capacity[atual][v]);
                if(v==T)
                    return new_flow;
                Q.push({v,new_flow});
            }
        }
    }

    return 0;
}

ll edmonkarp(){
    ll ans=0, new_flow;
    while(new_flow=bfs()){
        int atual=T, ant;
        ans+=new_flow;
        while(atual!=S){
            ant=pai[atual];
            capacity[ant][atual]-=new_flow;
            capacity[atual][ant]+=new_flow;
            atual=ant;
        }
    }
    return ans;
}
