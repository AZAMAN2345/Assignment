 #ifndef LIBRARY_H
 #define LIBRARY_H
 #include <vector>
 #include "book_Item.h"
 #include "patron.h"
 #include "patron_record.h"
 using namespace std;
 #include<iostream>
 class Library {
 private:

vector<BooKItems> books;
vector<Patron> patrons;
vector<patronRecord> patronRecord;

  
 
 public:
 //SearchFunctionality

 string SearchBookByTitle(string Titleserch){
cin>>Titleserch;

 }
 string SearchBookByAuthor(string AuthorSearch){

 }
 string SearchBookByPatronName(){

 }
 //Overdue Management
 string ListOverdueBooks(){

 }
string NotifyPatronsWithOverdueBooks(){

}
//Report Generation
string generateLibraryReport(){



}
//Book availabilities and reservation
 bool isBookAvailable(const string& isbn){


 }
 void reserveBook(const string& isbn, const string& patronCardNumber){
 }
 //Transaction History
 void ViewTransactionHistory(){


 }
 };

 #endif // LIBRARY_H
