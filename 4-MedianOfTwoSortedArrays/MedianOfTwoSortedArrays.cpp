#include <iostream>
#include <vector>
#include <algorithm>

/*Brute Force: 
    - Runtime: 36ms
    - Memory: 89MB
    - Complexity: O(log(n+m))

*/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::vector<int> merged; 

        merged.reserve(nums1.size() + nums2.size()); 
        merged.insert(merged.end(), nums1.begin(),nums1.end()); 
        merged.insert(merged.end(), nums2.begin(), nums2.end()); 
        std::sort(merged.begin(), merged.end()); 

        if(merged.size() % 2 == 0)
            return (merged[merged.size() / 2] + merged[(merged.size() / 2) - 1]) / 2.0;  
        else
            return (double) merged[merged.size() / 2]; 
    }
};