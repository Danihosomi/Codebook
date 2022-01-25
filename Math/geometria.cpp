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
 
struct tvector{//p, q
    ll x, y;
 
    tvector operator +(tvector q) const{
        return {x + q.x, y + q.y};
    }
    tvector operator -(tvector q) const{
        return {x - q.x, y - q.y};
    }
    double operator ~() const {
        return hypot(x, y);
    }
    ll operator *(tvector q) const {
        return (x*q.x + y*q.y);
    }
    ll operator ^(tvector q) const {
        return (x*q.y - y*q.x);
    }
};

int sgn(ll x){ 
    return (x >= 0 ? x ? 1 : 0 : -1);
}

bool inter(long long a, long long b, long long c, long long d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(tvector a, tvector b, tvector c, tvector d) {
    if (((a-c)^(d-c))==0 && ((b-c)^(d-c))==0)
        return (inter(a.x, b.x, c.x, d.x) && inter(a.y, b.y, c.y, d.y));

    return (sgn((b-a)^(c-a)) != sgn((b-a)^(d-a)) && sgn((d-c)^(a-c)) != sgn((d-c)^(b-c)));
}

double distPointToLine(tvector p, tvector q, tvector r){//distancia do ponto R à linha deerminada pelos pontos P e Q
    return fabs(((r-p)^(q-p))/(~(q-p)));
}

int cw(tvector a, tvector b, tvector c){ // Clock-wise
    return (((b-a)^(c-b)) < 0);
}

int ccw(tvector a, tvector b, tvector c){ // Counter Clock-Wise
    return (((b-a)^(c-b)) > 0);
}

double area_poli(vector<tvector>&V){
    double ans=0; V.eb(V[0]);
    for(int i=0;i<sz(V)-1;i++) ans+=V[i]^V[i+1];
    V.pop_back();
    return abs(ans)/2;
}
 
int main(){_

 
    return 0;
}