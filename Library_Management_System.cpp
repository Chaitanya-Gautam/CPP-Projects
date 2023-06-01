#include <iostream>
#include <string>
#include <algorithm>

class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    void setTitle(const std::string& title_x)
    {
        title = title_x;
    }

    void setAuthor(const std::string& autName)
    {
        author = autName;
    }

    void setISBN(const std::string& new_id)
    {
        isbn = new_id;
    }

    void setAvailable(bool newAvailable)
    {
        available = newAvailable;
    }

    std::string getTitle() const
    {
        return title;
    }

    std::string getAuthor() const
    {
        return author;
    }

    std::string getISBN() const
    {
        return isbn;
    }

    std::string getAvailable() const
    {
        return (available ? "Available" : "Checked out");
        std::cout << "-----------------------------------------";
    }

    void borrowBook()
    {
        if (available)
        {
            available = false;
            std::cout << "Book borrowed." << std::endl;
            std::cout << "-----------------------------------------";
        }
        else
        {
            std::cout << "Error: Book already issued." << std::endl;
            std::cout << "-----------------------------------------";
        }
    }

    void returnBook()
    {
        if (!available)
        {
            available = true;
            std::cout << "Book returned." << std::endl;
            std::cout << "-----------------------------------------";
        }
        else
        {
            std::cout << "Error: Book is available and can't be returned." << std::endl;
            std::cout << "-----------------------------------------";
        }
    }
};

int main()
{
    const int maxBooks = 100;
    Book library[maxBooks];
    Book newBook;
    std::string title, author, isbn;

    int choice;
    int numBooks = 0;
    bool exitFlag = false;

    while (!exitFlag)
    {
        std::cout << std::endl << std::endl << "Hello, Welcome to the library management system!" << std::endl
            << std::endl
            << "Menu:" << std::endl
            << "1. Add book" << std::endl
            << "2. Remove book" << std::endl
            << "3. Search for book" << std::endl
            << "4. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            if (numBooks == maxBooks)
            {
                std::cout << "Error: The library is full." << std::endl;
                std::cout << "-----------------------------------------";
                continue;
            }

            std::cout << "Enter Book title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            newBook.setTitle(title);

            std::cout << "Enter book author: ";
            std::getline(std::cin, author);
            newBook.setAuthor(author);

            std::cout << "Enter Book ISBN: ";
            std::cin >> isbn;
            newBook.setISBN(isbn);

            newBook.setAvailable(true);
            library[numBooks] = newBook;
            numBooks++;

            std::cout << std::endl << "Book added to library." << std::endl;
            std::cout << "-----------------------------------------";
        }
        else if (choice == 2)
        {
            std::cout << "Enter Book ISBN: ";
            std::cin.ignore();
            std::cin >> isbn;
            newBook.setISBN(isbn);

            bool foundBook = false;
            for (int i = 0; i < numBooks; i++)
            {
                if (library[i].getISBN() == isbn)
                {
                    library[i] = library[numBooks - 1];
                    numBooks--;
                    foundBook = true;
                    std::cout << "Book removed from library." << std::endl;
                    std::cout << "-----------------------------------------";
                    break;
                }
            }

            if (!foundBook)
            {
                std::cout << "Error: Book not found." << std::endl;
                std::cout << "-----------------------------------------";
            }
        }
        else if (choice == 3)
        {
            std::cout << "Enter book ISBN: ";
            std::cin.ignore();
            std::cin >> isbn;

            bool foundBook = false;

            for (int i = 0; i < numBooks; i++)
            {
                if (library[i].getISBN() == isbn)
                {
                    
                    std::cout << "Availability: " << library[i].getAvailable() << std::endl;
                    std::cout << "Book info:" << std::endl;
                    std::cout << "Title: " << library[i].getTitle() << std::endl;
                    std::cout << "Author: " << library[i].getAuthor() << std::endl;
                    std::cout << "ISBN: " << library[i].getISBN() << std::endl;
                    
                    foundBook = true;
                    break;
                }
            }

            if (!foundBook)
            {
                std::cout << "Error: Book not found." << std::endl;
                std::cout << "-----------------------------------------";
            }
        }
        else if (choice == 4)
        {
            std::cout << "Thank you for using the library management system!" << std::endl;
            std::cout << "-----------------------------------------";
            exitFlag = true;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cout << "-----------------------------------------";
        }
    }

    return 0;
}
