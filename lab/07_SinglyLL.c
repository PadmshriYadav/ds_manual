#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char usn[20], name[20], branch[20];
    int sem;
    long long phone;
    struct node *link;
};
typedef struct node *NODE;

NODE head = NULL;
int count = 0;

NODE create() {
    NODE snode = (NODE)malloc(sizeof(struct node));
    if (snode == NULL) { printf("Memory Error"); exit(0); }
    printf("Enter USN, Name, Branch, Sem, Phone: ");
    scanf("%s %s %s %d %lld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->link = NULL;
    count++;
    return snode;
}

void insertFront() {
    NODE temp = create();
    if (head == NULL) head = temp;
    else { temp->link = head; head = temp; }
}

void insertEnd() {
    NODE temp = create(), cur = head;
    if (head == NULL) { head = temp; return; }
    while (cur->link != NULL) cur = cur->link;
    cur->link = temp;
}

void deleteFront() {
    NODE temp;
    if (head == NULL) { printf("List Empty\n"); return; }
    temp = head;
    head = head->link;
    printf("Deleted USN: %s\n", temp->usn);
    free(temp);
    count--;
}

void deleteEnd() {
    NODE cur = head, prev = NULL;
    if (head == NULL) { printf("List Empty\n"); return; }
    if (head->link == NULL) {
        printf("Deleted USN: %s\n", head->usn);
        free(head); head = NULL;
    } else {
        while (cur->link != NULL) { prev = cur; cur = cur->link; }
        printf("Deleted USN: %s\n", cur->usn);
        free(cur);
        prev->link = NULL;
    }
    count--;
}

void display() {
    NODE cur = head;
    int i = 1;
    if (head == NULL) { printf("List Empty\n"); return; }
    printf("\n--- Student List ---\n");
    while (cur != NULL) {
        printf("%d. USN:%s | Name:%s | Branch:%s | Sem:%d | Ph:%lld\n", 
               i++, cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->link;
    }
    printf("Total Nodes: %d\n", count);
}

void stackDemo() {
    int ch;
    while (1) {
        printf("\n[Stack Demo] 1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insertFront(); break;
            case 2: deleteFront(); break;
            case 3: display(); break;
            case 4: return;
        }
    }
}

int main() {
    int ch, n, i;
    while (1) {
        printf("\n1.Create(N) 2.Display 3.InsEnd 4.DelEnd 5.StackDemo 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter N: "); scanf("%d", &n);
                    for(i=0; i<n; i++) insertFront(); break;
            case 2: display(); break;
            case 3: insertEnd(); break;
            case 4: deleteEnd(); break;
            case 5: stackDemo(); break;
            case 6: exit(0);
        }
    }
}