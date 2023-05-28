// Aho-corasick copiado do bruno monte
//
// query retorna o somatorio do numero de matches de
// todas as stringuinhas na stringona
//
// insert - O(|s| log(SIGMA)) SIGMA é tamanho do alfabeto
// build - O(N), onde N = somatorio dos tamanhos das strings
// query - O(|s|)

namespace aho {
    const int MAX = 1000001;
	map<char, int> to[MAX];
	int link[MAX], idx, term[MAX], exit[MAX], sobe[MAX];

	void insert(string& s) {
		int at = 0;
		for (char c : s) {
			auto it = to[at].find(c);
			if (it == to[at].end()) at = to[at][c] = ++idx;
			else at = it->second;
		}
		term[at]++, sobe[at]++;
	}
	
	void build() { // builda dps de inserir
		queue<int> q;
		q.push(0);
		link[0] = exit[0] = -1;
		while (q.size()) {
			int i = q.front(); q.pop();
			for (auto x : to[i]) {
				char c = x.f;
                int l = link[i], j = x.s;
				while (l != -1 && !to[l].count(c)) l = link[l];
				link[j] = (l == -1 ? 0 : to[l][c]);
				exit[j] = (term[link[j]] ? link[j] : exit[link[j]]);
				if (exit[j]+1) sobe[j] += sobe[exit[j]];
				q.push(j);
			}
		}
	}

	ll query(string& s) {
		int at = 0, ans = 0;
		for (char c : s){
			while (at != -1 && !to[at].count(c)) at = link[at];
			at = (at == -1 ? 0 : to[at][c]);
			ans += sobe[at];
		}
		return ans;
	}
}
