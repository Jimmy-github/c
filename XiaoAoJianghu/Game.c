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

#include "CharPicture.h"

extern  int x_pos,y_pos;

/*根据不同等级别对于玩家攻击力、防御力、内力、血量*/

char * levelNames[]={"乳臭未干","初出茅庐","粗通皮毛","青年才俊","略有小成","心领神会","出类拔萃","所向无敌","天人合一"};

int level_exp[]={0,50,100,200,400,600,800,1000,1200};

int level_att[]={1,5,10,15,20,25,30,35,40};

int level_diff[]={1,2,3,4,5,6,7,8,9};

int level_hp[]={100,200,300,400,500,600,700,800,900};

int level_mp_add[]={1,2,3,4,5,6,7,8,9};


Player Players[]={
    {.id=9527,.name="幸运的绛优",.pass="123456",.level=1,.exp=0,.hp=80,.mp=1,.gold=500,.att=1,.diff=1,.coord.x=3,.coord.y=1},
    {.id=9528,.name="哈哈哈",.pass="123456",.level=1,.exp=0,.hp=100,.mp=1,.gold=0,.att=1,.diff=1,.coord.x=2,.coord.y=0},
};

Monster Monsters[]={
    
    {.id=1,.name="刘正风",.level=1,.hp=20,.att=10,.diff=1,.minMoney=10,.maxMoney=20,.exp=30,.mp=1,.state=1,.coord.x=0,.coord.y=0},
    {.id=2,.name="田伯光",.level=2,.hp=40,.att=13,.diff=2,.minMoney=20,.maxMoney=40,.exp=20,.mp=1,.state=1,.coord.x=1,.coord.y=0},
    {.id=3,.name="岳灵珊",.level=2,.hp=60,.att=13,.diff=2,.minMoney=20,.maxMoney=40,.exp=200,.mp=1,.state=1,.coord.x=0,.coord.y=0},
    {.id=4,.name="习大大",.level=3,.hp=80,.att=14,.diff=4,.minMoney=30,.maxMoney=60,.exp=50,.mp=1,.state=1,.coord.x=1,.coord.y=0},
    {.id=5,.name="林平之",.level=4,.hp=100,.att=16,.diff=8,.minMoney=40,.maxMoney=80,.exp=80,.mp=2,.state=1,.coord.x=0,.coord.y=0},
    {.id=6,.name="虚竹",.level=5,.hp=130,.att=18,.diff=16,.minMoney=50,.maxMoney=100,.exp=100,.mp=3,.state=1,.coord.x=1,.coord.y=0},
    {.id=7,.name="风清扬",.level=6,.hp=150,.att=20,.diff=32,.minMoney=60,.maxMoney=120,.exp=300,.mp=4,.state=1,.coord.x=0,.coord.y=0}
    
    
};




Prop propArrary[]={
    {.id=1,.name="帝皇天烈剑1",.level=1,.stock=5,.price=50,.type=Weapon,.minAttack=1,.maxAttack=3,.desc="上古三皇五帝用过的剑"},
    {.id=2,.name="荆棘之甲1",.level=1,.stock=5,.price=50,.type=Armor,.minDefence=1,.maxDefence=2,.desc="取日月之精华，反弹厉害"},
    {.id=3,.name="玉液琼浆1",.level=1,.stock=5,.price=50,.type=Con,.minPower=20,.maxPower=25,.desc="蟠桃会上御用饮品"},
    
    {.id=1,.name="帝皇天烈剑2",.level=1,.stock=5,.price=50,.type=Weapon,.minAttack=1,.maxAttack=3,.desc="上古三皇五帝用过的剑"},
    {.id=2,.name="荆棘之甲2",.level=1,.stock=5,.price=50,.type=Armor,.minDefence=1,.maxDefence=2,.desc="取日月之精华，反弹厉害"},
    {.id=3,.name="玉液琼浆2",.level=1,.stock=5,.price=50,.type=Con,.minPower=20,.maxPower=25,.desc="蟠桃会上御用饮品"},
    
    {.id=1,.name="帝皇天烈剑3",.level=1,.stock=5,.price=50,.type=Weapon,.minAttack=1,.maxAttack=3,.desc="上古三皇五帝用过的剑"},
    {.id=2,.name="荆棘之甲3",.level=1,.stock=5,.price=50,.type=Armor,.minDefence=1,.maxDefence=2,.desc="取日月之精华，反弹厉害"},
    {.id=3,.name="玉液琼浆3",.level=1,.stock=5,.price=50,.type=Con,.minPower=20,.maxPower=25,.desc="蟠桃会上御用饮品"},
    
    {.id=1,.name="帝皇天烈剑4",.level=1,.stock=5,.price=50,.type=Weapon,.minAttack=1,.maxAttack=3,.desc="上古三皇五帝用过的剑"},
    {.id=2,.name="荆棘之甲4",.level=1,.stock=5,.price=50,.type=Armor,.minDefence=10,.maxDefence=13,.desc="取日月之精华，反弹厉害"},
    {.id=3,.name="玉液琼浆4",.level=1,.stock=5,.price=50,.type=Con,.minPower=20,.maxPower=25,.desc="蟠桃会上御用饮品"},
    
    {.id=1,.name="帝皇天烈剑5",.level=1,.stock=5,.price=50,.type=Weapon,.minAttack=60,.maxAttack=80,.desc="上古三皇五帝用过的剑"},
    {.id=2,.name="荆棘之甲5",.level=1,.stock=5,.price=50,.type=Armor,.minDefence=10,.maxDefence=13,.desc="取日月之精华，反弹厉害"},
    {.id=3,.name="玉液琼浆5",.level=1,.stock=5,.price=50,.type=Con,.minPower=20,.maxPower=25,.desc="蟠桃会上御用饮品"},
    
};



