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
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N;
vi V;

ll inv(vi &V1){
    if(sz(V1)==1)
        return 0;

    int ini1=0, ini2=0;
    ll cont=0;
    vi A, B;
    
    for(int i=0;i<sz(V1)/2;i++)
        A.eb(V1[i]);
    
    for(int i=sz(V1)/2;i<sz(V1);i++)
        B.eb(V1[i]);

    cont+=inv(A);
    cont+=inv(B);
    A.eb(INF);
    B.eb(INF);

    for(int i=0;i<sz(V1);i++){
        if(A[ini1]>B[ini2]){
            V[i]=B[ini2];
            ini2++;
            cont+=A.size()-ini1-1;
        }
        else{
            V1[i]=A[ini1];
            ini1++;
        }
    }
    
    return cont;
}

int main(){_
    cin>>N;

    for(int i=1;i<=N;i++){
        int A; cin>>A;
        V.eb(A);
    }

    cout<<inv(V)<<'\n';

    return 0;
}