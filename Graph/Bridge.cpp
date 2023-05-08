int n, m, low[100005], tin[100005], timer;
vector<int> v[100005];
vector<ii> ans;

void dfs(int a,int pai){
    timer++; tin[a]=low[a]=timer;
    
    for(auto x : v[a]){
        if(x==pai) continue;
        if(tin[x]) low[a]=min(low[a],tin[x]);
        else{ 
            dfs(x,a); low[a]=min(low[a],low[x]);
            if(low[x]>tin[a]) ans.pb({min(a,x),max(a,x)});
        }
    }
}

void bridge(){
    for(int i=1;i<=n;i++)
        if(!tin[i]) dfs(i,i);
}
