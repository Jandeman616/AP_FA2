#pragma once

#include <vector>
#include <iostream>
#include <sstream>

#include "employee.hpp"
#include "shelf.hpp"

class Warehouse
{
    public:
        std::vector<Employee> employees;
        std::vector<Shelf> shelves;

        Warehouse();
        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(std::string itemName, int itemCount);
        std::string toString();
};