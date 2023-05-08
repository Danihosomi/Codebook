vi KMP(string c){
    vi pi(sz(c)); pi[0]=0;

    for(int i=1;i<sz(c);i++){
        int j=pi[i-1];
        while(j && c[i]!=c[j]) j=pi[j-1];
        if(c[i]==c[j]) j++;

        pi[i]=j;
    }

    return pi;   
}