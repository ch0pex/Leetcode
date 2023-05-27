#include <iostream> 
#include <vector>
#include <cmath> 

/*Solution: 
    - Runtime: 132ms
    - Memory: 78MB
    - Complexity: O(n)
*/


class Solution {
public:
    int minimumAverageDifference(std::vector<int>& nums) {
        size_t min = 0;
        size_t minDiff = 999999; 
        long sum1 = nums.at(0); 
        long sum2 = 0; 
        int avDiff; 
        long vlen = (long) nums.size(); 

        for(int x = 1; x < vlen; x++){
            sum2 += nums.at(x); 
        }


        for (int i = 0; i < vlen; i++)
        {
            
            long len2 = vlen - i - 1 ; 


            if (len2 == 0){
                len2 = 1;
                sum2 = 0; 
            }  

            avDiff = abs(sum1 / (i+1) - sum2 / len2); 
            
            if(avDiff == 0) return i; 
            
            if (avDiff < minDiff) {
                min = i; 
                minDiff = avDiff; 
            } 

            if (i == vlen - 1) return min; 

            sum1 += nums.at(i+1); 
            sum2 -= nums.at(i+1); 
        }
        return min; 
        
    }
};




int main(){
    std::vector<int> nums = {1,2,3,4,5}; 
    Solution* sol = new Solution(); 
    int num = sol->minimumAverageDifference(nums); 
    std::cout << num; 
}


