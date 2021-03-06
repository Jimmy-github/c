//
//  Game.h
//  XiaoAoJianghu
//
//  Created by 张添杰 on 2017/6/25.
//  Copyright © 2017年 张添杰. All rights reserved.
//

#ifndef Game_h
#define Game_h

/*
 文件名： Game.h
 描述：用来定义游戏的一些核心结构和函数
 
 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h>

#include <unistd.h>





#define SEP  "------------------------------------------------------------------------------\n"

//界面宽度
#define WIDTH 78

#define HALF_WIDTH 39

//界面边距
#define MARGIN_X 15
#define INFORMATION_HEIGHT 9

#define MAIN_MENU_HEIGHT 20

#define TITLE_MARGIN_LEFT 27

#define WORLD_MARGIN_LEFT 4

#define BATTLT_FIELD 17

#define STORE_FIELD 17


//从第几行可是界面显示


static int START_LINE=6;

static int MAP_END_LINE;

static int INFO_END_LINE;

static int MENU_END_LINE;

//菜单窗口获得光标
static int MAPINFO_GET_CURSOR=1;

//武器商店获得光标
static int PROP_STORE_GET_CURSOR=1;

//彩蛋获得光标
static int EASTER_EGG_CURSOR=1;

//首页获得光标
static int LAUNCHER_GET_CURSOR=1;


char *input;

char key;//接受按键

int keynum;

char getInputKey();

static int x_pos,y_pos=0;   //当前地图x y坐标

/********* 游戏结构类型定义 **********/
//玩家、地图、装备、怪物、


//地图的坐标
typedef struct _coord{
    int x;
    int y;
    
}Coord;

typedef struct  _map{
    int id; //地图编号
    char name[50];//地图名称
    int minLevel;//玩家进入的最低等级
    Coord coord;//地图的坐标
    char desc[500];//地图的介绍
    
}Map;





/* 游戏道具类型枚举 武器、防具、消耗品、卡片、碎片*/
typedef enum _proptype{
    Weapon,  //
    Armor,
    Con,
    Card,
    Frag
}PropType;

/* 游戏道具 武器、防具、消耗品、卡片、碎片*/
typedef struct _prop {
    int id; //道具编号
    char name[50];//道具名称
    int level;//道具级别
    int stock;//道具库存或玩家背包中的叠加数量
    int price;//道具价格
    PropType type;//道具类型
    union{//联合  多选一
        int minAttack;//如果是武器，就对应攻击力
        int minDefence;//如果是防具，就对应防御力
        int minPower;//如果是血瓶等消耗品，就对应增加的能量值
        
    };
    union{//联合  多选一
        int maxAttack;//如果是武器，就对应攻击力
        int maxDefence;//如果是防具，就对应防御力
        int maxPower;//如果是血瓶等消耗品，就对应增加的能量值
        
    };
    char desc[200];//道具的功能描述
    
    
    
    
}Prop;


/*定义门派*/

typedef struct _martial{
    int id;
    char name[50];
    char type[30];//门派类型
    Coord coord;//总舵的坐标
    int isOpen;//门派是否开放
    char desc[1000];//门派描述
    
    
    
}Martial;


/*定义玩家对象*/

typedef struct _player{
    int id;
    char name[100];
    char pass[100];
    
    int level;//玩家级别
    int exp;//玩家经验值
    int hp;//玩家血量
    int mp;//玩家内力值
    
    int gold;//玩家金币数量
    
    int att; //玩家攻击力
    int diff;//玩家防御力
    
    Prop weapon;//玩家武器
    Prop armor;//玩家防具
    Coord coord; //玩家当前所在地图坐标
    
    Martial martial;//门派
    //背包
    
}Player;

/*定义怪物对象*/

typedef struct _monster{
    
    int id;
    char name[50];
    int level; //怪物级别
    int hp;//怪物生命值
    int att; //怪物攻击力
    int diff;//怪物防御
    int minMoney;//杀死怪物掉落最小金币
    int maxMoney;//杀死怪物掉落最大金币
    int exp;//杀死怪物玩家获得的经验值
    int mp;//杀死怪物玩家获得的内力值
    int state;//怪物当前状态， 0 怪物死 1怪物活
    //杀死怪物玩家获得的道具列表
    Coord coord; //怪物当前所在地图坐标
    
}Monster;

void Init();//初始化游戏数据
void Show();//显示全局数据

/* 显示欢迎页面*/
void ShowWelcome();
/* 显示游戏地图*/
void ShowMap();

/*显示当前地图信息*/

void ShowMapInfo();

/*首次显示地图信息*/
void ShowMapInfoFirst();
/* 刷新地图时后地图会下滑一行，所以要加1*/
void ShowMapRefresh();
/*显示游戏地图下方信息*/
void ShowInformation();
/*显示游戏主菜单*/

void ShowMainMenu();

void HideMainMenu();

/*从 x y 开始清除rowCount地图行宽度*/

void ClearContent(int x,int y,int rowCount);

void ClearLine(int x,int y,int rowCount);

/*处理游戏*/

void ProcessGameMenu(int keynum);

/* 显示玩家个人资料*/
void ShowPlayerInfo();

/*在信息界面显示 当前地图怪物资料*/
void ShowMosters();

/* 退出打怪*/
void QuitFight();
/*打怪*/
void FightMoster(Monster *moster);

/*延时函数*/
void MyDelay(int delaytime);
/*瞬间移动*/
void Move(int x,int y);
/*展示战场*/
void ShowBattlefield();
/*买装备*/
void BuyProp();
/*显示装备商店*/
void ShowPropStore();

/*紧急治疗*/

void SaveLife();


/*显示彩蛋*/
void ShowEasterEgg();

/*首页*/

void HomePage();


/*登录*/

void Login();


/*注册*/
void Regist();


#endif /* Game_h */
