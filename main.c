#include <stdio.h>
#include <stdbool.h>
#include "show_.c"
#include "maru.c"
#include "judge.c"
#include "batu.c"
#define FULL_CELL 9
enum coordi_num {
  MY_00,
  WRI_CAN_01,
  PC_02,
};
int main(void) {
    int marubatu[FULL_CELL] = {WRI_CAN_01,WRI_CAN_01,WRI_CAN_01,WRI_CAN_01,WRI_CAN_01,WRI_CAN_01,WRI_CAN_01,WRI_CAN_01,WRI_CAN_01};
    int temp = 0;
    
    while (1)
    {
      show(marubatu);  //碁盤を表示
      temp = judge_(marubatu);  //記入可能な場所があるか否かの判定
      if (temp == 0){printf("you win finish\n");break;}
      else if (temp == 1){maru(marubatu);} //〇を記入
      else if (temp == 2){printf("you lose finish\n");break;}
      else {printf("can not write finish\n");break;}
      batu(marubatu);   //×を記入
    }
}