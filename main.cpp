#include <iostream>
#include <string>
#include "src/user.h"
#include "src/hotel.h"

using namespace std;

int main() {
    UserList a;
    a.add_user(new User("小明"));
    a.add_user(new User("小红"));
    a.add_user(new User("小慌"));
    a.add_user(new User("效率"));
    a.add_user(new User("小蓝"));
    a.printUser();
    a.update_user("小红", new User("小慌"));
    a.delete_user("小蓝");
    a.printUser();
    User *user = a.find_user("小红");
    cout<<user->getName()<<endl;
    return 0;
}