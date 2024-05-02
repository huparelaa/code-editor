#include "compress.h"
#include "decompress.h"
#include <cstring>

//cpp

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s [compress|decompress] [file]\n", argv[0]);
        return 1;
    }


    if (strcmp(argv[1], "compress") == 0)
    {
        compress(argv[2]);
    }
    else if (strcmp(argv[1], "decompress") == 0)
    {
        decompress(argv[2]);
    }
    else
    {
        printf("Usage: %s [compress|decompress] [file]\n", argv[0]);
        return 1;
    }

    return 0;
}