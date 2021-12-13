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
int N;
vector<int> V, P;
vector<int>::iterator it;

int main(){_
    cin>>N;

    for(int i=0;i<N;i++){
        int A; cin>>A;
        V.push_back(A);
    }

    for(int i=0;i<V.size();i++){
        it=lower_bound(P.begin(),P.end(),V[i]);

        if(it==P.end()) P.push_back(V[i]);
        else (*it)=V[i];
    }

    cout<<P.size()<<'\n';

    return 0;
}

