CC=g++
CFLAGS=-g -Wall

all: test_list

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $<

test_list: test_list.cpp
	$(CC) $(CFLAGS) -o $@ $^

run_test_list: test_list
	./test_list

clean:
	rm *.o test_list
