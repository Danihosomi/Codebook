int N, M, ingrau[MAXN];
vi V[MAXN], ans;
queue<int> Q;

int main(){_
    cin>>N>>M;

    while(M--){
        int A, B; cin>>A>>B;
        V[A].eb(B);
        ingrau[B]++;
    }

    for(int i=0;i<N;i++){
        if(!ingrau[i]){
            Q.push(i);
            ans.eb(i);
        }
    }

    while(!Q.empty()){
        int X; X=Q.front(); Q.pop();
        for(auto v : V[X]){
            ingrau[v]--;
            if(!ingrau[v]){
                Q.push(v);
                ans.eb(v);
            }
        }
    }
    
    if(sz(ans)==N){
        printf("TEMOS DAG\n");
        for(auto a : ans)
            cout<<a<<' ';
        cout<<'\n';
    }
    else
        printf("NAO E DAG\n");

    return 0;
}