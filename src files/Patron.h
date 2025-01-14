#include <string>
#include<iostream>
using namespace std;

#ifndef PATRON_H
#define PATRON_H

class Patron{
private:
string Name;
int LibraryCardNumber;

public :
Patron(std::string n, double l){
Name = n;
LibraryCardNumber = l;
};

string GetName(){
    return Name;
};
void SetName(string n){
    Name = n;
 };

 int GetLibrary(){
    return LibraryCardNumber;
 };

 void SetLibrary(int l){
    LibraryCardNumber = l;
 };

string updateContactInfo(const string& newContactInfo){
    string contactInfo = newContactInfo;
    return contactInfo;
};
};

void canBorrowMoreBooks(int currentBorrowedCount, int maxLimit){
    
if (currentBorrowedCount >= maxLimit)
{
   cout<<"You have reached yout borrow limit";

   }
   
   else{ cout<<"Yes you can borrow "<<maxLimit-currentBorrowedCount<<" more books";
   
 };
};


 
 
#endif
