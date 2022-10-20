#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "filter.h"

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("not enough argument\n ./grep <file_name> <grep string>\n");
        return -1;
    }

    struct grep_res *grep_res_list = read_and_check(argv[1], argv[2]);
    for(struct grep_res * cur=grep_res_list; cur!=NULL; cur=cur->next) {
        printf("line found: %s", cur->res);
    }
    
    
    return 0;
}
