#include <stdio.h>
#include <stdbool.h>

// Structure to represent a card
struct Card {
    int value;
    char suit;
};

// Function to check if a hand is a flush (all the same suit)
bool is_flush(struct Card hand[]) {
    char suit = hand[0].suit;
    for (int i = 1; i < 5; i++) {
        if (hand[i].suit != suit) {
            return false;
        }
    }
    return true;
}

// Function to check if a hand is a straight (in order)
bool is_straight(struct Card hand[]) {
    int values[5];
    for (int i = 0; i < 5; i++) {
        values[i] = hand[i].value;
    }

    for (int i = 1; i < 5; i++) {
        if (values[i] != values[i-1] + 1) {
            return false;
        }
    }
    return true;
}

// Function to count the number of occurrences of each card value in a hand
void count_card_values(struct Card hand[], int value_count[]) {
    for (int i = 0; i < 5; i++) {
        int value = hand[i].value;
        value_count[value]++;
    }
}

// Function to score a poker hand
const char* score_hand(struct Card hand[]) {
    // Check for a straight flush
    if (is_flush(hand) && is_straight(hand)) {
        return "Straight Flush";
    }

    int value_count[15] = {0};  // Initialize the array to zeros
    count_card_values(hand, value_count);

    // Check for four of a kind
    for (int i = 1; i <= 13; i++) {
        if (value_count[i] == 4) {
            return "Four of a Kind";
        }
    }

    // Check for a full house
    bool has_two = false;
    bool has_three = false;
    for (int i = 1; i <= 13; i++) {
        if (value_count[i] == 2) {
            has_two = true;
        } else if (value_count[i] == 3) {
            has_three = true;
        }
    }
    if (has_two && has_three) {
        return "Full House";
    }

    // Check for a flush
    if (is_flush(hand)) {
        return "Flush";
    }

    // Check for a straight
    if (is_straight(hand)) {
        return "Straight";
    }

    // Check for three of a kind
    for (int i = 1; i <= 13; i++) {
        if (value_count[i] == 3) {
            return "Three of a Kind";
        }
    }

    // Check for two pairs
    int pair_count = 0;
    for (int i = 1; i <= 13; i++) {
        if (value_count[i] == 2) {
            pair_count++;
        }
    }
    if (pair_count == 2) {
        return "Two Pairs";
    }

    // Check for one pair
    for (int i = 1; i <= 13; i++) {
        if (value_count[i] == 2) {
            return "One Pair";
        }
    }

    // Default case: nothing
    return "Nothing";
}

// Function to read a card from the user
void read_card(struct Card card[]) {
    printf("Enter card value (1-13): ");
    scanf("%d", &(card->value));

    printf("Enter card suit (H, D, C, S): ");
    scanf(" %c", &(card->suit));
}

int main() {
    struct Card hand[5];

    printf("Enter your five-card hand:\n");
    for (int i = 0; i < 5; i++) {
        printf("Card %d:\n", i + 1);
        read_card(&hand[i]);
    }

    printf("\nHand: ");
    for (int i = 0; i < 5; i++) {
        printf("%d%c ", hand[i].value, hand[i].suit);
    }
    printf("\n");

    const char* hand_score = score_hand(hand);
    printf("Hand Score: %s\n", hand_score);

    return 0;
}
