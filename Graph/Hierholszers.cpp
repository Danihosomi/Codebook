int n, m, vis[100005], in[100005], out[100005];
vector<unordered_map<int,int>> v;
stack<int> p;
 
void dfs(int a){
    vis[a]=1;
    for(auto x : v[a]){
        if(vis[x.f]) continue;
        dfs(x.f);
    }
}
 
vi Hierholszers(int ini){
    vi ans; dfs(ini);
    
    int qtd=0;
    for(int i=1;i<=n;i++){  // Prestar atenção para as condições do Euler Path/ Euler Circuit e ajeitar a preferencia
        qtd += abs(in[i]-out[i]);
        if(qtd>2 || (!vis[i] && in[i]+out[i])) return ans;
    }

    p.push(ini);
    
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
    
    reverse(all(ans));
    return ans;
}
