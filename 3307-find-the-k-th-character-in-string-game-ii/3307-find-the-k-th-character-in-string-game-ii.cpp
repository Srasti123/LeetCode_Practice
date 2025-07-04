class Solution {
    char build(int gen , long long pos, vector<int>& ops){
        if(gen==0) return 'a';

        long long  half = 1LL<<(gen-1);
        long long npos = pos;
        if(pos > half) npos = pos - half;


        char c = build(gen-1,npos,ops);
        if(pos > half && ops[gen-1]==1) return ((c-'a'+1)%26)+'a';
        return c;
    }
public:
    char kthCharacter(long long k, vector<int>& ops) {
        int gen = 0;
        while ((1LL << gen) < k) gen++;
        return build(gen, k, ops);

    }
};