Map mapArray[8][8]={
    {
        {1,"少林寺",1,{0,0},"少林武功以外功见长，兼以易筋经、金刚经等强力心法为辅，防御力极强。团战时他们往往是站在队伍的最前方。"},
        {1,"日月神教",1,{1,0},"日月神教教主为东方不败，所使武器为日月双刃，必要时候会变成带有锁链的链刃，远近都可攻击。日月拥有大量的摔投技能，并且有突击能力，所以在单人pk和团战中可以创造出很多很好的战术。"},
        {1,"武当派",1,{2,0},"武当派内力雄厚，同时擅长的沉重玄铁剑以外功见长，可谓内外兼修。另外，八卦阵还能大范围提高攻击力和防御力，而远距离御剑术则可快速突进，使其在团战中拥有很强控制能力。"},
        {1,"中岳嵩山",1,{3,0},"左冷禅人品坏得没得说，不过这门派武功还是过的去的吧"},
        {1,"东岳泰山 ",1,{4,0},"(牛鼻子老道） 天门道长 正气凛然，嫉恶如仇，但脾气暴躁，性子刚烈，缺乏应变能力。"},
        {1,"西岳华山",1,{5,0},"华山剑法整体轻灵飘逸，机巧快捷，出招速度奇快，常常奇招迭出，令敌人猝不及防。他能够快速对敌人造成高爆发性的伤害，在团队中常常扮演着突进的角色。"},
        {1,"南岳衡山",1,{6,0},"衡山派为五岳剑派之一，门人皆精通音律，均将长短剑藏于琴中。长短剑，一长一短，以近战为主，辅以远攻，可对敌人造成远近不同的伤害。他们行动迅捷，速度极快，可在敌人眼中留下残影，令其迷惑。"},
        {1,"北岳恒山",1,{7,0},"恒山派为五岳剑派之一，创始人为佛门中人，颇有佛学渊源，弟子也大多数为尼姑，但却并不排除男性和俗家弟子。恒山派内力雄厚，能够很好的保护自己，加上绵密严谨的剑法和犀利的当身技，能在守御的同时制造出强大的爆发力。"}
    },
    {
        {1,"五仙",1,{0,1},"五仙教，起源于苗疆腹地，是日月神教的支教，教众皆为美艳女子。五仙弟子以软鞭为武器，鞭法阴柔狠辣，天下一绝。她们奉蛇、蜈蚣、蝎子、蜘蛛和蟾 蜍为尊，又爱与毒虫为伍，擅长蛊毒之术，因此外人称之为“五毒教”，江湖中人因此避而远之。"},
        {1,"逍遥",1,{1,1},"逍遥派，传承自道家，由武学奇才逍遥子所创，是武林中赫赫有名的门派。门下弟子稀少，但个个俊朗不凡。逍遥派手执铁扇，攻击可近可远，近为掌远为扇。他们内力较厚，能够将水汽冻结成冰，所以大部分远程技能都会有冰冻效果，在团队中往往能够成为最好的控制者。"},
        {1,"唐门",1,{2,1},"唐门是纯远程攻击门派，门人手持双枪火炮，射击精准、快速、密集。更是配合暗器和陷阱独霸江湖，在团队混战中常常能十米外快速制敌。但他们也因为主攻攻击，而往往疏忽了自身的防御。"},
        {1,"峨眉",1,{3,1},"峨眉派由先秦宗师司徒玄空所创，弟子以道姑为主，也接受男子。峨眉派武功介于少林阳刚与武当阴柔之间，亦柔亦刚，内外相重，长短并用且攻防兼备，在团队中辅助队友尤其得力。"},
        {1,"林远图",1,{4,1},"福建林远图以七十二路辟邪剑法称雄武林，创立福威漂局，驰骋江湖。远图死后，子孙无能，四方豪杰觊觎辟邪剑谱，纷至沓来。总镖头林震南一门被青城派屠戮殆尽。遗孤林平之拜投华山派掌门君子剑岳不群门下，一心学艺报仇。"},
        {1,"令狐冲",1,{5,1},"华山派长徒令狐冲自幼失怙，与不群独女岳灵珊青梅竹马，情好甚笃，平之入门，灵珊乃移情于林。令狐失恋，又以豪放不羁，违反门规，被罚思过崖面壁一载，无意间得窥崖后暗洞中石刻，尽悉五岳剑派剑术秘诀，后蒙华山剑宗前辈——隐士风清杨传授独孤九剑，从此剑术通神。"},
        {1,"东方不败",1,{6,1},"东方不败武功更是骇人听闻，任我行，令狐冲，向问天，他们任何一人的武功在江湖上都是罕逢敌手的，但在东方不败面前都成了小儿科，集三人之力也难以与东方一人抗衡。虽然他因为修炼《葵花宝典》变了性，但就算作为女人，最后就是那么死了，也是为情所困，仍让人感动。"},
        {1,"任我行",1,{7,1},"任我行也是一个呼风唤雨的大人物，任日月神教教主时威风凛凛，武林侧目，就算被囚12年，照样英雄不减当年，一逃脱就引起正邪各方的恐慌。他在少林寺对天下群雄的评介，关于自己最佩服和最不佩服的三个人的演说，充分表露了他纵横捭阖眼高于顶的英雄豪气，同时也说明他是非曲直分明，并不目空一切妄自尊大，而他的敬宁女侠鄙岳掌门之举，更使我们对他好感倍增。"}
    },
    {
        {1,"宁中则",1,{0,2},"“华山女侠宁中则”，她是当之无愧的女侠。宁女侠是最理解最爱令狐冲的人，说她是令狐冲的亲娘一点也不勉强，她又是华山派的灵魂，她对华山派，对丈夫，对女儿，对令狐冲，对林平之，对其他华山众弟子，都是一样的爱，一样的维护，可以说一切的重担全压在了她一个人肩上，当这一切都破灭时，除了用死来维护自己的尊严外，她实在是别无选择。"},
        {1,"定闲师太",1,{1,2},"她为人正直，刚正不阿，富有远见卓识，很早就看出了左冷蝉的阴谋，并坚决与之抗争，当令狐冲要率领群雄围攻少林寺时，她挺身而出为双方斡旋，对令狐冲的不规行为虽不很理解却能辩证地看待他并为他向岳不群说情，就是在生命的最后一刻她还保持清醒，坚持要令狐冲接任恒山掌门，而且至死也不说出杀死自己的凶手的名字，真的是一位令人敬重的女中豪杰"},
        {1,"方正大师",1,{2,2},"少林掌门"},
        {1,"冲虚道长",1,{3,2},"武当掌门"},
        {1,"岳不群",1,{4,2},"卑劣行径大家都有目共睹"},
        {1,"林平之",1,{5,2},"可耻人格使我作呕"},
        {1,"左冷蝉",1,{6,2},"左大掌门苦心经营数十载，就是为了合并五岳剑派，为了做五岳派掌门，为了与少林武当鼎足成之势， 为了完成统一武林成就霸业，他做了许多昧良心的事，他搞坏了自己的名声，他得罪了许多人，好不容易并派成功，却突然杀出个岳不群，不仅抢去了他苦苦追求的掌门之位，还弄瞎了他的眼睛，他可真是生不如死啊！"},
        {1,"余沧海",1,{7,2},"余沧海真不愧是左冷蝉的难兄难弟，为了得到《避邪剑谱》，先是独生子莫名其妙死在林平之剑下，接着是爱徒一个个的离他而去，最后还是让岳不群捷足先登，控制了林平之，得到了剑谱，而他自己呢，在几乎变成了疯子的林平之追杀戏耍之下，也是生不如死。"}
    },
    {
        {1,"刘正风",1,{0,3},"可以说不是武林中人，而是音乐大师，不仅是由于他们创作了惊世名曲《笑傲江湖》，还为这部作品献身为这部作品找到了传入，而且是因为他们把音乐看得比其他任何事物都重要，把音乐当成自己人生的全部追求和意义。"},
        {1,"曲洋",1,{1,3},"谱写的《笑傲江湖曲》为全书奠定了根基，发展了情节，拔高了格调，但他们两人实质上却是不属于这部书，不管是性情洒脱豪放不羁的令狐冲，还是音乐细胞丰厚的任盈盈黄钟公莫大先生绿竹翁，与他们两人相比之下，其差距是一目了然的。"},
        {1,"黄钟公",1,{2,3},"黄钟公是“江南四友”的老大，也的确有老大的威严和气度，他是真正的艺术痴迷者，为了专心自己的爱好特意避开纷争在梅庄过着半隐居的生活，如果不是令狐冲被向问天骗来梅庄救任我行，也许他可以在平静的日子中过完自己的艺术人生。"},
        {1,"莫大先生",1,{3,3},"莫大先生是衡山派掌门，他在师弟刘正风被嵩山派灭门时不敢出来维护，这使人多少有些遗憾，但考虑到他的身份和当时的形势，可以表示理解。他的急公好义，他对嵩山派的无畏反抗，他帮令狐冲秘密除去费彬，以及他在暗中的一些活动，也足以证明他是一位真正的武林前辈。全书结尾，他在令狐冲新婚之夜窗外拍琴祝贺，更使人觉得他真是位爱惜后辈的前辈名宿。"},
        {1,"风清扬",1,{4,3},"几乎都没来处没去处，在书中如神龙见首不见尾。令狐冲在思过崖练剑，风清扬突然出来指点，又毫无根据的教了他绝世剑法“独孤九剑”，然后又莫名其妙的消失了，关于他的身世，令狐冲后来也断断续续的知道了一些，但无论是对令狐冲本人还是广大读者来说，这个人始终是个谜一样的人物。"},
        {1,"绿竹翁",1,{5,3},"绿竹翁更是个神秘之极的人，在洛阳令狐冲去见任盈盈鉴定曲谱时，任盈盈身边就有了这么一个莫名其妙的“竹贤侄”，他在洛阳呆了许多年，有一手好竹艺，懂音律，武功高强，他到底是谁，我们连猜的思路都没有，而任盈盈离开洛阳时绿竹翁没一起走，他是否任留在那呢？他最后怎么样？也许金庸本人都不清楚。"},
        {1,"曲非烟",1,{6,3},"曲非烟是个很可爱的小姑娘，她死得毫无痛苦毫无反抗，谁叫她是曲洋的小孙女呢，谁叫她武功那么差呢，谁叫她要紧跟在曲洋身边呢。从她身上我们看到了小生命的脆弱，看到了命运的无情"},
        {1,"天门道人",1,{7,3},"天门道人千不该万不该当泰山派掌门，更不该那么冲动，被人轻巧的一激，掌门之位就轻易让出，真亏他还当了那么久活了那么多年。"}
    },
    {{1,"向问天",1,{0,4},"也许不是什么好人更不是大英雄大豪杰，但他们都非常豪爽非常洒脱，他们有情有义有血有肉，他们是真汉子！"},
        {1,"田伯光",1,{1,4},"有情有义有血有肉，他们是真汉子"},
        {1,"仪琳",1,{2,4},"其实尼姑也并非不可嫁人，但仪琳是个既善良又完美主义的女孩子，她不愿夺人所爱，也不想与人分享心上人的爱，因而，她只有默默地为心爱的人祝福"},
        {1,"岳灵珊",1,{3,4},"从本性上说，她跟令狐冲是矛盾的，如果真的结合在一起，不会很幸福的，因此当更与她性味相投的林平之出现后，她就很自然的移情别恋了，我们可以看不起她对爱情的不坚贞，但我们也要尊重她追求自身幸福的权利和自由。"},
        {1,"令狐冲",1,{4,4},"令狐冲就算不是大侠客大英雄大豪杰，但也不是卑鄙小人无赖混混，也算得上是个男子汉大丈夫，他生性玩劣，豪放洒脱，不拘小节，为人仗义"},
        {1,"任盈盈",1,{5,4},"任盈盈无疑也是一个为情不惜付出一切的好姑娘，为了令狐冲，她甘愿在少林寺思过十年，甘愿忤逆自己12年不见的父亲，甘愿放弃日月教教主之位，她的牺牲也许只有她本人才觉得值得。他们的最终结合，在很大程度上是双方的迁就，甚而至于有点政治婚姻的意味在内，因而就不那么感人了。"},
        {1,"昆仑",1,{6,4},"这里充满了西域文化！"},
        {1,"峨眉",1,{7,4},"这里充满了西域文化！"}
    },
    {
        {1,"丐帮",1,{0,5},"这里充满了西域文化！"},
        {1,"点苍",1,{1,5},"这里充满了西域文化！"},
        {1,"崆峒",1,{2,5},"这里充满了西域文化！"},
        {1,"青城",1,{3,5},"这里充满了西域文化！"},
        {1,"东海海沙",1,{4,5},"这里充满了西域文化！"},
        {1,"六合门",1,{5,5},"这里充满了西域文化！"},
        {1,"金刀门",1,{6,5},"这里充满了西域文化！"},
        {1,"八卦刀",1,{7,5},"这里充满了西域文化！"}
    },
    {
        {1,"梅庄",1,{0,6},"这里充满了西域文化！"},
        {1,"刀",1,{0,6},"这里充满了西域文化！"},
        {1,"枪",1,{2,6},"这里充满了西域文化！"},
        {1,"剑",1,{3,6},"这里充满了西域文化！"},
        {1,"戟",1,{4,6},"这里充满了西域文化！"},
        {1,"斧",1,{5,6},"这里充满了西域文化！"},
        {1,"钺",1,{6,6},"这里充满了西域文化！"},
        {1,"钩",1,{7,6},"这里充满了西域文化！"}
    },
    {
        {1,"叉",1,{0,7},"这里充满了西域文化！"},
        {1,"鞭",1,{1,7},"这里充满了西域文化！"},
        {1,"锏",1,{2,7},"这里充满了西域文化！"},
        {1,"锤",1,{3,7},"这里充满了西域文化！"},
        {1,"抓",1,{4,7},"这里充满了西域文化！"},
        {1,"镋",1,{5,7},"这里充满了西域文化！"},
        {1,"棍",1,{6,7},"这里充满了西域文化！"},
        {1,"槊",1,{7,7},"这里充满了西域文化！"}
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
    {.id=1,.name="少林派",.type="正派",.coord.x=0,.coord.y=0,.isOpen=1,.desc="武学泰斗，少林正宗"},
    {.id=2,.name="武当派",.type="正派",.coord.x=2,.coord.y=0,.isOpen=1,.desc="与少林齐名"},
    {.id=3,.name="恒山派",.type="正派",.coord.x=7,.coord.y=0,.isOpen=1,.desc="与少林齐名"},
    {.id=4,.name="日月神教",.type="邪派",.coord.x=1,.coord.y=0,.isOpen=1,.desc="与少林齐名"},
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
        printf("%d\t%s\t%d\t\n",propArrary[i].id,propArrary[i].name,propArrary[i].price);
        
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
void ShowMainMenu(){
    
    
    
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
            BuyProp();
            
            break;
        case 53:   //游戏菜单5 紧急治疗
            SaveLife();
            break;
        case 54:   //游戏菜单6 彩蛋
            ShowEasterEgg();
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
    
    printf("\033[33m(%d/%d)\033[0m",currentPlayer->hp,level_hp[currentPlayer->level-1]);
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
    
    SetPosition(MARGIN_X, INFO_END_LINE-1);
    SetTextColor(SEP);
    
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
        SetTextColor("血量:");  printf("\033[33m(%d/%d)\033[0m",currentPlayer->hp,level_hp[currentPlayer->level-1]);printf("      ");
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
        SetTextColor("血量:");  printf("\033[33m(%d/%d)\033[0m",currentPlayer->hp,level_hp[currentPlayer->level-1]); printf("      ");
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, INFO_END_LINE+10);
        
        SetTextColorRedBold(currentPlayer->name);
        
        SetTextColor("在战斗中死亡");
        
    }
    else if(moster->hp<=0){
        
        moster->state=0;
        moster->hp=0;
        
        SetPosition(MARGIN_X+HALF_WIDTH, INFO_END_LINE+5);
        SetTextColor("血量:");  SetIntColorYellow(moster->hp);  printf("      ");
        
        
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

/*买装备*/
void BuyProp(){
    
    ShowPropStore();
}

/*显示装备商店*/
void ShowPropStore(){
    
    //清除无用行
    
    
    
    ClearLine(MARGIN_X,MAP_END_LINE,MAIN_MENU_HEIGHT+INFORMATION_HEIGHT);
    
    //创建装备商店
    
    
    
    int i;
    for (i=0; i<STORE_FIELD; i++) {
        
        SetPosition(MARGIN_X, MAP_END_LINE+i);
        SetTextColor("|");
        
        SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+i);
        SetTextColor("|");
        
        
        
    }
    
    SetPosition(MARGIN_X, MAP_END_LINE+i);
    SetTextColor(SEP);
    
    
    
    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
    SetTextColorBold("欢迎来到武器库，请选购您心仪的武器");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+2);
    
    SetTextColor("编号");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+6, MAP_END_LINE+2);
    
    SetTextColor("名称");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+20, MAP_END_LINE+2);
    
    SetTextColor("级别");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+28, MAP_END_LINE+2);
    
    SetTextColor("类型");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+38, MAP_END_LINE+2);
    SetTextColor("金币");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+48, MAP_END_LINE+2);
    SetTextColor("库存");
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+56, MAP_END_LINE+2);
    SetTextColor("作用");
    
    
    
    
    
    PROP_STORE_GET_CURSOR=1;
    //将光标定位到信息框，让用户输入打怪编号
    
    
    while(PROP_STORE_GET_CURSOR){
        
        int prop_num=sizeof(propArrary)/sizeof(Prop);
        
        int weapon_store_count=0;
        int  props_index[9];
        
        
        
        for(int i=0;i<prop_num;i++){
            
            if(propArrary[i].type==Weapon||propArrary[i].type==Armor){
                
                
                
                
                props_index[weapon_store_count++]=i;
                
                if(weapon_store_count==9){
                    break;
                }
                
                
            }
        }
        
        for(int i=0;i<weapon_store_count;i++){
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+3+i);
            SetIntColorYellow(i+1);
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+28, MAP_END_LINE+3+i);
            
            
            
            if(propArrary[props_index[i]].type==Weapon){
                
                
                SetTextColorYellow("武器");
                
                SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+56, MAP_END_LINE+3+i);
                printf("\033[33m攻击提升%d-%d\033[0m",propArrary[props_index[i]].minAttack,propArrary[props_index[i]].maxAttack);
                
            }else if(propArrary[props_index[i]].type==Armor){
                
                
                SetTextColorYellow("防具");
                SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+56, MAP_END_LINE+3+i);
                printf("\033[33m防御提升%d-%d\033[0m",propArrary[props_index[i]].minDefence,propArrary[props_index[i]].maxDefence);
                
            }
            
            
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+6, MAP_END_LINE+3+i);
            
            SetTextColorYellow(propArrary[props_index[i]].name);
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+20, MAP_END_LINE+3+i);
            
            SetIntColorYellow(propArrary[props_index[i]].level);
            
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+38, MAP_END_LINE+3+i);
            SetIntColorYellow(propArrary[props_index[i]].price);
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+48, MAP_END_LINE+3+i);
            SetIntColorYellow(propArrary[props_index[i]].stock);
            
        }
        
        
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-2);
        
        printf("\033[K");
        
        SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+STORE_FIELD-2);
        SetTextColor("|");
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-2);
        SetTextColorBold("请输入要购买的武器编号(按0返回):");
        
        
        key= getInputKey();
        
        
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-1);
        printf("\033[K");
        
        SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+STORE_FIELD-1);
        SetTextColor("|");
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-1);
        
        keynum=key;
        
        keynum=keynum-48;
        
        if(keynum>=1&&keynum<weapon_store_count+1){
            
            if(currentPlayer->gold>=propArrary[props_index[keynum-1]].price){
                if(propArrary[props_index[keynum-1]].type==Weapon){
                    
                    currentPlayer->weapon=propArrary[props_index[keynum-1]];
                    
                }else if(propArrary[props_index[keynum-1]].type==Armor){
                    currentPlayer->armor=propArrary[props_index[keynum-1]];
                }
                currentPlayer->gold-=propArrary[props_index[keynum-1]].price;
                SetTextColor("您购买的武器已经装备好了,可退出查看,感谢光临");
                
                propArrary[props_index[keynum-1]].stock--;
                
            }else {
                SetTextColor("您的金币不够～请选择其他武器");
            }
            
        }
        else if(keynum==0){
            SetTextColor("您选择了->");
            SetTextColorPurple("退出");
            
            PROP_STORE_GET_CURSOR=0;
            
            QuitFight();
            
            
        }else{
            
            SetTextColor("您输入的武器编号不存在哟～");
            
        }
        
        
        
    }
    
    
    
    
}

