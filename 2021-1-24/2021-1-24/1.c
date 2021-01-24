# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>
// 指针笔试题

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;
}
//结果是2,5   &a是数组地址+1跳到下一个数组的地址（可以理解位数组指针）
//所以要强制类型转换成int*指针

//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;   //p是一个结构体指针  指针的大小只是4B
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
int main()
{
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	return 0;
}

//  解：第一个打印是0x00100014;
//      第二个unsigned long的大小是4B,把p转换成无符号长整形，加1就是加1，变成0x00100001；
//      第三个打印的是0x00100004;
笔试题3
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}

//解：ptr1表示的a数组后面的那一个数组的指针（是数组指针）
//所以ptr1[-1]是4,0x00000004,ptr1[-1]==*(ptr1+(-1)),就是ptr1回跳一个整形再解引用
//*ptr2 是0x00000002  做错了！！！

//解析：a[4]按小端存储的结果是 01000000 02000000 03000000 04000000
//把a（首地址）转换成int形再加1，就相当于后移动了一个字节，再转换成int*
//就是00000002内存中的存法————》实际打印出来是02000000

笔试题4
#include <stdio.h>
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int* p;
	p = a[0];
	printf("%d", p[0]);
	return 0;
}
//  陷阱！！！！！！！！！！！！大括号里面是逗号表达式！！！！！！
//（0,1）运算结果是1，所以值初始化了三个，1,3,4。
//解：p是第一行的地址，结果是1；
//p[0]==*(p+0) 所以就是第一个元素

笔试题5
int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}

// 解析见笔记本
笔试题6
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//解：
// &aa取到的是二维数组的地址，加1就跳过了整个数组指向下一个二维数组的
//起始位置，所以&aa+1是二维数组指针，强制类型转换成int（*）得到ptr1
//  第一个得到10
//aa是数组名，就是首元素（第一行）的地址，aa加1就是第二行的地址，
//*（aa+1）就是得到的是第二行的数组名，就是相当于aa[1],而aa[1]就是表示的
//第二行的首元素地址，再强制类型转化得到ptr2，
//第二个得到的是5

笔试题7
#include <stdio.h>
int main()
{
	char* a[] = { "work","at","alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa);
	return 0;
}
//解：
//			        a
//  char**(pa)--->char*--->"work"
//   pa++-------> char*--->"at"
//                char*--->"alibaba"
//a是数组，数组类型是字符指针，包含三个元素，第一个是"work"（w）的首地址，依次类推
//a 是数组名，表示首元素地址，也就是指向"work"的指针的地址，赋给pa
// char**p==char*(*P)   意思是p是指针  类型是char*
//pa++ 就是pa跳过一个char*类型的字节，指向"at"指针的地址
// *pa就是拿出"at"的地址   然后打印就是打印的是at
//

笔试题8

int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
} 

//解析在笔记本上
