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

/*根据不同等级别对于玩家攻击力、防御力、内力、血量*/

char * levelNames[]={"乳臭未干","初出茅庐","粗通皮毛","青年才俊","略有小成","心领神会","出类拔萃","所向无敌","天人合一"};

int level_exp[]={0,50,100,200,400,600,800,1000,1200};

int level_att[]={1,5,10,15,20,25,30,35,40};

int level_diff[]={1,2,3,4,5,6,7,8,9};

int level_hp[]={100,200,300,400,500,600,700,800,900};

int level_mp_add[]={1,2,3,4,5,6,7,8,9};


Player Players[]={
    {.id=9527,.name="唐伯虎",.pass="123456",.level=1,.exp=0,.hp=80,.mp=1,.gold=0,.att=1,.diff=1,.coord.x=3,.coord.y=1},
    {.id=9528,.name="祝枝山",.pass="123456",.level=1,.exp=0,.hp=80,.mp=1,.gold=0,.att=1,.diff=1,.coord.x=2,.coord.y=0},
};

Monster Monsters[]={
    
    {.id=1,.name="海绵宝宝",.level=1,.hp=20,.att=10,.diff=1,.minMoney=10,.maxMoney=20,.exp=101,.mp=1,.state=1,.coord.x=0,.coord.y=0},
    {.id=2,.name="凤姐",.level=2,.hp=40,.att=13,.diff=2,.minMoney=20,.maxMoney=40,.exp=10,.mp=1,.state=1,.coord.x=1,.coord.y=0},
    {.id=3,.name="罗永浩",.level=2,.hp=60,.att=13,.diff=2,.minMoney=20,.maxMoney=40,.exp=20,.mp=1,.state=1,.coord.x=0,.coord.y=0},
    {.id=4,.name="习大大",.level=3,.hp=80,.att=14,.diff=4,.minMoney=30,.maxMoney=60,.exp=50,.mp=1,.state=1,.coord.x=1,.coord.y=0},
    {.id=5,.name="老夫子",.level=4,.hp=100,.att=16,.diff=8,.minMoney=40,.maxMoney=80,.exp=80,.mp=2,.state=1,.coord.x=0,.coord.y=0},
    {.id=6,.name="虚竹",.level=5,.hp=130,.att=18,.diff=16,.minMoney=50,.maxMoney=100,.exp=100,.mp=3,.state=1,.coord.x=1,.coord.y=0},
    {.id=7,.name="乔峰",.level=6,.hp=150,.att=20,.diff=32,.minMoney=60,.maxMoney=120,.exp=150,.mp=4,.state=1,.coord.x=0,.coord.y=0}
    
    
};