/*紧急治疗*/

void SaveLife(){
    
    //清除无用行
    
    
    
    ClearLine(MARGIN_X,MAP_END_LINE,MAIN_MENU_HEIGHT+INFORMATION_HEIGHT);
    
    //创建装备商店
    
    
    
    int i;
    for (i=0; i<STORE_FIELD; i++) {
        
        SetPosition(MARGIN_X, MAP_END_LINE+i);
        SetTextColor("|");
        
        SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+i);
        SetTextColor("|");
        
        
        
    }
    
    SetPosition(MARGIN_X, MAP_END_LINE+i);
    SetTextColor(SEP);
    
    
    
    SetPosition(MARGIN_X+TITLE_MARGIN_LEFT, MAP_END_LINE);
    SetTextColorBold("欢迎来到治疗室，请选购您适合的药品");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+2);
    
    SetTextColor("编号");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+6, MAP_END_LINE+2);
    
    SetTextColor("名称");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+20, MAP_END_LINE+2);
    
    SetTextColor("级别");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+28, MAP_END_LINE+2);
    
    SetTextColor("类型");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+38, MAP_END_LINE+2);
    SetTextColor("金币");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+48, MAP_END_LINE+2);
    SetTextColor("库存");
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+56, MAP_END_LINE+2);
    SetTextColor("作用");
    
    
    
    
    
    PROP_STORE_GET_CURSOR=1;
    //将光标定位到信息框，让用户输入打怪编号
    
    
    while(PROP_STORE_GET_CURSOR){
        
        int prop_num=sizeof(propArrary)/sizeof(Prop);
        
        int weapon_store_count=0;
        int  props_index[9];
        
        
        
        for(int i=0;i<prop_num;i++){
            
            if(propArrary[i].type==Con){
                
                
                
                
                props_index[weapon_store_count++]=i;
                
                if(weapon_store_count==9){
                    break;
                }
                
                
            }
        }
        
        for(int i=0;i<weapon_store_count;i++){
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+3+i);
            SetIntColorYellow(i+1);
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+28, MAP_END_LINE+3+i);
            
            
            
            
            
            SetTextColorYellow("药品");
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+56, MAP_END_LINE+3+i);
            printf("\033[33m血量提升%d-%d\033[0m",propArrary[props_index[i]].minPower,propArrary[props_index[i]].maxPower);
            
            
            
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+6, MAP_END_LINE+3+i);
            
            SetTextColorYellow(propArrary[props_index[i]].name);
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+20, MAP_END_LINE+3+i);
            
            SetIntColorYellow(propArrary[props_index[i]].level);
            
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+38, MAP_END_LINE+3+i);
            SetIntColorYellow(propArrary[props_index[i]].price);
            
            SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+48, MAP_END_LINE+3+i);
            SetIntColorYellow(propArrary[props_index[i]].stock);
            
        }
        
        
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-2);
        
        printf("\033[K");
        
        SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+STORE_FIELD-2);
        SetTextColor("|");
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-2);
        SetTextColorBold("请输入要购买的药品编号(按0返回):");
        
        
        key= getInputKey();
        
        
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-1);
        printf("\033[K");
        
        SetPosition(MARGIN_X+WIDTH-1, MAP_END_LINE+STORE_FIELD-1);
        SetTextColor("|");
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, MAP_END_LINE+STORE_FIELD-1);
        
        keynum=key;
        
        keynum=keynum-48;
        
        if(keynum>=1&&keynum<weapon_store_count+1){
            
            
            
            if(currentPlayer->gold>=propArrary[props_index[keynum-1]].price){
                
                
                
                currentPlayer->gold-=propArrary[props_index[keynum-1]].price;
                
                srand(time(NULL));
                
                int  add_hp=(rand()%(propArrary[props_index[keynum-1]].maxPower-propArrary[props_index[keynum-1]].minPower+1))+propArrary[props_index[keynum-1]].minPower;
                
                if((level_hp[currentPlayer->level-1]-currentPlayer->hp)>=add_hp){
                    currentPlayer->hp+=add_hp;
                    SetTextColor("您的血量提升:");
                    printf("\033[33m%d\033[0m",add_hp);
                    
                }else {
                    currentPlayer->hp=level_hp[currentPlayer->level-1];
                    SetTextColor("您的血量全部恢复，可以去战斗啦～");
                    
                }
                
                propArrary[props_index[keynum-1]].stock--;
                
                
            }else {
                SetTextColor("您的金币不够～请选择其他药品");
            }
            
        }
        else if(keynum==0){
            SetTextColor("您选择了->");
            SetTextColorPurple("退出");
            
            PROP_STORE_GET_CURSOR=0;
            
            QuitFight();
            
            
        }else{
            
            SetTextColor("您输入的药品编号不存在哟～");
            
        }
        
        
        
    }
    
    
    
    
}


