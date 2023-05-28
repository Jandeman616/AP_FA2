#include <iostream>

#include "src/include/warehouse.hpp"

int main(void)
{
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    std::cout << warehouse.toString() << std::endl;

    warehouse.pickItems("Books", 57); // werkt
    warehouse.pickItems("Boxes", 23); // werkt
    warehouse.pickItems("Books", 398); // zijn te veel items om te vragen

    std::cout << "Na het weghalen van bepaalde producten:" << std::endl << std::endl;

    std::cout << warehouse.toString() << std::endl;
}
