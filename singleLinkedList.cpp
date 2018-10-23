#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;  //element type(“元素的类型”)

typedef struct node/*单链表结构体的定义*/
{
	elemtype data;
	struct node *next;
}
node, *linklist;



void main_menu();/*主菜单函数*/
node* creatfromhead();/*从头结点插入建立单链表*/
linklist LinkedListCreatH();/*从头结点插入建立单链表 method 2*/
linklist LinkedListCreatT();/*从尾结点插入建立单链表 method 2*/
node* get(linklist l);/*单链表的遍历*/
node* reverselist(linklist l);/*将带头结点的单链表逆置*/
node* creatfeidijian();/*头插法建立非递减单链表*/
node* combine(linklist la, linklist lb);/*将两个非递减链表合成一个非递减连表*/
node* inslist(linklist l, elemtype e);/*在非递减有序链表中插入一个元素使链表仍然有序*/
node* deletelist(linklist l, elemtype x);/*在非递减单链表中删除值为x的结点*/
int getLength(linklist l);
int getValueOfIndex(node *head,int index);
int getNodeIndex(node *head, int data);
node* insert(node *head, int num);
node *sort(node *head);


int main()/*主函数*/
{
	main_menu();
	return 0;
}



void main_menu()/*主菜单函数*/
{
	int input;
	printf("\t\t\t单链表的建立及其简单操作\t\t\n\n");
	printf("\t\t 1 从头结点插入建立单链表\n");
	printf("\t\t 2 单链表的遍历\n");
	printf("\t\t 3 将带头结点的单链表逆置\n");
	printf("\t\t 4 头插法建立非递减单链表\n");
	printf("\t\t 5 将两个非递减链表合成一个非递减连表\n");
	printf("\t\t 6 在非递减有序链表中插入一个元素使链表仍然有序\n");
	printf("\t\t 7 在非递减单链表中删除值为x的结点\n");
	printf("\t\t 8 测量单链表的长度\n");
	printf("\t\t 9  查询指定索引的节点值或指定节点值的索引\n");
	printf("\t\t 10 sort\n");
	printf("\t\t 0 退出\n");
	printf("\t\t注意事项：初始化单链表的时候以“0”结束初始化！！！！\n");
	printf("请输入需要操作的项目序号：");
	scanf("%d", &input);
	switch (input)
	{
	case 1: {
		node* head;
		printf("请输入一个单链表用“0”来结束输入：");
		head = LinkedListCreatH();
		printf("初始化后的单链表为：");
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 2: {
		node* head;
		printf("请首先输入一个单链表用“0”来结束输入：");
		head = creatfromhead();
		printf("单链表的遍历结果为：");
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 3: {
		node* head;
		printf("请输入需要逆置的单链表：");
		head = creatfromhead();
		printf("初始化后的单链表为：");
		get(head);
		printf("单链表的逆置结果为：");
		head = reverselist(head);
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 4: {
		node* head;
		printf("请输入一个非递减单链表序列：");
		head = creatfromhead();
		printf("初始化后的单链表为：");
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 5: {
		node* la, *lb, *head;
		printf("请输入非递减的单链表la：");
		la = creatfromhead();
		printf("单链表la为：");
		get(la);
		printf("请输入非递减的单链表lb：");
		lb = creatfromhead();
		printf("单链表lb为：");
		get(lb);
		head = combine(la, lb);
		printf("合并之后的新的单链表为：");
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 6: {
		node* head;elemtype e;
		printf("请输入一个非递减单链表序列：");
		head = creatfromhead();
		printf("初始化后的单链表为：");
		get(head);
		printf("请输入一个需要插入的元素：");
		scanf("%d", &e);
		head = insert(head, e);
		printf("插入之后的单链表为：");
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 7: {
		node* head;
		elemtype e;
		printf("请输入一个非递减单链表序列：");
		head = creatfromhead();
		printf("初始化后的单链表为：");
		get(head);
		printf("请输入一个需要删除的元素：");
		scanf("%d", &e);
		head = deletelist(head, e);
		printf("删除之后的单链表为：");
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 8: {
		node* head;
		elemtype e;
		int len;
		printf("请输入一个单链表序列：");
		head = creatfromhead();
		printf("初始化后的单链表为：");
		get(head);
		printf("这个单链表的长度为：");
		len = getLength(head);		
		printf("%d\n",len);
		printf("Before getLength1:head:%p\n", head);
		main_menu();
		break;
	}
	case 9: {
		node* head;
		elemtype e;
		elemtype data;
		int index;
		printf("请输入一个单链表序列：");
		head = creatfromhead();
		printf("初始化后的单链表为：");
		get(head);
		printf("请输入一个需要查询节点值的索引：");
		scanf("%d", &e);
		data = getValueOfIndex(head, e);
		printf("该索引的节点值为：%d\n",data);
		printf("请输入一个需要查询索引的节点值：");
		scanf("%d", &e);
		index = getNodeIndex(head, e);
		printf("该索引的节点值为：%d\n", index);
		printf("\n\n");
		main_menu();
		break;
	}
	case 10: {
		node* head;
		printf("请首先输入一个单链表用“0”来结束输入：");
		head = creatfromhead();
		printf("单链表的排序历结果为：");
		head = sort(head);
		get(head);
		printf("\n\n");
		main_menu();
		break;
	}
	case 0:
	{
		exit(0);break;
	}
	}
}



node* creatfromhead()/*头插法建立单链表*/
{
	linklist l;
	node *s;
	int c;
	int flag = 1;
	l = (node*)malloc(sizeof(node));
	if (l == NULL)
	{
		printf("申请空间失败！！");
		return 0;
	}
	l->next = NULL;
	while (flag)
	{
		scanf("%d", &c);
		if (c != 0)
		{
			s = (node*)malloc(sizeof(node));
			if (s == NULL)
			{
				printf("申请空间失败！！");
				return 0;
			}
			s->data = c;
			s->next = l->next;
			l->next = s;
		}
		else flag = 0;
	}
	return l;
}

//单链表的建立1，头插法建立单链表

linklist LinkedListCreatH()
{
	node *L;
	L = (node *)malloc(sizeof(node));   //申请头结点空间
	L->next = NULL;                      //初始化一个空链表

	elemtype x;                         //x为链表数据域中的数据
	while (scanf("%d", &x) != EOF)
	{
		node *p;
		p = (node *)malloc(sizeof(node));   //申请新的结点 
		p->data = x;                     //结点数据域赋值 
		p->next = L->next;                    //将结点插入到表头L-->|2|-->|1|-->NULL 
		L->next = p;
	}
	return L;
}

//单链表的建立2，尾插法建立单链表

linklist LinkedListCreatT()
{
	node *L;
	L = (node *)malloc(sizeof(node));   //申请头结点空间
	L->next = NULL;

	node *r;
	r = L;                          //r始终指向终端结点，开始时指向头结点。此时的头结点是终端结点 
	elemtype x;                         //x为链表数据域中的数据
	while (scanf("%d", &x) != EOF)
	{
		node *p;                    //p用来指向新生成的节点
		p = (node *)malloc(sizeof(node));   //申请新的结点 
		p->data = x;                     //用新节点的数据域来接受x 
		r->next = p;                 //用r来接纳新节点,将结点插入到表头L-->|1|-->|2|-->NULL 
		r = p;                      //r指向终端节点 
	}
	r->next = NULL;                //元素已经全部装入链表L中 L的终端节点指针域为NULL，L建立完成

	return L;
}



node* get(linklist l)/*单链表的遍历*/
{
	node *p;
	p = l->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return l;
}




node* reverselist(linklist l)/*将带头结点的单链表逆置*/
{
	node *q, *p;
	p = l->next;
	l->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = l->next;
		l->next = p;
		p = q;
	}
	return l;
}




node* creatfeidijian()/*头插法建立非递减单链表*/
{
	linklist l;
	node *s;
	int c;
	int flag = 1;
	printf("%s", "请输入一个非递减数列！！");
	l = (node*)malloc(sizeof(node));
	if (l == NULL)
	{
		printf("申请空间失败！！");
		return 0;
	}
	l->next = NULL;
	while (flag)
	{
		scanf("%d", &c);
		if (c != 0)
		{
			s = (node*)malloc(sizeof(node));
			if (s == NULL)
			{
				printf("申请空间失败！！");
				return 0;
			}
			s->data = c;
			s->next = l->next;
			l->next = s;
		}
		else flag = 0;
	}
	return l;
}



node* combine(linklist la, linklist lb)
/*将两个非递减链表合成一个非递减连表*/
{
	node *pa, *pb, *r;
	linklist lc;
	pa = la->next;
	pb = lb->next;
	lc = la;
	lc->next = NULL;r = lc;
	while (pa != NULL&&pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			r->next = pa;r = pa;pa = pa->next;
		}
		else
		{
			r->next = pb;r = pb;pb = pb->next;
		}
	}
	if (pa)
		r->next = pa;
	else
		r->next = pb;
	free(lb);
	return(lc);
}



node *inslist(linklist l, elemtype e)
/*在非递减有序链表中插入一个元素使链表仍然有序*/
{
	node *s, *p;
	p = l;
	while (l != NULL)
	{
		if (e >= l->data&&e <= l->next->data)
		{
			s = (node*)malloc(sizeof(node));
			s->data = e;
			s->next = l->next;
			l->next = s;
			break;
		}
		else
			l = l->next;
	}
	return p;
}
node * deletelist(linklist l, elemtype x)
/*在非递减单链表中删除值为x的结点*/
{
	node *p, *r, *q;
	p = l->next;q = l;
	while (p != NULL)
	{
		if (p->data == x)
		{
			r = p;
			p = r->next;
			q->next = p;
			free(r);
			break;
		}
		else
		{
			q = p;/*保留前驱节点*/
			p = p->next;
		}
	}
	if (p == NULL)
		printf("删除失败，没有找到相应的元素\n");
	return l;
}

int getLength(node *head) {

	int len = 0;
	/*node *p;         //新不新建指针都可以，不会影响主调函数的实参变量的值
	p = head;
	while (p != NULL) {
		p = p->next;
		len++;
	}*/
	while (head != NULL) {   
		head = head->next;
		len++;
	}
	return (len);
}



/** 获取指定角标的节点值 */
int getValueOfIndex(node *head, int index){

	if (index < 0 || index >= getLength(head)) {
		throw "角标越界！";
	}

	if (head == NULL) {
		throw "当前链表为空！";
	}

	node *dummyHead = head;

	while (dummyHead->next != NULL && index > 0) {
		dummyHead = dummyHead->next;
		index--;
	}

	return dummyHead->data;
}


/** 获取节点值等于 value 的第一个元素角标 */
int getNodeIndex(node *head, int data) {

	int index = -1;
	node *dummyHead = head;

	while (dummyHead != NULL) {
		index++;
		if (dummyHead->data == data) {
			return index;
		}
		dummyHead = dummyHead->next;
	}

	return -1;
}

node* insert(node *head, int num) {
	node *p0, *p1, *p2;
	p1 = head;
	p2 = NULL;
	p0 = (node *)malloc(sizeof(node));
	p0->data = num;
	while (p0->data > p1->data&&p1->next != NULL) {
		p2 = p1;p1 = p1->next;
	}
	if (p0->data <= p1->data) {
		if (head == p1) {
			p0->next = p1;
			head = p0;
		}
		else {
			p2->next = p0;
			p0->next = p1;
		}
	}
	else {
		p1->next = p0;
		p0->next = NULL;
	}
	return (head);
}

node *sort(node *head) {
	node *p, *p2, *p3;
	int n;int temp;
	n = getLength(head);
	if (head == NULL || head->next == NULL)
		return head;
	p = head;
	for (int j = 1;j < n;++j) {
		p = head;
		for (int i = 0;i < n - j;++i) {
			if (p->data > p->next->data) {
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
	return head;
}
