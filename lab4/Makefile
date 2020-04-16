TARGET=lab4
OBJS=main.o fk.o ik.o
CLFAGS=-g -Wall
LIBS=-lm

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS)
