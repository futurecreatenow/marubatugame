//〇を記入する関数
#include <stdio.h>
#include <stdbool.h>
#define JUDGE_NUM 9

enum judge {
  NOT_0, //記入できない
  CAN_WRITE_1 //記入可能
};
enum judge_ {
  MY_000,
  WRI_CAN_001,
  PC_002,
};
int judge_(int *marubatu){
    int temp_marubatu[JUDGE_NUM] = {NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0};
   
    int can_write[JUDGE_NUM] = {NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0,NOT_0};
    bool can_wri_flag;

    int one_flag;int two_flag;int three_flag;int four_flag;int five_flag;int six_flag;int seven_flag;int eight_flag;int nine_flag;
    for (int i = 0; i < JUDGE_NUM;i++)
    //碁盤の情報をcopy
    {
        temp_marubatu[i] = marubatu[i];
        // 未記入欄が存在する時、FLAGを立てる
        if (temp_marubatu[i] == CAN_WRITE_1){can_wri_flag = true;}
        if(temp_marubatu[i] == MY_000)
        {
            
            switch (i)
            {case 0:one_flag = 0;break;
             case 1:two_flag = 0;break;
             case 2:three_flag = 0;break;
             case 3:four_flag = 0;break;
             case 4:five_flag = 0;break;
             case 5:six_flag = 0;break;
             case 6:seven_flag = 0;break;
             case 7:eight_flag = 0;break;
             case 8:nine_flag = 0;break;
             default:break;
            }
        }
        else if(temp_marubatu[i] == WRI_CAN_001)
        {
            can_write[i] = WRI_CAN_001;
            switch (i)
            {case 0:one_flag = 1;break;
             case 1:two_flag = 1;break;
             case 2:three_flag = 1;break;
             case 3:four_flag = 1;break;
             case 4:five_flag = 1;break;
             case 5:six_flag = 1;break;
             case 6:seven_flag = 1;break;
             case 7:eight_flag = 1;break;
             case 8:nine_flag = 1;break;
             default:break;
            }
        }
        else if(temp_marubatu[i] == PC_002)
        {
            switch (i)
            {case 0:one_flag = 2;break;
             case 1:two_flag = 2;break;
             case 2:three_flag = 2;break;
             case 3:four_flag = 2;break;
             case 4:five_flag = 2;break;
             case 5:six_flag = 2;break;
             case 6:seven_flag = 2;break;
             case 7:eight_flag = 2;break;
             case 8:nine_flag = 2;break;
             default:break;
            }
        }
        
    }
    if (can_wri_flag == true)
    {
        
        
        //あなたの勝ち
        if (one_flag == 0 && two_flag == 0 && three_flag == 0){printf("you win>>>first row\n");return 0;}
        else if (four_flag == 0 && five_flag == 0 && six_flag == 0){printf("you win>>>second row\n");return 0;}
        else if (seven_flag == 0 && eight_flag == 0 && nine_flag == 0){printf("you win>>>third row\n");return 0;}
        else if (one_flag == 0 && four_flag == 0 && seven_flag == 0){printf("you win>>>first col\n");return 0;}
        else if (two_flag == 0 && five_flag == 0 && eight_flag == 0){printf("you win>>>second col\n");return 0;}
        else if (three_flag == 0 && six_flag == 0 && nine_flag == 0){printf("you win>>>third col\n");return 0;}
        else if (one_flag == 0 && five_flag == 0 && nine_flag == 0){printf("you win>>>left dia\n");return 0;}
        else if (three_flag == 0 && five_flag == 0 && seven_flag == 0){printf("you win>>>right dia\n");return 0;}

        //PCの勝ち
        else if (one_flag == 2 && two_flag == 2 && three_flag == 2){printf("you lose>>>first row\n");return 2;}
        else if (four_flag == 2 && five_flag == 2 && six_flag == 2){printf("you lose>>>second row\n");return 2;}
        else if (seven_flag == 2 && eight_flag == 2 && nine_flag == 2){printf("you lose>>>third row\n");return 2;}
        else if (one_flag == 2 && four_flag == 2 && seven_flag == 2){printf("you lose>>>first col\n");return 2;}
        else if (two_flag == 2 && five_flag == 2 && eight_flag == 2){printf("you lose>>>second col\n");return 2;}
        else if (three_flag == 2 && six_flag == 2 && nine_flag == 2){printf("you lose>>>third col\n");return 2;}
        else if (one_flag == 2 && five_flag == 2 && nine_flag == 2){printf("you lose>>>left dia\n");return 2;}
        else if (three_flag == 2 && five_flag == 2 && seven_flag == 2){printf("you lose>>>right dia\n");return 2;}

        //記入可能
        else {return 1;}
        
    }
    else{printf("full written...can not write\n");return 100;}
    
    

}
