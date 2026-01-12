/*9. Develop a Program in C for the following operationson Singly Circular Linked List (SCLL) with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in
POLYSUM(x,y,z). Support the program with appropriate functions for each of the above operations*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int c, x, y, z;
    struct node *link;
};
typedef struct node *NODE;

NODE create() {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->link = temp; // Circular initialization
    return temp;
}

NODE attach(int c, int x, int y, int z, NODE head) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    NODE cur = head->link;
    temp->c = c; temp->x = x; temp->y = y; temp->z = z;
    while (cur->link != head) cur = cur->link; // Traverse to end
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE read_poly(NODE head) {
    int n, c, x, y, z, i;
    printf("Enter terms: "); scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Coef, Pow x y z: "); scanf("%d %d %d %d", &c, &x, &y, &z);
        head = attach(c, x, y, z, head);
    }
    return head;
}

void display(NODE head) {
    NODE temp = head->link;
    if (temp == head) { printf("Polynomial empty"); return; }
    while (temp != head) {
        printf("%dx^%dy^%dz^%d", temp->c, temp->x, temp->y, temp->z);
        temp = temp->link;
        if (temp != head) printf(" + ");
    }
    printf("\n");
}

int evaluate(NODE head) {
    int x, y, z, sum = 0;
    NODE temp = head->link;
    printf("Enter x, y, z: "); scanf("%d %d %d", &x, &y, &z);
    while (temp != head) {
        sum += temp->c * pow(x, temp->x) * pow(y, temp->y) * pow(z, temp->z);
        temp = temp->link;
    }
    return sum;
}

// Logic: Returns 1 if Term A > Term B, -1 if B > A, 0 if equal
int compare(NODE a, NODE b) {
    if (a->x > b->x) return 1;
    if (a->x < b->x) return -1;
    if (a->y > b->y) return 1;
    if (a->y < b->y) return -1;
    if (a->z > b->z) return 1;
    if (a->z < b->z) return -1;
    return 0;
}

NODE poly_sum(NODE h1, NODE h2, NODE h3) {
    NODE a = h1->link, b = h2->link;
    while (a != h1 && b != h2) {
        int rel = compare(a, b);
        if (rel == 1) { // a > b
            h3 = attach(a->c, a->x, a->y, a->z, h3); a = a->link;
        } else if (rel == -1) { // b > a
            h3 = attach(b->c, b->x, b->y, b->z, h3); b = b->link;
        } else { // Equal exponents
            if (a->c + b->c != 0) h3 = attach(a->c + b->c, a->x, a->y, a->z, h3);
            a = a->link; b = b->link;
        }
    }
    while (a != h1) { h3 = attach(a->c, a->x, a->y, a->z, h3); a = a->link; }
    while (b != h2) { h3 = attach(b->c, b->x, b->y, b->z, h3); b = b->link; }
    return h3;
}

int main() {
    NODE h, h1, h2, h3;
    int ch;
    while (1) {
        printf("\n1.Evaluate 2.Add 3.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: h = create();
                    h = read_poly(h);
                    display(h);
                    printf("Result: %d\n", evaluate(h));
                    break;
            case 2: h1 = create(); h2 = create(); h3 = create();
                    printf("Poly 1:\n"); h1 = read_poly(h1);
                    printf("Poly 2:\n"); h2 = read_poly(h2);
                    printf("Sum: ");
                    h3 = poly_sum(h1, h2, h3);
                    display(h3);
                    break;
            case 3: exit(0);
        }
    }
}