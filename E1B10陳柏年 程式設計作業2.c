#include<stdio.h>
#include<stdlib.h>
int main (void)
{
	printf("                         * * *    * * *                                     \n");
	printf("                       *       * *      *                                   \n");
	printf("                     *          *        *                                  \n");
	printf("                    *                     *                                 \n");
	printf("                  *                        *                                \n");
	printf("                *                           *                               \n");
	printf("                *                            *                              \n");
	printf("                *                             *                             \n");
	printf("                 *                           *                              \n");
	printf("                  *                         *                               \n");
	printf("                   *                       *                                \n");
	printf("                    *                     *                                 \n");
	printf("                     *                   *                                  \n");
	printf("                      *                 *                                   \n");
	printf("                       *               *                                    \n");
	printf("                        *             *                                     \n");
	printf("                         *           *                                      \n");
	printf("                          *         *                                       \n");
	printf("                           *       *                                        \n");
	printf("                            *     *                                         \n");
	printf("                             *  *                                           \n");
	int z,i=0;

        while(i<3){                     //用while迴圈且設定迴圈執行小於3次 
    	    printf("輸入4個數字的密碼:");
            scanf("%d",&z);
        if(z==2024){                    //若輸入的數字等於2024 
    	printf("進入步驟二\n");         //則進入步驟二 
    	system("pause");                // 螢幕畫面暫停，並等待使用者按任意鍵
    	system("CLS");                  // 清除螢幕
		break;}
		else {
		i++;}}
    	if(i==3&&z!=2024){              //如果答錯次數等於3次且數字不等於2024 
    	printf("警告");                 //則出現警告 
        return 0;}
        printf("--------------------\n");
        printf("||a.畫出直角三角形||\n");
        printf("||b.顯示乘法表    ||\n");
        printf("||c.結束          ||\n");
        printf("--------------------\n");
        
    char a,b,d;
        printf("輸入A或a清除螢幕:");
        fflush(stdin);                  // 使input buffer淨空，常放在scanf()前
        scanf("%c",&b);
        
        while(b!='A'&&b!='a'){          //用while迴圈設定當b不等於A或a 
           printf("輸入A或a清除螢幕:");
           scanf(" %c",&b);}
        system("CLS");                  // 清除螢幕   
        
        printf("輸入一個a到n的字元:");
        fflush(stdin);                  // 使input buffer淨空，常放在scanf()前
        scanf("%c",&a);
        while(a<'a'||a>'n'){            //當輸入數值不在a到n的範圍之間 
            printf("警告\n");
            printf("輸入一個a到n的字元:");
            scanf(" %c",&a);
		}
        for (char c=a; c >= 'a'; c--) {    // 從打的字元開始遞減到a(外部循環) 
        for (char ch = c; ch <=a; ch++) {  //遞增到字符a(內部循環) 
            printf("%c", ch);
        }
        printf("\n");}
        system("pause");
        system("CLS");
    
        printf("--------------------\n");
        printf("||a.畫出直角三角形||\n");
        printf("||b.顯示乘法表    ||\n");
        printf("||c.結束          ||\n");
        printf("--------------------\n");
        
    char e;
        printf("輸入B或b清除螢幕:");
        fflush(stdin);                      // 使input buffer淨空，常放在scanf()前
        scanf("%c",&e);
        
        while(e!='B'&&e!='b'){              //用while迴圈，當e不等於符號B或b 
        	printf("輸入B或b清除螢幕:");    //重新輸入B或b清除螢幕 
            scanf(" %c",&e);}
        system("CLS");                      // 清除螢幕 
        fflush(stdin);                      // 使input buffer淨空，常放在scanf()前 
        
    int f,j;
        printf("輸入一個1-9的整數:");
        scanf("%d",&f);
        while(f<1||f>9){                    //用while迴圈，當輸入的數字不在1到9之間 
        	printf("警告\n");               //出現警告 
        	printf("輸入一個1-9的整數:");   //重新輸入數字直到輸入的數字在1到9之間 
            scanf(" %d",&f);}
        for(j=1;j<=f;j++)                   //用for迴圈把輸入的數字,當輸入n則會出現1到n的乘法 
        	printf("%d*%d=%d\n",j,j,j*j);    
        system("pause");                         // 螢幕畫面暫停，並等待使用者按任意鍵 
        system("CLS");                           //清除螢幕 
    
    char g,h;
        printf("輸入C或c:");
        scanf(" %c",&g);
        while(g!='C'&&g!='c'){
        printf("輸入C或c:");
        scanf(" %c",&g);}
        
        if(g=='C'||g=='c')                        //當輸入的數字等於C或c 
        printf("Continue?(y/n)需要重新輸入嗎\n");//則詢問是否要重新輸入 
        printf("輸入Y或y或N或n:");
        scanf(" %c",&h);
        while(h!='Y'&&h!='y'&&h!='N'&&h!='n'){    //用while迴圈，當輸入的數字不等於Y或y或N或n 
		    printf("錯誤\n");                     //則出現錯誤訊息 
		    printf("輸入Y或y或N或n:");
            scanf(" %c",&h);}
        if(h=='Y'||h=='y'){                       //當輸入數字等於Y或y 
            printf("--------------------\n");
            printf("||a.畫出直角三角形||\n");
            printf("||b.顯示乘法表    ||\n");
            printf("||c.結束          ||\n");
            printf("--------------------\n");}
        if(h=='N'||h=='n')                        //當輸入數字等於N或n 
        return 0;                                 //結束程式 
} 



	//經過這次撰寫程式後，我覺得寫程式需要非常有細心以及耐心，因為有可能錯了一個符號或是少了一
	//個空格都有可能讓程式出現不同的樣貌，所以這次打了100行的程式，我都是大概打完5行就讓程式跑
	//跑看會不會動，這樣才不會出錯。在這次打程式中，也應用到了很多while、for迴圈，以及if的用法
	//，而我覺得最難的部分是把字元符號變成直角三角形的那個步驟，他需要用到雙重迴圈，並且也要設
	//很多不同的字元，因此在那個地方我也研究了許久才完成，除了這些之外，我也更會運用清除螢幕和
	//螢幕畫面暫停的寫法，在這次撰寫程式中不僅僅讓我更加進步，也讓我能持續熟練c語言程式撰寫。 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
