class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (n == k) return totalSum; 
        int windowSize = n - k;
        int minSum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int currentSum = minSum;
        for (int i = windowSize; i < n; i++) {
            currentSum += cardPoints[i] - cardPoints[i - windowSize];
            minSum = min(minSum, currentSum);
        }
        return totalSum - minSum;
    }
};

        
        
