//Kashana Johnson
//Module 3 Assignment
//November 13 2025
//Library Management System with Templates
//Summary: A generic library management system where the program can manage different types of books (e.g., textbooks, novels, e-books) using templates
#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2, typename T3>
class Book {
private: // private variables
    T1 title;
    T2 author;
    T3 price;

public: // creating a constructor
    Book(T1 t, T2 a, T3 p) : title(t), author(a), price(p) {}
    void display() {
        cout << "Title: " << title << "Author:" << author << "Price: $" << price << endl;
    }

};

class Library {
private:
    Book <string, string, float>** books; //Array of book objects
    int capacity;
    int count;

public: //Constructor to allocate money for book storage
    Library(int size) {
        capacity = size;
        count = 0;
        books = new Book<string, string, float>* [capacity];
    }

    //Adding a book to the library
    void addBook(string title, string author, float price) {
        if (count < capacity) {
            books[count] = new Book <string, string, float>(title, author, price); count++;
        }
        else {
            cout << "Library is full" << endl;
        }
    }
    
    void showBooks() {
        for (int i = 0; i < count; i++) {
            books[i]->display();
        }// end for loop
    }// end void showBooks
    //destructor
    ~Library() {
        for (int i = 0; i < count; i++) {
            delete books[i];
        }
    }
};

int main() {
    Library lib(3); // creating and intializing a lib class with 3 books
    lib.addBook("C++ Basics ", "John Doe ", 29.99);

    cout << "\nLibrary Collection\n";
    lib.showBooks();

}