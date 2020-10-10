#include <iostream>
#include <string>
#include "src/user.h"
#include "src/hotel.h"

using namespace std;

int main() {
    UserList a;
    a.add_user(new User("С��"));
    a.add_user(new User("С��"));
    a.add_user(new User("С��"));
    a.add_user(new User("Ч��"));
    a.add_user(new User("С��"));
    a.printUser();
    a.update_user("С��", new User("С��"));
    a.delete_user("С��");
    a.printUser();
    User *user = a.find_user("С��");
    cout<<user->getName()<<endl;
    return 0;
}