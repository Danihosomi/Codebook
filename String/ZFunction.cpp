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

vi zFunction(string c){
    vi z(sz(c)); z[0]=0;

    for(int i=1,l=0,r=0;i<sz(c);i++){
        if (i<=r) z[i]=min(r-i+1,z[i-l]);
        
        while(i+z[i]<sz(c) && c[z[i]]==c[i+z[i]]) z[i]++;
        
        if (i+z[i]-1>r) l=i,r=i+z[i]-1;
    }

    return z;
}

int main(){_


    return 0;

}