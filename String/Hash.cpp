// Hash 1 indexado
namespace Hash{
    const int p = 53; // Colocar 53 se tiver minusculo e maiusculo
    const ll m = 1e9+9;
    ll powP[(int)1e6+1], invP[(int)1e6+1];
 
    ll inv_mod(ll a,ll b){
        return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
    }
 
    void init(){
        powP[0] = 1; invP[0] = inv_mod(1,m);
        for(int i=1;i<=(int)1e6;i++){ 
            powP[i] = (p*powP[i-1])%m;
            invP[i] = inv_mod(powP[i],m);
        }
    }
 
    vector<ll> makeHash(string const& c){ // Constroi o vetor dos Hash
        vector<ll> hashValue(sz(c)+1,0);
        
        for(int i=1;i<=sz(c);i++) hashValue[i] = (hashValue[i-1]+powP[i-1]*(c[i-1]-'a'+1))%m;
 
        return hashValue;
    }
 
    ll getHash(vector<ll>& hashValue,int l,int r){ // Te retorna o valor de um Hash
        return (((hashValue[r]-hashValue[l-1]+m)%m)*invP[l-1])%m;
    }
};