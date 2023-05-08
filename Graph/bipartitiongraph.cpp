int N, M, vis[100005], ok;
vi V[100005];

void dfs(int A,int cor){
    vis[A]=cor;
    for(auto v : V[A]){
        if(vis[v]){
            if(vis[v]==cor)
                ok=0;
            continue;
        }
        if(cor==1)
            dfs(v,2);
        else
            dfs(v,1);
    }
}

int main(){_
    cin>>N>>M;
    
    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].eb(B);
        V[B].eb(A);
    }

    for(int i=1;i<=N;i++){
        if(!vis[i])
            dfs(i,1);
    }

    if(ok)
        cout<<"NAO BIPARTIDO"<<'\n';
    else
        cout<<"BIPARTIDO"<<'\n';
    
 
    return 0;
}