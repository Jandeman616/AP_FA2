#include "include/warehouse.hpp"

Warehouse::Warehouse()
{
    
}

void Warehouse::addEmployee(Employee employee)
{
    this->employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf)
{
    this->shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf)
{
    bool canRearrange = false;

    for (Employee employee : this->employees)
    {
        if (!employee.getBusy() && employee.getForkliftCertificate())
        {
            canRearrange = true;
        }
    }

    while (canRearrange)
    {
        bool swapped = false;

        for (int i = 1; i < 4; i++)
        {
            if (shelf.pallets[i - 1].getItemCount() > shelf.pallets[i].getItemCount())
            {
                if (shelf.swapPallet(i - 1, i))
                {
                    swapped = true;
                }
            }
        }

        if (!swapped)
        {
            break;
        }
    }

    return canRearrange;
}

bool Warehouse::pickItems(std::string itemName, int itemCount)
{
    int items = 0;
    for (Shelf shelf : this->shelves) 
    {
        for (Pallet pallet : shelf.pallets) 
        {
            if (pallet.getItemName() == itemName) 
            {
                items += pallet.getItemCount();
            }
        }
    }

    int reqItems = itemCount;
    if (items >= reqItems) 
    {
        for (Shelf& shelf : this->shelves) 
        {
            for (Pallet& pallet : shelf.pallets) 
            {
                if (pallet.getItemName() == itemName) 
                {
                    while (pallet.takeOne())
                    {
                        reqItems--;

                        if (reqItems == 0)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}