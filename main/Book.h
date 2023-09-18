#ifndef MYBOOK
#define MYBOOK
#include <iostream>
#include "User.h" 
#include <string>
using namespace std;
class Book {
private:
	string title;
	string isbn;
	int id;
	string category;
	double averageRating;
	double ratings;
	int noOfratings;
	User *author;
public:
	static int count;
	Book();
	Book(string title, string isbn, string category);
	Book(const Book&);
	void setTitle(string title);
	string getTitle() const;
	void setISBN(string isbn);
	string getISBN() const;
	void setId(int id);
	int getId() const;
	void setCategory(string category);
	string getCategory() const;
	void setAuthor(User &author);
	User getAuthor() const;
	void rateBook(double rating);
	double getAverageRating() const;
	bool operator==(const Book&);
	friend ostream& operator<<(ostream& o, const Book& book);
	friend istream& operator>>(istream& i, Book& book);
	~Book();
};
ostream& operator<<(ostream& o, const Book& book);
istream& operator>>(istream& i, Book& book);
#endif
