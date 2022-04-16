 
#builds readline.o by compiling readline.c 
readline.o: readline.c readline.h
	gcc -c readline.c 

#builds book.o by compiling book.c
book.o: book.c book.h readline.h 
	gcc -c book.c

#builds book_requests.o by compiling book_requests.c 
book_requests.o: book_requests.c book.h
	gcc -c book_requests.c

#builds book_requests by linking readline.o, book.o, and book_requests.o
book_requests: book_requests.o book.o readline.o
	gcc -o book_requests book_requests.o book.o readline.o 
clean:
	rm book_requests book_requests.o book.o readline.o 
