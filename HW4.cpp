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
    system("clear"); // �� system("cls"); �p�G�A�b Windows �W����
}

void inputStudents(Student students[], int *count) {
    clearScreen();
    int n;
    printf("�п�J�ǥͤH�� (5~10): ");
    while (scanf("%d", &n) != 1 || n < 5 || n > 10) {
        printf("��J���~�A�п�J 5 �� 10 �����: ");
        while (getchar() != '\n'); // �M���w�İ�
    }

    *count = n;

    for (int i = 0; i < n; i++) {
        printf("��J�� %d ��ǥͪ��m�W: ", i + 1);
        scanf("%s", students[i].name);
        printf("��J�� %d ��ǥͪ��Ǹ� (6 ����): ", i + 1);
        while (scanf("%d", &students[i].id) != 1 || students[i].id < 100000 || students[i].id > 999999) {
            printf("��J���~�A�п�J 6 ���ƾǸ�: ");
            while (getchar() != '\n');
        }
        printf("��J�� %d ��ǥͪ��ƾǦ��Z (0~100): ", i + 1);
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100) {
            printf("��J���~�A�п�J 0 �� 100 �������ƾǦ��Z: ");
            while (getchar() != '\n');
        }
        printf("��J�� %d ��ǥͪ����z���Z (0~100): ", i + 1);
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100) {
            printf("��J���~�A�п�J 0 �� 100 ���������z���Z: ");
            while (getchar() != '\n');
        }
        printf("��J�� %d ��ǥͪ��^�妨�Z (0~100): ", i + 1);
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100) {
            printf("��J���~�A�п�J 0 �� 100 �������^�妨�Z: ");
            while (getchar() != '\n');
        }
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
}

void displayStudents(const Student students[], int count) {
    clearScreen();
    printf("�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t����\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n", students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
    printf("�����N��^��D���...");
    getchar(); getchar(); // ���d�b�e�����ݥΤ���U���N��
}

void searchStudent(const Student students[], int count) {
    clearScreen();
    char name[100];
    printf("�п�J�n�j�M���ǥͩm�W: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("���ǥ�: %s\n�Ǹ�: %d\n�ƾ�: %d\n���z: %d\n�^��: %d\n����: %.1f\n", students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
            printf("�����N��^��D���...");
            getchar(); getchar();
            return;
        }
    }
    printf("�����ǥ� %s\n", name);
    printf("�����N��^��D���...");
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

    printf("�m�W\t�Ǹ�\t����\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    printf("�����N��^��D���...");
    getchar(); getchar();
}

void mainMenu() {
    Student students[MAX_STUDENTS];
    int count = 0;

    while (1) {
        clearScreen();
        printf("�D���:\n");
        printf("a. ��J�ǥ͸��\n");
        printf("b. ��ܩҦ��ǥ͸��\n");
        printf("c. �j�M�ǥ͸��\n");
        printf("d. �̥������Z�Ƨ���ܾǥ͸��\n");
        printf("e. ���}\n");
        printf("�п��: ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                inputStudents(students, &count);
                system("pause");                // �ù��e���Ȱ��A�õ��ݨϥΪ̫����N��
    	        system("CLS"); 
                break;
            case 'b':
                displayStudents(students, count);
                system("pause");                // �ù��e���Ȱ��A�õ��ݨϥΪ̫����N��
    	        system("CLS"); 
                break;
            case 'c':
                searchStudent(students, count);
                system("pause");                // �ù��e���Ȱ��A�õ��ݨϥΪ̫����N��
    	        system("CLS"); 
                break;
            case 'd':
                displaySortedStudents(students, count);
                system("pause");                // �ù��e���Ȱ��A�õ��ݨϥΪ̫����N��
    	        system("CLS"); 
                break;
            case 'e':
                clearScreen();
                printf("�T�w���}�H (y/n): ");
                char exitChoice;
                while (1) {
                    scanf(" %c", &exitChoice);
                    if (exitChoice == 'y') {
                        exit(0);
                    } else if (exitChoice == 'n') {
                        break;
                    } else {
                        printf("��J���~�A�п�J 'y' �� 'n': ");
                    }
                }
                break;
            default:
                printf("��J���~�A�Э��s��J\n");
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
        mainMenu();
    return 0;}

