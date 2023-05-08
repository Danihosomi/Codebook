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
    //suffixArray.erase(suffixArray.begin()); //(Caso vazio conte como substring)
    return suffixArray;
}

// RMQ com Sparse-Table para fazer LCP no array de LCP
// É 0-indexado
namespace LCP{ 
    const int MAXL=22;
    int st[MAXL][500005], lg[500005], n;

    void build(const vi v){
        n=sz(v);
        for(int i=0;i<n;i++) st[0][i]=v[i];        

        for(int j=1;j<MAXL;j++)
            for(int i=0;i+(1<<j)<=n;i++)
                st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    
        lg[1]=0;
        for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    }

    int query(int l,int r){
        return min(st[lg[r-1-l]][l],st[lg[r-1-l]][r-1-(1<<lg[r-1-l])+1]);
    }
};

// Complexidade O(N)
// Baseado no CP algorithms
vi kasaiLCP(const string &c,const vi sa){
    int n = sz(sa), k=0;
    vi lcp(n-1,0), rank(n,0);

    for(int i=0;i<n;i++) rank[sa[i]]=i;

    for(int i=0;i<n;i++){
        if(rank[i]==n-1){ k=0; continue; }
        
        int j = sa[rank[i]+1];
        while(i+k<n && j+k<n && c[i+k]==c[k+j]) k++;

        lcp[rank[i]]=k;
        if(k) k--;
    }

    LCP::build(lcp);
    return lcp;
}

// Número diferente de substrings ((n*n+n)>>1) - somadosLCP
