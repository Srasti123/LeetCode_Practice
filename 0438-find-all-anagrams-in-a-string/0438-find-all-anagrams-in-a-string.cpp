class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
    if (s.size() < p.size()) return result;
    vector<int> pCount(26, 0), sCount(26, 0);
    for (char ch : p)
        pCount[ch - 'a']++;
    int windowSize = p.size();
    for (int i = 0; i < windowSize; i++)
        sCount[s[i] - 'a']++;
    if (sCount == pCount)
        result.push_back(0);
    for (int i = windowSize; i < s.size(); i++) {
        sCount[s[i] - 'a']++;                       
        sCount[s[i - windowSize] - 'a']--;         
        if (sCount == pCount)
            result.push_back(i - windowSize + 1);
    }
    return result;
}
};