#include <iostream> 
#include <vector> 
#include <algorithm>


//Algoritmo sliding window 

class Solution {
private: 
    bool compare(int *freq, int *window){
        for(int i = 0; i < 26; i++){
            if(freq[i] != window[i]) return false; 
        }
        return true; 
    }
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result; 
        int pLen = p.length(); 
        int sLen = s.length(); 
        if(sLen < pLen) return result;
        int freq_p[26] = {0};  
        int window[26] = {0};  
        for(size_t i = 0; i < pLen; i++){
            freq_p[p[i] - 'a']++;    
        }
        for(size_t x = 0; x < pLen; x++){
            window[s[x] - 'a']++;
        }

        if(compare(freq_p, window)){
            result.push_back(0); 
        }
        

        for(size_t y = pLen; y < sLen; y++){
            window[s[y]- 'a']++; 
            window[s[y - pLen] - 'a'] --; 
            if(compare(freq_p, window)) result.push_back(y - pLen + 1); 
        }

        return result; 
    }
};