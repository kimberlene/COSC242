#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num;
    int winner = 0;
    double s1, s2, s3;
    double score = 0.0;
    double new_score = 0.0;

    while(4 == scanf("%d%lg%lg%lg", &num, &s1, &s2, &s3)) {
        new_score = (s1+s2+s3)/3;

        if(score < (s1+s2+s3)/3) {
            score = new_score;
            winner = num;
    }
    }
        printf("Winner of the competition is candidate: %d  score:  %f\n", winner,score);
        return EXIT_SUCCESS;
        
}
