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
#define jump_speed 30.0//��ֱ����ĳ�ʼ�ٶȣ�δ��ֵǰ��
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

//character1 ������ ChaoYOU
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

//character1 ������ ZUO
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

//character2 ���S��
#define caotijing_chuchang "chara_pic_or_gif/cao/chuchang.gif"
#define caotijing_zhangong "chara_pic_or_gif/cao/zhangong.gif"
#define caotijing_dungong "chara_pic_or_gif/cao/dungong.gif"
#define caotijing_dunfang "chara_pic_or_gif/cao/dunfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"
#define caotijing_zhanfang "chara_pic_or_gif/cao/zhanfang.gif"

//character3 ���� YOU
#define dashe_jinchang1 "chara_pic_or_gif/dashe/jinchang.gif"
#define dashe_zhangong1 "chara_pic_or_gif/dashe/zhangong.gif"
#define dashe_zhanli1 "chara_pic_or_gif/dashe/zhanli.gif"
#define dashe_dungong1 "chara_pic_or_gif/dashe/dungong.gif"
#define dashe_zhitiao1 "chara_pic_or_gif/dashe/zhitiao.gif"
#define dashe_xietiao1 "chara_pic_or_gif/dashe/xietiao.gif"
#define dashe_houtui1 "chara_pic_or_gif/dashe/houtui.gif"
#define dashe_shanbi1 "chara_pic_or_gif/dashe/shanbi.gif"
#define dashe_skill01 "chara_pic_or_gif/dashe/skill0.gif"//������
#define dashe_skill11 "chara_pic_or_gif/dashe/skill1.gif"//�Ʒ�
#define dashe_xiadun1 "chara_pic_or_gif/dashe/xiadun.png"
#define dashe_skill21 "chara_pic_or_gif/dashe/skill2.gif"//Ѫ�� ��Ѫ�ӹ���
#define dashe_tui1 "chara_pic_or_gif/dashe/tui.gif"
#define dashe_qishen1 "chara_pic_or_gif/dashe/qishen.gif"
#define dashe_jidao1 "chara_pic_or_gif/dashe/jidao.gif"
#define dashe_shibai1 "chara_pic_or_gif/dashe/shibai.gif"

//���� ZUO
#define dashe_jinchang "chara_pic_or_gif/dashe1/jinchang.gif"
#define dashe_zhangong "chara_pic_or_gif/dashe1/zhangong.gif"
#define dashe_zhanli "chara_pic_or_gif/dashe1/zhanli.gif"
#define dashe_dungong "chara_pic_or_gif/dashe1/dungong.gif"
#define dashe_zhitiao "chara_pic_or_gif/dashe1/zhitiao.gif"
#define dashe_xietiao "chara_pic_or_gif/dashe1/xietiao.gif"
#define dashe_houtui "chara_pic_or_gif/dashe1/houtui.gif"
#define dashe_shanbi "chara_pic_or_gif/dashe1/shanbi.gif"
#define dashe_skill0 "chara_pic_or_gif/dashe1/skill0.gif"//������
#define dashe_skill1 "chara_pic_or_gif/dashe1/skill1.gif"//�Ʒ�
#define dashe_xiadun "chara_pic_or_gif/dashe1/xiadun.png"
#define dashe_skill2 "chara_pic_or_gif/dashe1/skill2.gif"//Ѫ�� ��Ѫ�ӹ���
#define dashe_tui "chara_pic_or_gif/dashe1/tui.gif"
#define dashe_qishen "chara_pic_or_gif/dashe1/qishen.gif"
#define dashe_jidao "chara_pic_or_gif/dashe1/jidao.gif"
#define dashe_shibai "chara_pic_or_gif/dashe1/shibai.gif"
#define dashe_shengli "chara_pic_or_gif/dashe1/shengli.gif"



//#define Gravity 5.0//���������ٶ�
//#define max_jump_height 200
#pragma comment(lib,"winmm.lib")
enum class directions {
    none,
    left,
    right,
    up,
    upper_right,//���¶������� ���Ϸ���
    upper_left,
    down
};
class QtWidgetsApplication1 : public QMainWindow
{

    Q_OBJECT

public:
    void facing(int characterX, int c_characterX);

    bool choice = 2;//ģʽѡ�� Ĭ��Ϊ˫����Ϸ
    QtWidgetsApplication1(QWidget* parent = nullptr);
    ~QtWidgetsApplication1();
    void keyPressEvent(QKeyEvent* event) override;  // ��д�����¼�������

    void keyReleaseEvent(QKeyEvent* event);
    void timeOut();
    void playGif(QMovie* characterMovie);



    //��c++��Ŀ�п��������Ĳ��ֺ���
    //���� qt �Ĺ��캯������GameControl 
   // void play();
   //  play���������ҵĹ��캯�� 
   //
    //��Ϸ������к���
    void CenterInitGraph();
    //ClearRange��������������ض����򣬿���ʵ������ȼ��ܡ�Ҳ����ʵ����Ϸ�������Ż���
    //void clearRange(int x, int y, int width, int height);
    //���溯��
    void Interface(wchar_t* text);
    //����ѡ��չʾ����
    void DHS_DISPLAY();

    //����gif��С�ĺ���
    void modifySize(QMovie* attackMovie);

    void victory();
    void fail();
private:
    bool isface = false;
    //�������� 
    QLabel* backgroundLabel = new QLabel(this);
    Ui::QtWidgetsApplication1Class ui;

    directions direction01;//����1 ��������
    directions direction02;//����2 ��������

    QLabel* characterLabel;
    int characterX;//��ɫ��X����
    int characterY;
    int characterY0;//��ʼy ������y����
    QTimer* moveTimer;//��ʱ��

