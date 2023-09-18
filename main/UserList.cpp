#include <iostream>
#include <string>
#include "UserList.h"
UserList::UserList() {
	capacity = 0;
	usersCount = 0;
}
UserList::UserList(int capacity) {
	this->capacity = capacity;
	usersCount = 0;
	users = new User[capacity];
}
void UserList::addUser(User& user) {
	if (usersCount < capacity) {
		users[usersCount++] = user;
		users[usersCount - 1].setId(usersCount);
	}
	else {
		cout << "Max capacity reached" << endl;
	}
}
User* UserList::searchUser(string name) {
	bool UserFound = false;
	/*User* searcheduser;*/
	for (int i = 0; usersCount > i; ++i) {
		if (users[i].getName().compare(name) == 0) {
			/*searcheduser = &users[i];*/
			UserFound = true;
			return &users[i];
		}
	}
	if (!UserFound) {
		cout << "User not found" << endl;
		return nullptr;
	}
}
User* UserList::searchUser(int id) {
	bool UserFound = false;
	/*User* searcheduser;*/
	for (int i = 0; usersCount > i; ++i) {
		if (users[i].getId()==id) {
			/*searcheduser = &users[i];*/
			UserFound = true;
			return &users[i];
		}
	}
	if (!UserFound) {
		cout << "User not found" << endl;
		return nullptr;
	}
}
void UserList::deleteUser(int id) {
	bool UserFound = false;
	int deletedindex;
	for (int i = 0; usersCount > i; ++i) {
		if (users[i].getId() == id) {
			UserFound = true;
			deletedindex = i;
			--usersCount;
			--capacity;
			for (int i = deletedindex; usersCount > i; ++i) {
				users[i] = users[i + 1];
			}
		}
	}
	if (!UserFound) {
		cout << "User not found" << endl;
	}
}
ostream& operator<<(ostream& o, UserList& userlist) {
	for (int i = 0; userlist.usersCount > i; ++i) {
		o << userlist.users[i];
	}
	return o;
}
UserList::~UserList(){
	delete[] users;
}