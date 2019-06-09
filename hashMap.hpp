#ifndef hashMap_hpp
#define hashMap_hpp

#include <stdio.h>
#include<iostream>
#include <string>

using namespace std;

class hashMap {
    
private:
    
    int length;
    int *counts;
    string **Hmap;
    int mapSize;
    
public:
    
    
    hashMap(int size = 2000000);
    ~hashMap();
    //-----Important Functions-----
    int mappingFunc(string key);
    void insertToMap(string key);
    void printMostRepTen()const;
    //-----------------------------
    int getLength();
    void print() const;
    
};

#endif
