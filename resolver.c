#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    if (argc<=1) {
        printf("[+] Example dns resolver in C [+]\n Use: ./resolver www.example.com\n");
        return 0;
    } else {
        struct hostent *target = gethostbyname(argv[1]);
        if (target==NULL) {
            printf("An error occurred :(\nUse: ./resolver www.example.com\n");
        } else {
            printf("\nHost: %s\n", inet_ntoa(*((struct in_addr *)target->h_addr)));
        }
    }
}
