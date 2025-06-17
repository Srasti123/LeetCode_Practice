int MOD = 1e9+7;
class Solution {
public:
    int findPower(long long a,long long b){
        if(b == 0){
            return 1;
        }

        long long half = findPower(a,b/2);
        long long res = (half*half)%MOD;

        if(b%2 == 1){
            res = (res*a)%MOD;
        }
        return res;
    }

   
    long long nCr(int n,int r, vector<long long> &factorial, vector<long long> &fermatFact){
        

        return factorial[n] * fermatFact[n-r]%MOD * fermatFact[r]%MOD; 
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1,1);
        factorial[0] = 1;
        factorial[1] = 1;

        
        for(int i = 2;i<=n;i++){
            factorial[i] = (factorial[i-1]*i) %MOD;
        }
        vector<long long> fermatFact(n+1,1);

        for(int i = 0;i<=n;i++){
            fermatFact[i] = findPower(factorial[i],MOD-2);
        }

        long long res = nCr(n-1,k,factorial,fermatFact); 

        res = (res * m) % MOD;
        res = (res * findPower(m-1,n-k-1))%MOD;

        return res;
    }
};