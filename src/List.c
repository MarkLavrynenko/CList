#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#include "List.h"

void create_node(list_node** outnode, int data) {
	list_node* node = (list_node*)malloc(sizeof(list_node));
	node->next = NULL;
	node->data = data;
	*outnode = node;
}

void create_list(list** outlst) {
	list* lst = (list*)malloc(sizeof(list));
	lst->head = NULL;
	lst->tail = NULL;
	lst->count = 0;
	*outlst = lst;
}


void start_work(list* lst) {	
	create_list(&lst);
}

bool is_list_empty(list* lst)
{	
	return (lst->count == 0);
}

void add_item(list* list, int item, bool begin) {
	list_node* node;
	create_node(&node, item);
	if (list->head == NULL) {
		list->tail = list->head= node;
		list->count = 1;		 
	} else {
		// vstavka v nachalo spiska
		if (begin) {
			node->next = list->head;
			list->head = node;			
		} else {
			list->tail->next = node;
			list->tail = node;
		}
		++list->count;
	}		
}

// dobavlenie el-ta v konets
void add_items(list* list, int* items, int count) {
	while (count > 0) {
		add_item(list, *items, false);
		++items;
		--count;
	}
}

list_node* get_head(list* lst) {
	return lst->head;
}

list_node* get_tail(list* lst) {
	return lst->tail;
}

int get_list_length(list* lst) {
	int len = 0;
	list_node* head = get_head(lst);
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

int replace_all(list* lst, int m, int n) {
	int repl = 0;
	list_node* node = get_head(lst);
	while (node != NULL) {
		if (node->data == m) {
			node->data = n;
			repl++;
		}
		node = node->next;
	}
	return repl;
}

list_node* find_element(list* lst, int elem) {
	list_node* node = get_head(lst);
	while (node != NULL) {
		if (node->data == elem) 
			return node;
		node = node->next;
	}
	return NULL;
}

list* list_concat(list* fst, list* scnd) {
	list* res;
	list_node* i;
	create_list(&res);
	i = fst->head;
	while (i != NULL) {
		add_item(res, i->data, false);
		i = i->next;
	}
	i = scnd->head;
	while (i != NULL) {
		add_item(res, i->data, false);
		i = i->next;
	}	
	return res;
}

// true, yesli perviy spisok yest' nachalom vtorogo
bool starts_with(list* frst, list* second) {
	int n, m;
	list_node *i, *j;
	n = get_list_length(frst);
	m = get_list_length(second);
	if (n < m)
		return false;
	i = frst->head;
	j = second->head;
	while (j != NULL && i->data == j->data) {
		i = i->next;
		j = j->next;
	}
	return j == NULL;	
}
// true, yesli perviy spisok soderzhit vtoroi
bool is_sublist(list* frst, list* scnd) {
	// zadanie peremennih
	int n, m;
	list part;	
	list_node *i = frst->head;
	// osnovnaya chast'
	part.count = n = frst->count;
	part.head = frst->head;
	part.tail = frst->tail;
	
	m = scnd->count;
	if (m == 0)
		return true;
	if (n < m)
		return false;
	// reshenie
	while (part.count >= m && i != NULL) {
		if (starts_with(&part, scnd))
			return true;		
		--part.count;
		part.head = part.head->next;	
	}
	return false;
}	
