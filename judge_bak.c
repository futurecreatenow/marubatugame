void judge(BOARD *test){
    printf("test_01\n");
    test->me_win_flag = false;
    test->pc_win_flag = false;
    for (int  i = 0; i < SIDE; i++)
    {
        printf("test_02\n");
        for (int j = 0; j < SIDE; j++)
        {
            printf("test_03\n");
            if(test->masu[i][j] != UNDECI){
                printf("test_04\n");
                if (test->masu[i][j] == CIRCLE)
                //私の勝利
                {
                    printf("test_05\n");
                    //縦方向
                    if (test->masu[i + 1][j] == CIRCLE && test->masu[i + 2][j] == CIRCLE)
                    {
                        test->me_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                    //横方向
                    if (test->masu[i][j + 1] == CIRCLE && test->masu[i][j + 2] == CIRCLE)
                    {
                        test->me_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                    //斜め方向(左上-右下)
                    if (test->masu[i + 1][j + 1] == CIRCLE && test->masu[i + 2][j + 2] == CIRCLE)
                    {
                        test->me_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                    //斜め方向(左下-右上)
                    if (test->masu[i + 1][j -1] == CIRCLE && test->masu[i + 2][j -2] == CIRCLE)
                    {
                        test->me_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                }
                if (test->masu[i][j] == CROSS)
                {
                    //PCの勝利
                    printf("test_B\n");
                    //縦方向
                    if (test->masu[i + 1][j] == CROSS && test->masu[i + 2][j] == CROSS)
                    {
                        test->pc_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                    //横方向
                    if (test->masu[i][j + 1] == CROSS && test->masu[i][j + 2] == CROSS)
                    {
                        test->pc_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                    //斜め方向(左上-右下)
                    if (test->masu[i + 1][j + 1] == CROSS && test->masu[i + 2][j + 2] == CROSS)
                    {
                        test->pc_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                    //斜め方向(左下-右上)
                    if (test->masu[i + 1][j -1] == CROSS && test->masu[i + 2][j -2] == CROSS)
                    {
                        test->pc_win_flag = true;
                        test->finish_flag = true;
                        break;
                    }
                }
            }
        }
        if ((test->pc_win_flag == true) || (test->me_win_flag == true))
        {
            break;
        }
    }
    printf("test_A\n");
    int undeci_num = 0; 
    for (int  i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            printf("test_15\n");
            switch (test->masu[i][j])
            {
                
                case UNDECI:undeci_num++;printf("test_25\n");break;
                default:break;
            }
            
        }
    }
    printf("test_06\n");
    if (undeci_num == 0)
    {
        test->finish_flag = true;
    }else{
        if (test->turn == MY_T)printf("NEXT_YOU\n");
        else printf("NEXT_PC\n");
        
    }
    printf("test_07\n");
}