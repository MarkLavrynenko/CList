typedef struct list_node {
	int data;
	struct list_node* next;
} list_node;

typedef struct list {
	list_node* head;
	list_node* tail;
	int count;
} list;

typedef int bool;
#define true 1
#define false 0

extern void create_node(list_node** outnode, int data);
extern void create_list(list** outlst);
extern void start_work(list* lst);
extern bool is_list_empty(list* lst);
extern void add_item(list* list, int item, bool begin);
extern void add_items(list* list, int* items, int count);
list_node* get_head(list* lst);
list_node* get_tail(list* lst);
extern int get_list_length(list* lst);
extern int replace_all(list* lst, int m, int n);
list_node* find_element(list* lst, int elem);
list* list_concat(list* fst, list* scnd);
extern bool starts_with(list* frst, list* second);
extern bool is_sublist(list* frst, list* scnd);
