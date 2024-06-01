#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	printf("*********************************          *                              *       \n");
	printf("              *                            *                              *       \n");
	printf("              *                            *                              *       \n");
	printf("              *                            *                             *        \n");
	printf("              *                            *                             *        \n");
	printf("              *                             *                            *        \n");
	printf("              *                              *                          *         \n");
	printf("              *                              *                          *         \n");
	printf("              *                              *                         *          \n");
	printf("              *                              *                         *          \n");
	printf("              *                               *                        *          \n");
	printf("              *                               *                       *           \n");
	printf("              *                               *                      *            \n");
	printf("              *                              *                     *              \n");
	printf("              *                               *                    *              \n");
	printf("              *                                *                  *               \n");
	printf("              *                                 *                *                \n");
	printf("              *                                  *               *                \n");
	printf("              *                                   *            *                  \n");
	printf("              *                                     *          *                  \n");
	printf("              *                                      *       *                    \n");
	printf(" *********************************                     * ** *                     \n");
	int z,i=0;

        while(i<3){                     //用while迴圈且設定迴圈執行小於3次 
    	    printf("輸入4個數字的密碼:");
            scanf("%d",&z);
        if(z==2024){                    //若輸入的數字等於2024 
    	printf("歡迎\n");         //則進入步驟二 
    	system("pause");                // 螢幕畫面暫停，並等待使用者按任意鍵
    	system("CLS");                  // 清除螢幕
		break;}
		else {
		i++;}}
    	if(i==3&&z!=2024){              //如果答錯次數等於3次且數字不等於2024 
    	printf("警告");                 //則出現警告 
        return 0;}
printf("------------------------------\n");
printf("|a. Enter student grades     |\n");
printf("|b.Display student grades    |\n");
printf("|c.Search for student grades |\n");
printf("|d.Grade ranking             |\n");
printf("|e.Exit system               |\n");
}


