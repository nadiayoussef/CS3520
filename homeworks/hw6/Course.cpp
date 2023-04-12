
#include <iostream>
#include "Course.hpp"
using namespace std;

Course::Course(string n, int c, string p, int cap) {
  this->name = n;
  this->crn = c;
  this->prof = p;
  this->capacity = cap;
}

string Course::get_name() {
  return this->name;
}

int Course::get_crn() {
  return this->crn;
}

string Course::get_prof() {
  return this->prof;
}

int Course::get_capacity() {
  return this->capacity;
}

void Course::set_name(string n) {
  this->name = n;
}

void Course::set_crn(int c) {
  this->crn = c;
}

void Course::set_prof(string p) {
  this->prof = p;
}

void Course::set_capacity(int cap) {
  this->capacity = cap;
}

ostream &operator<<(ostream &out, const Course &course) {
  out << course.name;
  return out;
}

bool Course::operator==(const Course &course) {
  if(
    this->name == course.name &&
    this->crn == course.crn &&
    this->prof == course.prof &&
    this->capacity == course.capacity)
  {return true;}
  else {   
   return false;
 }
};
