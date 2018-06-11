#pragma region 头文件引用

// Windows 头文件: 
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <time.h>
//#include <dsound.h>
//#include <mmreg.h>

//#include <afxwin.h>
//#include <afxext.h>
//#include <vfw.h>
//#pragma comment(lib,"vfw32.lib")

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string.h>

// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")


//引用程序需要的其他头文件
#include <vector>
#include <math.h>


#pragma endregion

#pragma region 宏定义

//窗口相关
#define WINDOW_WIDTH	800							//窗口宽度定义的宏
#define WINDOW_HEIGHT	600							//窗口高度定义的宏
#define WINDOW_TITLE	L"【 NeoR Automata 】"	//窗口标题定义的宏
#define WINDOW_TITLEBARHEIGHT	32		//标题栏高度

//关卡选择
#define STAGE_STARTMENU			0		//开始画面的ID
#define STAGE_1					1		//第一个游戏场景的ID
#define STAGE_2					2		//第二个游戏场景的ID
#define STAGE_HELP				3		//帮助界面的ID
#define STAGE_CHOICE			4		//选关界面的ID
#define STAGE_PAUSE				5		//暂停界面的ID
#define STAGE_FAILED			6		//失败界面的ID
#define STAGE_SUCCESS			7		//成功界面的ID

//主角相关
#define HERO_SIZE_X				25		//主角的宽度
#define HERO_SIZE_Y				25		//主角的高度
#define HERO_FRAME_NUMBER		12		//主角的动画帧数量
#define HERO_HEALTH_X			50		//主角生命值图像宽度
#define HERO_HEALTH_Y			39		//主角生命值图像高度
#define HERO_ACCELERATION		0.3		//主角加速度
#define HERO_MAXSPEED			6.0		//主角最大速度
#define HERO_LOW_MAXSPEED		3.5		//主角最大速度
#define HERO_SKILL_ATTACK		1		//主角技能：近身战；右键近战:消除子弹，无视防护，击杀小兵;技能按钮ID
#define	HERO_ATTACK_WITDH		150		//主角技能：近战图像大小
#define	HERO_ATTACK_HEIGHT		150		//主角技能：近战图像大小
#define HERO_SKILL_BULLET		2		//主角技能：子弹大师；子弹遇墙反弹一次,慢速，可抵消任意子弹；不会减速；击杀小兵与陷阱仅需两发子弹;技能按钮ID
#define HERO_SKILL_STRONG		3		//主角技能：生命庇佑；生命上限提升，防护时间提升;技能按钮ID
#define HERO_SKILL_LIGHTMOVE	4		//主角技能：数据跃迁；移动到鼠标所在位置并产生短时护盾;技能按钮ID
#define HERO_BULLET_ID			100		//主角子弹ID
#define HERO_BULLET_WIDTH		16		//主角子弹宽度
#define HERO_BULLET_HEIGHT		16		//主角子弹高度
#define BULLET_V				7		//主角子弹速度
#define BULLET_V_SKILL			6		//主角技能子弹的速度
#define BULLET_COLLISION_SKILL	3		//主角技能子弹可碰撞次数
#define BULLET_COLLISION		2		//主角普通子弹可碰撞次数
#define HERO_PROTECT_SIZE		50		//主角防护罩/boss1防护罩尺寸
#define CRASH_SIZE				64		//爆炸图像尺寸

