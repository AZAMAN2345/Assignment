#include <string>
#include<iostream>
#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H
#include"LibraryItems.h"
using namespace std;
class BooKItems: public LibraryItem{

 private:
 string author;
 string isbn;

 public:
 void Setauthor(string au){
    author = au;
 }
 string Getauthor(){
    return author;
 }

void Setisbn(string is){
    isbn = is;

}
string Getisbn(){

    return isbn;
}
  };
  #endif//BookItems