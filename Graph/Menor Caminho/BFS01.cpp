void bfs01(int ini){
    for(int i=0;i<=n;i++) dist[i] = inf;
    deque<int> dq;
    dist[ini] = 0; dq.push_front(ini);
    
    while(!dq.empty()){
        int a = dq.front(); dq.pop_front();

        for(auto x : v[a]){
            if(dist[x.f] > x.s + dist[a]){
                dist[x.f] = x.s + dist[a];
                if(x.s) dq.push_back(x.f);
                else dq.push_front(x.f);
            }
        }
    }
}