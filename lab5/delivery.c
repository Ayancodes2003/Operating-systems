#include <stdio.h>

#define MAX_CUSTOMERS 100

struct Customer {
    int id;
    int distance;
};

void sjf_scheduling(struct Customer customers[], int numCustomers) {
    int i, j;
    struct Customer temp;

    // Sort the customers based on distance in ascending order using bubble sort
    for (i = 0; i < numCustomers - 1; i++) {
        for (j = 0; j < numCustomers - i - 1; j++) {
            if (customers[j].distance > customers[j + 1].distance) {
                temp = customers[j];
                customers[j] = customers[j + 1];
                customers[j + 1] = temp;
            }
        }
    }

    // Display the sorted customers
    printf("Customers in the order of delivery:\n");
    for (i = 0; i < numCustomers; i++) {
        printf("Customer ID: %d, Distance: %d\n", customers[i].id, customers[i].distance);
    }
}

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int numCustomers, i;

    printf("Enter the number of customers: ");
    scanf("%d", &numCustomers);

    printf("Enter the customer details (ID and distance):\n");
    for (i = 0; i < numCustomers; i++) {
        printf("Customer %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &customers[i].id);
        printf("Distance: ");
        scanf("%d", &customers[i].distance);
    }

    sjf_scheduling(customers, numCustomers);

    return 0;
}

