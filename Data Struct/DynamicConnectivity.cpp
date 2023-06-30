// Conectividade Dinâmica
// O(nlogn) - Offline
// Tomar cuidado para adicionar as edges e tratar casos esquisitos
// devolve uma resposta para cada intervalo q[1...i], para i = 1,2,...,n
//

struct DSU{
    int n, ans;
    vi pai, qtd;
    stack<int> p;

    void build(int n1){
        ans=n=n1; pai.resize(n+2); qtd.resize(n+2);
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

    void rollback(){
        if(p.empty()) return ;
        int a=p.top(); p.pop();
        if(a==-1) return ;
        qtd[pai[a]]-=qtd[a];
        pai[a]=a, ans++;
    }
};

namespace DynamicConnectivity{
    vector<vector<ii>> q;
    DSU dsu;
    int n;

    void init(int n_,int tam_){
        n=n_; q.resize(4*n_+4); dsu.build(tam_);
    }

    void add(int id,int l,int r,int i,int j,ii val){
        if(i>j) return ;
        if(l==i && r==j){
            q[id].pb(val); return ;
        }

        int m = ((l+r)>>1);
        add(L(id),l,m,i,min(m,j),val);
        add(R(id),m+1,r,max(i,m+1),j,val);
    }

    void addQuery(ii val,int i,int j){
        add(1,1,n,i,j,val);
    }

    void dfs(int id,int l,int r,vi &ans){ // Percorro minha seg3
        for(auto& x : q[id]) dsu.join(x.f,x.s); // pego a resposta
		
		if(!l) return ;
        if(l>=r) ans[l-1] = dsu.ans;
        else{
            int m = ((l+r)>>1);
            dfs(L(id),l,m,ans);
            dfs(R(id),m+1,r,ans);
        }
        
        for(auto& x : q[id]) dsu.rollback(); // desfaço a resposta
    }

    vi solve(){ // função que resolve tudo
        vi ans(n,0); dfs(1,1,n,ans);
        return ans;
    }
};