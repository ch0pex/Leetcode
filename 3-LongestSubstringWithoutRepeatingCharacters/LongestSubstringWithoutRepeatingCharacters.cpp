#include <iostream>
#include <string> 

/*Brute Force: 
    - Runtime 81ms 
    - Memory: 6.8MB
    - Complexity: O(n^3)
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        int maxLen = 0;
        std::string sub; 
        for (size_t i = 0; i < s.size(); i++)
        {
            if(maxLen > s.size() - i) break;
            for (size_t j = i; j < s.size(); j++)
            {
                if(sub.find(s[j]) != -1) break; 
                sub.push_back(s[j]); 
            }
            if(sub.size() > maxLen) maxLen = sub.size(); 
            sub.clear(); 
        }
        return maxLen;   
    }
};

/*Sliding window: 
    - Runtime 14ms
    - Memory 11.6MB
    - Complexity: O(n)
*/
class Solution2 {
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        std::string sub; 
        int max = 0;  
        int ind = 0; 
        if(s.size() == 0) return 0; 
        for (size_t i = 0; i < s.size(); i++)
        {
            if((ind = sub.find(s[i])) == -1)
                sub.push_back(s[i]);
            
            else 
            {   
                if(s.size() < i + ind) break; 
                int start = i - sub.size() + ind + 1; 
                int len = sub.size() - ind; 
                sub = s.substr(start, len); 
            }

            if(sub.size() > max) 
                max = sub.size(); 
        }
        return max;
    }
};


int main(void)
{   
    Solution2 sol; 
    std::cout << sol.lengthOfLongestSubstring("ggububgvfk"); 
    return 0; 
}