Prop propArrary[]={
    {.id=1,.name="帝皇天烈剑",.level=1,.stock=5,.price=50,.type=Weapon,.minAttack=1,.maxAttack=3,.desc="上古三皇五帝用过的剑"},
    {.id=2,.name="荆棘之甲",.level=1,.stock=5,.price=50,.type=Armor,.minAttack=1,.maxAttack=2,.desc="取日月之精华，反弹厉害"},
    {.id=3,.name="玉液琼浆",.level=1,.stock=5,.price=50,.type=Con,.minAttack=1,.maxAttack=4,.desc="蟠桃会上御用饮品"}
  
};



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
    {{1,"擂鼓山",1,{0,4},"这里充满了西域文化！"},{1,"少林寺",1,{1,4},"这里充满了西域文化！"},
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








/*门派*/


//int id;
//char name[50];
//char type;//门派类型
//Coord coord;//总舵的坐标
//int isOpen;//门派是否开放
//char desc[1000];//门派描述
Martial martials[]={
    {.id=1,.name="少林派",.type="正派",.coord.x=1,.coord.y=4,.isOpen=1,.desc="武学泰斗，少林正宗"},
    {.id=2,.name="武当派",.type="正派",.coord.x=3,.coord.y=4,.isOpen=1,.desc="与少林齐名"}
    
};




Player *currentPlayer;
void Init(){//初始化游戏数据
    //设置当前登录玩家
    currentPlayer=Players;
    
    currentPlayer->weapon=propArrary[0];
    
    currentPlayer->armor=propArrary[1];
    
    currentPlayer->martial=martials[0];
    
    
    
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
    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, START_LINE+1);
    SetTextColorBold(text);
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
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+9*j, START_LINE+3+i);
            
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
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+9*j, START_LINE+3+i-1);
            
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
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+1+i);
        switch (i) {
            case 0:
                SetTextColorBold("游戏菜单：");
                
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
            case 5:
                SetTextColor("5.紧急治疗");
                break;
            case 6:
                SetTextColor("6.彩蛋");
                break;
                
                
            default:
                break;
        }
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+1+i);
        SetTextColor("|");
        
    }
    
    
    int margin_down=4; //命令行距离底部距离
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+i-margin_down);
    
    
    SetTextColorBold("请在这里输入您的命令:");
    
    SetPosition(MARGIN_X, INFO_END_LINE+1+i);
    SetTextColor(SEP);
    
    SetPosition(MARGIN_X+26, INFO_END_LINE+i-margin_down);
    
    
    
    
    input=(char *)malloc(100);
    
    while(1){
        
        
        
        SetPosition(MARGIN_X+26, INFO_END_LINE+i-margin_down-1);
        // printf("\033[2J"); //清屏
        
        
        
        
        
        printf("\033[K");
        // /033[K   清除从光标到行尾的内容
        
        
        /*补充 | */
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+i-margin_down-1);
        SetTextColor("|");
        SetPosition(MARGIN_X+26, INFO_END_LINE+i-margin_down-1);
        
        
        key= getInputKey();
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+i-margin_down);
        printf("\033[K");
        
        /*补充 | */
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+i-margin_down);
        SetTextColor("|");
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+i-margin_down);
        
        keynum=key;
        
        
        
        switch (keynum) {
            case 49:
                SetTextColor("您选择了->");
                SetTextColorPurple("自我欣赏");
                
                break;
            case 50:
                SetTextColor("您选择了->");
                SetTextColorPurple("查找怪物");
                
                break;
            case 51:
                SetTextColor("您选择了->");
                SetTextColorPurple("回总舵");
                break;
            case 52:
                SetTextColor("您选择了->");
                SetTextColorPurple("购买装备");
                break;
            case 53:
                SetTextColor("您选择了->");
                SetTextColorPurple("紧急治疗");
                break;
            case 54:
                SetTextColor("您选择了->");
                SetTextColorPurple("彩蛋");
                
                break;
            case -128:
                SetTextColor("您按了 "); SetTextColorWhiteBold("↑");SetTextColor("  箭头");
                if(y_pos==0){
                    y_pos=7;
                }else{
                    y_pos--;
                }
                
                ShowMapRefresh();
                
                
                break;
            case -125:
                SetTextColor("您按了 ");SetTextColorWhiteBold("→");SetTextColor("  箭头");
                if(x_pos==7){
                    x_pos=0;
                }else{
                    x_pos++;
                }
                ShowMapRefresh();
                break;
            case -127:
                SetTextColor("您按了 ");SetTextColorWhiteBold("↓");SetTextColor("  箭头");
                if(y_pos==7){
                    y_pos=0;
                }else{
                    y_pos++;
                }
                
                ShowMapRefresh();
                
                break;
            case -126:
                SetTextColor("您按了 ");SetTextColorWhiteBold("←");SetTextColor("  箭头");
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
    ClearContent(MARGIN_X+1,MAP_END_LINE,INFORMATION_HEIGHT);
    
    
    //2. 显示玩家当前所在地图信息
    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
    SetTextColorBold("玩家当前所在地图是《");
    SetTextColorBold(mapArray[y_pos][x_pos].name);
    SetTextColorBold("》");
    
    
    int lines=strlen(mapArray[y_pos][x_pos].desc)/108;
    
    
    char temp[108];
    for(int i=0;i<=lines;i++){
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+i+1);
        
        for(int j=0;j<108;j++){
            
            temp[j]='\0';
            temp[j]=mapArray[y_pos][x_pos].desc[i*108+j];
            //printf("%c",mapArray[y_pos][x_pos].desc[i*108+j]);
            
            // printf("\033[32m%c\033[0m",mapArray[y_pos][x_pos].desc[i*108+j]);
        }
        SetTextColor(temp);
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}

