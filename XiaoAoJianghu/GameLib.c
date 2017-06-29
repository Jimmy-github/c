//
//  GameLib.c
//  XiaoAoJianghu
//
//  Created by 张添杰 on 2017/6/26.
//  Copyright © 2017年 张添杰. All rights reserved.
//


#include "GameLib.h"

/*设置控制台窗口的标题*/


void SetTitle(char *title){
    
    
      /*修改标题*/
      printf("\033]0;%s\007",title);
    
}


void SetColor(int foreColor,int backColor){
    
      printf("\033[01;34;42m %s\033[0m\n","字体");
    
    
}

/*设置前景色*/
void SetTextColor(char *text){
     //printf("\033[01;34;42m %s\033[0m",text);
    printf("\033[32m%s\033[0m",text);
    
}

void SetTextColorYellow(char *text){
    //printf("\033[01;34;42m %s\033[0m",text);
    printf("\033[33m%s\033[0m",text);
    
}

//紫色
void SetSetTextColorPurple(char *text){
    printf("\033[35m%s\033[0m",text);
}

void SetTextColorRedBold(char *text){
    //printf("\033[01;34;42m %s\033[0m",text);
    printf("\033[01;31m%s\033[0m",text);
    
}

void SetTextColorWhiteBold(char *text){
    //printf("\033[01;34;42m %s\033[0m",text);
    printf("\033[01;37m%s\033[0m",text);
    
}

void SetTextColorBold(char *text){
    //printf("\033[01;34;42m %s\033[0m",text);
    printf("\033[01;32m%s\033[0m",text);
    
}
/*设置整型前景色*/
void SetIntColor(int num){
     printf("\033[32m%d\033[0m",num);
}

void SetIntColorYellow(int num){
    printf("\033[33m%d\033[0m",num);
}



/*设置前后背景色*/
void SetTextColorWithBackground(char *text){
  
    printf("\033[01;32;47m%s\033[0m",text);
    
}

/*设定光标位置*/
void SetPosition(int x,int y){
    printf("\033[%d;%dH",y,x);
}




