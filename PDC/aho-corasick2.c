#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// A node in the trie data structure
typedef struct node
{
    int is_end;
    struct node *next[ALPHABET_SIZE];
    struct node *fail;
} node;

// Create a new node in the trie
node *new_node()
{
    node *n = (node *)malloc(sizeof(node));
    n->is_end = 0;
    memset(n->next, 0, sizeof(n->next));
    n->fail = NULL;
    return n;
}

// Insert a pattern into the trie
void insert(node *root, char *pattern)
{
    node *curr = root;
    for (int i = 0; pattern[i]; i++)
    {
        int index = pattern[i] - 'a';
        if (curr->next[index] == NULL)
        {
            curr->next[index] = new_node();
        }
        curr = curr->next[index];
    }
    curr->is_end = 1;
}

// Build the failure function for the trie
void build_fail(node *root)
{
    root->fail = root;
    node *q[10000];
    int front = 0, rear = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->next[i] != NULL)
        {
            root->next[i]->fail = root;
            q[rear++] = root->next[i];
        }
    }
    while (front != rear)
    {
        node *curr = q[front++];
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (curr->next[i] != NULL)
            {
                node *next = curr->next[i];
                node *fail = curr->fail;
                while (fail != root && fail->next[i] == NULL)
                {
                    fail = fail->fail;
                }
                if (fail->next[i] != NULL)
                {
                    fail = fail->next[i];
                }
                next->fail = fail;
                q[rear++] = next;
            }
        }
    }
}

// Find all occurrences of the patterns in the text
void find(node* root, char* text) {
    node* curr = root;
    for (int i = 0; text[i]; i++) {
        int index = text[i] - 'a';
        while (curr != root && curr->next[index] == NULL) {
            curr = curr->fail;
        }
        if (curr->next[index] != NULL) {
            curr = curr->next[index];
        }
        node* match = curr;
        while (match != root) {
            if (match->is_end) {
                for (int j = 0; j < ALPHABET_SIZE; j++) {
                    if (match->next[j] != NULL) {
                        node* pattern_node = match->next[j];
                        printf("Word '%s' appears from the position %d to %d\n", text + i - (int) strlen(pattern_node->fail) + 1, i - (int) strlen(pattern_node->fail) + 1, i);
                    }
                }
            }
            match = match->fail;
        }
    }
}

int main()
{
    char text[10000];
    char patterns[1000][100];
    int n;

    printf("Enter the text:\n");
    scanf("%[^\n]s", text);
    getchar();
    printf("Enter the number of patterns:\n");
    scanf("%d", &n);
    getchar();

    node *root = new_node();

    printf("Enter the patterns:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", patterns[i]);
        insert(root, patterns[i]);
    }

    build_fail(root);

    find(root, text);

    return 0;
}