//按钮相关
////初始界面
#define BUTTON_STARTGAME			1001	//开始游戏按钮ID
#define BUTTON_STARTGAME_WIDTH		95		//开始游戏按钮宽度
#define BUTTON_STARTGAME_HEIGHT		24		//开始游戏按钮高度
#define BUTTON_TITLEGAME			1002	//游戏标题按钮ID
#define BUTTON_TITLEGAME_WIDTH		513		//游戏标题按钮宽度
#define BUTTON_TITLEGAME_HEIGHT		180		//游戏标题按钮高度
#define BUTTON_HELP					1003	//游戏帮助按钮ID
#define BUTTON_HELP_WIDTH			76		//游戏帮助按钮宽度
#define BUTTON_HELP_HEIGHT			24		//游戏帮助按钮高度
#define BUTTON_EXIT					1004	//游戏帮助按钮ID
#define BUTTON_EXIT_WIDTH			63		//游戏退出按钮宽度
#define BUTTON_EXIT_HEIGHT			23		//游戏退出按钮高度
////第一关、第二关
#define BUTTON_PAUSE				2001	//游戏暂停按钮ID
#define BUTTON_PAUSE_WIDTH			109		//游戏暂停按钮宽度
#define BUTTON_PAUSE_HEIGHT			29		//游戏暂停按钮高度
#define TRAP_WIDTH					75		//陷阱宽度
#define TRAP_1						101		//陷阱类型1：体力削减
#define TRAP_2						102		//陷阱类型2：子弹干扰，击破后产生小兵；使boss重新回到受保护状态
#define TRAP_3						103		//陷阱类型3：行动限制
#define BOSS_SIZE					45		//BOSS1图像尺寸;小兵图像尺寸
#define BOSS2_PROTECT_SIZE			128		//BOSS2防护罩尺寸
#define BOSS2_SIZE					100		//BOSS2尺寸
#define BOSS_SKILL1					1		//boss技能总览：瞬移；线性弹幕；召唤小兵；进化
#define BOSS_LIGHTMOVE				0		//boss技能：瞬移
#define BOSS_AIMED					1		//boss技能：追踪弹幕
#define BOSS_LINE2					2		//boss技能，线性弹幕补充
#define BOSS_LINE					3		//boss技能，线性弹幕
#define BOSS_RANDOM1				4		//boss技能，随机弹幕
#define BOSS_CALLING				5		//boss技能：召唤小兵
#define BOSS_SKILL2					2		//boss技能总览：瞬移，追踪弹幕；召唤小兵；快速移动
#define BOSS_MOVE					6		//boss技能：遁地
#define BOSS_AIMBULLET				7		//boss技能：跟踪子弹
#define BOSS_LINERUSH				8		//boss技能：抵消弹		
#define BOSS_RUSH					9		//boss技能：疾走
#define BOSS_BULLET_ID				101		//boss子弹与小兵兵种1、2子弹ID
#define	BOSS_AIMED_BULLET_ID		103		//boss2追踪子弹ID
#define BOSS_BULLET_SIZE			16		//boss子弹尺寸
#define BOSS_BULLET_V				3		//boss子弹移动速度
#define BOSS_HEALTH					40		//boss体力值
#define BOSS2_HEALTH				50		//boss2体力值
#define BOSS_V						1.6		//boss1移动速度
#define BOSS2_V						2.5		//boss2移动速度
#define BOSS2_MAXV					7.0		//boss2移动速度
#define BOSS_HEALTH1				31		//boss临界生命值1
#define BOSS_HEALTH2				15		//boss临界生命值2
#define BOSS_BULLET_RUSH_ID			102		//boss抵消弹ID
#define BOSS_BULLET_RUSH_SIZE		50		//boss抵消弹尺寸
#define BOSS_BULLET_RUSH_V			5		//boss抵消弹移动速度
#define ENEMY_V						2		//小兵移动速度
#define ENEMY_V2					3		//小兵移动速度
#define ENEMY_SKILL1				11		//小兵兵种1技能总览：线性弹幕，跑路；
#define ENEMY_SKILL2				12		//小兵兵种2技能总览：boss弹幕；
#define ENEMY_SIZE					45		//小兵图像尺寸
#define ENEMY_BULLET_V				3		//小兵子弹移动速度
#define ENEMY_HEALTH				4		//小兵体力值
#define ENEMY_ID1					100		//小兵自然出现
#define ENEMY_ID2					101		//小兵遵循召唤而来
#define BRICK_KIND1					1001	//砖块种类1：普通砖块
#define BRICK_KIND2					1002	//砖块种类2：可破坏砖块
#define BRICK_KIND3					1003	//砖块种类3：毁灭砖块
#define BRICK_KIND4					1004	//砖块种类4：恢复砖块
#define BRICK_SIZE					50	    //砖块尺寸
////选关界面
#define BUTTON_CHOICESTAGE1			4001	//选择第一关按钮ID
#define BUTTON_CHOICESTAGE1_WIDTH	100		//选择第一关按钮宽度
#define BUTTON_CHOICESTAGE1_HEIGHT	16		//选择第一关按钮高度
#define BUTTON_CHOICESTAGE2			4002	//选择第二关按钮ID
#define BUTTON_BACKGROUNDOFSTAGE1_WIDTH	450		//选择第一关背景故事按钮宽度
#define BUTTON_BACKGROUNDOFSTAGE1_HEIGHT	200	//选择第一关背景故事按钮高度
////暂停界面与失败界面
#define BUTTON_RETRY				3001	//重试按钮ID
#define BUTTON_RETRY_WIDTH			109		//重试按钮宽度
#define BUTTON_RETRY_HEIGHT			29		//重试按钮高度
#define BUTTON_CONTINUE				3002	//继续按钮ID
#define BUTTON_CONTINUE_WIDTH		109		//继续按钮宽度
#define BUTTON_CONTINUE_HEIGHT		29		//继续按钮高度
#define BUTTON_BACKTOTITLE			3003	//返回标题页按钮ID
#define BUTTON_BACKTOTITLE_WIDTH	109		//返回标题页按钮宽度
#define BUTTON_BACKTOTITLE_HEIGHT	29		//返回标题页按钮高度
#define BUTTON_BACKTOCHOICE			3004	//返回选择页按钮ID
#define BUTTON_BACKTOCHOICE_WIDTH	109		//返回选择页按钮宽度
#define BUTTON_BACKTOCHOICE_HEIGHT	29		//返回选择页按钮高度

