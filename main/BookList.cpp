#include <iostream>
#include <string>
#include "BookList.h"
BookList::BookList() {
	capacity = 0;
	booksCount = 0;
}
BookList::BookList(int capacity) {
	this->capacity = capacity;
	books = new Book[capacity];
	booksCount = 0;
}
BookList::BookList(const BookList& booklist) {
	this->capacity = booklist.capacity;
	this->booksCount = booklist.capacity;
	this->books = booklist.books;
}
void BookList::addBook(Book& book) {
	books[booksCount++] = book;
	books[booksCount - 1].setId(booksCount);
}
Book* BookList::searchBook(string title) {
	bool BookFound = false;
	for (int i = 0; booksCount > i; ++i) {
		if (books[i].getTitle().compare(title) == 0) {
			BookFound = true;
			return &books[i];
		}
	}
	if (!BookFound) {
		cout << "Book not found" << endl;
		return nullptr;
	}
}
Book* BookList::searchBook(int id) {
	bool BookFound = false;
	for (int i = 0; booksCount > i; ++i) {
		if (books[i].getId() == id) {
			BookFound = true;
			return &books[i];
		}
	}
	if (!BookFound) {
		cout << "Book not found" << endl;
		return nullptr;
	}
}
void BookList::deleteBook(int id) {
	bool BookFound = false;
	int deletedindex;
	for (int i = 0; booksCount > i; ++i) {
		if (books[i].getId() == id) {
			BookFound = true;
			deletedindex = i;
			--booksCount;
			--capacity;
			for (int i = deletedindex; booksCount > i; ++i) {
				books[i] = books[i + 1];
			}
		}
	}
	if (!BookFound) {
		cout << "Book not found" << endl;
	}
}
Book BookList::getTheHighestRatedBook() {
	double max = books[0].getAverageRating();
	Book HighestRatedBook = books[0];
	for (int i = 1; booksCount > i; ++i) {
		if (books[i].getAverageRating() > max) {
			max = books[i].getAverageRating();
			HighestRatedBook = books[i];
		}
	}
	return HighestRatedBook;
}
void BookList::getBooksForUser(User& user) {
	bool hasBooks = false;
	for (int i = 0; booksCount > i; ++i) {
		try {
			if (books[i].getAuthor() == user) {
				hasBooks = true;
				cout << books[i];
			}
		}
		catch(...){
		}
	}
	if (!hasBooks) {
		cout << "This user has no books" << endl;
	}
}
Book& BookList::operator[](int position) {
	if (position >= 0 || position < booksCount) {
		return books[position];
	}
	else {
		cout << "invalid position" << endl;
	}
}
ostream& operator<<(ostream& o, BookList& booklist) {
	for (int i = 0; booklist.booksCount > i; ++i) {
		o << booklist.books[i];
	}
	return o;
}
BookList::~BookList() {
	delete[] books;
}
