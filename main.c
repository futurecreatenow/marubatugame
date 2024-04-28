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
    test.me_win_flag = false,test.pc_win_flag = false;
    srand((unsigned int)time(NULL));
    makeArray(&test);
    setup(test);
    show(test);
    while ((test.me_win_flag == false) && (test.pc_win_flag == false))
    {
        select(&test);
        judge(&test);
        show(test);
    }
    printf("FINISH\n");
    if (test.me_win_flag == true) printf("YOU WIN\n");
    else printf("PC WIN\n");
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
    test->me_win_flag = false,test->pc_win_flag = false;
    int win_num = SIDE;
    int mark = -1;
    if (test->turn == MY_T)
    {
        mark = CIRCLE;
    }else{
        mark = CROSS;
    }
    int yoko = 0,tate = 0,count = 0;
    //横方向
    for (yoko = 0; yoko < SIDE; yoko++)
    {
        for (tate = 0; tate < SIDE; tate++)
        {
            if (test->masu[yoko][tate] == mark)
            {
                count++;
                printf("yoko:%d\n",tate + 1);
            }
            
        }
        if (count == win_num)
        {
            if (mark == CIRCLE)test->me_win_flag = true;
            else test->pc_win_flag = true;
            count = 0;
            printf("yoko_flag\n");
            break;
        }
    }

    count = 0;
    //縦方向
    for (tate = 0; tate < SIDE; tate++)
    {
        printf("tate_00\n");
        for (yoko = 0; yoko < count; yoko++)
        {
            printf("tate_01\n");
            if (test->masu[yoko][tate] == mark)
            {
                count++;
                printf("tate:%d\n",yoko + 1);
            }
        }
        if (count == win_num)
        {
            if (mark == CIRCLE)test->me_win_flag = true;
            else test->pc_win_flag = true;
            count = 0;
            printf("tate_flag\n");
            break;
        }
    }
    
    //右下
    count = 0;
    for (int k = 0; k < SIDE; k++)
    {
        if (test->masu[k][k] == mark)
        {
            count++;
        }
    }
    if (count == win_num)
    {
        if (mark == CIRCLE)test->me_win_flag = true;
        else test->pc_win_flag = true;
        printf("migisita_flag\n");
    }

    //左下
    count = 0;
    for (int k = 0; k < SIDE; k++)
    {
        if (test->masu[k][2 - k] == mark)
            {
                count++;
            }
            
    }
    if (count == win_num)
    {
        if (mark == CIRCLE)test->me_win_flag = true;
        else test->pc_win_flag = true;
        printf("hidarisita_flag\n");
    }
    count = 0;

    if ((test->me_win_flag == false) && (test->pc_win_flag == false))
    {
        if(mark == CIRCLE) test->turn = PC_T;
        else test->turn = MY_T;
    }

}
