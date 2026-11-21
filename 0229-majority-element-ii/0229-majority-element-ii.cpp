class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,candidate1=0,count2=0,candidate2=0;
        vector<int>res;
        int n=nums.size();
        if(n==1) return nums;
        for(int i=0;i<n;i++){
           if(nums[i] == candidate1) {
                count1++;
            }
            else if(nums[i] == candidate2) {
                count2++;
            }
            else if(count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate1){
                a++;
            }
            if(nums[i]==candidate2){
                b++;
            }
        }
        if(a>(n/3)) res.push_back(candidate1);
        if(b>(n/3)) {
            if(candidate1!=candidate2) res.push_back(candidate2);
        }
        return res;
        
        
    }
};