class Solution {
public:
int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    if (n == 1) return 10;
    int count = 10; 
    int uniqueChoices = 9;  
    int available = 9;  
    for (int i = 2; i <= n; i++) {
        uniqueChoices *= available;  
        count += uniqueChoices;
        available--;  
    }
    return count;
}
};

