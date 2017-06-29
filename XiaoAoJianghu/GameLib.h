//
//  GameLib.h
//  XiaoAoJianghu
//
//  Created by 张添杰 on 2017/6/26.
//  Copyright © 2017年 张添杰. All rights reserved.
//

#ifndef GameLib_h
#define GameLib_h

#include <stdio.h>

/*设置控制台窗口的标题*/
void SetTitle(char *title);
/*设置控制台字体前景色和背景色*/

void SetTextColor(char *text);

void SetTextColorYellow(char *text);

void SetSetTextColorPurple(char *text);

void SetTextColorRedBold(char *text);

void SetTextColorWhiteBold(char *text);

/*设置整型前景色*/
void SetIntColor(int num);

void SetIntColorYellow(int num);

//字体加粗
void SetTextColorBold(char *text);

void SetTextColorWithBackground(char *text);

/*设定光标位置*/
void SetPosition(int x,int y);






#endif /* GameLib_h */
