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
 
struct pt{//p, q
    ll x, y;
    
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}

    pt operator +(pt q) const{
        return {x + q.x, y + q.y};
    }
    pt operator -(pt q) const{
        return {x - q.x, y - q.y};
    }
    double operator ~() const {
        return hypot(x, y);
    }
    ll operator *(pt q) const {
        return (x*q.x + y*q.y);
    }
    ll operator ^(pt q) const {
        return (x*q.y - y*q.x);
    }
    bool operator < (pt a) const {
		if (x!=a.x) return x < a.x;
        return y<a.y;
	}
};

int sgn(ll x){ 
    return (x >= 0 ? x ? 1 : 0 : -1);
}

pt rotate(pt a,double o){
    pt ar;
    ar.x=a.x*cos(o)-a.y*sin(o);
    ar.y=a.x*sin(o)+a.y*cos(o);
    return ar;
}

int xySignal(pt a){
    if(a.y>0 || (!a.y && a.x>0)) return 0;
    return 1;
}

bool radialComp(pt a,pt b){
    if(xySignal(a)!=xySignal(b)) return xySignal(a)<xySignal(b);
    if((a^b)) return (a^b)>0;
    return (a*a)<(b*b);
}

bool inter(long long a, long long b, long long c, long long d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool checkInter(pt a, pt b, pt c, pt d) {
    if (((a-c)^(d-c))==0 && ((b-c)^(d-c))==0)
        return (inter(a.x, b.x, c.x, d.x) && inter(a.y, b.y, c.y, d.y));

    return (sgn((b-a)^(c-a)) != sgn((b-a)^(d-a)) && sgn((d-c)^(a-c)) != sgn((d-c)^(b-c)));
}

double distPointToPoint(pt p, pt q){//distancia do ponto R ao ponto Q
    return ~(p-q);
}

double distPointToLine(pt p, pt q, pt r){//distancia do ponto R à linha deerminada pelos pontos P e Q
    return fabs(((r-p)^(q-p))/(~(q-p)));
}

double distanceSegmentPoint(pt a, pt b, pt p){
	if ((p - a)*(b - a)<0) // Checa se p está abaixo de s
		return ~(p-a);
	if ((p - b)*(a - b)<0) // Checa se p está acima de t
		return ~(p-b);

	return distPointToLine(a, b, p);
}

int orientation(pt a,pt b,pt c){
    double v=((b-a)^(c-b));
    if(v<0) return -1;
    if(v>0) return 1;
    return 0;
}

int cw(pt a, pt b, pt c,int coolinear){ // Clock-wise
    return ((orientation(a,b,c)<0) || (orientation(a,b,c)==0 && coolinear));
}

int ccw(pt a, pt b, pt c,int coolinear){ // Counter Clock-Wise
        return ((orientation(a,b,c)>0) || (orientation(a,b,c)==0 && coolinear));
}

int pointInTriangle(pt a,pt b,pt c,pt q){
    ll s1=abs((b-a)^(c-a));
    ll s2=abs((a-q)^(b-q))+abs((b-q)^(c-q))+abs((c-q)^(a-q));
    return s1==s2;
}

int pointInPolygon(vector<pt> p,pt q,pt trans){
    int l=0, meio, r=sz(p)-1;
    q=q-trans;
    if((p[0]^q)!=1 && sgn(p[0]^q)!=sgn(p[0]^p[r])) return 0;
    if((p[r]^q) && sgn(p[r]^q)!=sgn(p[r]^p[0])) return 0;
    if(!(p[0]^q)) return (p[0]*p[0])>=(q*q);

    while(r-l>1){
        meio=l+((r-l)>>1);
        if((p[meio]^q)>=0) l=meio;
        else r=meio;
    }

    return pointInTriangle(p[l],p[l+1],pt(0,0),q);
}

void preparePolygon(vector<pt>& v,pt& trans){
    int pos=0;
    for(int i=1;i<sz(v);i++)
        if(v[i]<v[pos]) pos=i;

    rotate(v.begin(),v.begin()+pos,v.end());

    vector<pt> aux;
    trans=v[0];
    for(int i=1;i<sz(v);i++) aux.pb(v[i]-trans);
    v=aux;
}

double areaPoli(vector<pt>& V){
    double ans=0; V.pb(V[0]);
    for(int i=0;i<sz(V)-1;i++) ans+=V[i]^V[i+1];
    V.pop_back();
    return abs(ans)/2;
}

pair<ll,ll> laticePoints(vector<pt>& v){
    v.pb(v[0]); ll area=0, bound=0;
    
    for(int i=0;i<sz(v)-1;i++) area+=(v[i]^v[i+1]);
    area=abs(area);
    
    for(int i=0;i<sz(v)-1;i++){
        if(v[i].x==v[i+1].x) bound+=abs(v[i+1].y-v[i].y);
        else if(v[i].y==v[i+1].y) bound+=abs(v[i+1].x-v[i].x);
        else bound+=(1LL*__gcd(abs(v[i+1].y-v[i].y),abs(v[i+1].x-v[i].x)));
    }

    v.pop_back();
    return {bound,(area+2-bound)/2};
}

void convexHull(vector<pt>& v,int coolinear){
    if(sz(v)==1) return ;

    sort(all(v), [](pt a,pt b){
        return make_pair(a.x,a.y)<make_pair(b.x,b.y);
    });

    pt p1=v[0], p2=v.back();
    vector<pt> up, down;
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

double minimumDist(vector<pt> v){
    sort(all(v));
    int p=0;
    set<ii> active;
    double ans=distPointToPoint(v[0],v[1]);

    for(int i=0;i<sz(v);i++){
        while(v[i].x-v[p].x>ans){
            active.erase({v[p].y,p});
            p++;
        }

        ii acha = {v[i].y-floor(ans),0};
        auto it = active.lower_bound(acha);

        while(it!=active.end() && it->f<=v[i].y+floor(ans)){
            ans=min(ans,distPointToPoint(v[i],v[it->s]));
            it++;
        }
        active.insert({v[i].y,i});
    }

    return ans;
}
 
int main(){_

 
    return 0;
}