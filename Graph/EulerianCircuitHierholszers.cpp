int n, m, vis[500005];
vector<unordered_map<int,int>> v;
stack<int> p;
 
void dfs(int a){
    vis[a]=1;
    for(auto x : v[a]){
        if(vis[x.f]) continue;
        dfs(x.f);
    }
}
 
vi UndirectEulerCircuit(){
    vi ans; dfs(1);
 
    for(int i=1;i<=n;i++) if(sz(v[i])%2 || (!vis[i] && sz(v[i]))) return ans;
 
    p.push(1);
    
    while(!p.empty()){
        int atual = p.top();
        if(sz(v[atual])){
            int prox = v[atual].begin()->first;
            v[atual].erase(prox);
            v[prox].erase(atual); // this part makes the for undirected graph
            p.push(prox);
        }
        else{
            ans.pb(atual);
            p.pop();
        }
    }
 
    return ans;
}
