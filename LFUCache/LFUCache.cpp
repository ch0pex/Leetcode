#include <iostream>
#include <map>
#include <vector> 



//Solucion valida pero supera el tiempo, mejorar algoritmo

typedef struct Data{
    int value; 
    int uses; 
    int oldness; 
} Data; 


class LFUCache {
private: 
    int _capacity; 
    int _counter;
    std::map<int, Data> cache; 
    

    void deleteLFU(){
        int LFUdata = -1;
        
        for(auto const& data : cache){
            if(LFUdata == -1){
                LFUdata = data.first; 
                continue;
            } 
            if(data.second.uses < cache[LFUdata].uses) LFUdata = data.first; 
            else if (data.second.uses == cache[LFUdata].uses){
                if(data.second.oldness < cache[LFUdata].oldness) LFUdata = data.first; 
            }

        }
        
        cache.erase(LFUdata); 
    }

public:
    LFUCache(int capacity) {
        _capacity = capacity; 
        _counter = 0; 
    }
    
    int get(int key) {
        if(_capacity == 0 ) return (-1); 
        Data* data; 
        try
        {
            data = &cache.at(key);
        }
        catch(const std::out_of_range& e)
        {
            return (-1);
        }
        data->uses++; 
        _counter++; 
        data->oldness = _counter; 
        return data->value; 
        
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            cache[key].value = value; 
            return;  
        }
        
        
        Data newData; 
        _counter++;
        newData.oldness = _counter; 
        newData.value = value; 
        newData.uses = 1; 

        if(cache.size() == _capacity)
            deleteLFU(); 

        cache[key] = newData;  
            
           
    }
};

