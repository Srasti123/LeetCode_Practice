class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length()<t.length()) return "";
        unordered_map<char,int> need, window;
        for (char c:t) need[c]++;
        int have = 0, needCount=need.size();
        int left=0, right=0;
        int minLen=INT_MAX, minStart=0;
        while(right<s.length()){
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) {
                have++;
            }
            while (have == needCount) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char lChar = s[left];
                window[lChar]--;
                if (need.count(lChar) && window[lChar] < need[lChar]) {
                    have--;
                }
                left++;
            }
            right++;
        }
         return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
        