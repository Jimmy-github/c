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









int main(int argc, const char * argv[]) {
    
    SetTitle("笑傲江湖之-精忠报国");
    Init();
    ShowWelcome("欢迎来到笑傲江湖世界!!!\n");
    ShowMap();
    ShowInformation();
    ShowMianMenu();
    
    
   
    
    
    return 0;
}


