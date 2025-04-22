#include "Item.h"
#include <stdexcept>

using namespace std;

Item::Item(float weight, const std::string &name) : weight(weight), name(name) {
    if (weight < 0) {
        throw std::invalid_argument("Weight cannot be negative");
    }
}

float Item::getWeight() const {
    return weight;
}

const std::string Item::getName() const {
    return name;
}


//bash g++ -std=c++11 Item.cpp -o Item