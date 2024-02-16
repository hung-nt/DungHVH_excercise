#ifndef _ROOM_HPP_
#define _ROOM_HPP_
#include <string>
using namespace std;
/************************************************
 * Room*****************************************/
class Room {
    protected:
        string category;
        int price;
    public:
        Room(){};
        Room(string category, int price);

        string getCategory();

        void setCategory(string category);
        int getPrice();

        void setPrice(int price);
        virtual string toString() = 0;

        virtual ~Room(){};
};

#endif //_ROOM_HPP_