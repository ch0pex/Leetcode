#include <iostream> 

// NO CUMPLE CON LOS REQUISITOS DE TIEMPO, ES UNA SOLUCION POR FUERZA BRUTA

class Solution {
public:

    bool checkPerm(std::string s1, std::string sub){
        bool found; 
        std::string empty = ""; 
        for(char c : sub){
            int i; 
            found = false; 
            for(i = 0; i < s1.length(); i++){
                if(s1[i] == c){
                    found = true; 
                    break; 
                }
                         
            }
            if(!found) return false; 
            s1.replace(i, 1,empty); 
        }
        if(s1.length() > 0) return false; 
        return true;   
    }

    bool checkInclusion(std::string s1, std::string s2) {
        int len = s1.length();
        int incl = false; 
        for(int i = 0; i < s2.length(); i++){  
            std::string sub = s2.substr(i,len); 
            incl = checkPerm(s1, sub); 
            if(incl) return true; 
        }
        return false; 

    }
};

