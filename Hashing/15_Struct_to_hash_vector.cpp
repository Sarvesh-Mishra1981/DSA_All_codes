/*
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (int x : v) {
            h ^= std::hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};


this struct helps to hash the vector in the unordered_set 
just use unordered_set<vector<int>,VectorHash> 


*/