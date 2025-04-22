#include "Inventory.h"
#include <iostream>

#include <iostream>
#include "Item.h"
#include "Inventory.h"

int main() {
    try {
        Inventory inventory(-10, 16);
       
        Item bow(5, "Bow");
        Item helmet(1, "Helmet");
        Item armor(4, "Armor");

        
       cout << "Adding items to inventory"<<endl;

        int result = inventory.depositItem(bow);
       if (result == DepositResult::SUCCESS) {
            cout << "1 "<< "Added Bow."<<endl;
        }

         result = inventory.depositItem(helmet);
         if(result == DepositResult::SUCCESS){
             cout<<"2"<<"Added Helmet."<<endl;
        }

        result = inventory.depositItem(armor);
        if (result == DepositResult::SUCCESS) {
            cout << "3 "<< "Added Armor."<<endl;
        }

        cout << "Withdrawing Helmet"<<endl;
        Item removedItem = inventory.withdrawItem("Helmet");
        cout << "-"<< "Removed: "  <<removedItem.getName() << endl;

        cout << "Current Inventory Items: "<<endl;
        for (const auto &item : inventory.getItems()) {
            cout << item.getName()<<" " <<item.getWeight() <<"kgs"<<endl;
        }

    } catch (const char*msg ) {
       cerr<<"Error:"<<endl;
    }

    return 0;
}