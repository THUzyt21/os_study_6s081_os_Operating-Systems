#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char* argv[]){
    int p1[2],p2[2];
    pipe(p1);
    int prime;
    int n;
    int i = 2;
    for(; i <= 35; i++)
        write(p1[1], &i, sizeof(i));
    i = 0;
    write(p1[1], &i, sizeof(i)); //write in 0 to prevent jum
    i = 2;
    for(; i <= 35; ++i){
        pipe(p2);
        //father process
        read(p1[0], &prime, sizeof(prime));
        if(prime == 0){
            close(p1[0]);
            close(p2[0]);
            close(p1[1]);
            close(p2[1]);
            break;
        }
        printf(1,"prime: %d\n", prime);
        while (read(p1[0], &n, sizeof(n)) && n)
        {
            if(n % prime != 0)
                write(p2[1], &n, sizeof(n));
        }
        write(p2[1], &n, sizeof(n));
        if(fork() == 0){
            close(p1[0]);
            close(p1[1]);//delete pipe 1
            p1[0] = p2[0];
            p1[1] = p2[1]; //move pipe2 -> pipe1
            continue;
        }
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);
        close(p2[1]);
        break;
    }    
    wait();
    exit();
}