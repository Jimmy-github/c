//
//  main.c
//  XiaoAoJianghu
//
//  Created by 张添杰 on 2017/6/25.
//  Copyright © 2017年 张添杰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "Game.h"
#include "GameLib.h"
#include "CharPicture.h"


#include <time.h>
/* 延时输出按钮*/
//int main(int argc, const char * argv[])
//{
//    
//    while(1){
//    time_t current_time;
//    time_t start_time;
//
//    printf("About to delay 5 seconds\n");
//
//    time(&start_time);  // Get starting time in seconds
//
//    do {
//        time(&current_time);
//    } while ((current_time - start_time) < 1);
//
//    printf("Done\n");
//    }
//
//    //return 1;
//}







int main(int argc, const char * argv[]) {
    //CreateCat();

    
    SetTitle("笑傲江湖之-精忠报国");
    Init();
    ShowWelcome("欢迎来到笑傲江湖世界!!!\n");
    ShowMap();
    ShowInformation();
    ShowMianMenu();
    
    
   
    
    
    return 0;
}