    //����ʱ��
    QTimer* jumpTimer;
    //���䶨ʱ��
   //QTimer* downTimer;
    QMovie* characterMovie;
    QLabel* label;

    QLabel* healthLabel;   // Ѫ����ǩ
    QProgressBar* healthBar;   // Ѫ��
    QLabel* energyLabel;   // ��������ǩ
    QProgressBar* energyBar;   // ������
    double energyValue;   // ����ֵ
    double healthValue;   // Ѫ��ֵ

    double vy = jump_speed;
    double gravity = 2.5;
    //double jumpHeight=0;

    QMovie* attackMovie;   // ��������
    QMovie* jumpMovie;//��Ծ����
    bool is6 = false;

    bool isAttacking = false;   // �Ƿ����ڹ���
    // bool isLanded = true;//�ж��Ƿ����
     //bool isJumping = false;//�ж��Ƿ���Ծ
     //ǰ������
    QMovie* forwardMovie;
    //�¶׶���
    QMovie* crouchMovie;

    //���˶���
    QMovie* backwardMovie;

    QMovie* entranceMovie;//��������

    QMovie* crouchAttack;
    bool cantmove = false;   // �Ƿ�����ƶ�
    QMovie* skill0;//����0
    QMovie* jump;
    bool isMove = false;
    bool iscrouch = false;
    void skillFinished() { cantmove = false; }
    // ���ܶ���������ϣ����Խ�����������
    // �ָ��������ƶ��Ȳ���
    // ...
    // ���ñ�־λΪfalse����ʾ�����ͷ���� 
    QMetaObject::Connection connection;
    void showup();

    //{
    //    // ���ñ�־λΪ true����ʾ�����ͷż���
    //    cantmove = true;
    //    // ��ͣ�����������繥�����ƶ�
    //    // ...
    //    // ���ż��ܶ���
    //    characterLabel->clear();
    //    characterLabel->setMovie(skill0);
    //    skill0->start();
    //    // ��ȡ���ܶ�����֡��
    //    int totalFrames = skill0->frameCount();
    //    // ���� frameChanged �źŵ��ۺ���
    //    connect(skill0, &QMovie::frameChanged, this, [this, totalFrames]() {
    //        // ��ȡ��ǰ֡��
    //        int currentFrame = skill0->currentFrameNumber();
    //        // �ж��Ƿ�ﵽ��֡��
    //        if (currentFrame == totalFrames - 1) {
    //            // ����������һ�飬ֹͣ���ܶ���
    //            skillFinished();
    //        }
    //        });
    //}
     //��һ�����޸�
    QLabel* bar;
    void castSkill0();
    void castSkill1();
    void castSkill2();
    bool isskill=false;
    bool c_isskill=false;


    QMovie* skill1;
    bool boolskill0 = false;//�����жϼ���1�Ƿ����ͷ� �޸�bug����
    QMovie* skill2;
    bool boolskill2 = false;//�����жϼ���2�Ƿ����ͷ� �޸�bug����
    QMovie* dunfang;
    QMovie* zhanfang;
    bool ishit = false;
    QTimer* energyTimer;
    void updateEnergy();
    directions direction03;
    double distance;
    
    void castK();
    //���������
    //QTimer JTimer;
    //bool JPressed = false; // ��¼J���Ƿ���
    //int JKeyPressDuration = 0; // J������ʱ��
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

    //������������****������������character02 ����(��ǰ)

    directions c_direction01;//����1 ��������
    directions c_direction02;//����2 ��������
    double c_vy = jump_speed;
    QLabel* c_characterLabel;
    int c_characterX;//��ɫ��X����
    int c_characterY;
    int c_characterY0;//��ʼy ������y����
    QTimer* c_moveTimer;//��ʱ��
    void timeOut02();


    //����ʱ��
    QTimer* c_jumpTimer;
    //���䶨ʱ��
   //QTimer* downTimer;
    QMovie* c_characterMovie;
    // QLabel* label;

    QLabel* c_healthLabel;   // Ѫ����ǩ
    QProgressBar* c_healthBar;   // Ѫ��
    QLabel* c_energyLabel;   // ��������ǩ
    QProgressBar* c_energyBar;   // ������
    double c_energyValue;   // ����ֵ
    double c_healthValue;   // Ѫ��ֵ


    QMovie* c_attackMovie;   // ��������
    QMovie* c_jumpMovie;//��Ծ����

    bool c_isAttacking = false;   // �Ƿ����ڹ���
    // bool isLanded = true;//�ж��Ƿ����
     //bool isJumping = false;//�ж��Ƿ���Ծ
     //ǰ������
    QMovie* c_forwardMovie;
    //�¶׶���
    QMovie* c_crouchMovie;

    //���˶���
    QMovie* c_backwardMovie;

    QMovie* c_entranceMovie;//��������

    QMovie* c_crouchAttack;
    bool c_cantmove = false;   // �Ƿ�����ƶ�
    QMovie* c_skill0;//����0
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
    // ���ܶ���������ϣ����Խ�����������
    // �ָ��������ƶ��Ȳ���
    // ...
    // ���ñ�־λΪfalse����ʾ�����ͷ���� 
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
    double c_tuid;//����2������
    QTimer* timer;
    bool c_isdungong=false;
    double c_dungongd = 0;
    double c_skill0d=0;
    bool c_iszhangong = false;
    double c_zhangongd = 0;
    QTimer* c_skill0t;
    //int n=0;
    void c_skill0dmove();
    //һ���ܵĵ�λ
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






    //������������****������������

};