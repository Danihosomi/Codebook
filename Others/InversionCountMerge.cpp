ll inv(vi &v){
    if(sz(v)==1) return 0;

    int i1=0, i2=0;
    ll ans=0;
    vi a, b;
    
    for(int i=0;i<sz(v)/2;i++) a.pb(v[i]);
    for(int i=sz(v)/2;i<sz(v);i++) b.pb(v[i]);

    ans = inv(a)+inv(b);
    a.pb(inf); b.pb(inf);

    for(int i=0;i<sz(v);i++){
        if(a[i1]>b[i2]){
            v[i]=b[i2]; i2++; ans+=sz(a)-i1-1;
        }
        else{
            v[i]=a[i1]; i1++;
        }
    }

    return ans;
}