/*显示彩蛋*/
void ShowEasterEgg(){
    //清除无用行
    ClearLine(MARGIN_X,START_LINE-1,MAP_END_LINE+MAIN_MENU_HEIGHT+3);
    
    EASTER_EGG_CURSOR=1;
    while(EASTER_EGG_CURSOR){
        
        CreateBeer();
        
        char mylove[]="Happy birthday although a bit late~";
        
        int len=sizeof(mylove)/sizeof(char);
        
        SetPosition(15+len, START_LINE+1);
        
        printf("\033[K");
        
        key= getInputKey();
        
        SetPosition(15, START_LINE+1);
        printf("\033[K");
        
        keynum=key;
        
        keynum=keynum-48;
        
        if(keynum==0){
            EASTER_EGG_CURSOR=0;
            ClearLine(MARGIN_X,START_LINE-1,MAP_END_LINE+MAIN_MENU_HEIGHT+3);
            
            ShowWelcome("欢迎来到笑傲江湖世界!!!\n");
            ShowMap();
            ShowInformation();
            ShowMainMenu();
            
        }
        
    }
    
}

/*首页*/

void HomePage(){
    
       ShowWelcome("欢迎来到笑傲江湖世界!!!\n");
    
    int i;
    for ( i=0; i<8; i++) {
        
        SetPosition(MARGIN_X, START_LINE+3+i);
        SetTextColor("|");
        
        
       
        SetPosition(WIDTH+MARGIN_X-1, START_LINE+3+i);
        SetTextColor("|");
        printf("\n");
        
    }
  
    
    MAP_END_LINE=START_LINE+3+i;
    SetPosition(MARGIN_X, START_LINE+3+i);
    SetTextColor(SEP);
    
    char intro[]="自从日月神教强攻华山朝阳峰夺走武林秘籍《葵花宝典》，已经过去了几十年。此时，一本传说中能化腐朽为神奇的《辟邪剑谱》重现江湖，传说得剑谱者可无敌于天下。在正邪两派的对峙中，暗流涌动，一场新的江湖风暴正在缓缓拉开帷幕……";
    
    
    int lines=strlen(intro)/108;
    
    
    char temp[108];
    
    
    for(int i=0;i<=lines;i++){
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+i+3);
        
        for(int j=0;j<108;j++){
            
            temp[j]='\0';
            temp[j]=intro[i*108+j];
           
        }
        SetTextColor(temp);
        
        
        
    }
    
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+2);
    SetTextColorYellow("1.新手注册");
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+4);
    SetTextColorYellow("2.老司机登陆");
    
    LAUNCHER_GET_CURSOR=1;
    
    input=(char *)malloc(100);
    
    while(LAUNCHER_GET_CURSOR){
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+4+2);
        
        printf("\033[K");
        

        SetTextColorBold("请输入您的选择按1（注册）按2（登录）:");
        
        
        
        
        key= getInputKey();
        
        
        
        
        
       
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+4+2);
        printf("\033[K");
        
        SetTextColorBold("请输入您的选择按1（注册）按2（登录）:");
        
        keynum=key;
        
        keynum=keynum-48;
        
        printf("%d",keynum);
        
        switch (keynum) {
                
            case 1:   //1 注册
                LAUNCHER_GET_CURSOR=0;
                Regist();
               
                break;
            case 2:   //2 登录
                 Login();
                break;
                
           default:
                break;
        }
        
        
        
    }
    
    
    
    
}

