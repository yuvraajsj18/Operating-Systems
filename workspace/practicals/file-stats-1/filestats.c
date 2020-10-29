#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    struct stat buf;

    if (argc != 2)
    {
        printf("Error: Format is ./filestat filename\n");
        exit(1);
    }

    stat(argv[1], &buf);

    printf("File name is %s\n", argv[1]);
    printf("Owner id: %d\n", buf.st_uid);

    if (S_ISREG(buf.st_mode))
        printf("%s is a regular file\n", argv[1]);
    else 
        printf("%s is a directory\n", argv[1]);

    if (buf.st_mode & 0400)
        printf("Owner has read permission\n");
    else
        printf("Owner does not has read permission\n");

    if (buf.st_mode & 0200)
        printf("Owner has write permission\n");
    else
        printf("Owner does not has write permission\n");

    if (buf.st_mode & 0100)
        printf("Owner has execute permission\n");
    else
        printf("Owner does not has execute permission\n");

    
    if (buf.st_mode & 0040)
        printf("Group has read permission\n");
    else
        printf("Group does not has read permission\n");

    if (buf.st_mode & 0020)
        printf("Group has write permission\n");
    else
        printf("Group does not has write permission\n");

    if (buf.st_mode & 0010)
        printf("Group has execute permission\n");
    else
        printf("Group does not has execute permission\n");

    
    if (buf.st_mode & 0004)
        printf("Other has read permission\n");
    else
        printf("Other does not has read permission\n");

    if (buf.st_mode & 0002)
        printf("Other has write permission\n");
    else
        printf("Other does not has write permission\n");

    if (buf.st_mode & 0001)
        printf("Other has execute permission\n");
    else
        printf("Other does not has execute permission\n");
}

/* OUTPUT:
File name is file
Owner id: 1000
file is a regular file
Owner has read permission
Owner has write permission
Owner does not has execute permission
Group has read permission
Group does not has write permission
Group does not has execute permission
Other has read permission
Other does not has write permission
Other does not has execute permission

** ls -l
-rw-r--r-- 1 codespace codespace     0 Oct 29 03:35 file

*/