#include "Item.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

#ifndef   INVENTORY_H
#define   INVENTORY_H
using namespace std;

enum DepositResult {
    SUCCESS,
    CAPACITY_FULL,
    WEIGHT_FULL,
    BOTH_FULL
};

class Inventory {
private:
    float maxWeight;
    int maxItems;
    std::vector<Item> items;

public:
    Inventory(float maxWeight, int maxItems);
    
    DepositResult depositItem(const Item &item);
    Item withdrawItem(const std::string &name);
    
    const std::vector<Item> getItems() const;
};

#endif 