// Lembrar de adicionar a estrutura de ponto

int cw(pt a, pt b, pt c,int coolinear){ // Clock-wise
    return ((orientation(a,b,c)<0) || (orientation(a,b,c)==0 && coolinear));
}

int ccw(pt a, pt b, pt c,int coolinear){ // Counter Clock-Wise
    return ((orientation(a,b,c)>0) || (orientation(a,b,c)==0 && coolinear));
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