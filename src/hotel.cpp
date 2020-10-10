//
// Created by yuxudong on 2020/10/4.
//

#include "hotel.h"

Hotel::Hotel(int roomId) : roomId(roomId) {
    isUsed = false;
    userName = "";
    nextRoom = nullptr;
}

bool Hotel::isUsed1() const {
    return isUsed;
}

void Hotel::setIsUsed(bool isUsed) {
    Hotel::isUsed = isUsed;
}

const string &Hotel::getUserName() const {
    return userName;
}

void Hotel::setUserName(const string &userName) {
    Hotel::userName = userName;
}

Hotel *Hotel::getNextRoom() const {
    return nextRoom;
}

void Hotel::setNextRoom(Hotel *nextRoom) {
    Hotel::nextRoom = nextRoom;
}

int Hotel::getRoomId() const {
    return roomId;
}


int HotelList::createOneRoom() {
    if (firstRoom == nullptr){
        firstRoom = lastRoom = new Hotel(lastRoomId+1);
    }else{
        lastRoom->setNextRoom(new Hotel(lastRoomId+1));
        lastRoom = lastRoom->getNextRoom();
    }
    roomAcount ++;
    lastRoomId ++;
    return roomAcount;
}

void HotelList::deleteOneRoom(int roomId) {
    Hotel *iter, *before;
    iter = before = firstRoom;
    while(iter != nullptr) {
        if(iter->getRoomId() == roomId){
            break;
        }
        before = iter;
        iter=iter->getNextRoom();
    }
    if(iter!= nullptr && !iter->isUsed1()){
        before->setNextRoom(iter->getNextRoom());
        delete iter;
        roomAcount--;
    }
}

bool HotelList::checkUsed(int roomId) {
    Hotel * iter = firstRoom;
    while(iter != nullptr) {
        if(iter->getRoomId() == roomId){
           return iter->isUsed1();
        }
        iter=iter->getNextRoom();
    }
    return true;
}

int HotelList::checkIn(const string& userName) {
    Hotel * iter = firstRoom;
    while(iter != nullptr) {
        if(!iter->isUsed1()){
            break;
        }
        iter=iter->getNextRoom();
    }
    if(iter == nullptr){
        return -1;
    }else{
        iter->setIsUsed(true);
        iter->setUserName(userName);
        return iter->getRoomId();
    }
}

bool HotelList::checkOut(int roomId) {
    Hotel * iter = firstRoom;
    while(iter != nullptr) {
        if(iter->getRoomId() == roomId){
            iter->setIsUsed(false);
            iter->setUserName("");
            return true;
        }
        iter=iter->getNextRoom();
    }
    return false;
}

HotelList::HotelList() {
    firstRoom = lastRoom = nullptr;
    roomAcount = lastRoomId = 0;
}
