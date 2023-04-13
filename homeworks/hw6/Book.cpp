
#include <iostream>
#include "Book.hpp"
using namespace std;

Book::Book(string t, int i, string a, int y) {
  this->title = t;
  this->id = i;
  this->author = a;
  this->pub_year = y;
}

string Book::get_title() {
  return this->title;
}

int Book::get_id() {
  return this->id;
}

string Book::get_author() {
  return this->author;
}

int Book::get_year() {
  return this->pub_year;
}

void Book::set_title(string t) {
  this->title = t;
}

void Book::set_id(int i) {
  this->id = i;
}

void Book::set_author(string p) {
  this->author = p;
}

void Book::set_year(int y) {
  this->pub_year = y;
}

ostream &operator<<(ostream &out, const Book &book) {
  out << book.title;
  return out;
}


bool Book::operator==(const Book &book) {
  if(
    this->title == book.title &&
    this->id == book.id &&
    this->author == book.author &&
    this->pub_year == book.pub_year)
  {return true;}
  else {   
   return false;
 }
}

 bool Book::operator!=(const Book &book) {
  if(
    this->title != book.title ||
    this->id != book.id ||
    this->author != book.author ||
    this->pub_year != book.pub_year)
  {return true;}
  else {   
   return false;
 }
}