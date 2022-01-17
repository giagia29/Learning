#include <stdio.h>
void runtime_increment(int N);
void runtime_print(int N);
void runtime_print_long(int N, char* long_str);

int main(void){
 // call the functions here and record the time they take.
 int L = 1000, i;
 char str[L+1];
 for(i=0; i<L; i++){
 str[i] = 'A';
 }
 str[i] = '\0';
 //runtime_increment(1000);
 //runtime_print(300);
 runtime_print_long(1000, str);
}

/* void runtime_increment(int N){
int i, k, t, res = 0;
for(i = 1; i <= N; i=i+1)
    for(k = 1; k <= N; k++)
        for(t = 1; t <= N; t++)
            res = res + 1;
} */

/* void runtime_print(int N){
int i, k, t;
for(i = 1; i <= N; i=i+1)
    for(k = 1; k <= N; k++)
        for(t = 1; t <= N; t++)
            printf("A");
} */

void runtime_print_long(int N, char* long_str){
 int i, k, t;
 for(i = 1; i <= N; i=i+1)
 for(k = 1; k <= N; k++)
 for(t = 1; t <= N; t++)
 printf("%s\n", long_str);
}
