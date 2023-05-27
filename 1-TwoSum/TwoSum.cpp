#include <iostream>
#include <vector>
#include <unordered_map>

/* First Solution: 
    - Runtime 529ms 
    - Memory 10.1MB 
    - Complexity: O(n^2) 
*/ 
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::vector<int> sol; 
        int len = nums.size(); 
        sol.reserve(2); 

        for (size_t i = 0; i < len; i++)
        {
            for(size_t j = i + 1; j < len; j++)
            {
                if(nums.at(i) + nums.at(j) == target)
                {
                    sol.push_back(i); 
                    sol.push_back(j); 
                    return sol; 
                }                   
            }
        }
        return sol; 
    }
}; 

/* Optimal Solution: 
    - Runtime 13ms Beats: 70% 
    - Memory 11MB Beats: 25%
    - Complexity: O(n)    
    */
class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {

        std::unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++)
        {
            int check = nums[i];
            int min = target - check; 
            if(seen.count(min)) return {seen[min],i}; 
            seen[check] = i; 
        } 
        return {};
    }
};


int main(void)
{
    Solution2 sol; 
    std::vector<int> input = {3,3}; 
    std::vector<int> solVec; 
    solVec = sol.twoSum(input, 6);

    std::cout << solVec.at(0) << ", " << solVec.at(1) << std::endl; 
    return 0; 

}