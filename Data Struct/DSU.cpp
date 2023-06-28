// Com roll-back
// ans representa quantas componentes formam o grafo geral
// Complexidade (log(n))
namespace DSU{
    int n, ans, pai[200005], qtd[200005];
    stack<int> p;

    void build(int n1){
        ans=n=n1;
        for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
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

    void rollback(){
        int a=p.top(); p.pop();
        if(a==-1) return ;
        qtd[pai[a]]-=qtd[a];
        pai[a]=a, ans++;
    }
};

// DSU persistente
// ans representa quantas componentes formam o grafo geral
// Complexidade (log(n))
namespace DSU{
    int n, ans, pai[200005], qtd[200005];
    stack<int> p;
 
    void build(int n1){
        ans=n=n1;
        for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
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
};

// Sem rollback
// Complexidade de ackerman
namespace DSU{
    int n, pai[200005], qtd[200005];

    void build(int n1){
        n=n1; for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
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
};


//
// DSU para coisas bipartidas
//
namespace BipartiteDSU{
    int n, pai[200005], qtd[200005], len[200005];

    void build(int n1){
        n=n1; for(int i=0;i<=n+1;i++) pai[i]=i, qtd[i]=1;
    }

    ii acha(int x){
        if(x==pai[x]) return {x,0};
        auto prox = acha(pai[x]);
        pai[x] = prox.f;
        len[x] = (len[x]+prox.s)%2;
        return {pai[x],len[x]};
    }

    void join(int a,int b){
        auto proxa=acha(a), proxb=acha(b);
        if(proxa.f==proxb.f) return;
        if(qtd[proxa.f]<qtd[proxb.f]) swap(proxa,proxb);
        qtd[proxa.f]+=qtd[proxb.f]; pai[proxb.f]=proxa.f; len[proxb.f] = (1+proxa.s+proxb.s)%2;
    }
};