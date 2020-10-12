#include "passenger.h"
#include "flight.h"
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
const int MAX_FLIGHTS = 10;

#include <random>
#include <string>

string random_string(string::size_type length)
{
    static auto& chrs = "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

int main(){
    //Flight* zero = new Flight();
    Flight* flights[MAX_FLIGHTS];
    int flightNumber = 0;
    bool loop = true;
    while(loop){
        //Print the prompt to the console
        int selection;
        cout << "------------------------------------\n";
        //Prompt user for input
        cout << "Main Menu:\n\t1. Create a flight\n\t2. Create a booking\n\t3. Cancel a booking\n\t4. Print a flight's info\n\t5. Print all flights\n\t6. Exit\n\tSelect an option: ";
        cin >> selection;
        //Catch user if the input is not in range OR not an int.
        while(cin.fail() || selection < 1 || selection > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid entry.  Please enter a NUMBER between 1 and 5: ";
            //keep asking for input until valid.
            cin >> selection;
        }
        //Runs code based on number inputed.
        switch(selection){
            case 1:
            {
                cout<<"You selected: \"Create a flight\"\n------------------------------------\n";
                string depTime, arrTime;
                int firstCapacity, economyCapacity;
                cout << "ENTER THE FOLLOWING DATA:\n\t1.)Departure Time\n\t2.)Arrival Time\n\t3.)First Class Capacity\n\t4.)Economy Class Capacity\n";
                cin >> depTime >> arrTime >> firstCapacity >> economyCapacity;
                Flight* temp = new Flight(flightNumber,depTime,arrTime,firstCapacity,economyCapacity);
                //flights.operator[flightNumber];
                flights[flightNumber] = temp;
                flightNumber++;
            }
                break; 
            case 2:
                cout<<"You selected: \"Create a booking\"\n------------------------------------\n";
                {
                    int success = -1;

                    string name, booking;
                    int cabin, fn;
                    cout << "ENTER FLIGHT NUMBER: ";
                    cin >> fn;
                    cout << "ENTER PASSENGER NAME: ";
                    cin >> name;
                    cout << "ENTER 0 for FIRST CLASS or 1 for ECONOMY CLASS: ";
                    cin >> cabin;
                    Passenger currPassenger(name,random_string(6));
                    if(flights[fn]->getRemainingCapacity(cabin)){
                    flights[fn]->addPassenger(cabin,currPassenger);
                    cout << "Added Passenger:\t";
                    currPassenger.printPassenger();
                    }else{
                        cout << "ERROR: That cabin is full.\nPASSENGER NOT ADDED, PLEASE TRY AGAIN\n";
                    }
                    
                }
                break;
            case 3:
            {
                cout<<"You selected: \"Cancel a booking\"\n------------------------------------\n";
                string conf;
                int fn;
                cout<<"ENTER FLIGHT NUMBER: ";
                cin >> fn;
                cout<<"ENTER CONFIRMATION NUMBER: ";
                cin >> conf;
                flights[fn]->removePassenger(conf);
            }
                break;
            case 4:
                cout<<"You selected: \"Print a flight's info\"\n";
                {  
                    int fn;
                    cout <<"ENTER FLIGHT NUMBER: ";
                    cin >> fn;
                    flights[fn]->printPassengerManifest();
                }
                break;
            case 5:
            {
                for(int i = 0; i < flightNumber; i++){
                    flights[i]->printFlight();
                }
                break;
            }
            case 6:
                cout<<"You selected: \"Exit\"\n------------------------------------\n";
                loop = false; //breaks the while loop
                break;
        }
        
        
    }

}