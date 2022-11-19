#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int maxSuffix(string c,int mi=0){
    int ans=0; c.pb(*min_element(all(c))-1);
 
    for(int i=1;i<sz(c);i++){
        int j=0;
        while(ans+j<i && c[j+ans]==c[i+j]) j++;
        if(c[i+j]>c[ans+j]){
            if(!mi || i!=sz(c)-2) ans=i;
        }
        else if(j) i+=j-1;
    }
 
    return ans;
}

int minSuffix(string c){
    for(auto &i : c) i*=-1;
    c.pb(*max_element(all(c))+1);
    return maxSuffix(c,1);
}

int maxCyclicShift(string c){
    int tam=sz(c);
    for(int i=0;i<tam;i++) c.pb(c[i]);
    return maxSuffix(c);
}

int minCyclicShift(string c){
    for(auto &i : c) i*=-1;
    return maxCyclicShift(c);
}

int main(){_


    return 0;
}