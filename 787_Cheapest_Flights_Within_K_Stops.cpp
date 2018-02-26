class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int maxx= 1e9;
        vector< vector < int>> dp ( K + 2 , vector<int> (n, maxx )); 
        dp[0][src] = 0;
    
        for (int i = 1; i <= K + 1; ++i) {
            dp[i][src] = 0;
            for (const auto& p : flights)
                dp[i][p[1]] = min(dp[i][p[1]], dp[i-1][p[0]] + p[2]);    
        }
    
        if(dp[K+1][dst]>=maxx)
            return -1;
        else
            return dp[K+1][dst];
    
        
    }
};
