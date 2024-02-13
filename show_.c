//マス目を表示させる関数
#include <stdio.h>
#define ONE_SIDE 3
#define ALL_CELL 9
enum show_num {
  MY_0,
  WRI_CAN_1,
  PC_2,
};
void show(int *marubatu){
    printf("################\n");
    for (int  i = 0; i < ALL_CELL; i++)
    {
        if (marubatu[i] == MY_0){printf("o");}
        else if(marubatu[i] == PC_2){printf("x");}
        else if (marubatu[i] == WRI_CAN_1){printf("-");}
        
        if (i % ONE_SIDE == ONE_SIDE - 1){printf("\n");}    
    }
    printf("################\n");
}
