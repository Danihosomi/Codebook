int N, M, tam, odd;
vi V[100005], E;
set< ii > S;
 
void dfs(int A){
    if(sz(V[A]))
        odd++;
 
    for(auto v : V[A]){
        if(S.count({max(A,v),min(v,A)})) continue;
        S.insert({max(A,v),min(A,v)});
        dfs(v);
    }
    E.push_back(A);
}
 
int main(){_
    cin>>N>>M;
    tam=M+1;
    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
 
    dfs(1);
    if(E[0]==1 && E[tam-1]==1 && !odd){
        for(int i=tam-1;i>=0;i--)
            cout<<E[i]<<' ';
        cout<<'\n';
    }
    else
        cout<<"IMPOSSIBLE"<<'\n';
 
	return 0;
}