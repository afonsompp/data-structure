
#define MAX 100
struct student
{
	int registry;
	char name[30];
	float n1, n2, n3, n4;
};

typedef struct list List;
typedef struct student Student;

List *create_list();

int length_list(List *l);

int is_full(List *l);

int is_empty(List *l);

void free_list(List *l);

int add_first(List *li, Student st);

int add_last(List *li, Student st);

int add_sorted(List *li, Student st);

int remove_last(List *l);

int remove_first(List *li);

int remove_by_register(List *li, Student st);

int find_by_index(List *l, int pos, Student *st);

int find_by_register(List *l, Student find, Student *st);
