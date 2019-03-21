#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int n;
    double winner=0.0;
    int win_num=0;
    double s1, s2, s3;
    double avg= 0.0;
    while(4==scanf("%d%lg%lg%lg",&n,&s1,&s2,&s3)){
    if(s1<s2 && s1<s3) {
        avg = (s2+s3)/2;
    }
    else if(s2<s1 && s2<s3) {
        avg = (s1+s3)/2;
    }
    else {
        avg = (s1+s2)/2;
    }
    if(avg>winner) {
        winner = avg;
        win_num = n;
    }
    }
    printf("%d\n",win_num);

    return EXIT_SUCCESS;
}
