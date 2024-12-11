#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct student {
    char id[20];
    char name[20];
    int grade;
    int timeUsed;
    struct student *next;
    struct student *prev;
}ListNode;

// 初始化创建头结点
ListNode* ListInit();
// 动态申请一个结点
ListNode* BuyListNode(char *id, char *name, int grade, int time_used);
// 打印
void Listprint(ListNode* plist);
// 尾插
void ListPushBack(ListNode* plist, char *id, char *name, int grade, int time_used);
// 尾删
void ListPopBack(ListNode* plist);
// 头插
void ListPushFront(ListNode* plist, char *id, char *name, int grade, int time_used);
// 头删
void ListPopFront(ListNode* plist);
// 查找
ListNode* ListFind(ListNode* plist, char *id);
// 在pos前插入
void ListInsert(ListNode* pos, char *id, char *name, int grade, int time_used);
// 删除pos位置的结点
void ListErase(ListNode* pos);


// 快排相关的接口
void Swap(ListNode *p, ListNode *q);
int cmp(ListNode *i, ListNode *j);
ListNode *partition(ListNode *low, ListNode *high);
void quickSort(ListNode *low, ListNode *high);

void runTest(void);

int main(void) {
	runTest();
    return 0;
}

// 我写的测试用例，从文件里读取学生信息，然后排序打印。
// 学生信息由generate.py脚本生成，直接在对应目录终端执行命令：
//       $/ python generate.py
// 就可以执行，并生成信息。
// 你要是需要其他形式的测试用例，也可以自己去写。这个代码文件已经足够通俗易懂（烂）了
// 不过还是建议你去理解一下deluxe_version文件夹里的东西，对你技术提升帮助很大的
void runTest(void) {
	ListNode *list = ListInit();
	char id[15], name[15];
    int grade, timeUsed;

    FILE *fp = fopen("data.txt", "r"); // 感觉没有open函数好用，可惜windows系统没有这个系统调用（悲）
    if (NULL == fp) {
        perror("failed to open the file");
        exit(-1);
    }

    while (!feof(fp)) {
        fscanf(fp, "%s %s %d %d", id, name, &grade, &timeUsed);
		ListPushFront(list, id, name, grade, timeUsed);
    }
    fclose(fp);

	printf("BEFORE SORTING:\n");
	printf("               id          name     grade timeUsed\n");
	Listprint(list);

	quickSort(list, list);

	printf("AFTER SORTING:\n");
	printf("               id          name     grade timeUsed\n");
	Listprint(list);
}

