// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int hold1 = numeric_limits<int>::min();
        int release1 = numeric_limits<int>::min();

        for (const auto& p : prices) {
            hold1 = max(hold1, -p);
            release1 = max(release1, hold1 + p);
        }

        return release1;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty())
            return 0;
        
        int mini = prices[0];
        int maxi = 0;
        int n = prices.size();
        
        for(int i=0; i<n; i++) {
            
            /*  o(n2), time , no good
            for(int j=i+1; j<n; j++) {
                
                maxi = max(maxi, prices[j]-prices[i]);
                
            }
            */
            
            //o(n) time, better and easy to understand
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i]-mini);
            
        }
        
        return maxi; 
        
    }
};
