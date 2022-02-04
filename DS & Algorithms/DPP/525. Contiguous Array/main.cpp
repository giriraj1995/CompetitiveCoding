class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        int len = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                count--;
            }else{
                count++;
            }
            
            if(mp.count(count) != 0) {
                len = max(len, i-mp[count]);
            }else{
                mp[count] = i;
            }
        }
        
        return len;
    }
};
