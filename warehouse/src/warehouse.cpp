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

    // Controleer of er een medewerker is die tijd heeft en een forklift kan besturen
    for (Employee employee : this->employees)
    {
        if (!employee.getBusy() && employee.getForkliftCertificate())
        {
            canRearrange = true;
        }
    }

    // Als dit kan doe dan een bubblesort op de 4 pallets
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
    // Controleer hoeveel items er zijn met de gegeven naam
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

    // Kijk of er genoeg items zijn om de aan de gevraagde hoeveelheid te voldoen
    // En pak elke keer een item totdat de gevraagde hoeveelheid is gepakt
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

std::ostream& operator<<(std::ostream& stream, Warehouse& warehouse)
{
    stream << "Warehouse:" << std::endl << "[" << std::endl;
    for (Shelf& shelf : warehouse.shelves) 
    {
        stream << "  Shelf:" << std::endl << "  (" << std::endl;
        for (Pallet& pallet : shelf.pallets) 
        {
            stream << "    Pallet: " << pallet.getItemName();
            stream << ", stock: " << pallet.getItemCount() << "/" << (pallet.getItemCount() + pallet.getRemainingSpace()) << std::endl;
        }
        stream << "  )" << std::endl;
    }
    stream << "]" << std::endl;
    return stream;
}