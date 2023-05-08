// MinCostMaxMatch - O(N^3)
// F Moratonistas

int n;
ll cost[505][505], m[505][505];
vi p, way;
vector<ll> u, v;

pair<ll,vector<ii>> hungaro(){
    u.assign(n+3,0); v.assign(n+3,0);
    p.assign(n+3,0); way.assign(n+3,0);

    for(int i=1;i<=n;i++){
        p[0]=i; int j0=0;
        vector<ll> minv(n+3,inf);
        vi used(n+3,0);

        do{
            used[j0]=1;
            int i0 = p[j0], j1 = -1;
            ll delta = inf;
            for (int j = 1; j <= n; j++){
                if (!used[j]) {
                    ll cur = cost[i0][j]-u[i0]-v[j];
                    
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }
            }

            for (int j = 0; j <= n; j++){
                if (used[j]) u[p[j]] += delta, v[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        
        }while(p[j0]!=0);

        do{
            int j1=way[j0];
            p[j0] = p[j1];
			j0 = j1;
        }while(j0);
    }

    vector<ii> ans;
    for(int i=1;i<=n;i++) ans.pb({p[i],i});
    return {-v[0],ans};
}
