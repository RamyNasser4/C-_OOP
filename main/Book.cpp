#include <iostream>
#include <string>
#include "Book.h"
int Book::count = 0;
Book::Book() {
	title = "";
	isbn = "";
	id = ++count;
	category = "";
	averageRating = 0;
	ratings = 0;
	noOfratings = 0;
}
Book::Book(string title, string isbn, string category) {
	this->title = title;
	this->isbn = isbn;
	id = ++count;
	this->category = category;
	averageRating = 0;
	ratings = 0;
	noOfratings = 0;
}
Book::Book(const Book& book) {
	this->title = book.title;
	this->isbn = book.isbn;
	this->id = book.id;
	this->category = book.category;
	this->averageRating = book.averageRating;
	this->ratings = book.ratings;
	this->noOfratings = book.noOfratings;
	this->author = book.author;
}
void Book::setTitle(string title) {
	this->title = title;
}
string Book::getTitle() const {
	return title;
}
void Book::setISBN(string isbn) {
	this->isbn = isbn;
}
string Book::getISBN() const {
	return isbn;
}
void Book::setId(int id) {
	this->id = id;
}
int Book::getId() const {
	return id;
}
void Book::setCategory(string category) {
	this->category = category;
}
string Book::getCategory() const {
	return category;
}
void Book::setAuthor(User& author) {
	this->author = &author;
}
User Book::getAuthor() const {
	if (author != nullptr) {
		return *author;
	}
	else {
		throw runtime_error("Book has no author");
	}
}
void Book::rateBook(double rating) {
	try {
		if (rating > 5 || rating < 0) {
			throw domain_error("invalid rating");
		}
		ratings += rating;
		++noOfratings;
		averageRating = ratings / noOfratings;
	}
	catch(...){
		cout << "invalid rating" << endl;
	}
}
double Book::getAverageRating() const {
	return averageRating;
}
bool Book::operator == (const Book & book) {
	if (this->title.compare(book.title) == 0 && this->isbn.compare(book.isbn) == 0 && this->category.compare(book.category) == 0 && this->id == book.id && this->author == book.author) {
		return true;
	}
	else {
		return false;
	}
}
ostream& operator<<(ostream& o, const Book& book) {
	o << "Book " << book.id << " Info" << endl;
	o << "Title: " << book.title << endl;
	o << "Isbn: " << book.isbn << endl;
	o << "ID: " << book.id << endl;
	o << "Category: " << book.category << endl;
	o << "Average rating: " << book.averageRating << endl;
	if (book.author!= nullptr) {
		o << book.getAuthor() << endl;
	}
	return o;
}
istream& operator>>(istream& i, Book& book) {
	cout << "Enter book title: ";
	i >> book.title;
	cout << "Enter book isbn: ";
	i >> book.isbn;
	cout << "Enter book category: ";
	i >> book.category;
	book.averageRating = 0;
	return i;
}
Book::~Book() {
	author = NULL;
	delete author;
}
