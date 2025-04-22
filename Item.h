#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>

#ifndef ITEM_H
#define ITEM_H


using namespace std;

class Item 
{
    private:
    
    float weight;
    string name;

    public:
   
    Item(float weight, const std:: string &name);
    float getWeight() const;
    const string getName() const;

};    

    #endif