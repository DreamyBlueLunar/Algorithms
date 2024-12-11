#ifndef STUDENT_H_
#define STUDENT_H_

#include "dcl_list.h"

// 声明student结构体，添加entries_成员，使其可以实现双向循环链表
typedef struct student {
    char id_[20];
    char name_[20];
    int grade_;
    int time_used_;
    DCL_LIST_ENTRY(student) entries_;
} student_t;

DCL_LIST_HEAD(dcl_list, student);
typedef struct dcl_list dcl_list_t;

#define S2L 0
#define L2S 1

typedef int(*compare)(student_t *, student_t *);

int cmp_s2l(student_t *i, student_t *j);
int cmp_l2s(student_t *i, student_t *j);
student_t *partition(student_t *low, student_t *high, int mode);
void quick_sort(student_t *low, student_t *high, int mode);

// 这个才是最后暴露出来的接口
void dcl_list_sort(dcl_list_t list, int mode);
#endif