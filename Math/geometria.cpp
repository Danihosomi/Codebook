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

double distanceSegmentPoint(tvector a, tvector b, tvector p){
	if ((p - a)%(b - a)<0) // Checa se p está abaixo de s
		return distancePointPoint(p, a);
	if ((p - b)%(a - b)<0) // Checa se p está acima de t
		return distancePointPoint(p, b);

	return distanceLinePoint(a, b, p);
}

int orientation(tvector a,tvector b,tvector c){
    double v=((b-a)^(c-b));
    if(v<0) return -1;
    if(v>0) return 1;
    return 0;
}

int cw(tvector a, tvector b, tvector c,int coolinear){ // Clock-wise
    return ((orientation(a,b,c)<0) || (orientation(a,b,c)==0 && coolinear));
}

int ccw(tvector a, tvector b, tvector c,int coolinear){ // Counter Clock-Wise
        return ((orientation(a,b,c)>0) || (orientation(a,b,c)==0 && coolinear));
}

double area_poli(vector<tvector>&V){
    double ans=0; V.eb(V[0]);
    for(int i=0;i<sz(V)-1;i++) ans+=V[i]^V[i+1];
    V.pop_back();
    return abs(ans)/2;
}

void convex_hull(vector<tvector>& v,int coolinear){
    if(sz(v)==1) return ;

    sort(all(v), [](tvector a,tvector b){
        return make_pair(a.x,a.y)<make_pair(b.x,b.y);
    });

    tvector p1=v[0], p2=v.back();
    vector<tvector> up, down;
    up.pb(v[0]); down.pb(v[0]);

    for(int i=1;i<sz(v);i++){
        if(i==sz(v)-1 || cw(p1,v[i],p2,coolinear)){ 
            while(sz(up)>=2 && !cw(up[sz(up)-2],up.back(),v[i],coolinear)) up.pop_back();
            up.pb(v[i]);
        } 
        if(i==sz(v)-1 || ccw(p1,v[i],p2,coolinear)){
            while(sz(down)>=2 && !ccw(down[sz(down)-2],down.back(),v[i],coolinear)) down.pop_back();
            down.pb(v[i]);
        }
    }

    if(coolinear && sz(up)==sz(v)){
        reverse(all(v)); return;
    }
    v.clear();
    for(auto a : up) v.pb(a);
    for(int i=sz(down)-2;i>0;i--) v.pb(down[i]);
    reverse(all(v));
}
 
int main(){_

 
    return 0;
}