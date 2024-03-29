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

int pointLineIntersec(pt a,pt b, pt c){ // se c interecta ab : 1 se sim, 0 se não
	if(((b-a)^(c-a))!=0) return 0;	
	return (min(a.x, b.x) <=c.x && c.x <= max(a.x, b.x)) && (min(a.y, b.y) <=c.y &&c.y <= max(a.y, b.y));
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

int pointPolygon(pt a,vector<pt> v){ // Qualquer Poligono O(n)
	int cnt=0, bound=0;

	for(int i=0;i<sz(v);i++){
		int j=(i==sz(v)-1 ? 0 : i+1);
		if(pointLineIntersec(v[i],v[j],a)) bound=1;
        if((v[i].x<=a.x && a.x<v[j].x) && ((v[i]-a)^(v[j]-a))<0) cnt++;
		else if((v[j].x<=a.x && a.x<v[i].x) && ((v[j]-a)^(v[i]-a))<0) cnt++;
	}

	if(bound) return -1;
	return (cnt&1); // 1 -> dentro / 0 -> fora
}
