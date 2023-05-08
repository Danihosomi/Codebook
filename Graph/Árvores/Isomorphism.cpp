struct tree{
    int n;
    vector<vi> v;
    vi tam, centroid;
    vector<ll> power, val;

    int findSize(int a,int p){ // Acha o tamanho dos sizes das Subtrees
        tam[a]=1;
        
        for(auto x : v[a]){
            if(x==p) continue;
            tam[a]+=findSize(x,a);
        }

        return tam[a];
    }

    int findCentroid(int a,int p,int tamS){ // Retorna o Centroid da Subtree de tamanho tamS

        for(auto x : v[a]){
            if(x==p) continue;
            if(tam[x]*2>tamS)
                return findCentroid(x,a,tamS);
        }

        return a;
    }

    void parCentroid(){
        findSize(1,1); int ans1=findCentroid(1,1,tam[1]), ans2=ans1;
        for (int x : v[ans1]) if (2*tam[x]==tam[1]) ans2 = x;
        centroid = {ans1,ans2};
    }

    void dfs(int a,int p){
        vector<ii> nodes;
        for(auto x : v[a]){
            if(x==p) continue;
            dfs(x,a); nodes.pb({val[x],x});
        } 
        
        val[a]=1; sort(all(nodes));
        for(auto x : nodes) val[a] = (((power[tam[x.s]+1]*val[a])%mod)+x.f)%mod;
        val[a]=(val[a]*2)%mod;
    }

    vector<ll> hash(int root){
        val.resize(n+1);
        tam.resize(n+1);
        findSize(root,root);
        dfs(root,root);
        return val;
    }

    bool solve(tree t1,int root1 = -1,int root2 = -1){

        tam.resize(n+1);
        t1.tam.resize(n+1);
        val.resize(n+1);
        t1.val.resize(n+1);

        if(root1==-1 || root2==-1){
            parCentroid();
            t1.parCentroid();

            for(auto x : centroid)
                for(auto y : t1.centroid)
                    if(solve(t1,x,y)) return 1;

            return 0;
        }
        
        findSize(root1,root1);
        t1.findSize(root2,root2);

        dfs(root1,root1);
        t1.dfs(root2,root2);

        return (val[root1]==t1.val[root2]);
    }

    void add(int a,int b){
        v[a].pb(b); v[b].pb(a);
    }

    tree(int x){
        tam.clear(); val.clear(); centroid.clear();
        v.resize(x+1); power.resize(x+1); power[0]=1; n=x;
        for(int i=1;i<=x;i++) power[i]=(2*power[i-1])%mod, v[i].clear();
    }
};
