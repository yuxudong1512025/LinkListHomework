//
// Created by yuxudong on 2020/10/4.
//

#ifndef PROJECT1_USER_H
#define PROJECT1_USER_H
#include <string>

using namespace std;

class User {
public:
    User()= default;;

    explicit User(string name);

    User(User const &a);

    const string &getName() const;

    void setName(const string &basicString);

    const string &getTel() const;

    void setTel(const string &basicString);

    int getRoomNum() const;

    void setRoomNum(int num);

    User *getNextUser() const;

    void setNextUser(User *user);

private:
    string name;
    string tel;
    int roomNum{};
    User *nextUser{};

};

class UserList {
public:
    UserList();

    void add_user(User *a);

    bool delete_user(const string& name);

    bool update_user(const string& name, User * userA);

    User * find_user(const string& name);

    void printUser();
private:
    User *userHeader;
    User *currentUser;
};

#endif //PROJECT1_USER_H
