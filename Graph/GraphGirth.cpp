// Acha o tamanho do menor ciclo de um grafo
//
// Complexidade: O(n^2)
//

int n, m, vis[3005], pai[3005];
vi v[3005];

int findGirth(){
    queue<ii> q; int girth = inf;

    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis)); memset(pai,0,sizeof(pai));
        q.push({i,i}); vis[i]=1; pai[i]=i;

        while(!q.empty()){
            auto a = q.front(); q.pop();

            for(auto x : v[a.f]){
                if(x==a.s) continue;
                else{
                    if(!vis[x]) vis[x]=1+vis[a.f], pai[x]=a.f, q.push({x,a.f});
                    else{
                        int num1 = a.f, num2 = x, tam=1; 
                        while(num1!=num2){
                            tam++;
                            if(vis[num1]>vis[num2]) num1=pai[num1];
                            else num2=pai[num2];
                        }
                        girth=min(girth,tam);
                    }
                }
            }
        }
    }

    return girth;
}
