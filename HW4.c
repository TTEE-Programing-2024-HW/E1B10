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

        while(i<3){                     //��while�j��B�]�w�j�����p��3�� 
    	    printf("��J4�ӼƦr���K�X:");
            scanf("%d",&z);
        if(z==2024){                    //�Y��J���Ʀr����2024 
    	printf("�w��\n");         //�h�i�J�B�J�G 
    	system("pause");                // �ù��e���Ȱ��A�õ��ݨϥΪ̫����N��
    	system("CLS");                  // �M���ù�
		break;}
		else {
		i++;}}
    	if(i==3&&z!=2024){              //�p�G�������Ƶ���3���B�Ʀr������2024 
    	printf("ĵ�i");                 //�h�X�{ĵ�i 
        return 0;}
printf("------------------------------\n");
printf("|a. Enter student grades     |\n");
printf("|b.Display student grades    |\n");
printf("|c.Search for student grades |\n");
printf("|d.Grade ranking             |\n");
printf("|e.Exit system               |\n");
}


