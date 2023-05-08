int n, vis[100005], pai[100005];
vi v[100005];
queue<int>q;

int bfs(int ini){
    for(int i=0;i<=n;i++) vis[i]=pai[i]=-1;
    
    q.push(ini); vis[ini]=0;
    while(!q.empty()){
        int a=q.front(); q.pop();
        for(auto x : v[a]){
            if(vis[x]!=-1)  continue;
            vis[x]=1+vis[a]; pai[x]=a;
            q.push(x);
        }
    }

    int maior=0, id=0;
    for(int i=1;i<=n;i++)
        if(maior<vis[i]) maior=vis[i], id=i;

    return id;
}

int centro(){
    int ans, x;
    x=ans=bfs(bfs(1));

    while(vis[ans]>vis[x]/2) ans=pai[ans];

    return ans;
}
