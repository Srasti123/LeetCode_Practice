// Custom comparator function
bool compare(string a, string b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        
        // Sort strings using the custom comparator
        sort(strNums.begin(), strNums.end(), compare);
        
        // Handle edge case: If the largest number is '0', return '0'
        if (strNums[0] == "0") {
            return "0";
        }
        
        // Concatenate the sorted numbers into the largest number
        string largestNum;
        for (const string& str : strNums) {
            largestNum += str;
        }
        
        return largestNum;
    }
};