/*从 x y 开始清除rowCount行长度为内容行,用空格替换*/

void ClearContent(int x,int y,int rowCount){
    
    int i,j;
    for (i=0; i<rowCount; i++) {
        SetPosition(x, y+i);
        for (j=0; j<WIDTH-2; j++) {
            printf(" ");
        }
    }
}
/*从 x y 开始清除rowCount行长度为一整行,用空格替换*/
void ClearLine(int x,int y,int rowCount){
    int i,j;
    for (i=0; i<rowCount; i++) {
        SetPosition(x, y+i);
        for (j=0; j<WIDTH; j++) {
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
    ClearContent(MARGIN_X+1,MAP_END_LINE+1,INFORMATION_HEIGHT);
    
    //2. 显示玩家当前所在地图信息
    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE+1);
    SetTextColorBold("玩家当前所在地图是《");
    SetTextColorBold(mapArray[y_pos][x_pos].name);
    SetTextColorBold("》");
    
    
    int lines=strlen(mapArray[y_pos][x_pos].desc)/108;
    
    
    char temp[108];
    for(int i=0;i<=lines;i++){
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+i+1+1);
        
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
        case 50:   //游戏菜单2 打怪
            ShowMosters();
            break;
        case 51:   //游戏菜单3 瞬间移动
            Move(currentPlayer->martial.coord.x,currentPlayer->martial.coord.y);
            
            break;
        case 52:   //游戏菜单4 购买装备
            
            break;
        case 53:   //游戏菜单5 紧急治疗
            
            break;
        case 54:   //游戏菜单6 彩蛋
            
            break;
            
            
            
        default:
            break;
    }
    
}

/* 显示玩家个人资料*/
void ShowPlayerInfo(){
    //1.清除信息窗消息
    ClearContent(MARGIN_X+1,MAP_END_LINE,INFORMATION_HEIGHT);
    
    //2. 显示玩家资料
    
    
    
    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
    SetTextColorBold("《");
    SetTextColorYellow(currentPlayer->name);
    SetTextColorBold("》");
    SetTextColorBold("大侠您的资料如下");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+1);
    SetTextColor("门派:"); SetTextColorYellow(currentPlayer->martial.name);
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+2);
    SetTextColor("等级: ");
    
     printf("\033[33m%d (%s)\033[0m",currentPlayer->level,*(levelNames+(currentPlayer->level-1)));
    
    
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+3);
    SetTextColor("血量:");
    SetIntColorYellow(currentPlayer->hp);
    SetPosition(MARGIN_X+24, MAP_END_LINE+3);
    SetTextColor("经验值:");
    SetIntColorYellow(currentPlayer->exp);
    
    
    SetPosition(MARGIN_X+46, MAP_END_LINE+3);
    SetTextColor("金币:");
    SetIntColorYellow(currentPlayer->gold);
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+4);
    SetTextColor("攻击力:");
    SetIntColorYellow(currentPlayer->att);
    
    
    SetPosition(MARGIN_X+24, MAP_END_LINE+4);
    SetTextColor("防御力:");
    SetIntColorYellow(currentPlayer->diff);
    
    SetPosition(MARGIN_X+46, MAP_END_LINE+4);
    SetTextColor("内力:");
    SetIntColorYellow(currentPlayer->mp);
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+5);
    SetTextColor("当前武器:");
    SetTextColorYellow(currentPlayer->weapon.name);
    printf("\033[33m(%d/%d)\033[0m",currentPlayer->weapon.minAttack,currentPlayer->weapon.maxAttack);
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+6);
    SetTextColor("当前防具:");
    SetTextColorYellow(currentPlayer->armor.name);
    printf("\033[33m(%d/%d)\033[0m",currentPlayer->armor.minAttack,currentPlayer->armor.maxAttack);
}


