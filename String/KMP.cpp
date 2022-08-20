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

vi kmp(string c){
    vi pi(n);

    for(int i=1;i<sz(c);i++){
        int j=pi[i-1];
        while(j && c[i]!=c[j]) j=pi[j-1];
        if(c[i]==c[j]) j++;

        pi[i]=j;
    }

    return pi;   
}

int main(){


    return 0;
}