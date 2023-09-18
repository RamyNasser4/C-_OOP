#pragma once
#ifndef MYBOOKLIST
#define MYBOOKLIST
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;
class BookList {
private:
	Book* books;
	int capacity;
	int booksCount;
public:
	BookList();
	BookList(int capacity);
	BookList(const BookList& booklist);
	void addBook(Book& book);
	Book* searchBook(string title);
	Book* searchBook(int id);
	void deleteBook(int id);
	Book getTheHighestRatedBook();
	void getBooksForUser(User& user);
	Book& operator[](int position);
	friend ostream& operator<<(ostream& o, BookList& booklist);
	~BookList();
};
ostream& operator<<(ostream& o, BookList& booklist);
#endif