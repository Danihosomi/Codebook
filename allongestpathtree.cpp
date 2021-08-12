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

int N, in[200005], out[200005];
vi V[200005];

void dfs1(int A,int B){
    for(int i : V[A]){
        if(i==B) continue;
        dfs1(i,A);
        in[A]=max(in[A],1+in[i]);
    }
}

void dfs2(int A,int B){
    int max1, max2;
    max1=max2=-1;

   for(int i : V[A]){
        if(i==B) continue;
        if(in[i]>=max1){
            max2=max1;
            max1=in[i];
        }
        else if(in[i]>max2)
            max2=in[i];
    }

   for(int i : V[A]){
        if(i==B) continue;
        int use=max1;

        if(max1==in[i])
            use=max2;

        out[i]=max(1+out[A],2+use);

        dfs2(i,A);
    }
}

int main(){_
    cin>>N;

    for(int i=1;i<N;i++){
        int A, B;
        cin>>A>>B;
        V[A].push_back(B);
        V[B].push_back(A);
    }

    dfs1(1,0);
    dfs2(1,0);

    for(int i=1;i<=N;i++)
        cout<<max(in[i],out[i])<<' ';
    cout<<'\n';

    return 0;
}