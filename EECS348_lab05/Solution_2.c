#include <stdio.h>

void FindComb(int score) {
    int td, fg, safety;
    for (td = 0; td <= score/6; td++) {
        for (fg = 0; fg <= score/3; fg++) {
            for (safety = 0; safety <= score/2; safety++) {
                if (td*6 + fg*3 + safety*2 == score) {
                    printf("%d TD, %d FG, %d Safety\n", td, fg, safety);
                }
            }
        }
    }
}

int main() {
    int score;
    while (1) {
        printf("Enter the NFL score (o to 1 to STOP): ");
        int result = scanf("%d", &score);
        if  (result !=1 || score < 0) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;

        }
        if (score <= 1) break;
        FindComb(score);
    }

    return 0;
}