//计时器
#define TIMER_GAMETIMER				1		//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		10		//默认计时器刷新间隔的毫秒数
#define HERO_BULLET_TIMER			2		//主角子弹发射计时器ID
#define HERO_BULLET_TIMER_ELAPSE	200		//主角子弹发射计时器刷新间隔毫秒数
#define HERO_BULLET_SKILL_TIMER_ELAPSE	180		//主角子弹发射计时器刷新间隔毫秒数（存在技能）
#define TIMER_TRAP					3		//地图陷阱计时器ID
#define TIMER_TRAP_ELAPSE			2000	//地图陷阱计时器刷新间隔毫秒数
#define TIMER_HERO_SKILL_LAST_ID	9		//主角主动技能近战持续时间计时器ID
#define TIMER_HERO_SKILL_LAST		50		//主角主动技能近战持续刷新间隔
#define TIMER_HERO_SKILL_CD_ID		8		//主角主动技能冷却计时器ID
#define TIMER_HERO_SKILL2_CD		6000	//主角主动技能近身战冷却
#define TIMER_HERO_SKILL3_CD		1000	//主角被动技能子弹大师冷却
#define TIMER_HERO_SKILL1_CD		4000	//主角被动技能生命庇佑冷却
#define TIMER_HERO_SKILL4_CD		2500	//主角主动技能数据跃迁冷却
#define TIMER_BOSS1					4		//bossAI专用计时器ID
#define TIMER_BOSS1_ELAPSE1			4700	//boss1分段刷新机制：动作加速
#define TIMER_BOSS1_ELAPSE2			3200	//boss1分段刷新机制：动作加速
#define TIMER_BOSS1_ELAPSE3			1500	//boss1分段刷新机制：动作加速
/*#define TIMER_BOSS2_ELAPSE			2300	//boss2刷新  */
#define TIMER_BOSS1_BULLET			5		//boss子弹发射计时器ID
#define TIMER_BOSS1_BULLET_SENDNUM	7		//boss弹幕堆叠次数
#define TIMER_BOSS1_BULLET_ELAPSE1	650		//boss子弹发射间隔时间1
#define TIMER_BOSS1_BULLET_ELAPSE2	450		//boss子弹发射间隔时间2
#define TIMER_BOSS1_BULLET_ELAPSE3	200		//boss子弹发射间隔时间3
#define TIMER_BOSS2_BULLET_ELAPSE	300		//boss2子弹发射间隔时间
#define TIMER_BOSS_PROTECT			6		//boss防护罩计时器ID
#define TIMER_BOSS_PROTECT_ELAPSE	500		//boss防护罩击碎后恢复倒计时
#define TIMER_BOSS_PROTECT_DESTROY_ELAPSE	1500	//boss防护罩破碎倒计时
#define TIMER_BOSS2_PROTECT_DESTROY_ELAPSE  2500		//boss2防护罩破碎倒计时
#define TIMER_PROTECT				7		//主角受伤后无敌计时器ID
#define TIMER_PROTECT_ELAPSE		2000	//主角受伤后无敌计时器刷新时间
#define TIMER_PROTECT_ELAPSE_SKILL1		3000	//主角受伤后无敌计时器刷新时间（技能：生命庇护）
#define TIMER_PROTECT_ELAPSE_SKILL4		500	//主角跃迁后无敌计时器刷新时间（技能：数据跃迁）
#define TIMER_ENEMY_BULLET			11		//小兵子弹发射计时器ID
#define TIMER_ENEMY_BULLET_ELAPSE	1000		//小兵子弹发射间隔时间
#define TIMER_HERO_UP			12		//英雄生命回复计时器ID
#define TIMER_HERO_UP_ELAPSE	4000		//英雄生命回复间隔时间
#define TIMER_HERO_UPJUDGE			13		//英雄生命回复判断计时器ID
#define TIMER_HERO_UPJUDGE_ELAPSE	3000		//英雄生命回复启动所需时间

