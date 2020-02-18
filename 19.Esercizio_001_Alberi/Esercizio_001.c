// esercizio test alberi

#include <stdio.h>
#include <stdlib.h>

// struttura

struct node
{
    struct node *left;
    struct node *right;
    int key;
} node;

// inserisce un nuovo nodo

void insert(struct node **tree, struct node *new)
{
    if (*tree == NULL)
    {
        *tree = new;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else
    {
        if (new->key < (*tree)->key)
        {
            insert(&(*tree)->left, new);
        }
        else
        {
            if (new->key > (*tree)->key)
            {
                insert(&(*tree)->right, new);
            }
            else
            {
                printf("\n Chiave duplicata!!\n");
            }
        }
    }
}

// ricerca una key

struct node *find_by_key(struct node *tree, int key)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (key < tree->key)
    {
        return find_by_key(tree->left, key);
    }
    else if (key > tree->key)
    {
        return find_by_key(tree->right, key);
    }
    else
    {
        return tree;
    }
}

// stampa l'albero

void in_order_view(struct node *tree)
{
    if (tree != NULL)
    {
        in_order_view(tree->left);
        printf("\n Key : %d", tree->key);
        in_order_view(tree->right);
    }
}

// carica l'albero

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// main

int main(int argc, char const *argv[])
{
    struct node *tree;
    struct node *nodo;
    int data;
    char ancora;

    tree = NULL;
    nodo = NULL;

    // chiede la key iniziale

    printf("\n Inserire la chiave della root: ");
    fflush(stdin);
    scanf("%d", &data);

    tree = newNode(data);

    // chiede key all'utente e le aggiunge

    do
    {
        printf("\n Inserire la chiave del nodo: ");
        fflush(stdin);
        scanf("%d", &data);
        nodo = newNode(data);
        insert(&tree, nodo);

        printf("\n Vuoi inserirne ancora?");
        fflush(stdin);
        scanf("%c", &ancora);

    } while (ancora != 'n' && ancora != 'N');

    printf("\n Inserire la chiave del nodo da cercare: ");
    fflush(stdin);
    scanf("%d", &data);
    nodo = find_by_key(tree, data);
    printf("\n trovato: %d", nodo->key);

    in_order_view(tree);

    return 0;
}