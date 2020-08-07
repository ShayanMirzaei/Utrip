CC = g++
CCFLAGS = -std=c++11 

BUILD_DIR = ./build/
FILTER_DIR = ./filter/
HOTEL_DIR = ./hotel/
IO_DIR = ./io/
USER_DIR = ./user/
SERVER_DIR =./server/
UTILS_DIR = ./utils/

all: utrip.out
 
utrip.out: ${BUILD_DIR}main.o ${BUILD_DIR}Utrip.o ${BUILD_DIR}handlers.o ${BUILD_DIR}ServerInterface.o ${BUILD_DIR}server.o ${BUILD_DIR}route.o ${BUILD_DIR}response.o ${BUILD_DIR}request.o ${BUILD_DIR}utilities.o ${BUILD_DIR}Hotel.o ${BUILD_DIR}HotelDatabase.o ${BUILD_DIR}HotelDataParser.o ${BUILD_DIR}Room.o ${BUILD_DIR}RoomManager.o ${BUILD_DIR}StandardRoom.o ${BUILD_DIR}DeluxeRoom.o ${BUILD_DIR}LuxuryRoom.o ${BUILD_DIR}PremiumRoom.o ${BUILD_DIR}User.o ${BUILD_DIR}UserDatabase.o ${BUILD_DIR}UserInterface.o ${BUILD_DIR}utility_functions.o ${BUILD_DIR}Exception.o ${BUILD_DIR}Wallet.o ${BUILD_DIR}Output.o ${BUILD_DIR}Filter.o ${BUILD_DIR}FilterCity.o ${BUILD_DIR}FilterStar.o ${BUILD_DIR}FilterPrice.o ${BUILD_DIR}FilterDefaultPrice.o ${BUILD_DIR}FilterRoom.o ${BUILD_DIR}Reservation.o ${BUILD_DIR}Rating.o ${BUILD_DIR}Sort.o ${BUILD_DIR}Weight.o
	${CC} ${CCFLAGS} ${BUILD_DIR}main.o ${BUILD_DIR}Utrip.o ${BUILD_DIR}handlers.o ${BUILD_DIR}ServerInterface.o ${BUILD_DIR}server.o ${BUILD_DIR}route.o ${BUILD_DIR}response.o ${BUILD_DIR}request.o ${BUILD_DIR}utilities.o ${BUILD_DIR}Hotel.o ${BUILD_DIR}HotelDatabase.o ${BUILD_DIR}HotelDataParser.o ${BUILD_DIR}Room.o ${BUILD_DIR}RoomManager.o ${BUILD_DIR}StandardRoom.o ${BUILD_DIR}DeluxeRoom.o ${BUILD_DIR}LuxuryRoom.o ${BUILD_DIR}PremiumRoom.o ${BUILD_DIR}User.o ${BUILD_DIR}UserDatabase.o ${BUILD_DIR}UserInterface.o ${BUILD_DIR}utility_functions.o ${BUILD_DIR}Exception.o ${BUILD_DIR}Wallet.o ${BUILD_DIR}Output.o ${BUILD_DIR}Filter.o ${BUILD_DIR}FilterCity.o ${BUILD_DIR}FilterStar.o ${BUILD_DIR}FilterPrice.o ${BUILD_DIR}FilterDefaultPrice.o ${BUILD_DIR}FilterRoom.o ${BUILD_DIR}Reservation.o ${BUILD_DIR}Rating.o ${BUILD_DIR}Sort.o ${BUILD_DIR}Weight.o -o utrip.out

${BUILD_DIR}main.o: main.cpp Utrip.hpp ${IO_DIR}UserInterface.hpp ${BUILD_DIR}server.o ${BUILD_DIR}route.o
	${CC} ${CCFLAGS} -c main.cpp -o ${BUILD_DIR}main.o

${BUILD_DIR}Utrip.o: Utrip.cpp Utrip.hpp ${HOTEL_DIR}Hotel.hpp ${USER_DIR}Weight.hpp ${IO_DIR}HotelDataParser.hpp ${HOTEL_DIR}HotelDatabase.hpp ${USER_DIR}UserDatabase.hpp ${USER_DIR}User.hpp ${USER_DIR}Wallet.hpp ${IO_DIR}Output.hpp
	${CC} ${CCFLAGS} -c Utrip.cpp -o ${BUILD_DIR}Utrip.o

${BUILD_DIR}Hotel.o: ${HOTEL_DIR}Hotel.cpp ${HOTEL_DIR}Hotel.hpp ${HOTEL_DIR}RoomManager.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}Hotel.cpp -o ${BUILD_DIR}Hotel.o

