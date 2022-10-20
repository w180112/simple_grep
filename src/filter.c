#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <common.h>
#include "filter.h"

BOOL check_exist(char *line, size_t len, char *check_str);
void res_append(struct grep_res **head, char *res_str);

struct grep_res *read_and_check(const char *filename, char *grep_str) {
    FILE *fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    struct grep_res *res_list = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("can't open input file");
        return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (check_exist(line, len, grep_str) == TRUE) {
            res_append(&res_list, line);
        }
    }

    fclose(fp);
    if (line)
        free(line);

    return res_list;
}

BOOL check_exist(char *line, size_t len, char *check_str)
{
    for(int i=0; i<len; i++) {
        BOOL is_grepped = TRUE;
        for(int j=0; j<strlen(check_str); j++) {
            if (check_str[j] != '*' && check_str[j] != line[i+j]) {
                is_grepped = FALSE;
                break;
            }
        }
        if (is_grepped == TRUE)
            return TRUE;
    }

    return FALSE;
}

void res_append(struct grep_res **head, char *res_str)
{
    struct grep_res **indirect = head;

    struct grep_res *new = malloc(sizeof(struct grep_res));
    new->res = (char *)malloc(strlen(res_str)+1);
    strcpy(new->res, res_str);
    new->next = NULL;
    
    while (*indirect)
        indirect = &((*indirect)->next);
        
    *indirect = new;
}