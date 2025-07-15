class Solution {
public:
bool isvowel(char ch)
{
    if(ch=='a' or ch=='A' or ch=='e' or ch=='E' or ch=='i' or ch=='I' or ch=='o' or ch=='O' or ch=='u' or ch=='U') return true;
    else return false;
}

    bool isValid(string word) {
        int v=0,c=0;
        if(word.size()<3) return false;
        for(char ch:word)
        {
            if(ch>='0' and ch<='9') continue;        
            else if((ch>='a' and ch<='z' ) or (ch>='A' and ch<='Z'))
            {
                if(isvowel(ch)) v++;
                else c++;
            }
            else return false;
        }
        return c>=1 and v>=1;

    }
};