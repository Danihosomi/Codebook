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
#define MAXL 25
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

namespace RMQ{
    int st[MAXL][500005], lg[500005], n;

    void build(const vi v){
        n=sz(v);
        for(int i=0;i<n;i++) st[0][i]=v[i];        

        for(int j=1;j<MAXL;j++)
            for(int i=0;i+(1<<j)<=n;i++)
                st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    
        lg[1]=0;
        for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    }

    int query(int l,int r){
        return min(st[lg[r-l]][l],st[lg[r-l]][r-(1<<lg[r-l])+1]);
    }
};

int main(){_


    return 0;

}