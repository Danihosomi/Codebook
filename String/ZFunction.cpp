vi zFunction(string c){
    vi z(sz(c)); z[0]=0;

    for(int i=1,l=0,r=0;i<sz(c);i++){
        if (i<=r) z[i]=min(r-i+1,z[i-l]);
        
        while(i+z[i]<sz(c) && c[z[i]]==c[i+z[i]]) z[i]++;
        
        if (i+z[i]-1>r) l=i,r=i+z[i]-1;
    }

    return z;
}
