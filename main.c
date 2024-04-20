#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define FULL_CELL 9 //すべてのマス目数
#define SIDE 3 //一辺のマス目数
#define ZERO 0  //座標
#define ONE 1 //座標
#define TWO 2 //座標
#define UNDECI 0 //未記入
#define CIRCLE 1 //私の駒（丸印）
#define CROSS 2 //PCの駒（×印）

typedef enum{MY_T,PC_T}TURN;


typedef struct BOARD{
    int** masu;
    int yoko,tate;
    bool finish_flag;
    bool pc_win_flag;
    bool me_win_flag;
    int pc_tate,pc_yoko;
    TURN turn;
}BOARD;

//プロトタイプ宣言
void makeArray(BOARD *test); //碁盤の座標の生成
void freeArray(BOARD *test); //碁盤の座標の削除
void setup(BOARD test); //初期値の碁盤の配置
void show(BOARD test); //碁盤の表示
void select(BOARD *test); //駒を置く
void judge(BOARD *test);


int main(void) {
    BOARD test;
    test.turn = MY_T;
    test.finish_flag = false;
    srand((unsigned int)time(NULL));
    makeArray(&test);
    setup(test);
    show(test);
    while (test.finish_flag == false)
    {
        select(&test);
        show(test);
        judge(&test);
    }
    printf("FINISH");
    show(test);
    if (test.me_win_flag == true) printf("YOU WIN");
    else printf("PC WIN");
    freeArray(&test);

}
void select(BOARD *test){
    if (test->turn == MY_T)
    {
        test->yoko = -1,test->tate = -1;
        bool select_flag = false;
        while (select_flag == false)
        {
            printf("select yoko(0-2)>>>\n");
            scanf("%d",&test->yoko);
            printf("select tate(0-2)>>>\n");
            scanf("%d",&test->tate);
            if ((test->yoko < ZERO) ||(test->yoko > TWO) ||(test->tate < ZERO) ||(test->tate > TWO) )
            {
                printf("again_\n");
                select_flag = false;
            }
            else
            {
                if (test->masu[test->yoko][test->tate] == UNDECI)
                {
                    select_flag = true;
                    test->masu[test->yoko][test->tate] = CIRCLE;
                    break;
                }
                else
                {
                    printf("again_\n");
                    select_flag = false;
                }
                
            }
        
        }
        test->turn = PC_T;
    }else
    {
        printf("PC_");
        test->pc_yoko = -1,test->pc_tate = -1;
        bool pc_select = false;
        while (pc_select == false)
        {
            printf("PC:select yoko(0-2)>>>\n");
            scanf("%d",&test->pc_yoko);
            printf("PC:select tate(0-2)>>>\n");
            scanf("%d",&test->pc_tate);
            if ((test->pc_yoko < ZERO) ||(test->pc_yoko > TWO) ||(test->pc_tate < ZERO) ||(test->pc_tate > TWO) )
            {
                printf("again_\n");
                pc_select = false;
            }
            else
            {
                if (test->masu[test->pc_yoko][test->pc_tate] == UNDECI)
                {
                    pc_select = true;
                    test->masu[test->pc_yoko][test->pc_tate] = CROSS;
                    break;
                }
                else
                {
                    printf("again_\n");
                    pc_select = false;
                }
                
            }
        }
        

        test->turn = MY_T;
    }

}
    

void setup(BOARD test){
    for (int yoko = 0; yoko < SIDE; yoko++)
    {
        for (int tate = 0; tate < SIDE; tate++)
        {
            test.masu[yoko][tate] = UNDECI;
            
        }
    }
}
void show(BOARD test){
    int circle_num = 0,cross_num = 0,undeci_num = 0; 
    for (int  yoko = 0; yoko < SIDE; yoko++)
    {
        for (int tate = 0; tate < SIDE; tate++)
        {
            switch (test.masu[yoko][tate])
            {
                case CIRCLE:circle_num++;break;
                case CROSS:cross_num++;break;
                case UNDECI:undeci_num++;break;
                default:break;
            }
            
        }
    }
    if (test.turn == MY_T) printf("########YOUR TURN########\n");
    else printf("##########PC TURN########\n");
    
    printf("\n");
    printf("ME:o>>>%d\n",circle_num);
    printf("PC:x>>>%d\n",cross_num);
    printf("\n");
    printf("  012\n");
    for (int  yoko = 0; yoko < SIDE; yoko++)
    {
        printf("%-2d",yoko);
        for (int tate = 0; tate < SIDE; tate++)
        {
            switch (test.masu[yoko][tate])
            {
                case CIRCLE:printf("o");break;
                case CROSS:printf("x");break;
                case UNDECI:printf("-");break;
                default:break;
            }
            
        }
        printf("\n");
    }
    printf("#########################\n");
}
void makeArray(BOARD* test){
    test->masu = (int**)calloc(SIDE,sizeof(int*));
    for (int i = 0; i < SIDE; i++)
    {
        test->masu[i] = (int *)calloc(SIDE,sizeof(int));
    }
    
}
void freeArray(BOARD* test){
    for (int i = 0; i < SIDE; i++)
    {
        free(test->masu[i]);
    }
    free(test->masu);

}
void judge(BOARD *test){
    printf("test_01\n");
    test->me_win_flag = false;
    test->pc_win_flag = false;
    int win_num = 3;
    int mark = -1;
    if (test->turn == MY_T)
    {
        mark = CIRCLE;
    }else{
        mark = CROSS;
    }
    //横方向
    for (int yoko = 0; yoko < SIDE; yoko++)
    {
        int count = 0;
        for (int tate = 0; tate < SIDE; tate++)
        {
            if (test->masu[yoko][tate] == mark)
            {
                count++;
            }
            
        }
        if (count == win_num)
        {
            test->me_win_flag = true;
            count = 0;
            break;
        }
    }

    //縦方向
    for (int tate = 0; tate < SIDE; tate++)
    {
        int count = 0;
        for (int yoko = 0; yoko < count; yoko++)
        {
            if (test->masu[yoko][tate] == mark)
            {
                count++;
            }
        }
        if (count == win_num)
        {
            test->me_win_flag = true;
            count = 0;
            break;
        }
    }
    
    //右下
    int count = 0;
    for (int yoko = 0; yoko < SIDE; yoko++)
    {
        if (test->masu[yoko][yoko] == mark)
        {
            count++;
        }
    }
    if (count == win_num)
    {
        test->me_win_flag = true;
    }
    count = 0;

    //左下
    

}
