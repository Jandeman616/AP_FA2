#pragma once
#include <string>

#include "icontainer.hpp"

class Pallet : public IContainer
{
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;
    
    public:
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();
        std::string getItemName();
        int getItemCount();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();
        bool isEmpty() override;
        bool isFull() override;
};