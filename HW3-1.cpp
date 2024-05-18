#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define ROWS 9
#define COLS 9
#define BOOKINGS 10
// 初始化座位表
void initializeSeats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            seats[i][j] = 'O'; // 'O'表示空位
        }
    }
}

// 隨機預訂座位
void bookSeats(char seats[ROWS][COLS]) {
    int booked = 0;
    while (booked < BOOKINGS) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (seats[row][col] == 'O') {
            seats[row][col] = '*'; // '*'表示已預訂
            booked++;
        }
    }
}

// 顯示座位表
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
        printf("-------[BookingSystem]------\n");
        printf("||a. Available seats      ||\n");
        printf("||b. Arrange for you      ||\n");
        printf("||c. Choose by yourself   ||\n");
        printf("||d. Exit                 ||\n");
        printf("----------------------------\n");
        
        
    char seats[ROWS][COLS];
    char input;

    // 初始化隨機數生成器
    srand(time(NULL));

    // 初始化和隨機預訂座位
    initializeSeats(seats);
    bookSeats(seats);

    // 主循環
    while (1) {
        printf("請輸入'a'來顯示現有座位表，或輸入'q'退出: ");
        scanf(" %c", &input);

        if (input == 'a') {
            displaySeats(seats);
            break;                                                         //把這行拿來當修改的 
        } else if (input == 'q') {
            break;
        } else {
            printf("無效的輸入，請重試。\n");
        }
    }

    return 0;
}
        
        
    




        
        
        
        
        




