/* header file that contains struct book declaration 
and prototypes for the functions in book.c. 
*/

#ifndef BOOK_H //ifndef determines if book.h does not exist before including the following code 
#define BOOK_H 
#define TITLE_LEN 100
#define NAME_LEN 30
#define ROOM_LEN 20
struct book{
	char title[TITLE_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char classroom[ROOM_LEN+1];
	double price;
	struct book *next;
};


struct book *add_to_end(struct book *list);
void search(struct book *list);
void print_list(struct book *list);
void clear_list(struct book *list);
int read_line(char str[], int n);

#endif //closes the directives 