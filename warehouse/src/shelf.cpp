#include "include/shelf.hpp"
#include "include/pallet.hpp"

Shelf::Shelf()
{
    this->pallets = {Pallet(), Pallet(), Pallet(), Pallet()};
}

bool Shelf::swapPallet(int slot, int slot2)
{
    Pallet pallet_1 = this->pallets[slot];
    Pallet pallet_2 = this->pallets[slot2];

    // if (pallet_1.getItemName() == pallet_2.getItemName())
    // {
    //     return false;
    // }

    this->pallets[slot] = pallet_2;
    this->pallets[slot2] = pallet_1;
    return true;
}

bool Shelf::isEmpty()
{
    for (Pallet pallet : this->pallets)
    {
        if (!pallet.isEmpty())
        {
            return false;
        }
    }
    return true;
}

bool Shelf::isFull()
{
    for (Pallet pallet : this->pallets)
    {
        if (!pallet.isFull())
        {
            return false;
        }
    }
    return true;
}