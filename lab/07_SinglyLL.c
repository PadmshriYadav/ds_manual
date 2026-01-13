#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char usn[20], name[20], branch[20];
    int sem;
    long long phone;
    struct node *next;
};

struct node *head = NULL;
int count = 0;

struct node * create() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory Error");
        exit(0);
    }
    printf("Enter USN, Name, Branch, Sem, Phone: ");
    scanf("%s %s %s %d %lld", newNode->usn, newNode->name, newNode->branch, &newNode->sem, &newNode->phone);
    newNode->next = NULL;
    count++;
    return newNode;
}

void insertFront() {
    struct node *newNode = create();
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd() {
    struct node *newNode = create();
    struct node *ptr = head;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void deleteFront() {
    struct node *ptr;
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    ptr = head;
    head = head->next;
    printf("Deleted USN: %s\n", ptr->usn);
    free(ptr);
    count--;
}

void deleteEnd() {
    struct node *ptr = head;
    struct node *prev = NULL;
    
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    if (head->next == NULL) {
        printf("Deleted USN: %s\n", head->usn);
        free(head);
        head = NULL;
    } else {
        while (ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        printf("Deleted USN: %s\n", ptr->usn);
        free(ptr);
        prev->next = NULL;
    }
    count--;
}

void display() {
    struct node *ptr = head;
    int i = 1;
    
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    printf("\n--- Student List ---\n");
    while (ptr != NULL) {
        printf("%d. USN:%s | Name:%s | Branch:%s | Sem:%d | Ph:%lld\n", 
               i++, ptr->usn, ptr->name, ptr->branch, ptr->sem, ptr->phone);
        ptr = ptr->next;
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
            case 1: 
                printf("Enter N: ");
                scanf("%d", &n);
                for(i = 0; i < n; i++) insertFront();
                break;
            case 2: display(); break;
            case 3: insertEnd(); break;
            case 4: deleteEnd(); break;
            case 5: stackDemo(); break;
            case 6: exit(0);
        }
    }
    return 0;
}