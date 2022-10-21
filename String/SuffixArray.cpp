#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

vi sortCyclic(string const& c){
    int tam = sz(c), clas=1;
    const int alpha = 256;
    vi p(tam), c1(tam), cnt(max(alpha,tam), 0), pn(tam), cn(tam);

    for (int i = 0; i < tam; i++) cnt[c[i]]++;
    for (int i = 1; i < alpha; i++) cnt[i] += cnt[i-1];
    for (int i = 0; i < tam; i++) p[--cnt[c[i]]] = i;
    
    c1[p[0]] = 0;
    for (int i = 1; i < tam; i++) {
        if (c[p[i]] != c[p[i-1]]) clas++;
        c1[p[i]] = clas - 1;
    }

    for (int h = 0; (1 << h) < tam; ++h) {
        
        for (int i = 0; i < tam; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += tam;
        }

        fill(cnt.begin(), cnt.begin() + clas, 0);

        for (int i = 0; i < tam; i++) cnt[c1[pn[i]]]++;
        for (int i = 1; i < clas; i++) cnt[i] += cnt[i-1];
        for (int i = tam-1; i >= 0; i--) p[--cnt[c1[pn[i]]]] = pn[i];
        
        cn[p[0]] = 0; clas = 1;
        
        for (int i = 1; i < tam; i++) {
            ii cur = {c1[p[i]], c1[(p[i] + (1 << h)) % tam]}, prev = {c1[p[i-1]], c1[(p[i-1] + (1 << h)) % tam]};
            if (cur != prev) clas++;
            cn[p[i]] = clas - 1;
        }

        c1.swap(cn);
    }

    return p;
}

vi BuildSufix(string c){
    c+='$';
    vi suffixArray = sortCyclic(c);
    //suffixArray.erase(suffixArray.begin()); (Caso vazio conte como substring)
    return suffixArray;
}

int main(){_

    return 0;

}