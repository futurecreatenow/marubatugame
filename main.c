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
    while (test.finish_flag == false)
    {
        show(test);
        select(&test);
        judge(&test);
    }
    show(test);
    printf("finish");
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
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            test.masu[i][j] = UNDECI;
            
        }
    }
}
void show(BOARD test){
    int circle_num = 0,cross_num = 0,undeci_num = 0; 
    for (int  i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            switch (test.masu[i][j])
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
    for (int  i = 0; i < SIDE; i++)
    {
        printf("%-2d",i);
        for (int j = 0; j < SIDE; j++)
        {
            switch (test.masu[i][j])
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
    test->me_win_flag = false;
    test->pc_win_flag = false;
    for (int  i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if(test->masu[i][j] != UNDECI){
                
                if (test->masu[i][j] == CIRCLE)
                //私の勝利
                {
                    //縦方向
                    if (test->masu[i + 1][j] == CIRCLE && test->masu[i + 2][j] == CIRCLE)
                    {
                        test->me_win_flag = true;
                    }
                    //横方向
                    if (test->masu[i][j + 1] == CIRCLE && test->masu[i][j + 2] == CIRCLE)
                    {
                        test->me_win_flag = true;
                    }
                    //斜め方向(左上-右下)
                    if (test->masu[i + 1][j + 1] == CIRCLE && test->masu[i + 2][j + 2] == CIRCLE)
                    {
                        test->me_win_flag = true;
                    }
                    //斜め方向(左下-右上)
                    if (test->masu[i + 1][j -1] == CIRCLE && test->masu[i + 2][j -2] == CIRCLE)
                    {
                        test->me_win_flag = true;
                    }
                }else{
                //PCの勝利
                    //縦方向
                    if (test->masu[i + 1][j] == CROSS && test->masu[i + 2][j] == CROSS)
                    {
                        test->pc_win_flag = true;
                    }
                    //横方向
                    if (test->masu[i][j + 1] == CROSS && test->masu[i][j + 2] == CROSS)
                    {
                        test->pc_win_flag = true;
                    }
                    //斜め方向(左上-右下)
                    if (test->masu[i + 1][j + 1] == CROSS && test->masu[i + 2][j + 2] == CROSS)
                    {
                        test->pc_win_flag = true;
                    }
                    //斜め方向(左下-右上)
                    if (test->masu[i + 1][j -1] == CROSS && test->masu[i + 2][j -2] == CROSS)
                    {
                        test->pc_win_flag = true;
                    }
                }
                
            }
            
        }
    }
    if (test->pc_win_flag == true)
    {
        printf("you win\n");
        test->finish_flag = true;
    }
    if (test->pc_win_flag == true)
    {
        printf("you lose\n");
        test->finish_flag = true;
    }
    
    




    int circle_num = 0,cross_num = 0,undeci_num = 0; 
    for (int  i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            switch (test->masu[i][j])
            {
                case CIRCLE:circle_num++;break;
                case CROSS:cross_num++;break;
                case UNDECI:undeci_num++;break;
                default:break;
            }
            
        }
    }
    if (undeci_num == 0)
    {
        if (circle_num > cross_num) printf("you win\n");
        else printf("you lose\n");
        test->finish_flag = true;
    }else{
        if (test->turn == MY_T)printf("NEXT_YOU\n");
        else printf("NEXT_PC\n");
        
    }
}