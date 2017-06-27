//
//  Game.c
//  XiaoAoJianghu
//
//  Created by 张添杰 on 2017/6/25.
//  Copyright © 2017年 张添杰. All rights reserved.
//

#include <stdio.h>

#include "Game.h"

#include "GameLib.h"

extern  int x_pos,y_pos;


Map mapArray[8][8]={
    {
        {1,"天山",1,{0,0},"这里充满了西域文化！"},{1,"楼兰",1,{1,0},"这里充满了西域文化！"},
        {1,"白驼山",1,{2,0},"这里充满了西域文化！"},{1,"野猪林",1,{3,0},"这里充满了西域文化！"},
        {1,"水晶洞",1,{4,0},"这里充满了西域文化！"},{1,"天蚕洞",1,{5,0},"这里充满了西域文化！"},
        {1,"黑风寨",1,{6,0},"这里充满了西域文化！"},{1,"冰火岛",1,{7,0},"这里充满了西域文化！"}
    },
    {
        {1,"迷宫",1,{0,1},"这里充满了西域文化！"},{1,"凌霄城",1,{1,1},"这里充满了西域文化！"},
        {1,"轩辕岭",1,{2,1},"这里充满了西域文化！"},{1,"华山",1,{3,1},"这里充满了西域文化！"},
        {1,"嵩山",1,{4,1},"这里充满了西域文化！"},{1,"紫禁城",1,{5,1},"这里充满了西域文化！"},
        {1,"快活林",1,{6,1},"这里充满了西域文化！"},{1,"神龙岛",1,{7,1},"这里充满了西域文化！"}
    },
    {
        {1,"西域",1,{0,2},"这里充满了西域文化！"},{1,"葫芦谷",1,{1,2},"这里充满了西域文化！"},
        {1,"唐门",1,{2,2},"这里充满了西域文化！"},{1,"终南山",1,{3,2},"这里充满了西域文化！"},
        {1,"石窟",1,{4,2},"这里充满了西域文化！"},{1,"客栈",1,{5,2},"这里充满了西域文化！"},
        {1,"玉皇顶",1,{6,2},"这里充满了西域文化！"},{1,"灵蛇岛",1,{7,2},"这里充满了西域文化！"}
    },
    {
        {1,"光明顶",1,{0,3},"这里充满了西域文化！"},{1,"摩天崖",1,{1,3},"这里充满了西域文化！"},
        {1,"聚贤庄",1,{2,3},"这里充满了西域文化！"},{1,"后山",1,{3,3},"这里充满了西域文化！"},
        {1,"武当山",1,{4,3},"这里充满了西域文化！"},{1,"开封府",1,{5,3},"这里充满了西域文化！"},
        {1,"二十四桥",1,{6,3},"这里充满了西域文化！"},{1,"蓬莱仙境",1,{7,3},"这里充满了西域文化！"}
    },
    {{1,"擂鼓山",1,{0,4},"这里充满了西域文化！"},{1,"峨眉山",1,{1,4},"这里充满了西域文化！"},
        {1,"迷踪林",1,{2,4},"这里充满了西域文化！"},{1,"五虎岭",1,{3,4},"这里充满了西域文化！"},
        {1,"天宁寺",1,{4,4},"这里充满了西域文化！"},{1,"积善堂",1,{5,4},"这里充满了西域文化！"},
        {1,"镇江府",1,{6,4},"这里充满了西域文化！"},{1,"桃花岛",1,{7,4},"这里充满了西域文化！"}
    },
    {
        {1,"恶人谷",1,{0,5},"这里充满了西域文化！"},{1,"大理",1,{1,5},"这里充满了西域文化！"},
        {1,"百花谷",1,{2,5},"这里充满了西域文化！"},{1,"孔雀山庄",1,{3,5},"这里充满了西域文化！"},
        {1,"五花岗",1,{4,5},"这里充满了西域文化！"},{1,"万仞堂",1,{5,5},"这里充满了西域文化！"},
        {1,"千年古刹",1,{6,5},"这里充满了西域文化！"},{1,"六和塔",1,{7,5},"这里充满了西域文化！"}
    },
    {
        {1,"玩偶山庄",1,{0,6},"这里充满了西域文化！"},{1,"黑木崖",1,{1,6},"这里充满了西域文化！"},
        {1,"蝴蝶谷",1,{2,6},"这里充满了西域文化！"},{1,"铁花堡",1,{3,6},"这里充满了西域文化！"},
        {1,"霹雳堂",1,{4,6},"这里充满了西域文化！"},{1,"关帝庙",1,{5,6},"这里充满了西域文化！"},
        {1,"麒麟庄",1,{6,6},"这里充满了西域文化！"},{1,"销魂宫",1,{7,6},"这里充满了西域文化！"}
    },
    {
        {1,"石府",1,{0,7},"这里充满了西域文化！"},{1,"金三角",1,{1,7},"这里充满了西域文化！"},
        {1,"忏悔崖",1,{2,7},"这里充满了西域文化！"},{1,"通吃岛",1,{3,7},"这里充满了西域文化！"},
        {1,"通天观",1,{4,7},"这里充满了西域文化！"},{1,"紫霞亭",1,{5,7},"这里充满了西域文化！"},
        {1,"天弃庵",1,{6,7},"这里充满了西域文化！"},{1,"侠客岛",1,{7,7},"这里充满了西域文化！"}
    }
    
};

