CXX             = g++
BIN             = timer
OBJ             = expire_timer.o
LINKOBJ         = -pthread -lboost_system
CXXINC          = 
CXXFLAGS        = $(CXXINC) -std=c++11 -O3 -Wall
RM              = rm -f

$(BIN):$(OBJ)
	        $(CXX)  $(CXXFLAGS) $(OBJ) $(LINKOBJ) -o $(BIN)

%.o:%.cpp
	        $(CXX) $(CXXFLAGS) -c $<

clean:
	        $(RM) $(OBJ) $(BIN)

rebuild:
	        make clean
			make
