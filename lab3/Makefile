TARGET=lab3
OBJS=main.o lab3.o lab2.o
CLFAGS=-g -Wall
LIBS=-lm

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS)
