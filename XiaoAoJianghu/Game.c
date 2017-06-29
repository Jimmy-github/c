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
        {1,"天山",1,{0,0},"最早的源头是剑术大师霍行仲，当年霍行仲因战乱避于西域，其心雄万丈，也曾远游中原，矢志搜集各家剑谱，想以毕生之力，开创「天山剑派」。「天山派」刚开始时分成南北两派，南派为凌云凤执掌，北派为霍天都当家，合并后主要定居于天山南高峰，在两条冰川汇聚之处的冰塔群里。"},
        {1,"楼兰",1,{1,0},"这里充满了西域文化！"},
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



Player Players[]={
    {.id=9527,.name="唐伯虎",.pass="123456",.life=100,.level=3,.exp=1,.hp=10000,.mp=5000,.mpMax=900000,.gold=10000000,.coord.x=3,.coord.y=1},
    {.id=9528,.name="祝枝山",.pass="123456",.life=100,.level=3,.exp=1,.hp=10000,.mp=5000,.mpMax=900000,.gold=10000000,.coord.x=2,.coord.y=0},
};

/*typedef struct _monster{
 
 int id;
 char name[50];
 int level; //怪物级别
 int hp;//怪物生命值
 int att; //怪物攻击力
 int diff;//怪物防御
 int minMoney;//杀死怪物掉落最小金币
 int maxMoney;//杀死怪物玩家获得的经验值
 int exp;//杀死怪物玩家获得的道具列表
 int state;//怪物当前状态， 0 怪物死 1怪物活
 
 Coord coord; //怪物当前所在地图坐标
 
 }Monster;*/


