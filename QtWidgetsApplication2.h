    #pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include<QKeyEvent>
#include<QLabel>
#include<QMovie>
#include<QFileInfo>
#include<QTimer>
#include<stdio.h>
#include<conio.h>
#include<qsize.h>
#include<qpixmap.h>
#include<math.h>
#include<graphics.h>
#include<mmsystem.h>
#include<algorithm>
#include <iostream>
#include <chrono>
#include<Windows.h>
#include<QShortcut>
#include<qdebug.h>
#include<ctime>
#include <QProgressBar>
#include <QPixmap>
#include<mmsystem.h>
#include <QPropertyAnimation>
#pragma comment(lib,"winmm.lib")
#define gif_size 300
#define m_width 1250
#define m_height 750
#define m_speed 7.5
#define jump_speed 30.0//垂直方向的初始速度（未赋值前）
#define WIDTH 1024
#define HEIGHT 640
//#define path1 "resources/background/background1.gif"
#define path2 "resources/background/background2.gif"
#define path3 "resources/background/background3.gif"
#define path4 "resources/background/background4.gif"
#define path5 "resources/background/background5.gif"
#define path6 "resources/background/background6.gif"
#define path7 "resources/background/background7.gif"
#define path8 "resources/background/background8.gif"
#define path9 "resources/background/background9.gif"

//character1 八神庵 ChaoYOU
#define bashen_chuchang "chara_pic_or_gif/bashen/chuchang.gif"
#define bashen_zhanli "chara_pic_or_gif/bashen/zhanli.gif"
#define bashen_zhangong "chara_pic_or_gif/bashen/zhangong.gif"
#define bashen_dungong "chara_pic_or_gif/bashen/dungong.gif"
#define bashen_zhanli "chara_pic_or_gif/bashen/zhanli.gif"
#define bashen_zhitiao "chara_pic_or_gif/bashen/zhitiao.gif"
#define bashen_xietiao "chara_pic_or_gif/bashen/xietiao.gif"
#define bashen_xiadun "chara_pic_or_gif/bashen/xiadun.gif"
#define bashen_houtui "chara_pic_or_gif/bashen/houtui.gif"
#define bashen_qianjin "chara_pic_or_gif/bashen/qianjin.gif"
#define bashen_skill0 "chara_pic_or_gif/bashen/skill0.gif"
#define bashen_skill1 "chara_pic_or_gif/bashen/skill1.gif"
#define bashen_skill2 "chara_pic_or_gif/bashen/skill2.gif"
#define bashen_dunfang "chara_pic_or_gif/bashen/dunfang.gif"
#define bashen_zhanfang "chara_pic_or_gif/bashen/zhanfang.gif"
#define bashen_shanbi "chara_pic_or_gif/bashen/shanbi.gif"
#define bashen_benpao "chara_pic_or_gif/bashen/benpao.gif"
#define bashen_qishen "chara_pic_or_gif/bashen/qishen.gif"
#define bashen_jidao "chara_pic_or_gif/bashen/jidao.gif"
#define bashen_tui "chara_pic_or_gif/bashen/tui.gif"
#define bashen_shibai "chara_pic_or_gif/bashen/shibai.gif"
#define bashen_shengli "chara_pic_or_gif/bashen/shengli.gif"

//character1 八神庵 ZUO
#define bashen_chuchang1 "chara_pic_or_gif/bashen1/chuchang.gif"
#define bashen_zhanli1 "chara_pic_or_gif/bashen1/zhanli.gif"
#define bashen_zhangong1 "chara_pic_or_gif/bashen1/zhangong.gif"
#define bashen_dungong1 "chara_pic_or_gif/bashen1/dungong.gif"
#define bashen_zhanli1 "chara_pic_or_gif/bashen1/zhanli.gif"
#define bashen_zhitiao1 "chara_pic_or_gif/bashen1/zhitiao.gif"
#define bashen_xietiao1 "chara_pic_or_gif/bashen1/xietiao.gif"
#define bashen_xiadun1 "chara_pic_or_gif/bashen1/xiadun.gif"
#define bashen_houtui1 "chara_pic_or_gif/bashen1/houtui.gif"
#define bashen_qianjin1 "chara_pic_or_gif/bashen1/qianjin.gif"
#define bashen_skill01 "chara_pic_or_gif/bashen1/skill0.gif"
#define bashen_skill11 "chara_pic_or_gif/bashen1/skill1.gif"
#define bashen_skill21 "chara_pic_or_gif/bashen1/skill2.gif"
#define bashen_dunfang1 "chara_pic_or_gif/bashen1/dunfang.gif"
#define bashen_zhanfang1 "chara_pic_or_gif/bashen1/zhanfang.gif"
#define bashen_shanbi1 "chara_pic_or_gif/bashen1/shanbi.gif"
#define bashen_benpao1 "chara_pic_or_gif/bashen1/benpao.gif"
#define bashen_qishen1 "chara_pic_or_gif/bashen1/qishen.gif"
#define bashen_jidao1 "chara_pic_or_gif/bashen1/jidao.gif"
#define bashen_tui1 "chara_pic_or_gif/bashen1/tui.gif"
#define bashen_shibai1 "chara_pic_or_gif/bashen1/shibai.gif"
#define bashen_shengli1 "chara_pic_or_gif/bashen1/shengli.gif"