/*在信息界面显示 当前地图怪物资料*/
void ShowMosters(){
 
    
    
    //1.清除信息窗消息
    ClearContent(MARGIN_X+1,MAP_END_LINE,INFORMATION_HEIGHT);
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
        SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
        SetTextColorBold("当前地图很和平，没有怪物！！");
    }
    else{
        
        
        SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
        SetTextColorBold("当前地图怪物概况");
        for(int j=0;j<currentMapMonsterCount;j++){
            
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+j+1);
            
            
            printf("\033[32m%d. \033[0m",j+1);
            
            SetTextColorYellow((Monsters+currentMapMonsterIndexs[j])->name);
            
            SetPosition(MARGIN_X+18, MAP_END_LINE+j+1);
            printf("\033[32m(怪物级别:%s)\033[0m",* (levelNames+((Monsters+currentMapMonsterIndexs[j])->level)-1));
            
        }
        
        
        HideMainMenu();
        
        MAPINFO_GET_CURSOR=1;
        //将光标定位到信息框，让用户输入打怪编号
        while(MAPINFO_GET_CURSOR){
            
          
            
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+INFORMATION_HEIGHT-2);
            
            printf("\033[K");
            
            SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+INFORMATION_HEIGHT-2);
            SetTextColor("|");
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+INFORMATION_HEIGHT-2);
            SetTextColorBold("请输入要攻击的怪物编号(按0返回):");
            
            key= getInputKey();
            
            ClearLine(MARGIN_X,INFO_END_LINE,MAIN_MENU_HEIGHT);
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+INFORMATION_HEIGHT-1);
            printf("\033[K");
            
            SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+INFORMATION_HEIGHT-1);
            SetTextColor("|");
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+INFORMATION_HEIGHT-1);
            
            keynum=key;
            
            keynum=keynum-48;
            //printf("%d,%d\n",keynum,currentMapMonsterCount);
            
            
            if(keynum>=1&&keynum<currentMapMonsterCount+1){
                
                
                
                if(currentPlayer->hp<=0){
                    SetTextColor("大侠");
                    SetTextColorYellow(currentPlayer->name);
                    SetTextColor("您的生命已到最危险的尽头，请返回，进行紧急治疗～");
                }
                else{
                    
               
                
                
                SetTextColor("您选择了打->");
                
                
                SetTextColorYellow((Monsters+currentMapMonsterIndexs[keynum-1])->name);
                
                //打怪，将怪物的状态设为0
                // (->state=0;
                FightMoster((Monsters+currentMapMonsterIndexs[keynum-1]));
                
                
                //打怪后刷新信息窗
                
                
                currentMapMonsterCount=0;
                //1.清除信息窗消息
                ClearContent(MARGIN_X+1,MAP_END_LINE,INFORMATION_HEIGHT);
                
                for(i=0;i<monsterCount;i++){
                    if((Monsters+i)->coord.x==x_pos&&(Monsters+i)->coord.y==y_pos&&(Monsters+i)->state!=0){  //查找当前地图活着的怪物
                        currentMapMonsterIndexs[currentMapMonsterCount++]=i;
                        if(currentMapMonsterCount==INFORMATION_HEIGHT-1)
                            break;
                        
                        
                    }
                    
                    
                }
                
                if(currentMapMonsterCount<=0){
                    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
                    SetTextColorBold("当前地图很和平，没有怪物！！");
                }else{
                    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
                    SetTextColorBold("当前地图怪物概况");
                    for(int j=0;j<currentMapMonsterCount;j++){
                        
                        
                        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+j+1);
                        
                        
                        printf("\033[32m%d. \033[0m",j+1);
                        
                        SetTextColorYellow((Monsters+currentMapMonsterIndexs[j])->name);
                        
                        SetPosition(MARGIN_X+18, MAP_END_LINE+j+1);
                        printf("\033[32m(怪物级别:%s)\033[0m",* (levelNames+((Monsters+currentMapMonsterIndexs[j])->level)-1));
                        
                    }
                    
                    
                }
                
                }
                
            }
            else if(keynum==0){
                SetTextColor("您选择了->");
                SetTextColorPurple("退出");
                
                MAPINFO_GET_CURSOR=0;
                QuitFight();
                
            }else{
                
                SetTextColor("您输入的怪物编号不存在哟～");
                
            }
            
            
            
            
            
        }
        
        
        
        
        
        
        //让玩家选择要pk的怪物编号，调用Fight函数
        
        
    }
    
    
    
}


