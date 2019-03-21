#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int n;
    double s1, s2, s3;
    double avg= 0.0;
    printf("Enter scores: ");
    scanf("%d%lg%lg%lg", &n, &s1, &s2, &s3);
    if(s1<s2 && s1<s3) {
        avg = (s2+s3)/2;
        printf("%f",avg);
    }
    else if(s2<s1 && s2<s3) {
        avg = (s1+s3)/2;
        printf("%f", avg);
    }
    else {
        avg = (s1+s2)/2;
        printf("%f", avg);
    }

    return EXIT_SUCCESS;
}