//character2 草薙京
#define caotijing_chuchang "chara_pic_or_gif/cao/chuchang.gif"
#define caotijing_zhangong "chara_pic_or_gif/cao/zhangong.gif"
#define caotijing_dungong "chara_pic_or_gif/cao/dungong.gif"
#define caotijing_dunfang "chara_pic_or_gif/cao/dunfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"

//character3 大蛇 YOU
#define dashe_jinchang1 "chara_pic_or_gif/dashe/jinchang.gif"
#define dashe_zhangong1 "chara_pic_or_gif/dashe/zhangong.gif"
#define dashe_zhanli1 "chara_pic_or_gif/dashe/zhanli.gif"
#define dashe_dungong1 "chara_pic_or_gif/dashe/dungong.gif"
#define dashe_zhitiao1 "chara_pic_or_gif/dashe/zhitiao.gif"
#define dashe_xietiao1 "chara_pic_or_gif/dashe/xietiao.gif"
#define dashe_houtui1 "chara_pic_or_gif/dashe/houtui.gif"
#define dashe_shanbi1 "chara_pic_or_gif/dashe/shanbi.gif"
#define dashe_skill01 "chara_pic_or_gif/dashe/skill0.gif"//黑粒子
#define dashe_skill11 "chara_pic_or_gif/dashe/skill1.gif"//破防
#define dashe_xiadun1 "chara_pic_or_gif/dashe/xiadun.png"
#define dashe_skill21 "chara_pic_or_gif/dashe/skill2.gif"//血祭 扣血加攻击
#define dashe_tui1 "chara_pic_or_gif/dashe/tui.gif"
#define dashe_qishen1 "chara_pic_or_gif/dashe/qishen.gif"
#define dashe_jidao1 "chara_pic_or_gif/dashe/jidao.gif"
#define dashe_shibai1 "chara_pic_or_gif/dashe/shibai.gif"

//大蛇 ZUO
#define dashe_jinchang "chara_pic_or_gif/dashe1/jinchang.gif"
#define dashe_zhangong "chara_pic_or_gif/dashe1/zhangong.gif"
#define dashe_zhanli "chara_pic_or_gif/dashe1/zhanli.gif"
#define dashe_dungong "chara_pic_or_gif/dashe1/dungong.gif"
#define dashe_zhitiao "chara_pic_or_gif/dashe1/zhitiao.gif"
#define dashe_xietiao "chara_pic_or_gif/dashe1/xietiao.gif"
#define dashe_houtui "chara_pic_or_gif/dashe1/houtui.gif"
#define dashe_shanbi "chara_pic_or_gif/dashe1/shanbi.gif"
#define dashe_skill0 "chara_pic_or_gif/dashe1/skill0.gif"//黑粒子
#define dashe_skill1 "chara_pic_or_gif/dashe1/skill1.gif"//破防
#define dashe_xiadun "chara_pic_or_gif/dashe1/xiadun.png"
#define dashe_skill2 "chara_pic_or_gif/dashe1/skill2.gif"//血祭 扣血加攻击
#define dashe_tui "chara_pic_or_gif/dashe1/tui.gif"
#define dashe_qishen "chara_pic_or_gif/dashe1/qishen.gif"
#define dashe_jidao "chara_pic_or_gif/dashe1/jidao.gif"
#define dashe_shibai "chara_pic_or_gif/dashe1/shibai.gif"
#define dashe_shengli "chara_pic_or_gif/dashe1/shengli.gif"



