#include <stdio.h>
#include <stdbool.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 4
#define NUM_SEATS (NUM_ROWS * NUM_COLUMNS)

struct Seat {
    int row;
    char column;
    bool assigned;
} seats[NUM_SEATS];

void displaySeatPattern() {
    printf("Seat Pattern:\n");
    for (int i = 0; i < NUM_SEATS; i++) {
        if (i % NUM_COLUMNS == 0 && i != 0) {
            printf("\n");
        }
        if (seats[i].assigned) {
            printf("X");
        } else {
            printf("%d%c", seats[i].row, seats[i].column);
        }
    }
    printf("\n");
}

int main() {
    // Initialize seats
    for (int i = 0; i < NUM_SEATS; i++) {
        int row = (i / NUM_COLUMNS) + 1;
        char column = 'A' + (i % NUM_COLUMNS);
        seats[i].row = row;
        seats[i].column = column;
        seats[i].assigned = false;
    }

    int numAssignedSeats = 0;

    while (numAssignedSeats < NUM_SEATS) {
        displaySeatPattern();

        int numSeatsToReserve;
        printf("Enter the number of seats to reserve (enter 0 to exit): ");
        scanf("%d", &numSeatsToReserve);

        if (numSeatsToReserve == 0) {
            break;
        }

        bool allSeatsAvailable = true;

        for (int i = 0; i < numSeatsToReserve; i++) {
            int row;
            char column;

            printf("Enter seat choice %d (e.g., 1A): ", i + 1);
            scanf("%d %c", &row, &column);

            bool seatFound = false;

            for (int j = 0; j < NUM_SEATS; j++) {
                if (seats[j].row == row && seats[j].column == column) {
                    if (seats[j].assigned) {
                        printf("Seat %d%c is occupied. Please choose another seat.\n", row, column);
                    } else {
                        seats[j].assigned = true;
                        numAssignedSeats++;
                        seatFound = true;
                    }
                    break;
                }
            }

            if (!seatFound) {
                printf("Invalid seat choice. Please try again.\n");
                allSeatsAvailable = false;
                break;
            }
        }

        if (allSeatsAvailable) {
            printf("Seats reserved successfully!\n");
        }
    }

    printf("All seats have been assigned.\n");

    return 0;
}
