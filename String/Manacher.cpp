/*
Código copiado do Bruno Monteiro (UFMG)
Complexidades:
Manacher = O(n) (é o manacher de vdd)
LongestEnd = O(n) (pra cada i diz o palindromo maior que termina nele)
*/

vi manacher(const string &c){
    int n = sz(c), l=0, r=-1;
    vi par(n), impar(n);

    for(int i=0;i<n;i++){
        int j = (i>r ? 1 : min(impar[l+r-i],r-i));
        while(i+j<n && i-j>=0 && c[i+j]==c[i-j]) j++;
        impar[i]=j--;
        if(i+j>r) l=i-j, r=i+j;
    }

    l=0, r=-1;

    for(int i=0;i<n;i++){
        int j = (i>r ? 0 : min(par[l+r-i+1],r-i+1)); j++;
        while(i+j<=n && i-j>=0 && c[i+j-1]==c[i-j]) j++;
        par[i]=--j;
        if(i+j-1>r) l=i-j, r=i+j-1;
    }

    vi ans(2*n-1);
	for (int i = 0; i < n; i++) ans[2*i] = 2*impar[i]-1;
	for (int i = 0; i < n-1; i++) ans[2*i+1] = 2*par[i+1];

    return ans;
}

vi longestPal(const string &c){
    vi ans(sz(c)); ans[0]=1;
    vi mana = manacher(c);

    for(int i=1;i<sz(c);i++){
        ans[i]=min(i+1,ans[i-1]+2);
        while(!(mana[2*i-ans[i]+1]>=ans[i])) ans[i]--;
    }

    return ans;
}