#Airplane Makefile

airplane: main.o passenger.o flight.o
	g++ main.o passenger.o flight.o -o airplane 

main.o: main.cc passenger.h flight.h
	g++ -c main.cc -g

flight.o: flight.cc flight.h passenger.h
	g++ -c flight.cc -g

passenger.o: passenger.cc passenger.h
	g++ -c passenger.cc -g


clean:
	rm passenger.o main.o flight.o