//#define Gravity 5.0//拟重力加速度
//#define max_jump_height 200
#pragma comment(lib,"winmm.lib")
enum class directions {
    none,
    left,
    right,
    up,
    upper_right,//重新定义右上 左上方向
    upper_left,
    down
};
class QtWidgetsApplication1 : public QMainWindow
{

    Q_OBJECT

public:
    void facing(int characterX, int c_characterX);

    bool choice = 2;//模式选择 默认为双人游戏
    QtWidgetsApplication1(QWidget* parent = nullptr);
    ~QtWidgetsApplication1();
    void keyPressEvent(QKeyEvent* event) override;  // 重写键盘事件处理函数

    void keyReleaseEvent(QKeyEvent* event);
    void timeOut();
    void playGif(QMovie* characterMovie);



    //从c++项目中拷贝出来的部分函数
    //利用 qt 的构造函数当作GameControl 
   // void play();
   //  play函数就是我的构造函数 
   //
    //游戏界面居中函数
    void CenterInitGraph();
    //ClearRange函数，用于清空特定区域，可以实现隐身等技能。也可以实现游戏背景的优化。
    //void clearRange(int x, int y, int width, int height);
    //界面函数
    void Interface(wchar_t* text);
    //功能选择展示函数
    void DHS_DISPLAY();

    //调整gif大小的函数
    void modifySize(QMovie* attackMovie);

    void victory();
    void fail();
private:
    bool isface = false;
    //背景函数 
    QLabel* backgroundLabel = new QLabel(this);
    Ui::QtWidgetsApplication1Class ui;

    directions direction01;//方向1 控制左右
    directions direction02;//方向2 控制上下

    QLabel* characterLabel;
    int characterX;//角色的X坐标
    int characterY;
    int characterY0;//初始y 即地面y坐标
    QTimer* moveTimer;//定时器

    //跳起定时器
    QTimer* jumpTimer;
    //下落定时器
   //QTimer* downTimer;
    QMovie* characterMovie;
    QLabel* label;

    QLabel* healthLabel;   // 血条标签
    QProgressBar* healthBar;   // 血条
    QLabel* energyLabel;   // 能量条标签
    QProgressBar* energyBar;   // 能量条
    double energyValue;   // 能量值
    double healthValue;   // 血量值

    double vy = jump_speed;
    double gravity = 2.5;
    //double jumpHeight=0;

    QMovie* attackMovie;   // 攻击动画
    QMovie* jumpMovie;//跳跃动画
    bool is6 = false;

    bool isAttacking = false;   // 是否正在攻击
    // bool isLanded = true;//判断是否落地
     //bool isJumping = false;//判断是否跳跃
     //前进动画
    QMovie* forwardMovie;
    //下蹲动画
    QMovie* crouchMovie;

    //后退动画
    QMovie* backwardMovie;

    QMovie* entranceMovie;//开场动画

    QMovie* crouchAttack;
    bool cantmove = false;   // 是否可以移动
    QMovie* skill0;//技能0
    QMovie* jump;
    bool isMove = false;
    bool iscrouch = false;
    void skillFinished() { cantmove = false; }
    // 技能动画播放完毕，可以进行其他操作
    // 恢复攻击和移动等操作
    // ...
    // 设置标志位为false，表示技能释放完成 
    QMetaObject::Connection connection;
    void showup();

    //{
    //    // 设置标志位为 true，表示正在释放技能
    //    cantmove = true;
    //    // 暂停其他动作，如攻击和移动
    //    // ...
    //    // 播放技能动画
    //    characterLabel->clear();
    //    characterLabel->setMovie(skill0);
    //    skill0->start();
    //    // 获取技能动画的帧数
    //    int totalFrames = skill0->frameCount();
    //    // 连接 frameChanged 信号到槽函数
    //    connect(skill0, &QMovie::frameChanged, this, [this, totalFrames]() {
    //        // 获取当前帧数
    //        int currentFrame = skill0->currentFrameNumber();
    //        // 判断是否达到总帧数
    //        if (currentFrame == totalFrames - 1) {
    //            // 动画播放完一遍，停止技能动画
    //            skillFinished();
    //        }
    //        });
    //}
     //周一下午修改
    QLabel* bar;
    void castSkill0();
    void castSkill1();
    void castSkill2();
    bool isskill=false;
    bool c_isskill=false;


