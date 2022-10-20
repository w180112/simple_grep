#ifndef _FILTER_H_
#define _FILTER_H_

struct grep_res {
    char *res;
    struct grep_res *next;
};

struct grep_res *read_and_check(const char *filename, char *grep_str);

#endif
