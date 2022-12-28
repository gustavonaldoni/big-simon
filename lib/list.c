#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

void ListCreate(List *list)
{
    list->init = NULL;
    list->end = NULL;
}

bool ListIsEmpty(List list)
{
    return list.init == NULL && list.end == NULL;
}

bool ListInsertEnd(List *list, int i, int j)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    aux->i = i;
    aux->j = j;

    if (ListIsEmpty(*list))
    {
        list->init = aux;
        list->end = aux;

        aux->next = NULL;

        return true;
    }

    list->end->next = aux;
    aux->next = NULL;
    list->end = aux;

    return true;
}

void ListShow(List list)
{
    struct Node *aux;

    if (ListIsEmpty(list))
        return;

    aux = list.init;

    while (aux != NULL)
    {
        printf("(%d, %d)\n", aux->i, aux->j);
        aux = aux->next;
    }

    printf("===========\n");
}

bool ListInit(List list, int *i, int *j)
{
    if (ListIsEmpty(list))
        return false;

    *i = list.init->i;
    *j = list.init->j;
    return true;
}

bool ListEnd(List list, int *i, int *j)
{
    if (ListIsEmpty(list))
        return 0;

    *i = list.end->i;
    *j = list.end->j;
    return true;
}

int ListCountElements(List list)
{
    int counter = 0;
    struct Node *aux;

    if (ListIsEmpty(list))
        return 0;

    aux = list.init;

    while (aux != NULL)
    {
        counter += 1;
        aux = aux->next;
    }

    return counter;
}

int ListGetElement(List list, int position, int *i, int *j)
{
    struct Node *aux;
    int counter = 0;
    int numberOfElements = ListCountElements(list);

    if (ListIsEmpty(list))
        return 0;

    if (position < 0 || position >= numberOfElements)
        return 0;

    aux = list.init;

    while (counter < position)
    {
        aux = aux->next;
        counter++;
    }

    *i = aux->i;
    *j = aux->j;

    return 1;
}

bool ListRemove(List *list, int i, int j)
{
    struct Node *aux, *before, *current;

    if (ListIsEmpty(*list))
        return -1;

    // Remove first element of a unitary list
    if (list->init == list->end && list->init != NULL && list->init->i == i && list->init->j == j)
    {
        aux = list->init;

        aux->i = 0;
        aux->j = 0;

        list->init = NULL;
        list->end = NULL;

        free(aux);

        return true;
    }

    // Remove first element of a non unitary list
    if (list->init != list->end && list->init->i == i && list->init->j == j)
    {
        aux = list->init;

        list->init = list->init->next;

        free(aux);

        return true;
    }

    // Remove from any other position at of the list
    before = list->init;
    current = before->next;

    while (current->i != i && current->j != j && current->next != NULL)
    {
        before = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return false;
    }

    // Got to the last element at the list
    else if (current->next == NULL)
    {
        aux = current;

        before->next = NULL;
        list->end = before;

        free(aux);

        return true;
    }

    else
    {
        aux = current;

        before->next = current->next;

        free(aux);

        return true;
    }
}

int ListRemoveAll(List *list)
{
    struct Node *aux;

    if (ListIsEmpty(*list))
        return 0;

    aux = list->init;

    while (aux != NULL)
    {
        ListRemove(list, aux->i, aux->j);
        aux = aux->next;
    }

    return 1;
}