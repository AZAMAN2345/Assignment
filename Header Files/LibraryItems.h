#include <string>
#include<iostream>

#ifndef LibratyItem_H
#define LibratyItem_H
using namespace std;

class LibraryItems{
private:
string title;
bool isCheckedOut;
string duedate;

public:
void Settitle (string ti){
    ti = title;
}
string Gettitle (){
    return title;
    cout<<"----------------"<<title<<"---------------"<<endl;
}
void SetisCheckedOut (bool is){
    is = isCheckedOut;
}
bool GetisCheckedOut (){
    return isCheckedOut;
    cout<<isCheckedOut<<endl;
}

void Setduedate (string d){
    d = duedate;
}
string Getduedatee (){
    return duedate;
}

void checkOut(){
 SetisCheckedOut(true);
 
}
 void returnItem(){
    SetisCheckedOut(false);
 }
 int renewitems(int extradays){
    duedate +=extradays;

 }

void markAsLost(){
    // Edited by sherif
    std::cout << "The book (" << title << ") can not be found." << std::endl;
    // isCheckedOut and dueDate set to zero because book is missing.
    isCheckedOut = false;
    dueDate = 0;
    // end 

}
    //code for mark As Lost
};
#endif  
  
