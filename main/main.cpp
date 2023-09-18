#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
using namespace std;
void manage_user_menu(UserList* userlist,int id) {
	while (true) {
		cout << "1- Delete user" << endl;
		cout << "2- Return to users Menu" << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			userlist->deleteUser(id);
			break;
		}
		else if (answer == 2) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
}
void search_user_menu(UserList* userlist) {
	while (true) {
		cout << "SEARCH FOR A USER" << endl;
		cout << "1- Search by name" << endl;
		cout << "2- Search by id" << endl;
		cout << "3- Return to users Menu" << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			cout << "Enter Name: ";
			string name;
			cin >> name;
			bool userfound = true;
			if (userlist->searchUser(name) != nullptr) {
				cout << *(userlist->searchUser(name));
			}
			else {
				userfound = false;
			}
			if (userfound) {
				manage_user_menu(userlist, userlist->searchUser(name)->getId());
				break;
			}
		}
		else if (answer == 2) {
			cout << "Enter ID: ";
			int id;
			cin >> id;
			bool userfound = true;
			if (userlist->searchUser(id) != nullptr) {
				cout << *(userlist->searchUser(id));
			}
			else {
				userfound = false;
			}
			if (userfound) {
				manage_user_menu(userlist, id);
				break;
			}
		}
		else if (answer == 3) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
}
void users_menu(UserList *userlist) {
	while (true) {
		cout << "USERS MENU" << endl;
		cout << "1- Create a USER and add it to the list" << endl;
		cout << "2- Search for a user" << endl;
		cout << "3- Display all users" << endl;
		cout << "4- Back to the main" << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			cout << "Enter user information" << endl;
			User u1;
			cin >> u1;
			userlist->addUser(u1);
		}
		else if (answer == 2) {
			search_user_menu(userlist);
		}
		else if (answer == 3) {
			cout << *userlist;
		}
		else if (answer == 4) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
}
void manage_searched_book_menu(BookList* booklist,UserList *userlist,Book *b) {
	while (true) {
		cout << "1- Update author" << endl;
		cout << "2- Update name" << endl;
		cout << "3- Update Category" << endl;
		cout << "4- Delete Book" << endl;
		cout << "5- rate book" << endl;
		cout << "6- Get back to books menu" << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			cout << "Enter author (user) id :" << endl;
			int id;
			cin >> id;
			if (userlist != nullptr) {
				if (userlist->searchUser(id) != nullptr) {
					b->setAuthor(*(userlist->searchUser(id)));
					break;
				}
				else {
					cout << "No author found with id = " << id << endl;
				}
			}
			else {
				cout << "No author found with id = " << id << endl;
			}
		}
		else if (answer == 2) {
			cout << "Enter name :" << endl;
			string name;
			cin >> name;
			b->setTitle(name);
		}
		else if (answer == 3) {
			cout << "Enter category :" << endl;
			string category;
			cin >> category;
			b->setCategory(category);
		}
		else if (answer == 4) {
			booklist->deleteBook(b->getId());
			break;
		}
		else if (answer == 5) {
			cout << "Enter rating value :" << endl;
			double rating;
			cin >> rating;
			b->rateBook(rating);
		}
		else if (answer == 6) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
}
void search_book_menu(BookList* booklist,UserList* userlist) {
	while (true) {
		cout << "SEARCH FOR A BOOK" << endl;
		cout << "1- Search by name" << endl;
		cout << "2- Search by id" << endl;
		cout << "3- Return to Books Menu" << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			cout << "Enter Name: ";
			string name;
			cin >> name;
			bool bookfound = true;
			if (booklist->searchBook(name) != nullptr) {
				cout << *(booklist->searchBook(name));
			}
			else {
				bookfound = false;
			}
			if (bookfound) {
				manage_searched_book_menu(booklist, userlist, booklist->searchBook(name));
				break;
			}
		}
		else if (answer == 2) {
			cout << "Enter ID: ";
			int id;
			cin >> id;
			bool bookfound = true;
			if (booklist->searchBook(id) != nullptr) {
				cout << *(booklist->searchBook(id));
			}
			else {
				bookfound = false;
			}
			if (bookfound) {
				manage_searched_book_menu(booklist, userlist, booklist->searchBook(id));
				break;
			}
		}
		else if (answer == 3) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
}
void manage_addedbook_menu(Book *b,UserList* userlist) {
	while (true)
	{
		cout << "1- Assign Author" << endl;
		cout << "2- continue" << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			cout << "Enter author (user) id :" << endl;
			int id;
			cin >> id;
			if (userlist != nullptr) {
				if (userlist->searchUser(id) != nullptr) {
					b->setAuthor(*(userlist->searchUser(id)));
					break;
				}
				else {
					cout << "No author found with id = " << id << endl;
				}
			}
			else {
				cout << "No author found with id = " << id << endl;
			}
		}
		else if (answer == 2) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
}
void books_menu(BookList* booklist, UserList* userlist) {
	while (true) {
		cout << "BOOKS MENU" << endl;
		cout << "1- Create a book and add it to the list" << endl;
		cout << "2- Search for a book" << endl;
		cout << "3- Display all books (with book rating)" << endl;
		cout << "4- Get the highest rating" << endl;
		cout << "5- Get all books of a user" << endl;
		cout << "6- Back to the main menu" << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			cout << "Enter book information" << endl;
			Book *b = new Book;
			cin >> *b;
			manage_addedbook_menu(b, userlist);
			booklist->addBook(*b);
			b = NULL;
			delete b;
		}
		else if (answer == 2) {
			search_book_menu(booklist, userlist);
		}
		else if (answer == 3) {
			cout << *booklist;
		}
		else if (answer == 4) {
			cout << booklist->getTheHighestRatedBook();
		}
		else if (answer == 5) {
			cout << "Enter ID :" << endl;
			int id;
			cin >> id;
			if (userlist != nullptr) {
				if (userlist->searchUser(id) != nullptr) {
					booklist->getBooksForUser(*(userlist->searchUser(id)));
				}
				else {
					cout << "No author found with id = " << id << endl;
				}
			}
			else {
				cout << "No author found with id = " << id << endl;
			}
		}
		else if (answer == 6) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
}
void main_menu(bool &Usersadded,bool &Booksadded) {
	UserList* userlist = nullptr;
	BookList* booklist = nullptr;
	while (true) {
		cout << "Select one of the following choices : " << endl;
		cout << "1- Books Menu" << endl;
		cout << "2- Users Menu" << endl;
		cout << "3- Exit " << endl;
		int answer;
		cin >> answer;
		if (answer == 1) {
			if (!Booksadded) {
				int capacity;
				cout << "How many books will be added?" << endl;
				cin >> capacity;
				Booksadded = true;
				booklist = new BookList(capacity);
			}
			books_menu(booklist, userlist);
		}
		else if (answer == 2) {
			if (!Usersadded) {
				int capacity;
				cout << "How many users will be added?" << endl;
				cin >> capacity;
				Usersadded = true;
				userlist = new UserList(capacity);
			}
			users_menu(userlist);
		}
		else if (answer == 3) {
			break;
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
	userlist = NULL;
	booklist = NULL;
	delete userlist;
	delete booklist;
}
int main() {
	bool Usersadded = false;
	bool Booksadded = false;
	main_menu(Usersadded,Booksadded);
}