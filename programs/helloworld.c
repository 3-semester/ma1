
#include <stdio.h>




int main(int argc, char const *argv[])
{

    if((sizeof(argv) / sizeof((argv)[0])) > 0 && argv[1] != NULL){
    printf("Hello %s!", argv[1]);
    }else
    {
    printf("Hello World!");
    }
    




    return 0;
}
