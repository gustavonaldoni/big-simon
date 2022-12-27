struct Node
{
    int i, j;
    struct Node *next;
};

typedef struct
{
    struct Node *init;
    struct Node *end;
} List;

void ListCreate(List *);
bool ListIsEmpty(List);

bool ListInsertEnd(List *, int, int);

bool ListInit(List, int *, int *);
bool ListEnd(List, int *, int *);

int ListCountElements(List);
bool ListRemove(List *list, int, int);