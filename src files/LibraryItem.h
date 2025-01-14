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
LibraryItem(string t, bool ic, int d){
title = t;
isCheckedOut = ic;
duedate = d;
};

string Settitle (string ti){
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

string Setduedate (string d){
    duedate = d;
};

string Getduedate (){
    return duedate;
};

bool checkOut(){
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
   int dueDate = 0;
};
};
#endif  
  
