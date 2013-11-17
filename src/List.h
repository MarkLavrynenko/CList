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
#define MAX_LENGTH 20

void create_node(list_node** outnode, int data);
void create_list(list** outlst);
void start_work(list* lst);
bool is_list_empty(list* lst);
void add_item(list* list, int item, bool begin);
void add_items(list* list, int* items, int count);
list_node* get_head(list* lst);
list_node* get_tail(list* lst);
int get_list_length(list* lst);
int replace_all(list* lst, int m, int n);
list_node* find_element(list* lst, int elem);
list* list_concat(list* fst, list* scnd);
bool starts_with(list* frst, list* second);
bool is_sublist(list* frst, list* scnd);
