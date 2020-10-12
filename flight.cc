#include "passenger.h"
#include "flight.h"
#include <string>
#include <iostream>
using namespace std;

//Defines Flight methods

//Constructor for a flight
Flight::Flight(int flightNumber, string depTime, string arrTime, int firstCapacity, int economyCapacity){
    this->flightNumber=flightNumber;
    this->depTime = depTime;
    this->arrTime = arrTime;
    this->firstCapacity=firstCapacity;
    this->economyCapacity=economyCapacity;
    first = new Passenger[firstCapacity];
    economy = new Passenger[economyCapacity];
}

//Flight::Flight(){}

void Flight::addFlightInfo(int flightNumber, string depTime, string arrTime,int firstCapacity, int economyCapacity){
    this->flightNumber=flightNumber;
    this->depTime = depTime;
    this->arrTime = arrTime;
    this->firstCapacity=firstCapacity;
    this->economyCapacity=economyCapacity;
    first = new Passenger[firstCapacity];
    economy = new Passenger[economyCapacity];
}

/** Adds a passenger to the flight
 * 
 * @param cabin 0 for first class, 1 for economy
 * @param passenger the passenger object to add
 * @return -1 if cabin full, 0 if sucess
 **/
void Flight::addPassenger(int cabin, Passenger passenger){
    if(cabin==0){
        first[firstBooked] = passenger;
        firstBooked++;
    }else if(cabin==1){
        economy[economyBooked] = passenger;
        economyBooked++;
    }
}

//Prints the flight's information
void Flight::printPassengerManifest(){
    cout << "************************************\n";
    cout << "FLIGHT NUMBER: " << flightNumber << endl;
    cout << "------------------------------------\n";
    cout << "DEPARTURE TIME: " << depTime << endl;
    cout << "------------------------------------\n";
    cout << "ARRIVAL TIME: " << arrTime << endl;
    cout << "------------------------------------\n";
    cout << "FIRST CLASS:" << endl;
    for(int i=0;i<firstBooked;i++){
    first[i].printPassenger();
    }
    cout << "------------------------------------\n";
    cout << "ECONOMY CLASS:" << endl;
    for(int i=0;i<economyBooked;i++){
    economy[i].printPassenger();
    }
}

void Flight::printFlight(){
    cout << "************************************\n";
    cout << "FLIGHT NUMBER: " << flightNumber << endl;
    cout << "------------------------------------\n";
    cout << "DEPARTURE TIME: " << depTime << endl;
    cout << "------------------------------------\n";
    cout << "ARRIVAL TIME: " << arrTime << endl;
    printCapacity();
    cout << "------------------------------------\n";
}
//Prints the number of seats remaining
void Flight::printCapacity(){
    cout << "------------------------------------\n";
    cout << "FIRST CLASS SEATS REMAINING: " << (firstCapacity-firstBooked) << endl;
    cout << "------------------------------------\n";
    cout << "ECONOMY CLASS SEATS REMAINING: " << (economyCapacity-economyBooked) << endl;
}

int Flight::getRemainingCapacity(int cabin){
    if(!cabin){
        return firstCapacity - firstBooked;
    }else{
        return economyCapacity - economyBooked;
    }
}

void Flight::removePassenger(string booking){

    //search first class
    int firstPassIndex = -1;
    for(int i=0;i<firstBooked;i++){
        if(first[i].getBooking()==booking) {firstPassIndex = i;}
    }

    //search economy
    int economyPassIndex = -1;
    for(int i=0;i<economyBooked;i++){
        if(economy[i].getBooking()==booking){economyPassIndex = i;}
    }
    if((firstPassIndex == -1) && (economyPassIndex == -1)){cout << "ERROR BOOKING NOT FOUND, COULD NOT CANCEL BOOKING.\n";}

    if(firstPassIndex != -1){
        if(firstBooked!=1){
        for(int i=firstPassIndex;i<firstBooked;i++){
            first[i] = first[i+1];
            
        }
        firstBooked--;
        }
    }else{
        if(economyBooked!=1){
        for(int i=economyPassIndex;i<economyBooked;i++){
            economy[i] = economy[i+1];
        }
        economyBooked--;
        }
    }
    cout << "Updated Flight Info\n";
    printPassengerManifest();
}

Flight::~Flight(){
    delete[] first;
    delete[] economy;
}
