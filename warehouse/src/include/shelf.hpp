#pragma once
#include <array>

#include "icontainer.hpp"
#include "pallet.hpp"

class Shelf : public IContainer
{
    public:
        std::array<Pallet, 4> pallets;

        Shelf();
        bool swapPallet(int slot, int slot2);
        bool isEmpty() override;
        bool isFull() override;
};