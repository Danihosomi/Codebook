//
// Copiado de alguem ai
// CHT normal
// Deve ser ordenado por slope
// Linear
//

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
	long long eval(long long x) const { return k * x + m; }
};

// Linear e da query de minimo
struct CHT {
	deque<Line> hull;
	static const ll LMAX = linf;

	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(Line &x, const Line &y) {
		if (x.k == y.k) x.p = x.m > y.m ? LMAX : -LMAX;
		else x.p = div(y.m - x.m, x.k - y.k);
		return x.p >= y.p;
	}
	void add(long long k, long long m) { // Para max alterar L.p > hull.back().p
		Line L = {k, m, 0};
		while ((int) hull.size() >= 2 && (isect(L, hull.back()),isect(hull.back(), hull[(int) hull.size() - 2]), L.p < hull.back().p))  hull.pop_back();
		hull.push_back(L);
	}
	long long query(long long x) { // Para max alterar para <=
		while ((int) hull.size() >= 2 && hull[0].eval(x) >= hull[1].eval(x)) hull.pop_front();
		return hull[0].eval(x);
	}
};