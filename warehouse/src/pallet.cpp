#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount)
{
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
}

Pallet::Pallet()
{
    this->itemName = "";
    this->itemCapacity = 0;
    this->itemCount = 0;
}

std::string Pallet::getItemName()
{
    return this->itemName;
}

int Pallet::getItemCount()
{
    return this->itemCount;
}

int Pallet::getRemainingSpace()
{
    return this->itemCapacity - this->itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity)
{
    if (this->itemCount == 0)
    {
        return false;
    }

    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    return true;
}

bool Pallet::takeOne()
{
    if (this->isEmpty())
    {
        return false;
    }

    this->itemCount--;
    return true;
}

bool Pallet::putOne()
{
    if (this->isFull())
    {
        return false;
    }

    this->itemCount++;
    return true;
}

bool Pallet::isEmpty()
{
    return (this->getItemCount() == 0);
}

bool Pallet::isFull()
{
    return (this->getRemainingSpace() == 0);
}