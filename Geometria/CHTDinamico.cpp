// Convex Hull Trick
// Copiado da Kactl
// O(log n)
//
//

struct Line {
	mutable ll k, m, p; // y = k*x+m e p é o ponto de intersecção com a próxima reta
	bool operator < (const Line& o) const { return k < o.k; }
	bool operator < (ll x) const { return p < x; }
};

// Dinâmico e da Query de Max
struct CHT : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll MAXLL = linf;
	ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // floored division

	bool isect(iterator x, iterator y) { // checa se uma reta é inutil
		if (y == end()) return x->p = MAXLL, 0;
		if (x->k == y->k) x->p = x->m > y->m ? MAXLL : -MAXLL;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}

	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}

	ll query(ll x) {
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
