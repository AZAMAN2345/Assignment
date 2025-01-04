#include <string>
#include<iostream>

#ifndef LibratyItem_H
#define LibratyItem_H
using namespace std;

class LibraryItem{
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
}
void SetisCheckedOut (bool is){
    is = isCheckedOut;
}
bool GetisCheckedOut (){
    return isCheckedOut;
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


}
    //code for mark As Lost
};
#endif  
  