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
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);
 
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