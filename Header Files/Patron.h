#include <string>
#include<iostream>
using namespace std;

#ifndef PATRON_H
#define PATRON_H

class Patron{
private :
string Name;
int LibraryCardNumber;

public :
void GetName( string n){
    n = Name;
}
 string SetName(){
    return Name;
 }

 void GetLibrary(int L){
    L = LibraryCardNumber;
 }

 int SetLibrary(){
    return LibraryCardNumber;
 }

string updateContactInfo(const string& newContactInfo){
//update 

}

int canBorrowMoreBooks(int currentBorrowedCount, int maxLimit){
    
if (currentBorrowedCount >= maxLimit)
{
   cout<<"You have reached yout borrow limit";
}

else{ cout<<"Yes you can borrow "<<maxLimit-currentBorrowedCount<<" more books";
 
};
 

}

 };
#endif