class Solution {
    //two pointer
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size(),left=0,right=0,ans=n+1,sum=0;
            for(;right<n;right++){//right pointer
                sum+=nums[right];
                while (sum-nums[left]>=target)//smaller
                {
                    sum-=nums[left++];//left ++
                }
                if(sum>=target) ans=min(ans,right-left+1);
            }
            return ans<=n?ans:0;
        }
    };