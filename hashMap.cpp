#include "hashMap.hpp"

hashMap::hashMap(int size){
    if(size > 0){
        length = 0;
        Hmap = new string*[size];
        counts = new int[size];
    }
    
    for (int i = 0; i < size; i++){
        Hmap[i] = NULL;
        counts[i] = 0;
    }
    mapSize = size;
}

int hashMap::getLength(){
    return length;
}

//Creates nearly a unique number for every word in the data set
int hashMap::mappingFunc(string key){
    int hash = 0;
    int primeNum = 71;
    
    for(int i = 0; i<key.length(); i++){
        hash = primeNum * hash + key[i];
    }
    hash = hash % mapSize;
    return hash;
}

//Maps the word to the index we get from the mappingFunc and changes the counts array parallel to the Hmap.
void hashMap::insertToMap(string key){
    unsigned int keyPos = mappingFunc(key);
    keyPos = keyPos % mapSize;
    
    while (Hmap[keyPos] != NULL){
        if (*Hmap[keyPos] != key){
            keyPos = (keyPos + 1) % mapSize;
        }
        else {
            counts[keyPos]++;
            return;
        }
    }
    Hmap[keyPos] = new string(key);
    counts[keyPos]++;
    length++;
}

//Sorts the counts array just for the first 10 elements and prints them.
void hashMap::printMostRepTen()const{
    int count = 0;
    for (int i = 0; i < 10; i++){
        int greatest = 0;
        int greatesttNumPos = 0;
        for (int i = 1; i < mapSize; i++){
            if (counts[i] > greatest){
                greatest = counts[i];
                greatesttNumPos = i;
                count++;
            }
        }
        cout << *Hmap[greatesttNumPos] << " " << greatest << endl;
        
        counts[greatesttNumPos] = 0;
    }
    
}

//Prints every word in the Hmap with nearly a random order.
void hashMap::print()const{
    for (int i = 1; i < mapSize; i++){
        if (counts[i] != 0){
            cout << *Hmap[i] << "  "<< counts[i] << endl;
        }
    }
}

hashMap::~hashMap(){
    delete [] counts;
    delete [] Hmap;
}
