int n, m, low[100005], tin[100005], timer, check[100005];
vector<int> v[100005], ans;

void dfs(int a,int pai){
    int qtd=0;
    timer++; tin[a]=low[a]=timer;
    
    for(auto x : v[a]){
        if(x==pai) continue;
        if(tin[x]) low[a]=min(low[a],tin[x]);
        else{
            dfs(x,a), qtd++;
            low[a]=min(low[a],low[x]);
            if(low[x]>=tin[a] && a!=pai && !check[a]) ans.pb(a), check[a]=1;
        }
    }

    if(a==pai && qtd>1 && !check[a]) ans.pb(a), check[a]=1;
}

void artPoint(){
    for(int i=1;i<=n;i++)
        if(!tin[i]) dfs(i,i);
}
