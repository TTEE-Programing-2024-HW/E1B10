#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROWS 9
#define COLS 9
#define BOOKINGS 10
#define MAX_GROUP_SIZE 4


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

// 查找並標記建議座位
int suggestSeats(char seats[ROWS][COLS], int numSeats, char suggestion[ROWS][COLS]) {
    int found = 0;
    if (numSeats == 4) {
        for (int i = 0; i < ROWS - 1; ++i) {
            for (int j = 0; j < COLS - 1; ++j) {
                if (seats[i][j] == 'O' && seats[i][j + 1] == 'O' &&
                    seats[i + 1][j] == 'O' && seats[i + 1][j + 1] == 'O') {
                    suggestion[i][j] = suggestion[i][j + 1] = '@';
                    suggestion[i + 1][j] = suggestion[i + 1][j + 1] = '@';
                    found = 1;
                    return found;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - numSeats; ++j) {
            int k;
            for (k = 0; k < numSeats; ++k) {
                if (seats[i][j + k] != 'O') {
                    break;
                }
            }
            if (k == numSeats) {
                for (k = 0; k < numSeats; ++k) {
                    suggestion[i][j + k] = '@';
                }
                found = 1;
                return found;
            }
        }
    }
    return found;
}

// 檢查輸入的座位是否有效
int isValidSeatSelection(char seats[ROWS][COLS], int row, int col) {
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        return 0;
    }
    if (seats[row - 1][col - 1] == '*' || seats[row - 1][col - 1] == '@') {
        return 0;
    }
    return 1;
}

// 主程序
int main() {

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
        } 
    char seats[ROWS][COLS];
    char suggestion[ROWS][COLS];
    char input;
    int numSeats;
    int satisfied;

    // 初始化隨機數生成器
    srand(time(NULL));

    // 初始化和隨機預訂座位
    initializeSeats(seats);
    bookSeats(seats);

    // 主循環
    while (1) {
        printf("請輸入'a'來顯示現有座位表，'b'來選擇座位，'c'來手動選擇座位 ");
        scanf(" %c", &input);

        if (input == 'a') {
            displaySeats(seats);
        } else if (input == 'b') {
            printf("請輸入需要幾個座位（1~4）: ");
            scanf("%d", &numSeats);
            if (numSeats < 1 || numSeats > MAX_GROUP_SIZE) {
                printf("無效的輸入，請輸入1到4之間的數字。\n");
                continue;
            }
            // 初始化建議座位表
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    suggestion[i][j] = seats[i][j];
                }
            }
            if (suggestSeats(seats, numSeats, suggestion)) {
                displaySeats(suggestion);
                printf("是否滿意此安排？(y/n): ");
                char answer;
                scanf(" %c", &answer);
                if (answer == 'y') {
                    for (int i = 0; i < ROWS; ++i) {
                        for (int j = 0; j < COLS; ++j) {
                            if (suggestion[i][j] == '@') {
                                seats[i][j] = '*';
                            }
                        }
                    }
                    break;
                }
            } else {
                printf("無法找到連續的座位。\n");
            }
        } else if (input == 'c') {
            printf("請逐一輸入座位選擇（如1-2, 2-9）：\n");
            while (1) {
                int row, col;
                char temp;
                if (scanf("%d-%d%c", &row, &col, &temp) != 3 || temp != '\n') {
                    printf("輸入格式錯誤，請重新輸入。\n");
                    while (getchar() != '\n'); // 清除輸入緩衝區
                    continue;
                }
                if (!isValidSeatSelection(seats, row, col)) {
                    printf("座位無效或已被預訂，請重新輸入。\n");
                    continue;
                }
                seats[row - 1][col - 1] = '@';
                printf("是否繼續選擇座位？(y/n): ");
                char cont;
                scanf(" %c", &cont);
                if (cont == 'n') {
                    break;
                }
            }
            displaySeats(seats);
            printf("按任意鍵確認座位安排...");
            getchar(); // 等待用戶輸入任意鍵
            getchar(); // 捕獲第一個輸入的換行符
            // 確認選擇，將@替換為*
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    if (seats[i][j] == '@') {
                        seats[i][j] = '*';
                    }
                }
            }
            return 0;
        } else {
            printf("無效的輸入，請重試。\n");
        }
    }

    return 0;
}
