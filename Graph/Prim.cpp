// Algoritmo de Prim para MST
// Não sei pq coloquei
// Totalmente inutil
// Mesma complexidade do Kruskal
//

namespace Prim{
    int n;
    vi vis;
    vector<vector<pair<int,ll>>> v;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> p;

    void init(int n1){
        n = n1;  v.assign(n1+1,{}); vis.assign(n+1,0);
    }

    void add(int a,int b,ll c){
        v[a].pb({b,c}); v[b].pb({a,c});
    }

    pair<ll,int> solve(int ini){
        ll ans = 0; int qtd=n;
        p.push({0,ini});

        while(!p.empty()){
            auto a = p.top(); p.pop();
            if(vis[a.s]) continue;
            ans+=a.f; vis[a.s]=1; qtd--;

            for(auto x : v[a.s]){
                if(vis[x.f]) continue;
                p.push({x.s,x.f});
            }
        }

        return {ans,qtd};
    }
};