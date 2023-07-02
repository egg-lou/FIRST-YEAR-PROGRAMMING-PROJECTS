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
}seats[NUM_SEATS];


void showAirplaneSeats();
void initSeats();

int main() {
    int numAvailableSeats = NUM_SEATS;
    int seatsToReserve;
    int reservedSeats = 0;

    initSeats();
    printf("\nAirplane Seats Reserver\n\n");
    showAirplaneSeats();

    while (numAvailableSeats > 0) {
        printf("\nNumber of Available Seats: %d\n\n", numAvailableSeats);
        printf("How many airplane seats would you like to reserve? (0 to exit): ");
        
        if(scanf("%d", &seatsToReserve) != 1){
            printf("INVALID INPUT. Please enter numbers only.\n");
            while(getchar() != '\n');
        }

        if (seatsToReserve == 0)
            break;

        if (seatsToReserve > numAvailableSeats) {
            printf("\nInvalid number of seats. Only %d seat(s) available.\n", numAvailableSeats);
            continue;
        }

        showAirplaneSeats();

        for (int i = 0; i < seatsToReserve; i++) {
            int seatIndex;
            bool seatFound = false;

            while (!seatFound) {
                printf("\n\nPlease choose an available seat (e.g., 1A): ");
                scanf("%d%c", &seats[i].row, &seats[i].column);

                seats[i].column = toupper(seats[i].column);

                if (seats[i].row < 1 || seats[i].row > NUM_ROWS || seats[i].column < 'A' || seats[i].column > 'A' + NUM_COLUMNS - 1) {
                    printf("Invalid Seat Choice. Please try again.\n");
                } else {
                    seatIndex = (seats[i].row - 1) * NUM_COLUMNS + (seats[i].column - 'A');
                    if (seats[seatIndex].occupied) {
                        printf("Seat %d%c is already taken. Please choose another seat.\n", seats[i].row, seats[i].column);
                    } else {
                        seats[seatIndex].occupied = true;
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
        printf("All of the seats are reserved: %d/%d\n", reservedSeats, NUM_SEATS);
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
            int seatIndex = i * NUM_COLUMNS + j;

            if (seats[seatIndex].occupied) {
                printf(" X ");
            } else {
                printf(" %c ", 'A' + j);
            }
        }
        printf("\n");
    }
}

void initSeats() {
    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i].row = i / NUM_COLUMNS + 1;
        seats[i].column = 'A' + i % NUM_COLUMNS;
        seats[i].occupied = false;
    }
}