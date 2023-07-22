// Código adaptado da UFMG
// Pode ser adaptado para outras estruturas que possuem rollback
// O(m*sqrt(q)logn)
//
// Exemplo abaixo é utilizando DSU - acha quantidade de componentes com arestas de [l,r]

struct DSU{
    int n, ans;
    vi pai, qtd;
    stack<int> p;
 
    DSU(int n1){
        ans=n=n1; pai.resize(n+1); qtd.resize(n+1);
        for(int i=0;i<=n;i++) pai[i]=i, qtd[i]=1;
    }
 
    int acha(int x){
        while(x!=pai[x]) x=pai[x];
        return x;
    }
 
    void join(int a,int b){
        a=acha(a); b=acha(b);
        if(a==b) return p.push(-1);
        ans--; if(qtd[a]<qtd[b]) swap(a,b);
        p.push(b); qtd[a]+=qtd[b]; pai[b]=a;
    }
 
    void persist(){
        p.push(-2);
    }
 
    void rollback(){
        while(p.top()!=-2){
            int a=p.top(); p.pop();
            if(a==-1) continue ;
            qtd[pai[a]]-=qtd[a];
            pai[a]=a, ans++;
        } p.pop();
    }

    int query(){
        return ans;
    }
};

int len; // len = sqrt(n+.0)+1;

struct Query{
    int l, r, id;
    int operator<(Query other) const{
        return make_pair(l/len,r)<make_pair(other.l/len,other.r);
    }
};

int n, m, q; 
vector<ii> e;
vector<Query> query; // Offline, sem update, depende de outra estrutura de dados

vi resposta(){
    DSU menor(n); DSU maior(n); 
    len = sqrt(sz(query)+.0)+1;
    vi ans(sz(query)); sort(all(query)); 

    for(auto x : query){
        if(x.l/len==x.r/len){ 
            menor.persist();
            for(int j=x.l;j<=x.r;j++) menor.join(e[j].f,e[j].s);
            ans[x.id] = menor.query();
            menor.rollback();
        }
    }

    for(int i=0;i<sz(query);i++){
        auto x = query[i]; 
        if(x.l/len==x.r/len) continue;
        
        int lsqrt = (x.l/len+1)*len-1, antr = (x.l/len+1)*len-1, j = i-1;
        maior.persist();

        while(j+1<sz(query) && query[j+1].l/len==x.l/len){
            auto y = query[++j];
            if(y.l/len==y.r/len) continue;

            while(antr<y.r){ 
                antr++; maior.join(e[antr].f,e[antr].s);
            }

            maior.persist();
            
            for(int k=y.l;k<=min(lsqrt,sz(e)-1);k++) maior.join(e[k].f,e[k].s);
            ans[y.id] = maior.query();
            maior.rollback();
        } i=j; maior.rollback();
    }    

    return ans;
}
