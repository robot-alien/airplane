#include "passenger.h"
#include <iostream>
using namespace std;

//Constructors
Passenger::Passenger(string name){
    this->name = name;
}

Passenger::Passenger(string name, string booking){
    this->name = name;
    this->booking = booking;
}

Passenger::Passenger(){}
string Passenger::getName(){
    return name;
}

string Passenger::getBooking(){
    return booking;
}

void Passenger::setName(string name){
    this->name = name;
}

void Passenger::setBooking(string booking){
    this->booking = booking;
}

void Passenger::printPassenger(){
    cout << booking << "\t" << name << endl;
}