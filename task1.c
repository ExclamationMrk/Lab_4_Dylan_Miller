#include <stdio.h>
#include <stdbool.h>

// struct
struct Plays {
    int safety;
    int fieldgoal;
    int touchdown;
    int touchdown_fieldgoal;
    int touchdown_2points;
};

// const just for clarity, instead of using magic numbers
const struct Plays play = {
    .safety = 2,
    .fieldgoal = 3,
    .touchdown = 6,
    .touchdown_fieldgoal = 7,
    .touchdown_2points = 8
};

// terrible function but this is how the problem is done. literally waterfalls through ALL possibilities.
void score_checker(int score) {
    for (int j = 0; j <= score / play.touchdown_2points; j++) {
        for (int i = 0; i <= score / play.touchdown_fieldgoal; i++) {
            for (int k = 0; k <= score / play.touchdown; k++) {
                for (int m = 0; m <= score / play.fieldgoal; m++) {
                    for (int n = 0; n <= score / play.safety; n++) {
                        if (j * play.touchdown_2points +
                            i * play.touchdown_fieldgoal +
                            k * play.touchdown +
                            m * play.fieldgoal +
                            n * play.safety == score) {
                            
                            printf("%d Touchdowns with 2pt conversions, %d Touchdowns with 1pt conversions, %d Touchdowns, %d 3pt Field Goals, %d Safeties\n", j, i, k, m, n);
                        }
                    }
                }
            }
        }
    }
}

int main(void) {
    int score;
    while (true) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        
        // 1. Check if user entered a valid integer
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter a valid number.\n\n");
            // Clear input buffer (equivalent to cin.ignore in C++)
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // 2. Stop condition: 0, 1, or negative numbers exit the program
        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        // 3. Valid score: find all combinations
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        score_checker(score);
        printf("\n");
    }

    return 0;
}
