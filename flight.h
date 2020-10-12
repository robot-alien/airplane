//Flight.h

#include <string>
#include <vector>
#include "passenger.h"

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight{
private:
std::string depTime, arrTime;
int firstCapacity, economyCapacity, flightNumber;
int firstBooked = 0;
int economyBooked = 0;
Passenger* first;
Passenger* economy;
public:
Flight(int flightNumber, std::string depTime,std::string arrTime,int firstCapacity, int economyCapacity);
//Flight();
void addFlightInfo(int flightNumber, std::string depTime,std::string arrTime,int firstCapacity, int economyCapacity);
void addPassenger(int cabin, Passenger passenger);
void printPassengerManifest();
void printCapacity();
void printFlight();
void removePassenger(std::string booking);
int getRemainingCapacity(int cabin);
~Flight();
};
#endif