// Compressão de Coordenada
//
// 0-indexado
// 
// Value morato tmj

template <typename T>
struct CoordinateCompression {
    vector<T> v;
    CoordinateCompression(const vector<T> &_v) {
        v = _v; sort(all(v));
        v.resize(unique(all(v)) - v.begin());
    }

    int size() { return (int) v.size(); }

    int operator() (T x) {
        return (int) (lower_bound(all(v), x) - v.begin());
    }
};