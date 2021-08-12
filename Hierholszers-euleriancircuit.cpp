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

int N, M, grau[100005], odd, tot;
vector< unordered_map<int,int> > V;
vector<int> resp;
stack<int> S;

void dfs(){
    S.push(1);
    while(!S.empty()){
        int X=S.top();
        if(V[X].size()){
            int Y=(V[X].begin()->first);
            V[Y].erase(X);
            V[X].erase(Y);
            S.push(Y);
        }
        else{
            resp.push_back(X);
            S.pop();
        }
    }
    return;
}

int main(){_
    cin>>N>>M;
    tot=M+1;
    V.resize(N+1);

    while(M--){
        int A, B;
        cin>>A>>B;
        V[A][B]=1;
        V[B][A]=1;
        grau[A]++;
        grau[B]++;
    }

    for(int i=1;i<=N;i++){
        if(grau[i]%2)
            odd++;
    }

    dfs();

    if(resp.size()==tot && resp[0]==1 && resp[tot-1]==1 && !odd){
        for(int i=tot-1;i>=0;i--)
            cout<<resp[i]<<' ';
        cout<<'\n';
    }
    else
        cout<<"IMPOSSIBLE"<<'\n';
    

    return 0;
}