#include <string>
#include<iostream>

#ifndef BOOKS_H
#define BOOKS_H
using namespace std;
class book{
private:
string Title ;
string Author ;
int ISBN ;

public:
book(string t, string a, int i){
    Title = t;
    Author = a;
    ISBN = i;   
};

void SetTitle(string t){
    Title =t;
};
string GetTitle(){

    return Title;

};

void SetAuthor(string a){
    Author = a;
};

string GetAuthor(){

    return Author;

};
 
void SetISBN (int i)
{
    ISBN = i;
};

int  GetISBN (){
    return ISBN;
};
 };
  #endif  
