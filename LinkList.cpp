#include <iostream>
#include <string>

using namespace std;

class user {
private:
    string name;
    user *nextUser{};
public:
    explicit user(string name) {
        this->name = std::move(name);
        this->nextUser = nullptr;
    }
    user(user const &a){
        this->name= a.name;
    }
    void setNextUser(user *user){
        this->nextUser = user;
    }
    string getName() {
        return name;
    }
    user * getNextUser(){
        return nextUser;
    }
};

class Linklist {
private:
    user *userHeader;
    user *currentUser;
public:
    Linklist(){
        userHeader = nullptr;
        currentUser = nullptr;
    }
    void add_user(user *a){
        if(currentUser == nullptr){
            userHeader = currentUser = a;
        }else{
            currentUser->setNextUser(a);
            currentUser = a;
        }
    }
    bool delete_user(const string& name){
        user * before, * now;
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

    bool update_user(const string& name, user * userA){
        user * before, * now;
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
    
    user * find_user(const string& name){
        user *a = userHeader;
        while(a!= nullptr){
            if(a->getName() == name) break;
            a=a->getNextUser();
        }
        return a;
    }
    void printUser(){
        user *a = userHeader;
        while(a!= nullptr){
            cout<< a->getName()<<endl;
            a=a->getNextUser();
        }
    }
};
int main() {
    Linklist a;
    a.add_user(new user("小明"));
    a.add_user(new user("小1"));
    a.add_user(new user("小2"));
    a.add_user(new user("小3"));
    a.add_user(new user("小4"));
    a.printUser();
    a.update_user("小3", new user("小5"));
    a.delete_user("小3");
    a.printUser();
    user *user = a.find_user("小明");
    cout<<user->getName()<<endl;
    return 0;
}