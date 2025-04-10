class Solution {
public:
    long long solve(string &str,string &suff,int limit){
        if(str.size()<suff.size()){
            return 0ll;
        }
        long long cnt=0;
        string trail=str.substr(str.size()-suff.size(),suff.size());
        int rem=str.size()-suff.size();
        for(int i=0;i<rem;i++){
            int digit=str[i]-'0';
            if(digit<=limit){
                cnt+=digit*pow(limit+1,rem-i-1);
            }
            else{
                cnt+=pow(limit+1,rem-i);
                return cnt;
            }
        }
        if(trail>=suff){
            cnt++;
        }
        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string s1=to_string(start-1);
        string e1=to_string(finish);
        return solve(e1,s,limit)-solve(s1,s,limit);
    }
};