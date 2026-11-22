class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>res;
        res[0]=1;
        int total=0,count=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            if(res.find(total-k)!=res.end()){
                count+=res[total-k];
            }
            res[total]++;
        }
        return count;
        
    }
};