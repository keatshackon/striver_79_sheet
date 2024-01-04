class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        int i = n-2;
        int idx = -1;
        
        while(i >= 0){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
            i--;
        }
        
        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        i = n-1; 
        while(i >= idx){
            if(nums[i] > nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
            i--;
        }
        
        reverse(nums.begin()+idx+1,nums.end());
    }
};