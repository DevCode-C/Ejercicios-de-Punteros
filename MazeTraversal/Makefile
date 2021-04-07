TARGET = CardShuffling
CC = gcc
OBJS = main.o 
CFLAGS = -c -std=c99 -Wall -g -o
LDFLAGS += -lm 

all:$(OBJS) $(TARGET)

$(TARGET) : $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET) 

%.o : %.c  
	@$(CC) $(CFLAGS) $@ $^

.PHONY : clean
clean : 
	@rm -f *.o $(TARGET)
.PHONY : do
do : 
	@./$(TARGET)