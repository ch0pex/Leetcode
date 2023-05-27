#include <iostream> 
#include <vector> 


//runtime 175ms memoray 66.1MB

class Solution {
public: 
    int totalFruit(std::vector<int> & fruits){
        size_t size = fruits.size(); 
        size_t result = 0; 
        size_t max; 
        int sub[2] = {-1,-1}; 
        if(size <= 2) return size; 
        for(size_t i = 0; i < size - result; i++){
            size_t t; 
            max = 1; 
            sub[0] = fruits.at(i); 
            for (t = i + 1; t < size; t++)   
            {   
                
                max++; 
                if(fruits.at(t) != sub[0]) {
                    
                    sub[1] = fruits.at(t); 
                    break; 
                }
                
            }
            if(t == size - 1) break; 
            
            for(++t; t < size; t++){
                if(fruits.at(t) == sub[0] || fruits.at(t) == sub[1]) max++; 
                else break; 
            } 

            if(result < max) result = max; 

            
        }
        return result; 


    }
};


int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    std::vector fruits = {1,2,1};  
    std::cout << sol.totalFruit(fruits); 
    return 0;
}
