#include <string>
#include<iostream>
#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H
#include"LibraryItem.h"
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
string Title;
string Authour;
string Duedate;
string Setduedate(Duedate);
bool IscheckedOut = true;
bool SetisCheckedOut(IscheckedOut);
string Settitle(Title);



        std::cout << "Author : " << author << "." << std::endl;
        std::cout << "ISBN(International Standard Book Number) : " << isbn << "." << std::endl;
        std::cout << "Title : " << Title << "." << std::endl;
        if (IscheckedOut == true){
            std::cout << "The book is not available at the moment." << std::endl;
        } else {
            std::cout << "The book is currently available."<< std::endl;
        }

        std::cout << "The book is due in " << Duedate << " days." << std::endl;
    };

double calculateLateFees(int daysOverdue){
        // Charges 1000 for the the first day overdue then charges 50 naira per day for subsequent days
        double lateFees;
        lateFees = 1000 + (50 * daysOverdue);
        return lateFees;

    };
 };

 #endif//BookItems
