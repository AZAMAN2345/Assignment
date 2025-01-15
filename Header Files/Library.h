 #ifndef LIBRARY_H
 #define LIBRARY_H
 #include <iostream>
 #include <vector>
 #include <string>
 #include <map>
 #include <ctime>
 #include <chrono> 
 #include <algorithm> 
 #include "book_Item.h"
 #include "patron.h"
 #include "patron_record.h"
 using namespace std;

class Library {
public:
    struct Book {
        string title;
        string author;
        int isbn;
        bool available;
        time_t dueDate; 

        Book(const string& t, const string& a, int i) 
            : title(t), author(a), isbn(i), available(true), dueDate(0) {}
    };

    struct Patron {
        string name;
        vector<Book*> checkedOutBooks; 
        vector<Book*> reservedBooks; 
        vector<pair<string, time_t>> transactionHistory; // Store borrowing/returning history
    };

    void addBook(const Book& book) {
        books.push_back(book); 
    }

    void addPatron(const string& patronName) {
        patrons.insert({patronName, Patron{patronName}}); 
    }

    bool borrowBook(const string& patronName, const string& bookTitle) {
        for (auto& book : books) {
            if (book.title == bookTitle && book.available) {
                book.available = false;
                book.dueDate = time(nullptr) + 7 * 24 * 60 * 60; // 7 days from now
                for (auto& patron : patrons) {
                    if (patron.first == patronName) {
                        patron.second.checkedOutBooks.push_back(&book); // Corrected: Use patron.second
                        patron.second.transactionHistory.push_back({bookTitle, time(nullptr)}); // Record borrowing time
                        return true;
                    }
                }
            }
        }
        return false; 
    }
       

    bool returnBook(const string& patronName, const string& bookTitle) {
        for (auto& patron : patrons) {
            if (patron.first == patronName) {
                for (auto it = patron.second.checkedOutBooks.begin(); it != patron.second.checkedOutBooks.end(); ++it) {
                    if ((*it)->title == bookTitle) {
                        (*it)->available = true; 
                        patron.second.checkedOutBooks.erase(it); 
                        patron.second.transactionHistory.push_back({bookTitle, time(nullptr)}); // Record returning time
                        return true;
                    }
                }
            }
        }
        return false; 
    }

   vector<Book> searchBooksByTitle(const string& title) const { 
        vector<Book> results; 
        for (const Book& book : books) { // Use const Book& for efficiency
            if (book.title.find(title) != string::npos) {
                results.push_back(book); 
            }
        }
        return results;
    }

    vector<Book> searchBooksByAuthor(const string& author) const {
        vector<Book> results;
        for (const auto& book : books) {
            if (book.author.find(author) != string::npos) {
                results.push_back(book);
            }
        }
        return results;
    }

   vector<Patron> searchPatronByName(const string& name) const {
    vector<Patron> results;
    for (const auto& patronPair : patrons) { // Use patronPair instead of patron
        if (patronPair.first.find(name) != string::npos) { 
            results.push_back(patronPair.second); // Push back the Patron object
        }
    }
    return results;
}

    void listOverdueBooks() const {
        cout << "Overdue Books:" << endl;
        for (const auto& book : books) {
            if (!book.available && book.dueDate < time(nullptr)) {
                cout << "- " << book.title << endl;
            }
        }
    }

    void notifyPatronsWithOverdueBooks() {
    cout << "Patrons with Overdue Books:" << endl;
    for (const auto& patronPair : patrons) { // Iterate through the map of patrons
        const string& patronName = patronPair.first;
        const Patron& patron = patronPair.second; 
        for (const auto& book : patron.checkedOutBooks) {
            if (!book->available && book->dueDate < time(nullptr)) {
                cout << "- " << patronName << " (" << book->title << ")" << endl;
                break; 
            }
        }
    }
}

    void generateLibraryReport() const {
        cout << "Library Report:" << endl;
        cout << "Total Books: " << books.size() << endl;
        cout << "Available Books: " << count_if(books.begin(), books.end(), 
                                            [](const Book& b) { return b.available; }) 
             << endl;
        cout << "Checked Out Books: " << count_if(books.begin(), books.end(), 
                                            [](const Book& b) { return !b.available; }) 
             << endl;
        cout << "Number of Patrons: " << patrons.size() << endl;
        listOverdueBooks(); 
    }

    bool isBookAvailable(int isbn) const { // Change parameter type to int
            for (const auto& book : books) {
                if (book.isbn == isbn && book.available) {
                    return true;
                }
            }
            return false;
        }

   void reserveBook(int isbn, const string& patronCardNumber) { 
    for (auto& book : books) {
        if (book.isbn == isbn && !book.available) {
            for (auto& patronPair : patrons) { 
                if (patronPair.first == patronCardNumber) {
                    patronPair.second.reservedBooks.push_back(&book); 
                    cout << "Book " << isbn << " reserved by " << patronCardNumber << endl; 
                    return; 
                }
            }
        }
    }
}

   void viewTransactionHistory(const string& patronCardNumber) const {
    for (const auto& patronPair : patrons) { 
        if (patronPair.first == patronCardNumber) {
            const Patron& patron = patronPair.second;
            cout << "Transaction History for " << patronCardNumber << ":" << endl;
            for (const auto& transaction : patron.transactionHistory) {
                cout << " - " << transaction.first << " (" << ctime(&transaction.second) << ")" << endl; 
            }
            return;
        }
    }
    cout << "Patron not found." << endl;
}

void displayBooks() const {
        cout << "Available Books:" << endl;
        for (const auto& book : books) {
            if (book.available) {
                cout << "- " << book.title << " by " << book.author << endl;
            }
        }
    }

    void displayPatronRecords() const {
        for (const auto& patronPair : patrons) {
            const string& patronName = patronPair.first;
            const Patron& patron = patronPair.second;
            cout << "Patron: " << patronName << endl;
            cout << "  Checked Out Books:" << endl;
            for (const auto& book : patron.checkedOutBooks) {
                cout << "    - " << book->title << endl;
            }
            cout << "  Reserved Books:" << endl;
            for (const auto& book : patron.reservedBooks) {
                cout << "    - " << book->title << endl;
            }
            cout << endl; 
        }
    }


private:
    vector<Book> books;
    map<string, Patron> patrons; 
};
 #endif // LIBRARY_H
