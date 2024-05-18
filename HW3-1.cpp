#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define ROWS 9
#define COLS 9
#define BOOKINGS 10
// ��l�Ʈy���
void initializeSeats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            seats[i][j] = 'O'; // 'O'��ܪŦ�
        }
    }
}

// �H���w�q�y��
void bookSeats(char seats[ROWS][COLS]) {
    int booked = 0;
    while (booked < BOOKINGS) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (seats[row][col] == 'O') {
            seats[row][col] = '*'; // '*'��ܤw�w�q
            booked++;
        }
    }
}

// ��ܮy���
void displaySeats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }
}



int main(void)
{
	printf("****************    *****************      *                              *      \n");
	printf("       *                    *              *                              *      \n");
	printf("       *                    *              *                              *      \n");
	printf("       *                    *              *                             *       \n");
	printf("       *                    *              *                             *       \n");
	printf("       *                    *              *                            *        \n");
	printf("       *                    *               *                          *         \n");
	printf("       *                    *               *                          *         \n");
	printf("       *                    *               *                         *          \n");
	printf("       *                    *               *                         *          \n");
	printf("       *                    *               *                        *           \n");
	printf("       *                    *               *                       *            \n");
	printf("       *                    *               *                       *            \n");
	printf("       *                    *                *                     *             \n");
	printf("       *                    *                *                    *              \n");
	printf("       *                    *                 *                  *               \n");
	printf("       *                    *                  *                *                \n");
	printf("       *                    *                   *               *                \n");
	printf("       *                    *                    *            *                  \n");
	printf("       *                    *                     *          *                   \n");
	printf("       *                    *                      *       *                     \n");
	printf("       *                    *                        * *  *                      \n");
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
        printf("-------[BookingSystem]------\n");
        printf("||a. Available seats      ||\n");
        printf("||b. Arrange for you      ||\n");
        printf("||c. Choose by yourself   ||\n");
        printf("||d. Exit                 ||\n");
        printf("----------------------------\n");
        
        
    char seats[ROWS][COLS];
    char input;

    // ��l���H���ƥͦ���
    srand(time(NULL));

    // ��l�ƩM�H���w�q�y��
    initializeSeats(seats);
    bookSeats(seats);

    // �D�`��
    while (1) {
        printf("�п�J'a'����ܲ{���y���A�ο�J'q'�h�X: ");
        scanf(" %c", &input);

        if (input == 'a') {
            displaySeats(seats);
            break;                                                         //��o�殳�ӷ�ק諸 
        } else if (input == 'q') {
            break;
        } else {
            printf("�L�Ī���J�A�Э��աC\n");
        }
    }

    return 0;
}
        
        
    




        
        
        
        
        




