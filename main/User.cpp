#include "User.h"
#include <iostream>
#include <exception>
using namespace std;
int User::count = 0;
User::User() {
	name = "";
	age = 0;
	password = "";
	email = "";
	id = ++count;
}
User::User(string name, int age, string password, string email) {
	this->name = name;
	this->age = age;
	this->password = password;
	this->email = email;
	id = ++count;
}
User::User(const User& user) {
	this->name = user.name;
	this->age = user.age;
	this->password = user.password;
	this->email = user.email;
	this->id = user.id;
}
bool User::operator==(const User& user) {
	if (this->name.compare(user.name)==0 && this->age == user.age && this->email.compare(user.email) == 0  && this->id == user.id) {
		return true;
	}
	else {
		return false;
	}
}
void User::setName(string name) {
	this->name = name;
}
string User::getName() const {
	return name;
}
void User::setPassword(string password) {
	this->password = password;
}
string User::getPassword() const {
	return password;
}
void User::setEmail(string email) {
	this->email = email;
}
string User::getEmail() const {
	return email;
}
void User::setAge(int age) {
	this->age = age;
}
int User::getAge() const {
	return age;
}
void User::setId(int id) {
	this->id = id;
}
int User::getId() const {
	return id;
}
void User::Display(){
	cout<< "User " << id << " info" << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "ID: " << id << endl;
	cout << "Email: " << email << endl;
}
ostream& operator<<(ostream& o, const User& user) {
	return o << "User " << user.id << " info" << endl
	<< "Name: " << user.name << endl
    << "Age: " << user.age << endl
    << "ID: " << user.id << endl
	<< "Email: " << user.email << endl;
}
istream& operator>>(istream& i, User& user) {
	cout << "Enter username: ";
	i >> user.name;
	cout << "Enter user age: ";
	cin >> user.age;
	cout << "Enter user email: ";
	cin >> user.email;
	cout << "Enter user password: ";
	cin >> user.password;
	return i;
}