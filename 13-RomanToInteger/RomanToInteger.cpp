#include <iostream>
#include <string> 
#include <map>

/* Solution: 
    - Runtime 4ms (Beats 90%)
    - Memory 8.1MB (Beats 40%)
    - Complexity: O(n)
*/

class Solution {

private: 
    std::map<char, int> values = {
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
    };
    
public:

    size_t romanToInt(std::string s){
        size_t number = 0; 
        char prev = '0';
        for (const char character : s){
            if (prev == 'I' && (character == 'V' || character == 'X'))
                number += (values[character] - 2);

            else if (prev == 'X' && (character == 'L' || character == 'C'))
                number += (values[character] - 20); 

            else if (prev == 'C' && (character == 'D' || character == 'M'))
                number += (values[character] - 200); 
            else 
                number += values[character]; 
            prev = character; 

        }
        return number; 
    }
}; 

int main(){
    Solution* sol = new Solution();
    const size_t num = sol->romanToInt("MCMXCIV");
    std::cout << num; 
}