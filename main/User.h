#ifndef MYUSER
#define MYUSER
#include <iostream>
#include <string>
using namespace std;
class User {
private:
	string name;
	int age;
	int id;
	string password;
	string email;
public:
	static int count;
	User();
	User(string name, int age, string password, string email);
	User(const User& user);
	bool operator==(const User& user);
	void setName(string name);
	string getName() const;
	void setPassword(string password);
	string getPassword() const;
	void setEmail(string email);
	string getEmail() const;
	void setAge(int age);
	int getAge() const;
	void setId(int id);
	int getId() const;
	void Display();
	friend ostream& operator<<(ostream& o, const User& user);
	friend istream& operator>>(istream& i, User& user);
};
ostream& operator<<(ostream& o, const User& user);
istream& operator>>(istream& i, User& user);
#endif