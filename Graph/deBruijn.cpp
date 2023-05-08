int n;
unordered_set<string> vis;
string resp="01";
vi e;

ll binpow(ll a,ll e){
    ll ans = 1;
    while(e){
        if(e&1LL) ans=(ans*a)%mod;
		a=(a*a)%mod, e>>=1;
    }
    return ans;
}

void dfs(string a){
    for(int i=0;i<2;i++){
        string x = a+resp[i];
        if(!vis.count(x)){
            vis.insert(x); dfs(x.substr(1)); e.pb(i);    
        }
    }
}

string deBruijn(){
    string ans=""; string ini= string(n-1,resp[0]);
    
    dfs(ini);

    int tam=binpow(2,n);
    for(int i=0;i<tam;i++) ans+=resp[e[i]];
    ans+=ini;

    return ans;
}
