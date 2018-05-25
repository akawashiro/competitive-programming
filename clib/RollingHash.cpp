// hash returns s[i,j)
const int N_TYPE_OF_HASH = 2;
class RollingHash {
    public:
        int n;
        const long long mod[N_TYPE_OF_HASH] = {999999937LL, 1000000007LL};
        long long base = 9973;
        vector<long long> hs[N_TYPE_OF_HASH], pw[N_TYPE_OF_HASH];
        RollingHash(){}
        RollingHash(const string &s) {
            n = s.size();
            for (int i = 0; i < N_TYPE_OF_HASH; i++) {
                hs[i].assign(n+1,0);
                pw[i].assign(n+1,0);
                hs[i][0] = 0;
                pw[i][0] = 1;
                for (int j = 0; j < n; j++) {
                    pw[i][j+1] = pw[i][j]*base%mod[i];
                    hs[i][j+1] = (hs[i][j]*base+s[j])%mod[i];
                }
            }
        }

        long long hash(int l, int r, int i) { return ((hs[i][r]-hs[i][l]*pw[i][r-l])%mod[i]+mod[i])%mod[i]; }

        bool match(int l1, int r1, int l2, int r2) {
            bool ret = 1;
            for (int i = 0; i < N_TYPE_OF_HASH; i++) ret &= hash(l1,r1,i)==hash(l2,r2,i);
            return ret;
        }

        bool match(int l, int r, long long h[]) {
            bool ret = 1;
            for (int i = 0; i < N_TYPE_OF_HASH; i++) ret &= hash(l,r,i)==h[i];
            return ret;
        }
};


