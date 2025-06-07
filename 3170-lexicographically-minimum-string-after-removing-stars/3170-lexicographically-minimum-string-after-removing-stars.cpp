struct compare{
    bool operator()(pair<char,int>& a, pair<char,int>& b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare> pq;

        int n = s.size();

        vector<int> take(n,1);

        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                auto [a,b] = pq.top();
                pq.pop();

                take[b] = 0;
                take[i] = 0;
            }
            else{
                pq.push({s[i],i});
            }
        }

        string ans = "";

        for(int i=0; i<n; i++){
            if(take[i] == 1){
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};