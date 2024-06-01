#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 #define MAX_STUDENTS 10





typedef struct {
    char name[100];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

void clearScreen() {
    system("clear"); // 或 system("cls"); 如果你在 Windows 上執行
}

void inputStudents(Student students[], int *count) {
    clearScreen();
    int n;
    printf("請輸入學生人數 (5~10): ");
    while (scanf("%d", &n) != 1 || n < 5 || n > 10) {
        printf("輸入錯誤，請輸入 5 到 10 的整數: ");
        while (getchar() != '\n'); // 清除緩衝區
    }

    *count = n;

    for (int i = 0; i < n; i++) {
        printf("輸入第 %d 位學生的姓名: ", i + 1);
        scanf("%s", students[i].name);
        printf("輸入第 %d 位學生的學號 (6 位整數): ", i + 1);
        while (scanf("%d", &students[i].id) != 1 || students[i].id < 100000 || students[i].id > 999999) {
            printf("輸入錯誤，請輸入 6 位整數學號: ");
            while (getchar() != '\n');
        }
        printf("輸入第 %d 位學生的數學成績 (0~100): ", i + 1);
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100) {
            printf("輸入錯誤，請輸入 0 到 100 之間的數學成績: ");
            while (getchar() != '\n');
        }
        printf("輸入第 %d 位學生的物理成績 (0~100): ", i + 1);
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100) {
            printf("輸入錯誤，請輸入 0 到 100 之間的物理成績: ");
            while (getchar() != '\n');
        }
        printf("輸入第 %d 位學生的英文成績 (0~100): ", i + 1);
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100) {
            printf("輸入錯誤，請輸入 0 到 100 之間的英文成績: ");
            while (getchar() != '\n');
        }
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
}

void displayStudents(const Student students[], int count) {
    clearScreen();
    printf("姓名\t學號\t數學\t物理\t英文\t平均\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n", students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
    printf("按任意鍵回到主選單...");
    getchar(); getchar(); // 停留在畫面等待用戶按下任意鍵
}

void searchStudent(const Student students[], int count) {
    clearScreen();
    char name[100];
    printf("請輸入要搜尋的學生姓名: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("找到學生: %s\n學號: %d\n數學: %d\n物理: %d\n英文: %d\n平均: %.1f\n", students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
            printf("按任意鍵回到主選單...");
            getchar(); getchar();
            return;
        }
    }
    printf("未找到學生 %s\n", name);
    printf("按任意鍵回到主選單...");
    getchar(); getchar();
}

int compareStudents(const void *a, const void *b) {
    float avgA = ((Student *)a)->average;
    float avgB = ((Student *)b)->average;
    return (avgB - avgA) > 0 ? 1 : -1;
}

void displaySortedStudents(Student students[], int count) {
    clearScreen();
    qsort(students, count, sizeof(Student), compareStudents);

    printf("姓名\t學號\t平均\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    printf("按任意鍵回到主選單...");
    getchar(); getchar();
}

void mainMenu() {
    Student students[MAX_STUDENTS];
    int count = 0;

    while (1) {
        clearScreen();
        printf("主選單:\n");
        printf("a. 輸入學生資料\n");
        printf("b. 顯示所有學生資料\n");
        printf("c. 搜尋學生資料\n");
        printf("d. 依平均成績排序顯示學生資料\n");
        printf("e. 離開\n");
        printf("請選擇: ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                inputStudents(students, &count);
                system("pause");                // 螢幕畫面暫停，並等待使用者按任意鍵
    	        system("CLS"); 
                break;
            case 'b':
                displayStudents(students, count);
                system("pause");                // 螢幕畫面暫停，並等待使用者按任意鍵
    	        system("CLS"); 
                break;
            case 'c':
                searchStudent(students, count);
                system("pause");                // 螢幕畫面暫停，並等待使用者按任意鍵
    	        system("CLS"); 
                break;
            case 'd':
                displaySortedStudents(students, count);
                system("pause");                // 螢幕畫面暫停，並等待使用者按任意鍵
    	        system("CLS"); 
                break;
            case 'e':
                clearScreen();
                printf("確定離開？ (y/n): ");
                char exitChoice;
                while (1) {
                    scanf(" %c", &exitChoice);
                    if (exitChoice == 'y') {
                        exit(0);
                    } else if (exitChoice == 'n') {
                        break;
                    } else {
                        printf("輸入錯誤，請輸入 'y' 或 'n': ");
                    }
                }
                break;
            default:
                printf("輸入錯誤，請重新輸入\n");
                getchar(); getchar();
        }
    }
}
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
        mainMenu();
    return 0;}

