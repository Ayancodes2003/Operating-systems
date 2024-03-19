#include <stdio.h>
#include <stdbool.h>

// Shared account balance
int balance = 2000;

// Flags and turn variable for Peterson's algorithm
bool flag[2];
int turn;

// Initialize Peterson's algorithm
void lock_init() {
    flag[0] = flag[1] = false;
    turn = 0;
}

// Peterson's lock function
void lock(int self) {
    flag[self] = true;
    turn = 1 - self;
    while (flag[1 - self] && turn == 1 - self);
}

// Peterson's unlock function
void unlock(int self) {
    flag[self] = false;
}

// Function to deposit an amount into the account
void deposit(int amount) {
    lock(0); // Assuming 0 for person X and 1 for person Y
    balance += amount;
    printf("Deposited %d, new balance: %d\n", amount, balance);
    unlock(0);
}

// Function to withdraw an amount from the account
void withdraw(int amount) {
    lock(1);
    if (balance >= amount) {
        balance -= amount;
        printf("Withdrew %d, new balance: %d\n", amount, balance);
    } else {
        printf("Insufficient balance\n");
    }
    unlock(1);
}

// Thread function for person X
void *personX(void *arg) {
    deposit(1000); // Person X deposits Rs 1000
    return NULL;
}

// Thread function for person Y
void *personY(void *arg) {
    withdraw(500); // Person Y withdraws Rs 500
    return NULL;
}

int main() {
    lock_init(); // Initialize Peterson's algorithm

    // Assuming a single-threaded environment for simplicity
    // In a real multi-threaded environment, you would use threads for personX and personY
    deposit(1000); // Person X deposits Rs 1000
    withdraw(500); // Person Y withdraws Rs 500

    return 0;
}

