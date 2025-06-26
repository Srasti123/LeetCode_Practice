class Solution {
public:
    int longestSubsequence(string &s, int k) {
        return (s.size() < bit_width((unsigned) k)) ? s.size() : bit_width((unsigned) k) + count(s.begin(), s.end() - bit_width((unsigned) k), '0') - (stoi(s.substr(s.size() - bit_width((unsigned) k), bit_width((unsigned) k)), nullptr, 2) > k);
    }
};