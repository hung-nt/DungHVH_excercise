#include "Room.hpp"
/************************************************
 * Room******************************************
*************************************************/

Room::Room(string category, int price)
{
    this->category = category;
    this->price = price;
}

string Room::getCategory()
{
    return category;
}
void Room::setCategory(string category)
{
    this->category = category;
}

int Room::getPrice()
{
    return price;
}

void Room::setPrice(int price)
{
    this->price = price;
}
