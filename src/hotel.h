//
// Created by yuxudong on 2020/10/4.
//

#ifndef PROJECT1_HOTEL_H
#define PROJECT1_HOTEL_H
#include <string>
using namespace std;

class Hotel {
private:
    int roomId;
public:
    int getRoomId() const;

public:
    Hotel(int roomId);

private:
    bool isUsed;
public:
    bool isUsed1() const;

    void setIsUsed(bool isUsed);

    const string &getUserName() const;

    void setUserName(const string &userName);

    Hotel *getNextRoom() const;

    void setNextRoom(Hotel *nextRoom);

private:
    string userName;
    Hotel *nextRoom;
public:
};

class HotelList {
private:
    Hotel *firstRoom;
    Hotel *lastRoom;
    int roomAcount;
    int lastRoomId;
public:
    HotelList();

    int createOneRoom();
    void deleteOneRoom(int roomId);
    bool checkUsed(int roomId);
    int checkIn(const string& userName);
    bool checkOut(int roomId);

    Hotel *getFirstRoom() {
        return firstRoom;
    }
    Hotel *setFirstRoom(Hotel *temp) {
        this->firstRoom = temp;
        return firstRoom;
    }
};

#endif //PROJECT1_HOTEL_H
