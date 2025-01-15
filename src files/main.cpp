 #include"lin.h"
 #include"book.h"
 #include"book_Item.h"
 #include"Library.h"
 #include"LibraryItem.h"
 #include"Patron.h"
 #include"Patron_Record.h"
#include <string>
#include<iostream>
#include<vector>
using namespace std;
 int main(){

  //Book
    Book bookOne("title1", "author1", 123456);
    std::cout<<bookOne.getAuthor()<<std::endl;
    std::cout<<bookOne.getISBN()<<std::endl;
    bookOne.setAuthor("author2");
    std::cout<<bookOne.getAuthor()<<std::endl;
    std::cout<<""<<std::endl;

    //Patron
    Patron patronOne("patron1", 1234);
    patronOne.getName();
    std::cout<<patronOne.getLibCardNo()<<std::endl;
    patronOne.setLibCardNo(1256);
    std::cout<<patronOne.getLibCardNo()<<std::endl;
    std::cout<<patronOne.updateContactInfo("Emmanuel")<<std::endl;
    patronOne.canBorrowMoreBooks(2,3);
    std::cout<<""<<std::endl;

    //LibraryItem
    LibraryItem libraryitem("title 6", false, 5);
    libraryitem.checkOut();
    libraryitem.returnItem();
    libraryitem.renewItem(10);
    libraryitem.markAsLost();
    std::cout<<""<<std::endl;


    //BookItem
    BookItem obj2("author2", 200, "title2", false, 20);
    std::cout<<obj2.getAuthor()<<std::endl;
    obj2.printDetails();
    obj2.checkOut();
    obj2.printDetails();
    obj2.renewItem(30);
    obj2.printDetails();
    obj2.markAsLost();
    obj2.calculateLateFees(20);

    //PatronRecord
   PatronRecord patron1("henry");
   patron1.addBook("Book 1", 20);
   patron1.addBook("Book 2", 20);
   patron1.addBook("Book 3", 0);
   patron1.addBook("Book 4", 0);
   patron1.listCheckedOutBooks();
   patron1.getBorrowedBookCount();
   patron1.hasOverdueBooks();
   patron1.calculateTotalLateFees();

    
    //Library
    // Create books
    Library::Book book1("Title1", "author1", 123);
    Library::Book book2("Title2", "author2", 456);
    Library::Book book3("Title3", "author3", 789);
    

    // Create a library
    Library library;
    std::cout<<""<<std::endl;

    // Add books to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    std::cout<<""<<std::endl;

    // Add patrons with initial checked-out books
    library.addPatron("Emmanuel");
    library.addPatron("John");
    library.borrowBook("John", "Title2");
    library.borrowBook("Emmanuel", "Title3");
    std::cout<<""<<std::endl;

    // Display library information
    library.displayBooks();
    std::cout<<""<<std::endl;
    library.displayPatronRecords();
    std::cout<<""<<std::endl;

    // Search functionalities
     vector<Library::Book> foundBooks = library.searchBooksByTitle("Title"); 
    cout << "Books found by title: " << endl;
    for (const auto& book : foundBooks) {
        cout << "- " << book.title << endl;
    }
    std::cout<<""<<std::endl;
    // Overdue management
    library.listOverdueBooks(); 
    library.notifyPatronsWithOverdueBooks();
    std::cout<<""<<std::endl;

    // Library report
    library.generateLibraryReport(); 
    std::cout<<""<<std::endl;

    // Book availability and reservation 
    cout << "Is 'Title1' available? " 
         << (library.isBookAvailable(123) ? "Yes" : "No") << endl; 
    library.reserveBook(123, "John"); 
    std::cout<<""<<std::endl;

    // View transaction history
    library.viewTransactionHistory("John");
return 0;



 }