Prop propArrary[]={
    {1,"帝皇天烈剑",1,5,5000,Weapon,.minAttack=1,.maxAttack=4,"上古三皇五帝用过的剑"},
    {2,"荆棘之甲",2,5,10000,Armor,.minDefence=2,.maxDefence=6,"取日月之精华，反弹厉害"},
    {3,"玉液琼浆",3,5,15000,Con,.minPower=100,.maxPower=500,"蟠桃会上御用饮品"},
    
};
void Init(){//初始化游戏数据
    
    
};
void Show(){//显示全局数据
    
    int propCount=sizeof(propArrary)/sizeof(Prop);
    for (int i=0; i<propCount; i++) {
        printf("%d\t%s\t%.0lf\t\n",propArrary[i].id,propArrary[i].name,propArrary[i].price);
        
        switch (propArrary[i].type) {
            case Weapon:
                printf("最小攻击力：%d\t 最大攻击力：%d\t\n",propArrary[i].minAttack,propArrary[i].maxAttack);
                break;
            case Armor:
                printf("最小防御力：%d\t 最大防御力力：%d\t\n",propArrary[i].minDefence,propArrary[i].maxDefence);
                break;
            case Con:
                printf("最小消耗：%d\t 最大消耗：%d\t\n",propArrary[i].minPower,propArrary[i].maxPower);
                break;
                //            case Card:
                //                printf("最小卡片：%d\t 最大卡片：%d\t\n",propArrary[i].minAttack,propArrary[i].maxAttack);
                //                break;
                //            case Frag:
                //                printf("最小碎片：%d\t 最大碎片：%d\t\n",propArrary[i].minAttack,propArrary[i].maxAttack);
                //                break;
            default:
                break;
        }
    }
    
    
    printf("打印地图信息\n");
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%-8s\t",mapArray[i][j].name);
            
        }
        printf("\n");
        
    }
    
    
};



/* 显示欢迎页面*/
void ShowWelcome(char *text){
    //1.文字颜色
    
    
    
    //2.控制光标
    
    SetPosition(MARGIN_X, START_LINE);
    SetTextColor(SEP);
    
    SetPosition(MARGIN_X, START_LINE+1);
    SetTextColor("|");
    SetPosition(MARGIN_X*4, START_LINE+1);
    SetTextColor(text);
    SetPosition(WIDTH+MARGIN_X-1, START_LINE+1);
    SetTextColor("|");
    SetPosition(MARGIN_X, START_LINE+2);
    SetTextColor(SEP);
    
  
    
}
/* 显示游戏地图*/
void ShowMap(){
    
    int i;
    for ( i=0; i<8; i++) {
        
        SetPosition(MARGIN_X, START_LINE+3+i);
        SetTextColor("|");
        
        
        for (int j=0; j<8; j++) {
            
            SetPosition(MARGIN_X+5+9*j, START_LINE+3+i);
            
            if(j==x_pos&&i==y_pos){
                SetTextColorWithBackground(mapArray[i][j].name);
            }
            else{
                SetTextColor(mapArray[i][j].name);
            }
            
            
            
            
            
            printf("\t");
        }
        SetPosition(WIDTH+MARGIN_X-1, START_LINE+3+i);
        SetTextColor("|");
        printf("\n");
        
    }
    
    SetPosition(MARGIN_X, START_LINE+3+i);
    MAP_END_LINE=START_LINE+3+i;
    SetTextColor(SEP);
    
    
    
}


