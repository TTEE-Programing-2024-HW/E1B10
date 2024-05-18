#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROWS 9
#define COLS 9
#define BOOKINGS 10
#define MAX_GROUP_SIZE 4


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

// �d��üаO��ĳ�y��
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

// �ˬd��J���y��O�_����
int isValidSeatSelection(char seats[ROWS][COLS], int row, int col) {
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        return 0;
    }
    if (seats[row - 1][col - 1] == '*' || seats[row - 1][col - 1] == '@') {
        return 0;
    }
    return 1;
}

// �D�{��
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
        } 
    char seats[ROWS][COLS];
    char suggestion[ROWS][COLS];
    char input;
    int numSeats;
    int satisfied;

    // ��l���H���ƥͦ���
    srand(time(NULL));

    // ��l�ƩM�H���w�q�y��
    initializeSeats(seats);
    bookSeats(seats);

    // �D�`��
    while (1) {
        printf("�п�J'a'����ܲ{���y���A'b'�ӿ�ܮy��A'c'�Ӥ�ʿ�ܮy�� ");
        scanf(" %c", &input);

        if (input == 'a') {
            displaySeats(seats);
        } else if (input == 'b') {
            printf("�п�J�ݭn�X�Ӯy��]1~4�^: ");
            scanf("%d", &numSeats);
            if (numSeats < 1 || numSeats > MAX_GROUP_SIZE) {
                printf("�L�Ī���J�A�п�J1��4�������Ʀr�C\n");
                continue;
            }
            // ��l�ƫ�ĳ�y���
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    suggestion[i][j] = seats[i][j];
                }
            }
            if (suggestSeats(seats, numSeats, suggestion)) {
                displaySeats(suggestion);
                printf("�O�_���N���w�ơH(y/n): ");
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
                printf("�L�k���s�򪺮y��C\n");
            }
        } else if (input == 'c') {
            printf("�гv�@��J�y���ܡ]�p1-2, 2-9�^�G\n");
            while (1) {
                int row, col;
                char temp;
                if (scanf("%d-%d%c", &row, &col, &temp) != 3 || temp != '\n') {
                    printf("��J�榡���~�A�Э��s��J�C\n");
                    while (getchar() != '\n'); // �M����J�w�İ�
                    continue;
                }
                if (!isValidSeatSelection(seats, row, col)) {
                    printf("�y��L�ĩΤw�Q�w�q�A�Э��s��J�C\n");
                    continue;
                }
                seats[row - 1][col - 1] = '@';
                printf("�O�_�~���ܮy��H(y/n): ");
                char cont;
                scanf(" %c", &cont);
                if (cont == 'n') {
                    break;
                }
            }
            displaySeats(seats);
            printf("�����N��T�{�y��w��...");
            getchar(); // ���ݥΤ��J���N��
            getchar(); // ����Ĥ@�ӿ�J�������
            // �T�{��ܡA�N@������*
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    if (seats[i][j] == '@') {
                        seats[i][j] = '*';
                    }
                }
            }
            return 0;
        } else {
            printf("�L�Ī���J�A�Э��աC\n");
        }
    }

    return 0;
}
