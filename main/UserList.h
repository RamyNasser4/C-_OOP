#pragma once
#ifndef MYUSERLIST
#define MYUSERLIST
#include <iostream>
#include <string>
#include "User.h"
using namespace std;
class UserList {
private:
	User* users;
	int capacity;
	int usersCount;
public:
	UserList();
	UserList(int capacity);
	void addUser(User& user);
	User* searchUser(string name);
	User* searchUser(int id);
	void deleteUser(int id);
	friend ostream& operator<<(ostream& o, UserList& userlist);
	~UserList();
};
ostream& operator<<(ostream& o, UserList& userList);
#endif
