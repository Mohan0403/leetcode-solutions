class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>p(nums.size());
        int n=nums.size();
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            p[i]=p[i-1]+nums[i];
        }        
       
        for(int i=0;i<nums.size();i++){
                int lefttotal=(i==0)?0:p[i-1];
                int righttotal=p[n-1]-p[i];
                if(lefttotal==righttotal){
                    return i;
                }
        }
        return -1;
    }
};