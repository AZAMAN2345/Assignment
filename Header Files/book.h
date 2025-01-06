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

void SetTitle(string t){
    Title =t;
}
string GetTitle(){

    return Title;

}

void SetAuthor(string a){
    Author = a;
}
string GetAuthor(){

    return Author;

}
 
void SetISBN (int i)
{
    i = ISBN;
}
int  GetISBN (){
    return ISBN;
}
 };
  #endif  