#include "../src/filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_read_and_check();

int main(int argc, char **argv)
{
    if (test_read_and_check() < 0) {
        printf("read_and_check() unit test failed\n");

        return -1;
    }
    printf("all tests succeed\n");

    return 0;
}

int test_read_and_check()
{
    struct grep_res *list_first, *list_second;
    struct grep_res *res1_list = (struct grep_res *)malloc(sizeof(struct grep_res));
    res1_list->next = (struct grep_res *)malloc(sizeof(struct grep_res));
    list_first = res1_list;
    list_first->res = "this is a book.\n";
    list_second = res1_list->next;
    list_second->res = "here is an apple.\n";
    
    struct grep_res *res1 = read_and_check("test_file.dat", "* is*");
    struct grep_res *res_cur = res1_list, *test_cur = res1;
    for(;test_cur!=NULL&&res_cur!=NULL; test_cur=test_cur->next, res_cur=res_cur->next) {
        if (strncmp(test_cur->res, res_cur->res, strlen(test_cur->res)) != 0) {
            printf("unit test error, need to be %s, but result is: %s\n", test_cur->res, res_cur->res);
            return -1;
        }
    }
    if (test_cur!=NULL || res_cur!=NULL) {
        printf("unit test result amount not equal\n");
        return -1;
    }

    printf("read_and_check() unit test succeed\n");
    
    return 0;
}