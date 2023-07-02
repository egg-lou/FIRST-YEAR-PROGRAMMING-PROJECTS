#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 4
#define NUM_SEATS (NUM_ROWS * NUM_COLUMNS)

struct AirplaneSeats {
    int row;
    char column;
    bool occupied;
}seats[NUM_ROWS][NUM_COLUMNS];

void showAirplaneSeats();
void initSeats();

int main() {
    int numAvailableSeats = NUM_SEATS;
    int seatsToReserve;
    int reservedSeats = 0;

    initSeats();
    printf("Airplane Seats Reserver\n");

    while (numAvailableSeats > 0) {
        printf("\nNumber of Available Seats: %d\n\n", numAvailableSeats);
        printf("How many airplane seats would you like to reserve? (0 to exit): ");

        while (scanf("%d", &seatsToReserve) != 1)	{
    	printf("INVALID INPUT. Please enter numbers only.\n");
    	while (getchar() != '\n');
	    }

        if (seatsToReserve == 0)
            break;

        if (seatsToReserve > numAvailableSeats) {
            printf("\nInvalid number of seats. Only %d seat(s) available.\n", numAvailableSeats);
            continue;
        }

        showAirplaneSeats();

        for (int i = 0; i < seatsToReserve; i++) {
            int row;
            char col;
            bool seatFound = false;

            while (!seatFound) {
                printf("\n\nPlease choose an available seat (e.g., 1A): ");
                scanf("%d%c", &row, &col);

                col = toupper(col);

                if (row < 1 || row > NUM_ROWS || col < 'A' || col > 'A' + NUM_COLUMNS - 1) {
                    printf("Invalid Seat Choice. Please try again.\n");
                } else {
                    int seatIndex = (row - 1) * NUM_COLUMNS + (col - 'A');
                    if (seats[row - 1][col - 'A'].occupied) {
                        printf("Seat %d%c is already taken. Please choose another seat.\n", row, col);
                    } else {
                        seats[row - 1][col - 'A'].occupied = true;
                        numAvailableSeats--;
                        reservedSeats++;
                        seatFound = true;
                    }
                }
            }

            showAirplaneSeats();
        }
    }

    if(reservedSeats == NUM_SEATS)
        printf("All of the seats are reserved: %d/%d", reservedSeats, NUM_SEATS);
    else
        printf("\nNumber of seats reserved: %d/%d\n", reservedSeats, NUM_SEATS);

    showAirplaneSeats();
    getch();

    return 0;
}

void showAirplaneSeats() {
    printf("Airplane Seats Available:\n");

    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%d    ", i + 1);

        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (seats[i][j].occupied) {
                printf(" X ");
            } else {
                printf(" %c ", 'A' + j);
            }
        }
        printf("\n");
    }
}

void initSeats() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            seats[i][j].row = i + 1;
            seats[i][j].column = 'A' + j;
            seats[i][j].occupied = false;
        }
    }
}