${BUILD_DIR}HotelDatabase.o: ${HOTEL_DIR}HotelDatabase.cpp ${HOTEL_DIR}HotelDatabase.hpp ${HOTEL_DIR}Hotel.hpp ${HOTEL_DIR}RoomManager.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}HotelDatabase.cpp -o ${BUILD_DIR}HotelDatabase.o

${BUILD_DIR}HotelDataParser.o: ${IO_DIR}HotelDataParser.cpp ${IO_DIR}HotelDataParser.hpp ${HOTEL_DIR}HotelDatabase.hpp
	${CC} ${CCFLAGS} -c ${IO_DIR}HotelDataParser.cpp -o ${BUILD_DIR}HotelDataParser.o

${BUILD_DIR}RoomManager.o: ${HOTEL_DIR}RoomManager.cpp ${HOTEL_DIR}RoomManager.hpp ${HOTEL_DIR}Room.hpp ${HOTEL_DIR}StandardRoom.hpp ${HOTEL_DIR}DeluxeRoom.hpp ${HOTEL_DIR}LuxuryRoom.hpp ${HOTEL_DIR}PremiumRoom.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}RoomManager.cpp -o ${BUILD_DIR}RoomManager.o

${BUILD_DIR}Room.o: ${HOTEL_DIR}Room.cpp ${HOTEL_DIR}Room.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}Room.cpp -o ${BUILD_DIR}Room.o
	
${BUILD_DIR}StandardRoom.o: ${HOTEL_DIR}StandardRoom.cpp ${HOTEL_DIR}StandardRoom.hpp ${HOTEL_DIR}Room.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}StandardRoom.cpp -o ${BUILD_DIR}StandardRoom.o

${BUILD_DIR}DeluxeRoom.o: ${HOTEL_DIR}DeluxeRoom.cpp ${HOTEL_DIR}DeluxeRoom.hpp ${HOTEL_DIR}Room.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}DeluxeRoom.cpp -o ${BUILD_DIR}DeluxeRoom.o

${BUILD_DIR}LuxuryRoom.o: ${HOTEL_DIR}LuxuryRoom.cpp ${HOTEL_DIR}LuxuryRoom.hpp ${HOTEL_DIR}Room.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}LuxuryRoom.cpp -o ${BUILD_DIR}LuxuryRoom.o

${BUILD_DIR}PremiumRoom.o: ${HOTEL_DIR}PremiumRoom.cpp ${HOTEL_DIR}PremiumRoom.hpp ${HOTEL_DIR}Room.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}PremiumRoom.cpp -o ${BUILD_DIR}PremiumRoom.o

${BUILD_DIR}UserDatabase.o: ${USER_DIR}UserDatabase.cpp ${USER_DIR}UserDatabase.hpp ${USER_DIR}User.hpp 
	${CC} ${CCFLAGS} -c ${USER_DIR}UserDatabase.cpp -o ${BUILD_DIR}UserDatabase.o

${BUILD_DIR}User.o: ${USER_DIR}User.cpp ${USER_DIR}User.hpp ${USER_DIR}Wallet.hpp ${USER_DIR}Weight.hpp ${USER_DIR}Sort.hpp
	${CC} ${CCFLAGS} -c ${USER_DIR}User.cpp -o ${BUILD_DIR}User.o

${BUILD_DIR}UserInterface.o: ${IO_DIR}UserInterface.cpp ${IO_DIR}UserInterface.hpp ${IO_DIR}interface_definitions.hpp Utrip.hpp
	${CC} ${CCFLAGS} -c ${IO_DIR}UserInterface.cpp -o ${BUILD_DIR}UserInterface.o

${BUILD_DIR}ServerInterface.o: ${IO_DIR}ServerInterface.cpp ${IO_DIR}ServerInterface.hpp ${IO_DIR}interface_definitions.hpp Utrip.hpp handlers.hpp
	${CC} ${CCFLAGS} -c ${IO_DIR}ServerInterface.cpp -o ${BUILD_DIR}ServerInterface.o
 
${BUILD_DIR}utility_functions.o: utility_functions.cpp utility_functions.hpp
	${CC} ${CCFLAGS} -c utility_functions.cpp -o ${BUILD_DIR}utility_functions.o

${BUILD_DIR}Exception.o: Exception.cpp Exception.hpp
	${CC} ${CCFLAGS} -c Exception.cpp -o ${BUILD_DIR}Exception.o

${BUILD_DIR}Wallet.o: ${USER_DIR}Wallet.cpp ${USER_DIR}Wallet.hpp
	${CC} ${CCFLAGS} -c ${USER_DIR}Wallet.cpp -o ${BUILD_DIR}Wallet.o

${BUILD_DIR}Output.o: ${IO_DIR}Output.cpp ${IO_DIR}Output.hpp ${IO_DIR}output_definitions.hpp 
	${CC} ${CCFLAGS} -c ${IO_DIR}Output.cpp -o ${BUILD_DIR}Output.o

