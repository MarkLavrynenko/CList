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
		// insert at the beginning of the list
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

// append items to the end
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

int replace_all(list* lst, int n, int m) {
	int repl = 0;
	list_node* node = get_head(lst);
	while (node != NULL) {
		if (node->data == n) {
			node->data = m;
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

void list_invert(list* lst) {
   list_node *i, 
             *prev   = NULL,
             *tmp    = NULL;
   i = get_head(lst);
   while (i != NULL) {
      tmp = i;
      i = i->next;
      tmp->next = prev;
      prev = tmp;
   }
   lst->head = prev;
}

// return true if first list begins with second list
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
// return true if first list contains the second
bool is_sublist(list* frst, list* scnd) {
	// declare variables
	int n, m;
	list part;	
	list_node *i = frst->head;
	// init part
	part.count = n = frst->count;
	part.head = frst->head;
	part.tail = frst->tail;
	
	m = scnd->count;
	if (m == 0)
		return true;
	if (n < m)
		return false;
	// solve
	while (part.count >= m && i != NULL) {
		if (starts_with(&part, scnd))
			return true;		
		--part.count;
		part.head = part.head->next;	
	}
	return false;
}

int compare(const void* x1, const void* x2) {
   return *((int*)x1)  - *((int*)x2);
}


// sort list using quick sort algorithm, Time - O(N*log(N)), O(N) - additional memory for array
void list_sort(list* lst) {   
   list_node* iter;
   int i = 0, count = lst->count;
   int* a = (int*)malloc(sizeof(int) * count);

   //extract data from list
   iter = lst->head;   
   while (iter != NULL) {
      *(a+(i++)) = iter->data;
      iter = iter->next;
   }
   qsort(a, count, sizeof(int), compare);

   // update date into list
   iter = lst->head;   
   i = 0;
   while (iter != NULL) {
      iter->data = *(a+(i++));
      iter = iter->next;
   }
   free(a);
}