#pragma endregion

#pragma region 结构体声明


struct Stage	// 场景结构体
{
	int stageID;		//场景编号
	HBITMAP background;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）
};

struct Button	// 按钮结构体
{
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度
};

struct Trap		//陷阱结构体
{
	int trapID;
	HBITMAP img;
	bool visible;
	int health;
	bool inn;	//是否在陷阱内部
	int x;
	int y;
};

struct Trick		//砖块结构体
{
	int brickID;
	HBITMAP img;
	bool visible;
	int health;
	int x;
	int y;
};
struct Hero		// 主角结构体
{
	HBITMAP img;	//图片
	int frame;		//当前显示的帧数
	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值
	int skill;      //技能选择
	bool protect;	//受伤后无敌时间
};

struct Bullet_Normal		// 子弹结构体
{
	HBITMAP img;	//图片，并作为判断子弹是否可以抵消的依据
	bool visible;	//是否需要保留
	int ID;			//发出者
	int x;			//坐标x
	int y;			//坐标y
	double v;				//总速度
	int direction_x;		//速度方向x
	int direction_y;		//速度方向y
	bool inn;		//是否在陷阱中
	int collision;		//是否发生过碰撞
};

struct Boss_Condition		// Boss结构体
{
	HBITMAP img;	//图片
	bool protect;	//是否处于保护状态
	int x;			//坐标x
	int y;			//坐标y
	double v;				//总速度
	int direction_x;		//速度方向x
	int direction_y;		//速度方向y
	int skill;				//boss种类
	int health;			//boss体力值
};

struct Enemy_Condition		// 小兵结构体
{
	HBITMAP img;	//图片
	bool protect;	//是否处于保护状态
	int x;			//坐标x
	int y;			//坐标y
	double v;				//总速度
	int direction_x;		//速度方向x
	int direction_y;		//速度方向y
	int skill;				//小兵种类
	int health;			//小兵体力值
	int ID;			//小兵如何出现：自然or召唤
};



#pragma endregion

#pragma region 窗口注册函数声明
	
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

#pragma endregion

#pragma region 事件处理函数声明
// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
// AI弹幕发射函数
void Send_Bullet(int kind, HWND hWnd);
// 鼠标右键按下事件处理函数
void RButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
// 鼠标右键松开事件处理函数
void RButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion

#pragma region 状态处理函数声明
// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);
// 添加主角函数
Hero* CreateHero(HBITMAP img, int x, int y, int health, int skill);
// 添加主角直线子弹函数声明
Bullet_Normal* CreateHeroBullet(HBITMAP img, int ID);
// 初始化场景函数
void InitStage(HWND hWnd, int stageID);
// 刷新主角状态函数
void UpdateHero(HWND hWnd);
// 计算主角的当前帧数
int GetHeroFrame(double dirX, double dirY);
// 地图陷阱函数
Trap* CreateTrap(HBITMAP img, int x, int y, int trap_id);
// 主角防护罩
void Protect_Hero(HWND hWnd);
// boss行动指南
void UpdateBoss(HWND hWnd);
//boss无敌
void Protect_Boss(HWND hWnd);
//boss无敌暂时失效
void Protect_Boss_Destroy(HWND hWnd);
// 添加boss子弹
Bullet_Normal* CreateBossBullet(HBITMAP img, int x, int y, int directx, int directy, int ID);
//子弹碰撞检测
void Bullet_Collision(HWND hWnd);
//添加小兵函数
Enemy_Condition* CreateEnemy(HBITMAP img, int x, int y, int direct_x, int direct_y, int skill, HWND hWnd, int ID);
//小兵状态更新
void UpdateEnemy(HWND hWnd);
//添加小兵子弹函数
Bullet_Normal* CreateEnemyBullet(Enemy_Condition* enemy, HBITMAP img, int directx, int directy, int ID);

#pragma endregion

#pragma region 绘图与资源加载、释放函数声明
//资源加载与初始化
BOOL Game_Load ( HWND hWnd, WPARAM wParam, LPARAM lParam);
//图形绘制
void Game_Paint(HWND hWnd);
//暂停结束后的资源清理
void pause_clear(HWND hWnd);   

#pragma endregion