/* 刷新地图时后地图会下滑一行，所以要加1*/
void ShowMapRefresh(){
//    ShowWelcome("欢迎来到笑傲江湖世界!!!\n");
//    ShowMap();
//    ShowInformation();
//    ShowMianMenu();
    int i;
    for ( i=0; i<8; i++) {
        
        SetPosition(MARGIN_X, START_LINE+3+i-1);
        SetTextColor("|");
        
        
        for (int j=0; j<8; j++) {
            
            SetPosition(MARGIN_X+5+9*j, START_LINE+3+i-1);
            
            if(j==x_pos&&i==y_pos){
                SetTextColorWithBackground(mapArray[i][j].name);
            }
            else{
                SetTextColor(mapArray[i][j].name);
            }
            
            
            
            
            
            printf("\t");
        }
        SetPosition(WIDTH+MARGIN_X-1, START_LINE+3+i-1);
        SetTextColor("|");
        printf("\n");
        
    }
    
    SetPosition(MARGIN_X, START_LINE+3+i-1);
    MAP_END_LINE=START_LINE+3+i;
    SetTextColor(SEP);
    
    
    
}
/*显示游戏地图下方信息*/
void ShowInformation(){
    
    
    
    int i;
    
    for (i=0; i<INFORMATION_HEIGHT; i++) {
        
        SetPosition(MARGIN_X, MAP_END_LINE+1+i);
        SetTextColor("|");
        SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+1+i);
        SetTextColor("|");
        
    }
    SetPosition(MARGIN_X, MAP_END_LINE+1+i);
    SetTextColor(SEP);
    
    
    INFO_END_LINE=MAP_END_LINE+1+i;
}
/*显示游戏主菜单*/
void ShowMianMenu(){
    
    int i;
    
    
    
    for (i=0; i<MAIN_MENU_HEIGHT; i++) {
        
        SetPosition(MARGIN_X, INFO_END_LINE+1+i);
        SetTextColor("|");
        
        switch (i) {
            case 0:
                SetTextColor("游戏菜单：");
                
                break;
            case 1:
                SetTextColor("1.自我欣赏");
                break;
            case 2:
                SetTextColor("2.查找怪物");
                break;
            default:
                break;
        }
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+1+i);
        SetTextColor("|");
        
    }
    
    
    int margin_down=3; //命令行距离底部距离
    
    
    SetPosition(MARGIN_X+2, INFO_END_LINE+i-margin_down);
    
    
    SetTextColorBold("在这里输入您的命令:");
    
    SetPosition(MARGIN_X, INFO_END_LINE+1+i);
    SetTextColor(SEP);
    
    SetPosition(MARGIN_X+22, INFO_END_LINE+i-margin_down);
    
    
    
    
    input=(char *)malloc(100);;
    
    while(1){
        
        
        SetPosition(MARGIN_X+22, INFO_END_LINE+i-margin_down-1);
       // printf("\033[2J"); //清屏
    
    
        
        
        printf("\033[K");
        // /033[K   清除从光标到行尾的内容
        key= getInputKey();
        SetPosition(MARGIN_X+2, INFO_END_LINE+i-margin_down);
        printf("\033[K");
       
       
        
        keynum=key;
        
        switch (keynum) {
            case 49:
                SetTextColorYellow("您选择了菜单游戏1");
                break;
            case 50:
               SetTextColorYellow("您选择了菜单游戏2");
                break;
            case 51:
                 SetTextColorYellow("您选择了菜单游戏3");
                break;
            case 52:
                SetTextColorYellow("您选择了菜单游戏4");
                break;
            case 53:
                SetTextColorYellow("您选择了菜单游戏5");
                break;
            case 54:
                SetTextColorYellow("您选择了菜单游戏6");
                break;
            case -128:
                SetTextColorYellow("您按了 "); SetTextColorRedBold("↑");SetTextColorYellow(" 箭头");
                if(y_pos==0){
                    y_pos=7;
                }else{
                    y_pos--;
                }
                
                ShowMapRefresh();
                
                
                break;
            case -125:
                  SetTextColorYellow("您按了 ");SetTextColorRedBold("→");SetTextColorYellow(" 箭头");
                if(x_pos==7){
                    x_pos=0;
                }else{
                    x_pos++;
                }
                 ShowMapRefresh();
                break;
            case -127:
                SetTextColorYellow("您按了 ");SetTextColorRedBold("↓");SetTextColorYellow(" 箭头");
                if(y_pos==7){
                    y_pos=0;
                }else{
                    y_pos++;
                }
                
                 ShowMapRefresh();
                
                break;
            case -126:
                 SetTextColorYellow("您按了 ");SetTextColorRedBold("←");SetTextColorYellow(" 箭头");
                if(x_pos==0){
                    x_pos=7;
                }else{
                    x_pos--;
                }
                 ShowMapRefresh();
                break;
            
            default:
                break;
        }
        
      
    }
}




char  getInputKey(){
    
    fflush(stdin);
    scanf("%s",input);
    
    fflush(stdin);
    
    getchar();
    fflush(stdin);
    
    int len=strlen(input);
    
    
    
    char directkey[2];//用来放方向键的值
    
    
    if(len>=2){
        if(*(input+len-2)=='['){
            
            switch (*(input+len-1)) {
                case 'A':
                    return -128;    //上
                    break;
                case 'C':
                    return -125;    //右
                    break;
                case 'B':
                    return -127;    //下
                    break;
                case 'D':
                    return -126;    //左
                    break;
                default:
                    return -1;
                    break;
            }
        }else{
            int k=*(input+len-1);
            // printf(":%d:",k);
            return k;
        }
        
        
    }
    
    else{
        int k=*(input+len-1);
         //printf(":%d:",k);
        return k;
    }
    
    
    
    return -1;
    
    
}











