#include <stdio.h>

// Define the structure for a single term in a polynomial
struct poly {
    int coeff;  // coefficient of the term
    int expo;   // exponent of the term
};

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    struct poly p1[10], p2[10], p3[10];  // arrays to store polynomials
    int t1, t2, t3;  // number of terms in polynomials

    // Read and display first polynomial
    printf("Enter the first polynomial:\n");
    t1 = readPoly(p1);
    printf("\nFirst polynomial : ");
    displayPoly(p1, t1);

    // Read and display second polynomial
    printf("\nEnter the second polynomial:\n");
    t2 = readPoly(p2);
    printf("\nSecond polynomial : ");
    displayPoly(p2, t2);

    // Add two polynomials and display resultant polynomial
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition : ");
    displayPoly(p3, t3);
    printf("\n");

    return 0;
}

// Function to read polynomial terms from user
int readPoly(struct poly p[10]) {
    int t, i;
    printf("Enter the total number of terms in the polynomial: ");
    scanf("%d", &t);
    printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t; i++) {
        printf("Enter Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return t;
}

// Function to add two polynomials
int addPoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10]) {
    int i = 0, j = 0, k = 0;

    // Traverse both polynomials until all terms are processed
    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            // If exponents are equal, add coefficients and store in p3
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
        } else if (p1[i].expo > p2[j].expo) {
            // If exponent of p1 term is higher, copy it to p3
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
        } else {
            // If exponent of p2 term is higher, copy it to p3
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
        }
        k++;  // Move to the next position in p3
    }

    // Copy remaining terms of p1, if any
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // Copy remaining terms of p2, if any
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k;  // Return the number of terms in the resultant polynomial p3
}

// Function to display polynomial
void displayPoly(struct poly p[10], int term) {
    int i;
    for (i = 0; i < term - 1; i++) {
        printf("%d(x^%d) + ", p[i].coeff, p[i].expo);
    }
    printf("%d(x^%d)\n", p[i].coeff, p[i].expo);
}
