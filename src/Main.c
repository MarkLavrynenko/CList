#include <stdio.h>
#include <stdlib.h>
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
int main() {
    int out = printf("Hello to my list program\n");
	test_list_creation();	
	test_list_length();
	test_list_search();	
	test_list_concat();	
	test_starts_with();
	test_is_sublist();
	printf("All programs done.\n");
    list* first, *second, *result;
    list_node* i;
    char l;
    int n,k1,k2;
    init_lists(&first, &second);
    create_list(&result);
    printf("Vvedite element spiska 1 or 0 dlia vyhoda.\n");
    do{scanf("%d",&n);
    if (n==0) break;
    add_item (first, n, true);} while(1);
    printf("Vvedite element spiska 2 or 0 dlia vyhoda.\n");
    do{scanf("%d",&n);
    if (n==0) break;
    add_item (second,n,true);} while(1);
    k1=get_list_length(first);
    k2=get_list_length(second);
    printf("Dlina 1 spiska=\n");
    printf("Dlina 2 spiska=\n",k2);
    printf("Vvedite element poiska.\n");
    scanf("%d",&n);
    if(find_element(first,n)==NULL) printf("Element otsutstvuet y spiske 1.\n");
    else printf("Element est' v spiske 1.\n");
    result=list_concat(first,second);
    i = result->head;
	while (i != NULL) {printf(" ",i->data); i = i->next;}
    getch();
    return 0;
}
