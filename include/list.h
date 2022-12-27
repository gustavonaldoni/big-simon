struct Node
{
    int data;
    struct Node *next;
};

typedef struct
{
    struct Node *init;
    struct Node *end;
} ListLSE;

void ListLSECreate(ListLSE *);
bool ListLSEIsEmpty(ListLSE);

bool ListLSEInsertEnd(ListLSE *, int);

int ListLSEInit(ListLSE);
int ListLSEEnd(ListLSE);

int ListLSECountElements(ListLSE);
int ListLSERemove(ListLSE *list, int);