
APP_READ = readshm
READ_OBJS = readshm.o
APP_WRITE = writeshm
WRITE_OBJS = writeshm.o

CC = gcc
INC = ./
CFLAG += -g

.PHONY : all

all : $(APP_READ) $(APP_WRITE)

$(APP_READ) : $(READ_OBJS)
	$(CC) $(CFLAG) $(READ_OBJS) -o $(APP_READ)

$(APP_WRITE) : $(WRITE_OBJS)
	$(CC) $(CFLAG) $(WRITE_OBJS) -o $(APP_WRITE)
	
%.o : %.c
	$(CC) -c $(CFLAG) $^ -o $@

.PHONY : clean

clean :
	rm -f *.o
	rm -f $(APP_READ) $(APP_WRITE)
	