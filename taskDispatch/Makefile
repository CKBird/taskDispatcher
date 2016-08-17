CC = g++
CFLAGS  = -g -Wall

default: taskMain

# Build all
taskMain:  taskMain.o TCB.o queueBase.o functionLUT.o
	$(CC) $(CFLAGS) -o taskMain taskMain.o TCB.o queueBase.o functionLUT.o

# Create taskMain object
taskMain.o:  taskMain.cpp 
	$(CC) $(CFLAGS) -c taskMain.cpp

# Create TCB Class Object
TCB.o:  TCB.cpp TCB.h 
	$(CC) $(CFLAGS) -c TCB.cpp

#Create queueBase Class Object
queueBase.o: queueBase.cpp queueBase.h
	$(CC) $(CFLAGS) -c queueBase.cpp

#Create functionLUT Class Object
functionLUT.o: functionLUT.cpp functionLUT.h
	$(CC) $(CFLAGS) -c functionLUT.cpp
	
# Clean Everything
clean: 
	$(RM) taskMain *.o *~