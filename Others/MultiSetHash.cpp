#define MAX (int)1e6+5
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
typedef unsigned long long ull;

ull val[MAX];
void init(){
    for(int i=0;i<MAX;i++) val[i] = rng64();
}

ull getHash(vector<int>& vec){
  ull h=0;
  for(auto v : vec) h+=val[v];// xor for set
  return h;
}
