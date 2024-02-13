//×を記入する関数
#include <stdio.h>
#include <stdbool.h>
#define BATU_NUM 9

enum batu {
  MY_00000,
  WRI_CAN_00001,
  PC_00002,
};
void batu(int *marubatu){
    for (int i = 0; i < BATU_NUM; i++)
    {
        if (marubatu[i] == WRI_CAN_00001)
        {
            marubatu[i] = PC_00002;
            break;
        }
    }

}