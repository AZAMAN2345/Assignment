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
 BooKItems(string a, int i, string t, bool ic, int d) : LibraryItem(t, ic, d){
        author = a;
        isbn = i;
  };

 void Setauthor(string au){
    author = au;
 };

 string Getauthor(){
    return author;
 };

void Setisbn(string is){
    isbn = is;
};

string Getisbn(){
    return isbn;
};

void printDetails(){
        std::cout << "Author : " << author << "." << std::endl;
        std::cout << "ISBN(International Standard Book Number) : " << isbn << "." << std::endl;
        std::cout << "Title : " << title << "." << std::endl;
        if (isCheckedOut == 1){
            std::cout << "The book is not available at the moment." << std::endl;
        } else {
            std::cout << "The book is currently available."<< std::endl;
        }

        std::cout << "The book is due in " << duedate << " days." << std::endl;
    };

 };

 #endif//BookItems