/*注册*/
void Regist(){
    
    
     ClearLine(MARGIN_X,START_LINE+3+8+2,7);
    
     SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+2);
    
     SetTextColorBold("大侠请输入您的大名:");
    
    fflush(stdin);
    scanf("%s",input);
    
    fflush(stdin);
    
    getchar();
    fflush(stdin);
    
    
   
    
    ClearLine(MARGIN_X,START_LINE+3+8+2,7);
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+2);
    
     strcpy(currentPlayer->name, input);
    
    
    printf("%s 请输入您的密码:",currentPlayer->name);
    
    fflush(stdin);
    scanf("%s",input);
    
    fflush(stdin);
    
    getchar();
    fflush(stdin);
    
    
   
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+3);
    strcpy(currentPlayer->pass, input);
    
     ClearLine(MARGIN_X,START_LINE+3+8+2,7);
    
    
    
    
    int startinput=1;
    
    while(startinput){
        
    
    
   
    
     SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+2+2);
    
   
  
    
    
    
    SetTextColor("编号");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+12, START_LINE+3+8+2+2);
    
    SetTextColor("门派");
    
    SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+24, START_LINE+3+8+2+2);
    
    SetTextColor("类型");
    
    
    
    
    for(int i=0;i<sizeof(martials)/sizeof(Martial);i++){
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+2+2+2+i);
        
        
        
        
        
        
        SetIntColorYellow(martials[i].id);
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+12, START_LINE+3+8+2+2+2+i);
        
        SetTextColorYellow(martials[i].name);
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT+24, START_LINE+3+8+2+2+2+i);
        
        SetTextColorYellow(martials[i].type);
        
    }
    
  
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+2);
        printf("%s 请输入您的门派编号:",currentPlayer->name);
        
        key= getInputKey();
        
        
        
        
        
        
        SetPosition(MARGIN_X+WORLD_MARGIN_LEFT, START_LINE+3+8+2);
        printf("%s 请输入您的门派编号:",currentPlayer->name);
        printf("\033[K");
        
   
        keynum=key;
        
        keynum=keynum-48;
        
       
        
        if(keynum<=sizeof(martials)/sizeof(Martial)&&keynum>0){
            
            currentPlayer->martial=martials[keynum-1];
            
            startinput=0;
            
            //清除无用行
            ClearLine(MARGIN_X,START_LINE-1,MAP_END_LINE+MAIN_MENU_HEIGHT+3);
            
                ShowWelcome("欢迎来到笑傲江湖世界!!!\n");
                ShowMap();
                ShowInformation();
                ShowMainMenu();
            
            
        }
        
        
  
        
    
    
    }
    
    
}

/*登录*/

void Login(){
    
    
    
}



















