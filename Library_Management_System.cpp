#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Book
{
private:                         //declaring private variables
    string title;
    string author;
    string isbn;
    bool available;

public:
    void setTitle(const string &title_x)
    {

        title = title_x;
    }
    void setAuthor(const string &autName)
    {
        author = autName;
    }
    void setISBN(const string &new_id)
    {
        isbn = new_id;
    }
    void setAvailable(bool newAvailable)
    {
        available = newAvailable;
    }

    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    string getISBN() const
    {
        return isbn;
    }
    string getAvailable() const
    {
        return (available ? "Available" : "Checked out");
        cout << "---------------------------";
    }

    void borrowBook()
    {
        if (available)
        {
            available = false;
            cout << "Book borrowed." << endl;
            cout << "---------------------------";
        }
        else
        {
            cout << "Error:Book already issued." << endl;
            cout << "---------------------------";
        }
    }

    void returnBook()
    {
        if (!available)
        {
            available = true;
            cout << "Book returned" << endl;
            cout << "---------------------------";
        }
        else
        {
            cout << "Error: Book is available and can't be returned" << endl;
            cout << "---------------------------";
        }
    }
};

int main()
{
    const int maxBooks = 100;
    Book library[maxBooks];
    Book newBook;
    string title, author, isbn;

    int choice;
    int numBooks = 0;
    bool exitFlag = false;
    while (!exitFlag)
    {

        cout << endl << endl <<  "Welcome to the library management system!" << endl
             << endl
             << "Menu:"
             << endl
             << "1. Add book" << endl
             << "2. Remove book" << endl
             << "3. Search for book" << endl
             << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (numBooks == maxBooks)
            {
                cout << "Error: The library is full" << endl;
                cout << "---------------------------";
                continue;
            }

            cout << "Enter Book title: ";
            cin.ignore();
            getline(cin, title);
            newBook.setTitle(title);

            cout << "Enter book author: ";
            getline(cin, author);
            newBook.setAuthor(author);

            cout << "Enter Book ISBN: ";
            cin >> isbn;
            newBook.setISBN(isbn);

            newBook.setAvailable(true);
            library[numBooks] = newBook;
            numBooks++;

            cout << endl
                 << "Book added to library";
        }
        else if (choice == 2)
        {
            cout << "Enter Book ISBN: ";
            cin.ignore();
            cin >> isbn;
            newBook.setISBN(isbn);

            bool foundBook = false;
            for (int i = 0; i < numBooks; i++)
            {
                if (library[i].getISBN() == isbn)
                {
                    // delete library[i];
                    library[i] = library[numBooks - 1];
                    numBooks--;
                    foundBook = true;
                    cout << "Book removed from library." << endl;
                    cout << "---------------------------";
                    break;
                }
            }

            if (!foundBook)
            {
                cout << "Error: Book not found";
                cout << "---------------------------";
            }
        }
        else if (choice == 3)
        {
            cout << "Enter book ISBN: ";
            cin.ignore();
            cin >> isbn;

            bool foundBook = false;

            for (int i = 0; i < numBooks; i++)
            {
                if (library[i].getISBN() == isbn)
                {
                    cout << "Book info: " << endl;
                    cout << "Title: " << library[i].getTitle() << endl;
                    cout << "Author: " << library[i].getAuthor() << endl;
                    cout << "ISBN: " << library[i].getISBN() << endl;
                    cout << "Availablity: " << library[i].getAvailable() << endl;
                    cout << "---------------------------";
                    foundBook = true;
                    break;
                }
            }
                if (!foundBook)
                {
                    cout << "Error: Book not found." << endl;
                    cout << "---------------------------";
                }
            
        }
        else if (choice == 4)
        {

            cout << "Thank you for using the library management system!" << endl;
            cout << "---------------------------";
            exitFlag = true;                                                         //STOPS while loop and exicts code
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            cout << "---------------------------";
        }
    }
    return 0;
}
