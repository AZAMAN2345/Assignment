#include <string>
#include<iostream>
#include<vector>
#include "book_Item.h"
#ifndef PATRON_RECORD
#define PATRON_RECORD
using namespace std;
class patronRecord
{private:
string patron_name;
// Collects name of checked out book 
vector<string>checkedOutItems;
// Collects day(s) the book has been overdue for
 vector<int>checkoutBooksOverdueDate;
       
public:
patronRecord(std::string p){
      patron_name = p;
      };
      //Function to add a book
      void addBook(string book, int daysOverdue){
         checkedOutItems.push_back(book);
           checkoutBooksOverdueDate.push_back(daysOverdue);
      };

      //Function to remove a book
      void removebook(std::string book){
          int n = 0;
          // Deletes a checked out book
          for (std::string i : checkedOutItems){
              if (book == i){
                  checkedOutItems.erase(checkedOutItems.begin() + n);
              }
              n = n + 1;

          // Deletes its corresponding overdue date
          checkoutBooksOverdueDate.erase(checkoutBooksOverdueDate.begin() + n);
          };

      };

      // Function to list all books the patron currently has
      void listCheckedOutBooks(){
          for (std::string i : checkedOutItems){
              {std::cout << i <<std::endl;}
              
          }
      };

      // Function to count how many books is checked out
      void getBorrowedBookCount(){
          std::cout<<checkedOutItems.size()<<std::endl;
      };

      // Function to check if the patron has overdue books
      void hasOverdueBooks(){
          int n = 0;
          for (int i : checkoutBooksOverdueDate){
              if (i != 0){
                  n = n + 1;
              }
              
          };
          std::cout<<patron_name<<" has "<< n << "overdue books."<<std::endl;    
      };

      //Function to calculate total late fees
      void calculateTotalLateFees(){
          int f = 0;
          for (int i : checkoutBooksOverdueDate){
              if (i != 0){
                  f = f + 1000 + (50 * i); //1000 for the first late day and 50 per day afterwards
              }
          };
          std::cout<<"Total late fee is"<<f<<"."<<std::endl;
              
          };
};
#endif
