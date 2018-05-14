main : BOOK_.cpp Book.o User.o Paper.o User_management.o Book_Database.o name.o
	g++ BOOK_.cpp Book.o User.o Paper.o User_management.o Book_Database.o name.o -o main

Book.o : Book.cpp Book.h name.o
	g++ Book.cpp -c
User.o : User.cpp User.h name.o
	g++ User.cpp -c
Paper.o : Paper.cpp Paper.h name.o
	g++ Paper.cpp -c
Book_Database.o : Book_Database.cpp Book_Database.h name.o
	g++ Book_Database.cpp -c
User_management.o : User_management.cpp User_management.h name.o
	g++ User_management.cpp -c
name.o : name.cpp
	g++ name.cpp -c

clear:
	rm *.o