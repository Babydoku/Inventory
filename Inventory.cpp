#include "Inventory.h"

using namespace std;

Inventory::Inventory(float maxWeight, int maxItems) : maxWeight(maxWeight), maxItems(maxItems) {
    if (maxWeight < 0) {
        throw std::invalid_argument("Max weight cannot be negative");
    }
    if (maxItems % 8 != 0) {
        throw std::invalid_argument("Max items must be divisible by 8");
    }
}

DepositResult Inventory::depositItem(const Item &item) {
    float currentWeight = 0;
    for (const auto &i : items) {
        currentWeight += i.getWeight();
    }

    if (items.size() >= maxItems && currentWeight + item.getWeight() > maxWeight) {
        return DepositResult::BOTH_FULL;
    } else if (items.size() >= maxItems) {
        return DepositResult::CAPACITY_FULL;
    } else if (currentWeight + item.getWeight() > maxWeight) {
        return DepositResult::WEIGHT_FULL;
    }

    items.push_back(item);
    return DepositResult::SUCCESS;
}

Item Inventory::withdrawItem(const std::string &name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == name) {
            Item item = *it;
            items.erase(it);
            return item;
        }
    }
    throw "Item not found";
}

    const std::vector<Item> Inventory::getItems() const {
        return items; 
}
