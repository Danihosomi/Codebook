struct aresta{
        int x, y;
        ll w;
};

bool comp(aresta a,aresta b){
    return a.w<b.w;
}

namespace Kruskal{
    int n, pai[200005], qtd[200005];
    vector< aresta > e;

    void build(int n1){
        n=n1; for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
    }

    void add(aresta a){
        e.pb(a);
    }

    int acha(int x){
        return (x==pai[x] ? x : pai[x]=acha(pai[x]));
    }

    void join(int a,int b){
        a=acha(a); b=acha(b);
        if(a==b) return;
        if(qtd[a]<qtd[b]) swap(a,b);
        qtd[a]+=qtd[b]; pai[b]=a;
    }

    ll solve(){
        ll ans=0; sort(all(e),comp);
        for(auto a : e)
            if(acha(a.x)!=acha(a.y)){
                join(a.x,a.y); ans+=a.w;
            }
        

        return ans;
    }
};
