//Passenger.h
#include<string>
#ifndef PASSENGER_H
#define PASSENGER_H
class Passenger{
private:
std::string name,booking;
public:
Passenger();
Passenger(std::string name);
Passenger(std::string name,std::string booking);
std::string getName();
std::string getBooking();
void setName(std::string name);
void setBooking(std::string booking);
void printPassenger();
};
#endif