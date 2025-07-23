class Solution {
public:
    int maximumGain(string& s, int x, int y) {
        if (x<y){
            reverse(s.begin(), s.end());
            swap(x, y);
        }
        int a=0, b=0, points=0;
        for(char c: s){
            switch(c){
                case 'a': a++; break;
                case 'b':
                    if (a>0){
                        a--;
                        points+=x;
                    }
                    else b++;
                    break;
                default:
                    points+=min(a, b)*y;
                    a=b=0;
            }
        }
        points+=min(a, b)*y;
        return points;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();