Monster Monsters[]={
    
    {.id=1,.name="海绵宝宝",.level=1,.hp=100,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=2,.name="凤姐",.level=2,.hp=200,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=3,.name="罗永浩",.level=1,.hp=1,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=4,.name="习大大",.level=1,.hp=1,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=5,.name="老夫子",.level=1,.hp=1,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    
    {.id=1,.name="海绵宝宝",.level=1,.hp=100,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=2,.name="凤姐",.level=2,.hp=200,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=3,.name="罗永浩",.level=1,.hp=1,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=4,.name="习大大",.level=1,.hp=1,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    {.id=5,.name="老夫子",.level=1,.hp=1,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=0},
    
    {.id=6,.name="小鬼子",.level=1,.hp=1,.att=5,.diff=2,.minMoney=5,.maxMoney=10,.exp=5,.state=1,.coord.x=0,.coord.y=1}
    
};

Player *currentPlayer;
void Init(){//初始化游戏数据
    //设置当前登录玩家
    currentPlayer=Players;
    
    currentPlayer->weapon=propArrary[0];
    
    
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
    
    
    
    
   
    MAP_END_LINE=START_LINE+3+i;
    SetPosition(MARGIN_X, START_LINE+3+i);
    SetTextColor(SEP);
    
    
    
    ShowMapInfoFirst();
}


/* 刷新地图时后地图会下滑一行，所以要加1*/
void ShowMapRefresh(){

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
    
     ShowMapInfo();
    

    
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
            case 3:
                SetTextColor("3.回总舵");
                break;
            case 4:
                SetTextColor("4.购买装备");
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
        
        
        /*补充 | */
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+i-margin_down-1);
        SetTextColor("|");
        SetPosition(MARGIN_X+22, INFO_END_LINE+i-margin_down-1);
        
        
        key= getInputKey();
        
        
        
        SetPosition(MARGIN_X+2, INFO_END_LINE+i-margin_down);
        printf("\033[K");
       
        /*补充 | */
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+i-margin_down);
        SetTextColor("|");
        SetPosition(MARGIN_X+2, INFO_END_LINE+i-margin_down);
        
        keynum=key;
        
       
        
        switch (keynum) {
            case 49:
                SetSetTextColorPurple("您选择了菜单游戏1");
                
                break;
            case 50:
               SetSetTextColorPurple("您选择了清除信息");
              
                break;
            case 51:
                 SetSetTextColorPurple("您选择了菜单游戏3");
                break;
            case 52:
                SetSetTextColorPurple("您选择了菜单游戏4");
                break;
            case 53:
                SetSetTextColorPurple("您选择了菜单游戏5");
                break;
            case 54:
                SetSetTextColorPurple("您选择了菜单游戏6");
               
                break;
            case -128:
                SetSetTextColorPurple("您按了 "); SetTextColorWhiteBold("↑");SetSetTextColorPurple(" 箭头");
                if(y_pos==0){
                    y_pos=7;
                }else{
                    y_pos--;
                }
                
                ShowMapRefresh();
                
                
                break;
            case -125:
                  SetSetTextColorPurple("您按了 ");SetTextColorWhiteBold("→");SetSetTextColorPurple(" 箭头");
                if(x_pos==7){
                    x_pos=0;
                }else{
                    x_pos++;
                }
                 ShowMapRefresh();
                break;
            case -127:
                SetSetTextColorPurple("您按了 ");SetTextColorWhiteBold("↓");SetSetTextColorPurple(" 箭头");
                if(y_pos==7){
                    y_pos=0;
                }else{
                    y_pos++;
                }
                
                 ShowMapRefresh();
                
                break;
            case -126:
                 SetSetTextColorPurple("您按了 ");SetTextColorWhiteBold("←");SetSetTextColorPurple(" 箭头");
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
        
         ProcessGameMenu(keynum);
        
      
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


/*显示当前地图信息*/

void ShowMapInfo(){
    
    
    //1.清除信息窗消息
     Clear(MARGIN_X+1,MAP_END_LINE,INFORMATION_HEIGHT);
    
    //2. 显示玩家当前所在地图信息
    SetPosition(MARGIN_X+20, MAP_END_LINE);
    SetTextColor("玩家当前所在地图是《");
    SetTextColor(mapArray[y_pos][x_pos].name);
    SetTextColor("》");
    
    
     int lines=strlen(mapArray[y_pos][x_pos].desc)/108;
    
    
    char temp[108];
    for(int i=0;i<=lines;i++){
        SetPosition(MARGIN_X+3, MAP_END_LINE+i+1);
        
        for(int j=0;j<108;j++){
            
            temp[j]='\0';
            temp[j]=mapArray[y_pos][x_pos].desc[i*108+j];
            //printf("%c",mapArray[y_pos][x_pos].desc[i*108+j]);
            
           // printf("\033[32m%c\033[0m",mapArray[y_pos][x_pos].desc[i*108+j]);
        }
        SetTextColor(temp);
       
        
        
    }
    
   
    
  
    
    
    
    
    
    
    
    
   
}

/*从 x y 开始清除rowCount行,用空格替换*/

void Clear(int x,int y,int rowCount){
    
    int i,j;
    for (i=0; i<rowCount; i++) {
        SetPosition(x, y+i);
        for (j=0; j<WIDTH-2; j++) {
            printf(" ");
        }
    }
}

/*首次显示地图信息*/
void ShowMapInfoFirst(){
    
//    SetPosition(MARGIN_X+2, MAP_END_LINE+1);
//    printf("玩家当前所在地图是《%s》",mapArray[y_pos][x_pos].name);
//    
//    
    
    //1.清除信息窗消息
    Clear(MARGIN_X+1,MAP_END_LINE+1,INFORMATION_HEIGHT);
    
    //2. 显示玩家当前所在地图信息
    SetPosition(MARGIN_X+20, MAP_END_LINE+1);
    SetTextColor("玩家当前所在地图是《");
    SetTextColor(mapArray[y_pos][x_pos].name);
    SetTextColor("》");
    
    
    int lines=strlen(mapArray[y_pos][x_pos].desc)/108;
    
    
    char temp[108];
    for(int i=0;i<=lines;i++){
        SetPosition(MARGIN_X+3, MAP_END_LINE+i+1+1);
        
        for(int j=0;j<108;j++){
            
            temp[j]='\0';
            temp[j]=mapArray[y_pos][x_pos].desc[i*108+j];
          
        }
        SetTextColor(temp);
        
        
        
    }
}

/*处理游戏*/

void ProcessGameMenu(int keynumn){
    
    switch (keynum) {
        case 49:   //游戏菜单1 显示玩家资料
            ShowPlayerInfo();
            break;
        case 50:   //游戏菜单2
            ShowMosters();
            break;
        case 51:   //游戏菜单3
            
            break;
        case 52:   //游戏菜单4
            
            break;
            
        default:
            break;
    }
    
}

/* 显示玩家个人资料*/
void ShowPlayerInfo(){
    //1.清除信息窗消息
    Clear(MARGIN_X+1,MAP_END_LINE,INFORMATION_HEIGHT);
    
    //2. 显示玩家资料
   
    

    
    
    SetPosition(MARGIN_X+20, MAP_END_LINE);
    SetTextColor("《");
    SetTextColorYellow(currentPlayer->name);
    SetTextColor("》");
    SetTextColor("大侠你的资料如下");
    
   
    SetPosition(MARGIN_X+2, MAP_END_LINE+1);
    SetTextColor("等级:");
    SetIntColorYellow(currentPlayer->level);
    SetPosition(MARGIN_X+12, MAP_END_LINE+1);
    SetTextColor("血量:");
    SetIntColorYellow(currentPlayer->hp);
    SetPosition(MARGIN_X+27, MAP_END_LINE+1);
    SetTextColor("经验值:");
    SetIntColorYellow(currentPlayer->exp);
    SetPosition(MARGIN_X+37, MAP_END_LINE+1);
    SetTextColor("内力:");
    SetIntColorYellow(currentPlayer->mp);
    
    SetPosition(MARGIN_X+2, MAP_END_LINE+2);
    
    SetTextColor("当前武器:");
    SetTextColorYellow(currentPlayer->weapon.name);
    printf("\033[33m(%d/%d)\033[0m",currentPlayer->weapon.minAttack,currentPlayer->weapon.maxAttack);
}


/*在信息界面显示 当前地图怪物资料*/
void ShowMosters(){
    //1.清除信息窗消息
    Clear(MARGIN_X+1,MAP_END_LINE,INFORMATION_HEIGHT);
    //2.显示怪物信息
    
   
    //怪物总数
    int monsterCount=sizeof(Monsters)/sizeof(Monster);
    //当前地图怪物总数
    int currentMapMonsterCount=0;
    
    int currentMapMonsterIndexs[INFORMATION_HEIGHT-1];
    
    int i;
    for(i=0;i<monsterCount;i++){
        if((Monsters+i)->coord.x==x_pos&&(Monsters+i)->coord.y==y_pos&&(Monsters+i)->state!=0){  //查找当前地图活着的怪物
            currentMapMonsterIndexs[currentMapMonsterCount++]=i;
            if(currentMapMonsterCount==INFORMATION_HEIGHT-1)
                break;
            
            
        }
        
        
    }
    
    if(currentMapMonsterCount<=0){
        SetPosition(MARGIN_X+20, MAP_END_LINE);
        SetTextColor("当前地图很和平，没有怪物！！");
    }
    else{
        
        
        SetPosition(MARGIN_X+20, MAP_END_LINE);
        SetTextColor("当前地图怪物概况:");
        for(int j=0;j<currentMapMonsterCount;j++){
            
            
            SetPosition(MARGIN_X+2, MAP_END_LINE+j+1);
            
            
            printf("\033[32m怪物%d:%s(怪物级别:%d)\033[0m",j+1,(Monsters+currentMapMonsterIndexs[j])->name,(Monsters+currentMapMonsterIndexs[j])->level);
            
        }
    }
  
    
    
}








