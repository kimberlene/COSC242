#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10

int main(void) {
    double judge1[ARRAY_SIZE];
    double judge2[ARRAY_SIZE];
    double judge3[ARRAY_SIZE];
    double dist1=0.0, dist2=0.0, dist3=0.0;
    int num = 0;
    int candidate = 0;
    double s1, s2, s3;
    double sum1=0.0, sum2=0.0, sum3=0.0;
    int i = 0;
    int j = 0;
    double sd1=0.0, sd2=0.0, sd3=0.0;
    double m1=0.0, m2=0.0, m3=0.0;
    double dfa1=0.0, dfa2= 0.0, dfa3=0.0;

    while(4 == scanf("%d%lg%lg%lg", &candidate, &s1, &s2, &s3)) {
        judge1[num] = s1;
        judge2[num] = s2;
        judge3[num] = s3;
        num = num + 1;
    }

    for( i=0; i<num; i++) {
        sum1+=judge1[i];
        sum2+=judge2[i];
        sum3+=judge3[i];
    }

    for(j=0; j<num; j++) {
        dist1+=pow((judge1[i]-(sum1/(num+1))),2);
        dist2+=pow((judge2[i]-(sum2/(num+1))),2);
        dist3+=pow((judge3[i]-(sum3/(num+1))),2);
    }


    m1 = sum1/(num+1);
    m2 = sum2/(num+1);
    m3 = sum3/(num+1);
    dfa1 = (dist1/num);
    dfa2 = (dist2/num);
    dfa3 = (dist3/num);
    sd1 = sqrt(dfa1);
    sd2 = sqrt(dfa2);
    sd3 = sqrt(dfa3);
    printf("       Average SD\n");
    printf("judge1: %3.2f %3.2f\n",(sum1/num+1) , sqrt(dist1/num);
    printf("judge2: %3.2f %3.2f\n", m2, sd2);
    printf("judge3: %3.2f %3.2f\n", m3, sd3);

    return EXIT_SUCCESS;
}
