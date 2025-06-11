class Solution
{
private:
    inline int get_status(int a,int b)
    {
        return ((a&1)<<1)|(b&1);
    }
    
public:
    int maxDifference(const string& s, int k)
    {
        int ans=INT_MIN;
        for(char a='0';a<='4';a++)
        {
            for(char b='0';b<='4';b++)
            {
                if(a==b)
                {
                    continue;
                }
                int cnt_a=0;
                int cnt_b=0;
                int prev_a=0;
                int prev_b=0;
                int best[4]={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
                int l=-1;
                for(int r=0;r<s.size();r++)
                {
                    if(s[r]==a)
                    {
                        cnt_a++;
                    }
                    if(s[r]==b)
                    {
                        cnt_b++;
                    }
                    while(r-l>=k&&cnt_b-prev_b>=2)
                    {
                        int left=get_status(prev_a,prev_b);
                        best[left]=min(best[left],prev_a-prev_b);
                        l++;
                        if(s[l]==a)
                        {
                            prev_a++;
                        }
                        if(s[l]==b)
                        {
                            prev_b++;
                        }
                    }
                    int right=get_status(cnt_a,cnt_b);
                    if(best[right^0b10]!=INT_MAX)
                    {
                        ans=max(ans,cnt_a-cnt_b-best[right^0b10]);
                    }
                }
            }
        }
        return ans;
    }
};