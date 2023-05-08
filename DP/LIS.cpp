// O(nlogn) com Busca Binaria
// Da para fazer O(nlogn) com Segment Tree (Mais versátil)

vi LIS(vi &v){
    vi p;

    for(auto x : v){
        vi::iterator it=lower_bound(all(p),x);
        if(it==p.end()) p.pb(x);
        else (*it)=x;
    }

    return p;
}
