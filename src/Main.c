#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <assert.h>
#include <conio.h>
#include "List.h"

void test_list_creation();
void test_list_length();
void test_list_search();
void test_list_concat();
void test_starts_with();
void test_is_sublist();

void show_search();
void show_concat();
void show_invert();

void test_list_creation() {
	list* tlst;
	create_list(&tlst);
	assert(tlst != NULL);
	return;
};

void test_list_length() {
	list* tlist;
	create_list(&tlist);
	add_item(tlist, 2, true);
	add_item(tlist, 5, true);
	add_item(tlist, 5, false);
	add_item(tlist, 6, true);
	assert(get_list_length(tlist) == 4);
}

void test_list_search() {
	list* tlist;
	create_list(&tlist);
	//// 7, 912, -42
	add_item(tlist, 912, true);
	add_item(tlist, -42, false);
	add_item(tlist, 7, true);
	assert(find_element(tlist, 912) != NULL);
	assert(find_element(tlist, 11) == NULL);
	assert(find_element(tlist, -42)->next == NULL);
}

void test_replace() {
	int initial;
	list* tlist;
	create_list(&tlist);
	add_item(tlist, 2, true);
	add_item(tlist, 3, false);
	add_item(tlist, 2, true);
	initial = get_list_length(tlist);
	assert(find_element(tlist, 3) != NULL);
	replace_all(tlist, 3, 2);
	assert(find_element(tlist, 3) == NULL);
	assert(get_list_length(tlist) == initial);	
}


void init_lists(list** a, list** b){
	create_list(a);
	create_list(b);	
}

void test_list_concat() {
	list* first, *second, *result;
	init_lists(&first, &second);	
	create_list(&result);
	add_item(first, 1, true);
	add_item(first, 2, true);
	
	add_item(second, 10, false);
	add_item(second, 12, false);
	add_item(second, 13, false);
	result = list_concat(first, second);
	assert(get_list_length(result) == get_list_length(first) + get_list_length(second));
	assert(find_element(result, 12) != NULL);
}

void test_starts_with() {
	list* first, *second;
	int a[4] = {1, 2, 3, 4};
	int b[3] = {1, 2, 3};
	init_lists(&first, &second);
	add_items(first, a, 4);
	add_items(second, b, 3);
	assert(starts_with(first, second));
	assert(!starts_with(second, first));
}

void test_is_sublist() {
	list* first, *second;
	int a[4] = {1, 2, 3, 4};
	int b[2] = {2, 3};
	init_lists(&first, &second);
	add_items(first, a, 4);
	add_items(second, b, 2);
	assert(is_sublist(first, second) == true);
}


void read_list(list** lst, int number) {
   int item;
   create_list(lst);
   printf("Enter list %d \n", number);
   printf("Enter item or zero to finish\n");
   scanf("%d", &item);
   while (item != 0) {      
      add_item(*lst, item, false);
      scanf("%d", &item);
   }
   printf("Done with list %d length is %d\n", number, get_list_length(*lst));
}

void print_list(list* lst) {
   list_node* iter;
   assert(lst != NULL);
   iter = lst->head;
   printf("List length is %d ( ", get_list_length(lst));
   while (iter != NULL) {
      printf("%d ", iter->data);
      iter = iter->next;
   }
   printf(")\n");
}

int main() {
   char command[10];   
   int out = printf("Hello to my list program\n");
	test_list_creation();	
	test_list_length();
	test_list_search();	
	test_list_concat();	
	test_starts_with();
	test_is_sublist();
	printf("All tests done.\n");
   printf("Which program u want to run?\n Enter one of the following:\nsearch\nconcat\ninvert\nisstart\nissublist\nreplace\n");
   scanf("%s", command);
   if (strcmp(command, "search") == 0) {
      show_search();
   } else if (strcmp(command, "concat") == 0) {
      show_concat();
   } else if (strcmp(command, "invert") == 0) {
      show_invert();
   } else if (strcmp(command, "isstart") == 0) {

   } else if (strcmp(command, "issublist") == 0) {

   } else if (strcmp(command, "replace") == 0) {

   } else printf("Invalid command\n");   
   getch();
   return 0;
}


void show_search() {
   list* a;
   int element;
   printf("List search demo\n");
   read_list(&a, 1);
   printf("Enter element to search-> ");
   scanf("%d", &element);
   printf("%s\n", (find_element(a, element) == NULL) ? "No such element" : "Found");
}

void show_concat() {
   list *a, *b, *res;
   printf("List concatenation demo");
   read_list(&a, 1);
   read_list(&b, 2);
   printf("Result list is: ");
   res = list_concat(a, b);
   print_list(res);
}

void show_invert() {
   list* a;
   printf("Show list invert demo\n");
   read_list(&a, 1);
   printf("Result list is: ");
   list_invert(a);
   print_list(a);
}
