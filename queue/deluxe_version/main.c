#include "student.h"
#include "dcl_list.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    char id[15], name[15];
    int grade, time_used;
    dcl_list_t list;
    DCL_LIST_INIT(list, student_t, entries_);
    student_t *new_node = NULL;
    FILE *fp = fopen("data.txt", "r"); // 感觉没有open函数好用，可惜windows系统没有这个系统调用（悲）
    if (NULL == fp) {
        perror("failed to open the file");
        exit(-1);
    }

    while (!feof(fp)) {
        fscanf(fp, "%s %s %d %d", id, name, &grade, &time_used);
        new_node = malloc(sizeof(student_t));
        memset(new_node->id_, '\0', sizeof(new_node->id_));
        memset(new_node->name_, '\0', sizeof(new_node->name_));
        memcpy(new_node->id_, id, sizeof(id));
        memcpy(new_node->name_, name, sizeof(id));
        new_node->grade_ = grade;
        new_node->time_used_ = time_used;
        DCL_LIST_INSERT_HEAD(list, student_t, new_node, entries_);
    }
    fclose(fp);


    printf("BEFORE SORTING:\n");
    student_t *cur = NULL;
    int idx = 1;
    DCL_LIST_FOREACH(cur, list, entries_) {
        printf("student#%4d: %8s, %10s, %3d, %3d\n", idx, cur->id_, cur->name_, cur->grade_, cur->time_used_);
        idx ++;
    }

    dcl_list_sort(list, L2S);

    printf("AFTER SORTING:\n");
    cur = NULL;
    idx = 1;
    DCL_LIST_FOREACH(cur, list, entries_) {
        printf("student#%4d: %8s, %10s, %3d, %3d\n", idx, cur->id_, cur->name_, cur->grade_, cur->time_used_);
        idx ++;
    }

    DCL_LIST_DESTROY(list, student_t, entries_);

    return 0;
}