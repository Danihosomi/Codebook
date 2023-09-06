// Li-Chao Tree
//
// Adiciona retas a*x+b, e computa o minimo entre as retas em umn x dado
// Overflow? Talvez o CHT funcione?
// 
// Complexidade: O(log(n))

#define MI -1e9
#define MA 1e9

struct LiChao{
    
    struct linha{
        ll a, b; vi CH;

        linha (ll _a = 0, ll _b = linf) : a(_a), b(_b), CH({-1, -1}) {}

        ll operator () (ll x) { return a*x + b; }
    };

    vector<linha> v;

    LiChao() { v.emplace_back(); }

    int CH(int p,int d){
        if (v[p].CH[d] == -1) {
			v[p].CH[d] = sz(v);
			v.emplace_back();
		}
		return v[p].CH[d];
    }

    void add(linha S,ll l=MI,ll r=MA,int p = 0){
        ll m = (l+r)/2;
		bool testaL = S(l) < v[p](l);
		bool testaM = S(m) < v[p](m);
		bool testaR = S(r) < v[p](r);

		if (testaM) swap(v[p],S), swap(v[p].CH, S.CH);
		if (S.b == linf) return;
		if (testaL != testaM) add(r, l, m-1, CH(p, 0));
		else if (testaR != testaM) add(r, m+1, r, CH(p, 1));
    }

    ll query(int x,ll l=MI,ll r=MA,int p = 0){
        ll m = (l+r)/2, ret = v[p](x);
        if(ret==linf) return ret;
        return (x<m ? min(ret, query(x, l, m-1, CH(p, 0))) : min(ret, query(x, m+1, r, CH(p, 1))));
    }

};