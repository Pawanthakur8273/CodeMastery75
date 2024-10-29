
class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int index) {
        //base case
        if(index >= nums.size()) {
            return 0;
        }

        //recursive relation
        int include = nums[index] + solveUsingRecursion(nums, index+2);
        int exclude = 0 + solveUsingRecursion(nums, index+1);
        int ans = max(include, exclude);
        return ans;
    }
    //memo
    int solveUsingMem(vector<int>& nums, int index, vector<int>& dp) {
        //base case
        if(index >= nums.size()) {
            return 0;
        }
        //ans already exists
        if(dp[index] != -1) {
            return dp[index];
        }

        //recursive relation
        int include = nums[index] + solveUsingMem(nums, index+2, dp);
        int exclude = 0 + solveUsingMem(nums, index+1, dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }
    //tabulation
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        //step1
        vector<int> dp(n, -1);
        //step2
        dp[n-1] = nums[n-1];
        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = dp[index+2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

     int solveUsingTabulationSO(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        int next = 0;
        int curr;

        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;
            curr = max(include, exclude);

            //bhul jata hu
            next = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int index = 0;
        //int ans  = solveUsingRecursion(nums, index);
        //return ans;
        int n = nums.size();
        // vector<int> dp(n, -1);
        // int ans  = solveUsingMem(nums, index, dp);
        // return ans;
        int ans = solveUsingTabulationSO(nums);
        return ans;
    }
};


class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount) {
        //base case
        if(amount == 0) {
            return 0;
        }

        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            //find ans using ith coin
            //call recursion only for valid amounts i.e. >=0  wale amounts
            if(amount - coins[i] >= 0) {
                int recursionKaAns = solveUsingRecursion(coins, amount - coins[i]);
                //if a valid answeer
                if(recursionKaAns != INT_MAX) {
                    //considering uage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini  = min(mini, ans);
                }
            }
        }
        return mini;
    }
    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
        //base case
        if(amount == 0) {
            return 0;
        }
        //already ans exist
        if(dp[amount] != -1) {
            return dp[amount];
        }
        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            //find ans using ith coin
            //call recursion only for valid amounts i.e. >=0  wale amounts
            if(amount - coins[i] >= 0) {
                int recursionKaAns = solveUsingMem(coins, amount - coins[i], dp);
                //if a valid answeer
                if(recursionKaAns != INT_MAX) {
                    //considering uage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini  = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int solveUsingTabulation(vector<int>& coins, int amount) {
        //step1: done
        int n = amount;
        vector<int> dp(n+1, INT_MAX);
        //step2: base case analyse
        dp[0] = 0;
        //for loop
        for( int value = 1; value<=amount; value++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
            
                if(value - coins[i] >= 0) {
                    int recursionKaAns = dp[value - coins[i] ];
                    
                    if(recursionKaAns != INT_MAX) {
                        
                        int ans = 1 + recursionKaAns;
                        mini  = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans =  solveUsingRecursion(coins, amount);
        //int n = amount;
        //vector<int> dp(n+1, -1);
        int ans = solveUsingTabulation(coins, amount);
        if(ans == INT_MAX)
            return -1;
        else {
            return ans;
        }
    }
};
class Solution {
public:
    //plain recursion
    int solveUsingRecursion(int n) {
        //base case
        if(n == 0)
            return 0;
        if(n == 1) {
            return 1;
        }
        //recursive relation
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }
    //recursion + memo
    int solveUsingMemoisation(int n, vector<int>& dp) {
        //base case
        if(n == 0)
            return 0;
        if(n == 1) {
            return 1;
        }
        //step3: check if already exist , then return ans
        if(dp[n] != -1) {
            return dp[n];
        }
        //recursive relation
        //step2: store ans in dp array
        dp[n] = solveUsingMemoisation(n-1,dp) + solveUsingMemoisation(n-2, dp);
        return dp[n];
    }
    //tabulation method
    int solveUsingTabulation(int n) {
        //step1: create dp array
        vector<int> dp(n+1, -1);
        //step2: analyse base case and fill dp array
        dp[0] = 0;
        if(n == 0) {
            return 0;
        }
        dp[1] = 1;
        //step3: fill the remaingin dp array
        //array size = n+1
        //index move from 0 to n
        //0 and 1 index ko already fill krlia h
        //2 index se n index tak abhi filled nahi h
        for(int index = 2; index<=n; index++) {
            //copy paste karo recursive logic ko
            //repalce recursive calls  with dp array
            //make sure dp array is using looping variable
            dp[index] = dp[index-1] + dp[index-2];
        }
        //return ans;
        return dp[n];
    }

    int solveUsingTabulationSpaceOptimised(int n) {
        int prev = 0;
        if(n == 0) {
            return 0;
        }
        int curr = 1;
        if(n == 1) {
            return 1;
        }
        int ans;
        for(int index = 2; index<=n; index++) {
            ans = curr + prev;
            // prev and curr ko ek step aage move krna
            prev = curr;
            curr = ans;
        }
        //return ans;
        return ans;
    }
    int fib(int n) {
        // int ans = solveUsingRecursion(n);
        // return ans;

        //step1: create dp array
        // vector<int> dp(n+1, -1);
        // int ans = solveUsingMemoisation(n, dp);
        // return ans;

        // int ans = solveUsingTabulation(n);
        // return ans;
        return solveUsingTabulationSpaceOptimised(n);
    }
};
