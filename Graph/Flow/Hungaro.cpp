#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

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

int main(){_


    return 0;

}