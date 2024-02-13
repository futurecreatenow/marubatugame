//〇を表示させる関数
#include <stdio.h>
#define JUDGE_NUM_ 9
#define LENGTH 3
#define WIDTH 3

enum show {
  MY_0000,
  WRI_CAN_0001,
  PC_0002,
};

void maru(int *marubatu){
    int temp_num;
    printf("you can write>>>");
    for (int i = 0; i < JUDGE_NUM_; i++)
    {
        if (marubatu[i] == WRI_CAN_0001){printf("%d,",i + 1);}
    }
    printf("\n");
    printf("input num>>>");
    scanf("%d",&temp_num);
    for (int i = 0; i < JUDGE_NUM_; i++)
    {
        if (i + 1 == temp_num){marubatu[i] = MY_0000;}
    }

}