#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define FULL_CELL 9 //すべてのマス目数
#define SIDE 3 //一辺のマス目数
#define ZERO 0  //座標
#define ONE 1 //座標
#define TWO 2 //座標
#define UNDECI 0 //未記入
#define CIRCLE 1 //私の駒（丸印）
#define CROSS 2 //PCの駒（×印）


typedef struct PC{
    int pc_yoko,pc_tate;
}PC;

typedef struct BOARD{
    int** masu;
    int yoko,tate;
    PC info;
}BOARD;

//プロトタイプ宣言
void makeArray(BOARD* test); //碁盤の座標の生成
void freeArray(BOARD* test); //碁盤の座標の削除
void setup(BOARD test); //初期値の碁盤の配置
void show(BOARD test); //碁盤の表示
void select(BOARD test);


int main(void) {
  BOARD test;
  makeArray(&test);
  setup(test);
  show(test);
  select(test);
  printf("good");
  freeArray(&test);

}
void select(BOARD test){
    test.yoko = -1,test.tate = -1;
    bool select_flag = false;
    while (select_flag == false)
    {
      printf("select yoko(0-2)>>>\n");
      scanf("%d",&test.yoko);
      printf("select tate(0-2)>>>\n");
      scanf("%d",&test.tate);
      if ((test.yoko < ZERO) ||(test.yoko > TWO) ||(test.tate < ZERO) ||(test.tate > TWO) )
      {
        printf("again_\n");
        select_flag = false;
      }
      else
      {
        if (test.masu[test.yoko][test.tate] == UNDECI)
        {
            select_flag = true;
            break;
        }
        else
        {
            select_flag = false;
            printf("again_\n");
        }
        
      }
      
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
    printf("################\n");
    printf("\n");
    printf("ME:o\n");
    printf("PC:x\n");
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
    printf("################\n");
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