// 初始化创建头结点
ListNode* ListInit() {
	ListNode* phead = BuyListNode("\0", "\0", 0, 0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

// 动态申请一个结点
ListNode* BuyListNode(char *id, char *name, int grade, int timeUsed) {
	ListNode* NewNode = malloc(sizeof(ListNode));
	if (NewNode == NULL) {
		printf("分配内存失败\n");
		exit(-1);
	}
	NewNode->prev = NewNode->next = NULL;
	memset(NewNode->id, '\0', sizeof(NewNode->id));
	memset(NewNode->name, '\0', sizeof(NewNode->name));
    memcpy(NewNode->id, id, sizeof(id));
    memcpy(NewNode->name, name, sizeof(name));
    NewNode->grade = grade;
    NewNode->timeUsed = timeUsed;
	return NewNode;
}

// 打印
void Listprint(ListNode* plist) {
	assert(plist);
    int idx = 1;
	ListNode* cur = plist->next;
	while (cur != plist) {
        printf("student#%4d: %8s, %10s, %3d, %3d\n", idx, cur->id, cur->name, cur->grade, cur->timeUsed);
		cur = cur->next;
        idx ++;
	}
	printf("\n");
}

// 尾插
void ListPushBack(ListNode* plist, char *id, char *name, int grade, int timeUsed) {
	assert(plist);
	ListNode* NewNode = BuyListNode(id, name, grade, timeUsed);
	ListNode* tail = plist->prev;
	tail->next = NewNode;
	NewNode->prev = tail;
	plist->prev = NewNode;
	NewNode->next = plist;
}

// 尾删
void ListPopBack(ListNode* plist) {
	assert(plist);
	assert(plist->next != plist);
	ListNode* tail = plist->prev;
	ListNode* tail_prev = tail->prev;
	tail_prev->next = plist;
	plist->prev = tail_prev;
	free(tail);
	tail = NULL;
}

// 头插
void ListPushFront(ListNode* plist, char *id, char *name, int grade, int timeUsed) {
	assert(plist);
	ListNode* NewNode = BuyListNode(id, name, grade, timeUsed);
	ListNode* first = plist->next;
	plist->next = NewNode;
	NewNode->prev = plist;
	NewNode->next = first;
	first->prev = NewNode;
}

// 头删
void ListPopFront(ListNode* plist) {
	assert(plist);
	assert(plist->next != plist);
	ListNode* first = plist->next;
	ListNode* second = first->next;
	plist->next = second;
	second->prev = plist;
	free(first);
	first = NULL;
}

// 查找
ListNode* ListFind(ListNode* plist, char *id) {
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist) {
		if (memcmp(id, cur->id, sizeof(id)))
			return cur;
		cur = cur->next;
	}
	return NULL;
}

// 在pos位置前插入
void ListInsert(ListNode* pos, char *id, char *name, int grade, int timeUsed) {
	assert(pos);
	ListNode* NewNode = BuyListNode(id, name, grade, timeUsed);
	ListNode* PosPrev = pos->prev;
	PosPrev->next = NewNode;
	NewNode->prev = PosPrev;
	NewNode->next = pos;
	pos->prev = NewNode;
}

void ListInsertNode(ListNode* pos, ListNode* NewNode) {
	assert(pos);
	ListNode* PosPrev = pos->prev;
	PosPrev->next = NewNode;
	NewNode->prev = PosPrev;
	NewNode->next = pos;
	pos->prev = NewNode;
}

// 删除pos位置的结点
void ListErase(ListNode* pos) {
	assert(pos);
	ListNode* PosPrev = pos->prev;
	ListNode* PosNext = pos->next;
	PosPrev->next = PosNext;
	PosNext->prev = PosPrev;
	free(pos);
	pos = NULL;
}


//交换两节点，p, q互换
void Swap(ListNode *elm_1, ListNode *elm_2) {
 	ListNode *elm_1_prev = elm_1->prev;
    ListNode *elm_2_prev = elm_2->prev;             
    ListNode *elm_1_next = elm_1->next;             
    ListNode *elm_2_next = elm_2->next;             
    if (elm_1->next == elm_2) {               
        elm_1_prev->next = elm_2;             
        elm_2->prev = elm_1_prev;             
        elm_2->next = elm_1;                  
        elm_1->prev = elm_2;                  
        elm_1->next = elm_2_next;             
        elm_2_next->prev = elm_1;             
    } else if (elm_2->next == elm_1) {        
        elm_2_prev->next = elm_1;             
        elm_1->prev = elm_2_prev;             
        elm_1->next = elm_2;                  
        elm_2->prev = elm_1;                  
        elm_2->next = elm_1_next;             
        elm_1_next->prev = elm_2;  
	} else {
        elm_1_prev->next = elm_2;             
        elm_2->prev = elm_1_prev;             
        elm_2->next = elm_1_next;             
        elm_1_next->prev = elm_2;             
        elm_2_prev->next = elm_1;             
        elm_1->prev = elm_2_prev;             
        elm_1->next = elm_2_next;             
        elm_2_next->prev = elm_1;             
    }
}

int cmp(ListNode *i, ListNode *j) {
    if (i->grade == j->grade) {
        return i->timeUsed - j->timeUsed;
    }
    return j->grade - i->grade;
}

/*
 * 这个partition方法我都忘了是在哪本书上看见的了，好像是算法导论？
 * @param: low 是分界区间的下界
 * @param: high 是分界区间的上界
 * @return: 返回放到正确位置上的那个节点
 */
ListNode *partition(ListNode *low, ListNode *high) {
    ListNode *p, *q, *tmp;
 
    p = low->next;  //这里head可以理解为本次待划分的链表的头结点
    q = high->prev; //这里tail是链表的最后一个节点的后面，可以理解为NULL

    //区间长度等于零时结束
    //特别说明，内层循环中判断条件中，有且仅有一个内层循环要加“<=”号，二选一
    //内层循环只能是两个，如果是一个的话，会出错，举例：12 34 78 56 23 99 34 12 45 76
    while(p != q) {
        //从后面开始往前遍历，直到p==q或者p->data大于等于q->data
        while(p != q && cmp(p, q) < 0) {
            q = q->prev;
        }
 
        if(p == q) {  //如果p->data 都小于q->data，表示已经排好
            break;
        }
 
        tmp = p->prev;    //交换前先保留p->prev，用来复位p 和 q
        Swap(p, q);       //交换p和q
        q = p;            //q复位
        p = tmp->next;    //p复位
 
        //从前面开始往后遍历，直到p==q或者p->data大于q->data
        while(p != q && cmp(p, q) <= 0) {
            p = p->next;
        }
 
        if(p == q) {  //如果p->data 都小于q->data，表示已经排好
            break;
        }
 
        tmp = p->prev;    //交换前先保留p->prev，用来复位p 和 q
        Swap(p, q);       //交换p和q
        q = p;            //q复位
        p = tmp->next;    //p复位
    }
 
    return p;
}
 
/*
 * 快速排序
 * @param: low 是分界区间的下界
 * @param: high 是分界区间的上界
 */
void quickSort(ListNode *low, ListNode *high) {
    //头结点是空的或者表是空的或者表只有一个节点时候不用排
    //tail是链表的结束点，一开始等于head,后面等于basic
    if(!low || low->next == high
        || low->next->next == high) {
        return;
    }
    //baisc前的节点都比basic小，baisc后的节点都比baisc大
    ListNode *basic = partition(low, high);
 
    quickSort(low, basic); //把head->next到basic前一个进行递归排序
    quickSort(basic, high); //从basic->next到tail前一个进行递归排序
}