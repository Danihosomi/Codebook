#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define MAXN (int)2e5
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

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