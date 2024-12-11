#include "dcl_list.h"
#include "student.h"

// 由于规定排序方式的两个宏正好被设置成 0 和 1
// 那不妨直接用这两个宏当作下标选取对应的比较函数
// cmp[S2L]就是从小到大排序，cmp[L2S]就是从大到小排序
compare cmp[2];

/*
 * 比较两个学生的优先级，按照规则，先比较成绩，再比较用时。
 * 如果 i 优先级高于 j，返回正数；
 * 如果 j 优先级高于 i，返回负数；
 * 如果二者优先级相同，返回 0；
 */
int cmp_s2l(student_t *i, student_t *j) {
    if (i->grade_ == j->grade_) {
        return j->time_used_ - i->time_used_;
    }
    return i->grade_ - j->grade_;
}

int cmp_l2s(student_t *i, student_t *j) {
    if (i->grade_ == j->grade_) {
        return i->time_used_ - j->time_used_;
    }
    return j->grade_ - i->grade_;
}

/*
 * 这个partition方法我都忘了是在哪本书上看见的了，好像是算法导论？
 * @param: low 是分界区间的下界
 * @param: high 是分界区间的上界
 * @return: 返回放到正确位置上的那个节点
 */
student_t *partition(student_t *low, student_t *high, int mode) {
    student_t *p, *q, *tmp;
 
    p = DCL_LIST_NEXT((low), entries_);  //这里head可以理解为本次待划分的链表的头结点
    q = DCL_LIST_PREV((high), entries_); //这里tail是链表的最后一个节点的后面，可以理解为NULL
 
    //区间长度等于零时结束
    //特别说明，内层循环中判断条件中，有且仅有一个内层循环要加“<=”号，二选一
    //内层循环只能是两个，如果是一个的话，会出错，举例：12 34 78 56 23 99 34 12 45 76
    while(p != q) {
        //从后面开始往前遍历，直到p==q或者p->data大于等于q->data
        while(p != q && cmp[mode](p, q) < 0) {
            q = DCL_LIST_PREV((q), entries_); 
        }
 
        if(p == q) {  //如果p->data 都小于q->data，表示已经排好
            break;
        }
 
        tmp = DCL_LIST_PREV((p), entries_);                     //交换前先保留p->prev，用来复位p 和 q
        DCL_LIST_SWAP_ENTRIES(p, q, student_t, entries_);       //交换p和q
        q = p;                                                  //q复位
        p = DCL_LIST_NEXT((tmp), entries_);                     //p复位
 
        //从前面开始往后遍历，直到p==q或者p->data大于q->data
        while(p != q && cmp[mode](p, q) <= 0) {
            p = DCL_LIST_NEXT((p), entries_);
        }
 
        if(p == q) {  //如果p->data 都小于q->data，表示已经排好
            break;
        }
 
        tmp = DCL_LIST_PREV((p), entries_);                     //交换前先保留p->prev，用来复位p 和 q
        DCL_LIST_SWAP_ENTRIES(p, q, student_t, entries_);       //交换p和q
        q = p;                                                  //q复位
        p = DCL_LIST_NEXT((tmp), entries_);                     //p复位
    }
 
    return p;
}
 
/*
 * 快速排序
 * @param: low 是分界区间的下界
 * @param: high 是分界区间的上界
 */
void quick_sort(student_t *low, student_t *high, int mode) {
    //头结点是空的或者表是空的或者表只有一个节点时候不用排
    //tail是链表的结束点，一开始等于head,后面等于basic
    if(!low || DCL_LIST_NEXT((low), entries_) == high
        || DCL_LIST_NEXT(DCL_LIST_NEXT((low), entries_), entries_) == high) {
        return;
    }
    //baisc前的节点都比basic小，baisc后的节点都比baisc大
    student_t *basic = partition(low, high, mode);
 
    quick_sort(low, basic, mode); //把head->next到basic前一个进行递归排序
    quick_sort(basic, high, mode); //从basic->next到tail前一个进行递归排序
}

/*
 * 对双向循环链表进行排序的接口，只需要传入list对象，就可以完成排序功能
 * @param: list 是双向循环链表对象
 */
void dcl_list_sort(dcl_list_t list, int mode) {
    cmp[S2L] = cmp_s2l;
    cmp[L2S] = cmp_l2s;
    quick_sort(DCL_LIST_FIRST(list), DCL_LIST_FIRST(list), mode);
}