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
LibraryItem(string t, bool ic, int d){
title = t;
isCheckedOut = ic;
duedate = d;
};

void Settitle (string ti){
    title = ti;
};

string Gettitle (){
    return title;
    cout<<"----------------"<<title<<"---------------"<<endl;
};

void SetisCheckedOut (bool is){
    isCheckedOut = is;
};

bool GetisCheckedOut (){
    return isCheckedOut;
};

void Setduedate (string d){
    duedate = d;
};

string Getduedate (){
    return duedate;
};

void checkOut(){
 SetisCheckedOut(true);
};

 void returnItem(){
    SetisCheckedOut(false);
 };

 void renewitems(int extradays){
    duedate +=extradays;
 };

void markAsLost(){
    std::cout << "The book (" << title << ") can not be found." << std::endl;
    // isCheckedOut and dueDate set to zero because book is missing.
    isCheckedOut = false;
    dueDate = 0;
};
};
#endif  
  