    QMovie* skill1;
    bool boolskill0 = false;//用于判断技能1是否在释放 修复bug（）
    QMovie* skill2;
    bool boolskill2 = false;//用于判断技能2是否在释放 修复bug（）
    QMovie* dunfang;
    QMovie* zhanfang;
    bool ishit = false;
    QTimer* energyTimer;
    void updateEnergy();
    directions direction03;
    double distance;
    
    void castK();
    //攻击键检测
    //QTimer JTimer;
    //bool JPressed = false; // 记录J键是否按下
    //int JKeyPressDuration = 0; // J键按下时长
    void jatt();
    QMetaObject::Connection jconnection;
    bool atkdetc = false;
    QMovie* shanbi;
    QMovie* tui;
    QMovie* benpao;
    QMovie* qishen;
    QMovie* jidao;
   // QMovie* benpao;
    bool  isjumping = false;
    bool c_isjumping = false;
    void castL();
   // int n=0;
    bool fan = false;

    //——————****——————character02 大蛇(当前)

    directions c_direction01;//方向1 控制左右
    directions c_direction02;//方向2 控制上下
    double c_vy = jump_speed;
    QLabel* c_characterLabel;
    int c_characterX;//角色的X坐标
    int c_characterY;
    int c_characterY0;//初始y 即地面y坐标
    QTimer* c_moveTimer;//定时器
    void timeOut02();


    //跳起定时器
    QTimer* c_jumpTimer;
    //下落定时器
   //QTimer* downTimer;
    QMovie* c_characterMovie;
    // QLabel* label;

    QLabel* c_healthLabel;   // 血条标签
    QProgressBar* c_healthBar;   // 血条
    QLabel* c_energyLabel;   // 能量条标签
    QProgressBar* c_energyBar;   // 能量条
    double c_energyValue;   // 能量值
    double c_healthValue;   // 血量值


    QMovie* c_attackMovie;   // 攻击动画
    QMovie* c_jumpMovie;//跳跃动画

    bool c_isAttacking = false;   // 是否正在攻击
    // bool isLanded = true;//判断是否落地
     //bool isJumping = false;//判断是否跳跃
     //前进动画
    QMovie* c_forwardMovie;
    //下蹲动画
    QMovie* c_crouchMovie;

    //后退动画
    QMovie* c_backwardMovie;

    QMovie* c_entranceMovie;//开场动画

    QMovie* c_crouchAttack;
    bool c_cantmove = false;   // 是否可以移动
    QMovie* c_skill0;//技能0
    QMovie* c_skill1;
    QMovie* c_skill2;
    QMovie* c_jump;
    QMovie* c_dunfang;
    QMovie* c_zhanfang;
    QMovie* c_shanbi;
    bool c_ishit = false;
    bool c_isMove = false;
    bool c_iscrouch = false;
    void c_skillFinished() { c_cantmove = false; }
    // 技能动画播放完毕，可以进行其他操作
    // 恢复攻击和移动等操作
    // ...
    // 设置标志位为false，表示技能释放完成 
    QMetaObject::Connection c_connection;
    void c_castSkill0();
    void c_castSkill1();
    void c_castSkill2();
    //QMovie* c_shanbi;
    QMovie* c_tui;
    QMovie* c_benpao;
    QMovie* c_qishen;
    QMovie* c_jidao;
    void c_cast2();
    void c_cast3();
    double c_tuid;//大蛇2的踢腿
    QTimer* timer;
    bool c_isdungong=false;
    double c_dungongd = 0;
    double c_skill0d=0;
    bool c_iszhangong = false;
    double c_zhangongd = 0;
    QTimer* c_skill0t;
    //int n=0;
    void c_skill0dmove();
    //一技能的点位
    double c_skill1d=0;
    QTimer* c_skill1t;
    void c_skill1dmove();

    //bashen
    QMetaObject::Connection atkconnection;
    double skill1d;
    QTimer* skill1t;
    void skill1dmove();



    double skill0d;
    QTimer* skill0t;
    void skill0dmove();
    int skill0n = 0;

    double skill2d;
    QTimer* skill2t;
    void skill2dmove();


    bool isface1 = false;
    bool isface2 = false;
    QMovie* ENDCHARA;
    QMovie* ENDC_CHARA;
    QMovie* ENDCHARA2;
    QMovie* ENDC_CHARA2;
    void ENDC();
    void ENDC2();
    bool boolENDCHARA;
    bool boolENDC_CHARA;
    bool boolENDCHARA2;
    bool boolENDC_CHARA2;






    //——————****——————

};