/* 退出打怪*/
void QuitFight(){
    ClearLine(MARGIN_X,INFO_END_LINE,MAIN_MENU_HEIGHT);
    
    ShowMapInfo();
    
    int i;
    for (i=0; i<MAIN_MENU_HEIGHT-3; i++) {
        
        SetPosition(MARGIN_X, INFO_END_LINE+i);
        SetTextColor("|");
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+i);
        switch (i) {
            case 0:
                SetTextColorBold("游戏菜单：");
                
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
            case 5:
                SetTextColor("5.紧急治疗");
                break;
            case 6:
                SetTextColor("6.彩蛋");
                break;
            default:
                break;
        }
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+i);
        SetTextColor("|");
        
        
        
    }
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+i-2);
    
    SetTextColorBold("请在这里输入您的命令:");
    
    SetPosition(MARGIN_X, INFO_END_LINE+i);
    SetTextColor(SEP);
    
}

void HideMainMenu(){
    ClearLine(MARGIN_X,INFO_END_LINE,MAIN_MENU_HEIGHT);
    
}

/*打怪*/
void FightMoster(Monster *moster){
    
    
    
    
    srand(time(NULL));
    
    int count=0;
    //玩家和怪物互相PK
    int player_attack_prop;
    int player_defence_prop;
    
    int player_hurt;
    int  moster_hurt;
    
    ShowBattlefield();
    
    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, INFO_END_LINE);
    SetTextColorYellowBold(currentPlayer->name);
    SetTextColorRedBold("  PK  ");
    SetTextColorYellowBold(moster->name);
    
    
    
    while(1){
        count ++;
        
        
        
        
        
        player_attack_prop=(rand()%(currentPlayer->weapon.maxAttack-currentPlayer->weapon.minAttack+1))+currentPlayer->weapon.minAttack;
        
        player_defence_prop=(rand()%(currentPlayer->armor.maxDefence-currentPlayer->armor.minDefence+1))+currentPlayer->armor.minDefence+1;
        
        //玩家造成伤害=玩家武器+玩家攻击力+玩家内力-怪物防御力
        
        player_hurt=player_defence_prop+currentPlayer->att+currentPlayer->mp-moster->diff;
        
        moster_hurt =moster->att-currentPlayer->mp-player_defence_prop-currentPlayer->diff; //怪物造成伤害=怪物攻击-玩家防御-玩家防具-玩家内力；
        
        if(player_hurt<0){
            player_hurt=0;
        }
        
        if(moster_hurt<0){
            moster_hurt=0;
        }
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+3);
        SetTextColor("大侠大名:");  SetTextColorYellow(currentPlayer->name);
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+4);
        SetTextColor("级别:");  SetIntColorYellow(currentPlayer->level);
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+5);
        SetTextColor("血量:");  SetIntColorYellow(currentPlayer->hp);printf("      ");
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+6);
        SetTextColor("攻击力:");  SetIntColorYellow(currentPlayer->att);
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+7);
        SetTextColor("防御力:");  SetIntColorYellow(currentPlayer->diff);
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+8);
        SetTextColor("本轮有效伤害:");  SetIntColorYellow(player_hurt);
        
        
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+3);
        SetTextColor("怪物称号:");  SetTextColorYellow(moster->name);
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+4);
        SetTextColor("级别:");  SetIntColorYellow(moster->level);
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+5);
        SetTextColor("血量:");  SetIntColorYellow(moster->hp);printf("      ");
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+6);
        SetTextColor("攻击力:");  SetIntColorYellow(moster->att);
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+7);
        SetTextColor("防御力:");  SetIntColorYellow(moster->diff);
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+8);
        SetTextColor("本轮有效伤害:");  SetIntColorYellow(moster_hurt);
      
        
        moster->hp-=player_hurt;
        //怪物血量没了，退出pk；
        if(moster->hp<=0){
            
            
            break;
        }
        
     
      
        currentPlayer->hp-=moster_hurt;
        //玩家血量没了，退出pk；
        if(currentPlayer->hp<=0){
            
            break;
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        //printf("done");
        MyDelay(1);
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+4, INFO_END_LINE+1);
        
        SetTextColor("第");
        SetIntColorYellow(count);
        SetTextColor("回合");
        
        
        printf("%s\n","  ");
        
        
        
        
    }
    
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, 32);
    
    //printf("%d怪物%s血量剩余：%d,王家血量剩余%d;",count,moster->name,moster->hp,currentPlayer->hp);
    
    if(currentPlayer->hp<=0){
        currentPlayer->hp=0;
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+5);
        SetTextColor("血量:");  SetIntColorYellow(currentPlayer->hp); printf("      ");
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+10);
        
        SetTextColorRedBold(currentPlayer->name);
        
        SetTextColor("在战斗中死亡");
        
    }
    else if(moster->hp<=0){
        
        moster->state=0;
        moster->hp=0;
        
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+5);
        SetTextColor("血量:");   SetIntColorYellow(moster->hp); printf("      ");
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+10);
        
        SetTextColorRedBold(moster->name);
        
        SetTextColor("在战斗中死亡");
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+11);
        
        SetTextColor("大侠");SetTextColorYellow(currentPlayer->name);SetTextColor("获胜");
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+12);
        
        int gold=(rand()%(moster->maxMoney-moster->minMoney+1))+moster->minMoney;
        
        SetTextColor("得到金币:"); SetIntColorYellow(gold); SetTextColor("    经验值增加:"); SetIntColorYellow(moster->exp);
        SetTextColor("    内力值增加:"); SetIntColorYellow(moster->mp);
        
        currentPlayer->exp+=moster->exp;
        
        currentPlayer->gold+=gold;
        currentPlayer->mp+=moster->mp;
        
        int pre_level=currentPlayer->level;
       
        int i;
        for ( i=0; i<sizeof(level_exp)/sizeof(int); i++) {
            if(currentPlayer->exp<level_exp[i]){
                break;
            }
        }
        
        if(currentPlayer->level-1<i){
            currentPlayer->level=i;
            
            if(currentPlayer->level>pre_level){
                SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+14);
                
                currentPlayer->att=level_att[i];
                currentPlayer->diff=level_diff[i];
                currentPlayer->mp+=level_mp_add[i];
                
                SetTextColor("恭喜级别上升为:");SetIntColorYellow(currentPlayer->level);
                SetTextColor("    攻击力升为:");SetIntColorYellow(currentPlayer->att);
                SetTextColor("    防御力升为:");SetIntColorYellow(currentPlayer->diff);
                SetTextColor("    内力提高为:");SetIntColorYellow(currentPlayer->mp);
                SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+15);
                
                SetTextColor("由");  SetTextColorYellow(*(levelNames+(pre_level-1))); SetTextColor("-->");
                SetTextColorYellow(*(levelNames+(currentPlayer->level-1)));
                
                SetTextColor("    血量提升为:");currentPlayer->hp=level_hp[currentPlayer->level-1];
                SetIntColorYellow(currentPlayer->hp);
                SetTextColorRedBold("    恭喜恭喜!!");
                
                if(currentPlayer->level-pre_level>1){
                    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+16);
                    SetTextColorYellow("连升");
                    printf("\033[01;31m%d\033[0m",currentPlayer->level-pre_level);
                    SetTextColorYellow("级，您简直是万中无一的武学土豪，可以笑傲江湖了啦～～");
                }
                
            }
            
            
     
           
        }
        
  
    }
    
    
    
    
}





void MyDelay(int delaytime){
    time_t current_time;
    time_t start_time;
    
    
    
    time(&start_time);
    
    do {
        time(&current_time);
    } while ((current_time - start_time) < delaytime);
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, 32);
}


/*瞬间移动*/
void Move(int x,int y){
    x_pos=x;
    y_pos=y;
    
    ShowMapRefresh();
}

/*展示战场*/
void ShowBattlefield(){
    int i;
    for (i=0; i<BATTLT_FIELD; i++) {
        
        SetPosition(MARGIN_X, INFO_END_LINE+i);
        SetTextColor("|");
        
        SetPosition(MARGIN_X+WIDTH-1, INFO_END_LINE+i);
        SetTextColor("|");
        
        
        
    }
    
    SetPosition(MARGIN_X, INFO_END_LINE+i);
    SetTextColor(SEP);
}





