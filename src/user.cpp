//
// Created by yuxudong on 2020/10/4.
//

#include "user.h"
#include <string>
#include <iostream>

User::User(string name) : name(std::move(name)) {
    tel = "";
    roomNum = -1;
    nextUser = nullptr;
}

const string &User::getName() const {
    return name;
}

void User::setName(const string &basicString) {
    User::name = basicString;
}

const string &User::getTel() const {
    return tel;
}

void User::setTel(const string &basicString) {
    User::tel = basicString;
}

int User::getRoomNum() const {
    return roomNum;
}

void User::setRoomNum(int num) {
    User::roomNum = num;
}

User *User::getNextUser() const {
    return nextUser;
}

void User::setNextUser(User *user) {
    User::nextUser = user;
}

User::User(User const &a) {
    this->name = a.name;
    this->tel = a.tel;
    this->roomNum = a.roomNum;
    this->nextUser = a.nextUser;
}

UserList::UserList() {
    userHeader = nullptr;
    currentUser = nullptr;
}

void UserList::add_user(User *a){
    if(currentUser == nullptr){
        userHeader = currentUser = a;
    }else{
        currentUser->setNextUser(a);
        currentUser = a;
    }
}
bool UserList::delete_user(const string& name){
    User * before, * now;
    before = now = userHeader;
    while(now!= nullptr){
        if(now->getName() == name) break;
        before = now;
        now=now->getNextUser();
    }
    if(before!= nullptr && now != nullptr){
        before->setNextUser(now->getNextUser());
        delete now;
        return true;
    }
    return false;
}

bool UserList::update_user(const string& name, User * userA){
    User * before, * now;
    before = now = userHeader;
    while(now!= nullptr){
        if(now->getName() == name) break;
        before = now;
        now=now->getNextUser();
    }
    if(before!= nullptr && now != nullptr){
        userA->setNextUser(now->getNextUser());
        before->setNextUser(userA);
        delete now;
        return true;
    }
    return false;
}

User * UserList::find_user(const string& name){
    User *a = userHeader;
    while(a!= nullptr){
        if(a->getName() == name) break;
        a=a->getNextUser();
    }
    return a;
}
void UserList::printUser(){
    User *a = userHeader;
    while(a!= nullptr){
        cout<< a->getName()<<endl;
        a=a->getNextUser();
    }
}