${BUILD_DIR}Filter.o: ${FILTER_DIR}Filter.cpp ${FILTER_DIR}Filter.hpp
	${CC} ${CCFLAGS} -c ${FILTER_DIR}Filter.cpp -o ${BUILD_DIR}Filter.o

${BUILD_DIR}FilterCity.o: ${FILTER_DIR}FilterCity.cpp ${FILTER_DIR}FilterCity.hpp ${FILTER_DIR}Filter.hpp
	${CC} ${CCFLAGS} -c ${FILTER_DIR}FilterCity.cpp -o ${BUILD_DIR}FilterCity.o

${BUILD_DIR}FilterPrice.o: ${FILTER_DIR}FilterPrice.cpp ${FILTER_DIR}FilterPrice.hpp ${FILTER_DIR}Filter.hpp
	${CC} ${CCFLAGS} -c ${FILTER_DIR}FilterPrice.cpp -o ${BUILD_DIR}FilterPrice.o

${BUILD_DIR}FilterRoom.o: ${FILTER_DIR}FilterRoom.cpp ${FILTER_DIR}FilterRoom.hpp ${FILTER_DIR}Filter.hpp
	${CC} ${CCFLAGS} -c ${FILTER_DIR}FilterRoom.cpp -o ${BUILD_DIR}FilterRoom.o

${BUILD_DIR}FilterDefaultPrice.o: ${FILTER_DIR}FilterDefaultPrice.cpp ${FILTER_DIR}FilterDefaultPrice.hpp ${FILTER_DIR}Filter.hpp
	${CC} ${CCFLAGS} -c ${FILTER_DIR}FilterDefaultPrice.cpp -o ${BUILD_DIR}FilterDefaultPrice.o

${BUILD_DIR}FilterStar.o: ${FILTER_DIR}FilterStar.cpp ${FILTER_DIR}FilterStar.hpp ${FILTER_DIR}Filter.hpp
	${CC} ${CCFLAGS} -c ${FILTER_DIR}FilterStar.cpp -o ${BUILD_DIR}FilterStar.o

${BUILD_DIR}Reservation.o: ${HOTEL_DIR}Reservation.cpp ${HOTEL_DIR}Reservation.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}Reservation.cpp -o ${BUILD_DIR}Reservation.o

${BUILD_DIR}Rating.o: ${HOTEL_DIR}Rating.cpp ${HOTEL_DIR}Rating.hpp
	${CC} ${CCFLAGS} -c ${HOTEL_DIR}Rating.cpp -o ${BUILD_DIR}Rating.o

${BUILD_DIR}Sort.o: ${USER_DIR}Sort.cpp ${USER_DIR}Sort.hpp ${HOTEL_DIR}Hotel.hpp ${HOTEL_DIR}RoomManager.hpp
	${CC} ${CCFLAGS} -c ${USER_DIR}Sort.cpp -o ${BUILD_DIR}Sort.o

${BUILD_DIR}Weight.o: ${USER_DIR}Weight.cpp ${USER_DIR}Weight.hpp ${USER_DIR}Sort.cpp
	${CC} ${CCFLAGS} -c ${USER_DIR}Weight.cpp -o ${BUILD_DIR}Weight.o

${BUILD_DIR}server.o: ${SERVER_DIR}server.cpp ${SERVER_DIR}server.hpp
	${CC} ${CCFLAGS} -c ${SERVER_DIR}server.cpp -o ${BUILD_DIR}server.o

${BUILD_DIR}route.o: ${SERVER_DIR}route.cpp ${SERVER_DIR}route.hpp
	${CC} ${CCFLAGS} -c ${SERVER_DIR}route.cpp -o ${BUILD_DIR}route.o

${BUILD_DIR}response.o: ${UTILS_DIR}response.cpp ${UTILS_DIR}response.hpp
	${CC} ${CCFLAGS} -c ${UTILS_DIR}response.cpp -o ${BUILD_DIR}response.o

${BUILD_DIR}request.o: ${UTILS_DIR}request.cpp ${UTILS_DIR}request.hpp
	${CC} ${CCFLAGS} -c ${UTILS_DIR}request.cpp -o ${BUILD_DIR}request.o

${BUILD_DIR}utilities.o: ${UTILS_DIR}utilities.cpp ${UTILS_DIR}utilities.hpp
	${CC} ${CCFLAGS} -c ${UTILS_DIR}utilities.cpp -o ${BUILD_DIR}utilities.o

${BUILD_DIR}handlers.o: handlers.cpp handlers.hpp ${UTILS_DIR}response.hpp ${UTILS_DIR}request.hpp
	${CC} ${CCFLAGS} -c handlers.cpp -o ${BUILD_DIR}handlers.o



clean: 
	rm ${BUILD_DIR}*.o
	rm utrip.out