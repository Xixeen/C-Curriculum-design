#pragma once
#include "QtWidgetsApplication2.h"
#include"KeyPressEvent.h"
#include"KeyReleaseEvent.h"

void QtWidgetsApplication1::facing(int characterX, int c_characterX)
{
    if (c_characterX < characterX)
    {
        // 翻转GIF2，使其面对GIF1
        QImage image = characterMovie->currentImage();
        QImage mirroredImage = image.mirrored(true, false);
        QPixmap pixmap = QPixmap::fromImage(mirroredImage);
        c_characterLabel->setPixmap(pixmap);
        c_characterLabel->setGeometry(characterX - (c_characterX - characterX), c_characterY, characterMovie->scaledSize().width(), characterMovie->scaledSize().height());
    }
    else if (c_characterX > characterX) {
        // 翻转GIF1，使其面对GIF2
        QImage image = characterMovie->currentImage();
        QImage mirroredImage = image.mirrored(true, false);
        QPixmap pixmap = QPixmap::fromImage(mirroredImage);
        characterLabel->setPixmap(pixmap);
        c_characterLabel->setGeometry(c_characterX - (characterX - c_characterX), characterY, c_characterMovie->scaledSize().width(), c_characterMovie->scaledSize().height());
    }
}

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    DHS_DISPLAY();
    switch (choice)
    {
        //启动单人模式
    case(1):
    {

        // break;
    }

    //启动双人模式
    case(2): {

        // closegraph(); 
        closegraph();
        QMovie* backgroundMovie;

        //随机地图
        srand(time(nullptr));
        int num=rand()%7+1;
        switch (num)
        {
        //case(9):backgroundMovie = new QMovie(path9); break;
        case(1):backgroundMovie = new QMovie(path2); break;
        case(2):backgroundMovie = new QMovie(path3); break;
        case(3):backgroundMovie = new QMovie(path4); break;
       // case(4):backgroundMovie = new QMovie(path5); break;
        case(5):backgroundMovie = new QMovie(path6); break;
        case(6):backgroundMovie = new QMovie(path7); break;

        case(7):backgroundMovie = new QMovie(path8); break;

        case(8):backgroundMovie = new QMovie(path9); break;
        default:backgroundMovie = new QMovie(path8);
        }
        //modifySize(backgroundMovie);
       // backgroundMovie = new QMovie(path1);
        backgroundLabel->setGeometry(0, 0, m_width, m_height);
        backgroundLabel->setMovie(backgroundMovie);
        backgroundMovie->start();

        // 创建角色的 QMovie 对象
        //QFileInfo fileInfo("chara_pic_or_gif/bashen/zhanli.gif");
        //QString absolutePath = fileInfo.absoluteFilePath();

        //捕捉键盘事件
        //installEventFilter(this);
        // 创建角色的 QLabel 对象

        mciSendStringA("open resources/music/bgm2.mp3 alias BGM", 0, 0, 0);
        mciSendStringA("play BGM repeat", 0, 0, 0);

        //  int n = 0;
        mciSendString(L"play resources/music/kuangxiao.wav", 0, 0, 0);
        mciSendString(L"play resources/music/dashechuchang.wav", 0, 0, 0);
        //mciSendString(L"play resources/music/bgm.wav", 0, 0, 0);


        characterMovie = new QMovie(bashen_zhanli);
        c_characterMovie = new QMovie(dashe_zhanli);

        characterLabel = new QLabel(this);
        c_characterLabel = new QLabel(this);

        this->setFixedSize(m_width, m_height);

        characterLabel->setGeometry(150, 175, m_width, m_height); // 设置初始位置和大小
        c_characterLabel->setGeometry(m_width - 300, 175, m_width, m_height);
        // modifySize(characterMovie);

        // playGif(characterMovie);
        characterLabel->setMovie(characterMovie);
        c_characterLabel->setMovie(c_characterMovie);
        // 在构造函数或初始化函数中...

        // 创建角色的出场动画
        //QMovie* entranceMovie;
        entranceMovie = new QMovie(bashen_chuchang);
        c_entranceMovie = new QMovie(dashe_jinchang);
        jump = new QMovie("chara_pic_or_gif/bashen/xietiao.gif");
       // mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);

        c_jump = new QMovie(dashe_xietiao);
        // 启动出场动画
        //c_characterLabel->setGeometry(850,-100, m_width, m_height);

        showup();
        //c_characterLabel->setGeometry(m_width - 300, 175, m_width, m_height);

      //  c_characterLabel->setGeometry(m_width - 300, 175, m_width, m_height);

        // 将 characterLabel 指针赋值为创建的 QLabel 对象
        this->characterLabel = characterLabel;
        this->c_characterLabel = c_characterLabel;
        // 初始化 characterX 变量为角色的初始 x 坐标
        characterX = characterLabel->x();
        c_characterX = m_width - 300;
        // 初始化 characterY0 变量为角色的初始 y 坐标 
        characterY0 = characterLabel->y();
        characterY = characterLabel->y();

        c_characterY0 = 175;
        c_characterY = 175;

        direction01 = directions::none;
        direction02 = directions::none;

        c_direction01 = directions::none;
        c_direction02 = directions::none;

        // 创建定时器
        moveTimer = new QTimer(this);
        jumpTimer = new QTimer(this);

        c_moveTimer = new QTimer(this);
        c_jumpTimer = new QTimer(this);

        c_skill0t = new QTimer(this);
        c_skill0t->setInterval(10);
      


        // 假设每帧 22 毫秒
        moveTimer->setInterval(22);
        jumpTimer->setInterval(22);

        c_moveTimer->setInterval(22);
        c_jumpTimer->setInterval(22);
        c_skill1t = new QTimer(this);
        c_skill1t->setInterval(10);

        skill1t = new QTimer(this);
        skill1t->setInterval(10);
        connect(skill1t, &QTimer::timeout, this, &QtWidgetsApplication1::skill1dmove);

        skill0t = new QTimer(this);
        skill0t->setInterval(10);
        connect(skill0t, &QTimer::timeout, this, &QtWidgetsApplication1::skill0dmove);

        connect(c_skill1t, &QTimer::timeout, this, &QtWidgetsApplication1::c_skill1dmove);
        connect(c_skill0t, &QTimer::timeout, this, &QtWidgetsApplication1::c_skill0dmove);
        //downTimer->setInterval(16);
        // 连接信号和槽
        connect(moveTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut);
        connect(jumpTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut);

        connect(c_moveTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut02);
        connect(c_jumpTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut02);

        //connect(downTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut);
        // 其他初始化操作...

        // 开始播放角色的动画
        characterMovie->start();
        c_characterMovie->start();

        // 创建血条标签和血条控件
        healthLabel = new QLabel("", this);
        healthLabel->setGeometry(10, 10, 50, 20);
        healthBar = new QProgressBar(this);
        healthBar->setGeometry(70, 10, 300, 30);
        healthBar->setTextVisible(true);
        healthBar->setMaximum(100);
        healthBar->setMinimum(0);
        // 设置文本字号和颜色
        healthBar->setStyleSheet("QProgressBar {"
            "    text-align: right;"    // 居中对齐
            "}");

        // 修改血条的样式为类似拳皇的样式
        healthBar->setStyleSheet("QProgressBar { \
                            border: none; \
                            border-radius: 50px; \
                            background-color: none; \
                        } \
                        QProgressBar::chunk { \
                            background-color: red; \
                        }");
        healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 red, stop:0.25 orange,stop:0.5 yellow, stop:1 green);"
            "}");


        // 创建能量条标签和能量条控件
        energyLabel = new QLabel("", this);
        energyLabel->setGeometry(10, 40, 50, 20);
        energyBar = new QProgressBar(this);
        energyBar->setGeometry(70, 60, 100, 20);
        energyBar->setTextVisible(true);

        // 修改能量条的颜色为蓝色
        energyBar->setStyleSheet("QProgressBar::chunk { background-color: blue; }");


        // 初始化血量和能量值
        healthValue = 100;
        energyValue = 0;
        // 更新血条和能量条的数值
        healthBar->setValue(healthValue);    // 根据实际血量值进行更新
        energyBar->setValue(energyValue);  // 根据实际能量值进行更新
        healthBar->raise(); healthBar->raise();



        energyTimer = new QTimer(this);
        energyTimer->start(100);
        connect(energyTimer, &QTimer::timeout, this, &QtWidgetsApplication1::updateEnergy);
        energyBar->setMaximum(100);
        energyBar->setMinimum(0);



        bar = new QLabel(this);
        QPixmap barImage("chara_pic_or_gif/bashen/bar.png"); // 使用资源路径加载图像

        QPixmap scaledbarImage = barImage.scaled(1250, 750, Qt::KeepAspectRatio);
        bar->setPixmap(scaledbarImage);
        bar->setGeometry(0, 0, scaledbarImage.width(), scaledbarImage.height());
        healthBar->setGeometry(133.75, 51.25, 428.75, 14); // 血条偏移
        energyBar->setGeometry(219, 94, 166, 14.5); // 能量条偏移
        bar->lower();
        backgroundLabel->lower(); backgroundLabel->lower();



        //角色222222222222222222222222血条能量条
        // 创建血条标签和血条控件
        c_healthLabel = new QLabel("", this);
        c_healthLabel->setGeometry(10, 10, 50, 20);
        c_healthBar = new QProgressBar(this);
        c_healthBar->setGeometry(70, 10, 300, 30);
        c_healthBar->setTextVisible(true);
        c_healthBar->setMaximum(100);
        c_healthBar->setMinimum(0);
        // 设置文本字号和颜色
        c_healthBar->setStyleSheet("QProgressBar {"
            "    text-align: right;"    // 居中对齐
            "}");

        // 修改血条的样式为类似拳皇的样式
        c_healthBar->setStyleSheet("QProgressBar { \
                            border: none; \
                            border-radius: 50px; \
                            background-color: none; \
                        } \
                        QProgressBar::chunk { \
                            background-color: red; \
                        }");
        c_healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 red, stop:0.75 orange,stop:0.5 yellow, stop:0 green);"
            "}");

        // 创建能量条标签和能量条控件
        c_energyLabel = new QLabel("", this);
        c_energyLabel->setGeometry(10, 40, 50, 20);
        c_energyBar = new QProgressBar(this);
        c_energyBar->setGeometry(70, 60, 100, 20);
        c_energyBar->setTextVisible(true);

        // 修改能量条的颜色为蓝色
        c_energyBar->setStyleSheet("QProgressBar::chunk { background-color: blue; }");



        // 更新血条和能量条的数值
        c_healthBar->setValue(healthValue);    // 根据实际血量值进行更新
        c_energyBar->setValue(energyValue);  // 根据实际能量值进行更新
        c_healthBar->raise(); healthBar->raise();
        c_energyBar->setMaximum(100);
        c_energyBar->setMinimum(0);
        // 初始化血量和能量值
        c_healthValue = 100;
        c_energyValue = 0;

        //倒转显示
        c_healthBar->setInvertedAppearance(true);
        c_energyBar->setInvertedAppearance(true);

        c_healthBar->setGeometry(692, 51.25, 428.75, 14); // 血条偏移
        c_energyBar->setGeometry(870, 94, 166, 14.5); // 能量条偏移


        c_healthBar->setAlignment(Qt::AlignHCenter);
        c_energyBar->setAlignment(Qt::AlignHCenter);
        healthBar->setAlignment(Qt::AlignHCenter);
        energyBar->setAlignment(Qt::AlignHCenter);

        // 站攻
        attackMovie = new QMovie(bashen_zhangong);
        c_attackMovie = new QMovie(dashe_zhangong);
        // modifySize(attackMovie);

         //noMovie = new QMovie(" ");
         // 初始化攻击状态
        isAttacking = false;
        c_isAttacking = false;

        //直跳
        jumpMovie = new QMovie(bashen_zhitiao);
        c_jumpMovie = new QMovie(dashe_zhitiao);
        //modifySize(jumpMovie);

        //下蹲动画
        crouchMovie = new QMovie(bashen_xiadun);
        c_crouchMovie = new QMovie(dashe_xiadun);
        //modifySize(crouchMovie);

        //蹲攻
        crouchAttack = new QMovie(bashen_dungong);
        c_crouchAttack = new QMovie(dashe_dungong);
        // modifySize(crouchAttack);

         //前进动画

        forwardMovie = new QMovie(bashen_qianjin);
        c_forwardMovie = new QMovie(dashe_houtui);
       
         //后退动画
        backwardMovie = new QMovie(bashen_houtui);
        c_backwardMovie = new QMovie(dashe_zhanli);
        // modifySize(backwardMovie);

         //技能0动画

        skill0 = new QMovie(bashen_skill0);
        c_skill0 = new QMovie(dashe_skill0);
        //技能1动画
        skill1 = new QMovie(bashen_skill1);
        c_skill1 = new QMovie(dashe_skill1);
        //技能2动画
        skill2 = new QMovie(bashen_skill2);
        c_skill2 = new QMovie(dashe_skill2);
        //蹲防
        dunfang = new QMovie(bashen_dunfang);
        c_dunfang = new QMovie(dashe_xiadun);
        //站防
        zhanfang = new QMovie(bashen_zhanfang);
        c_zhanfang = new QMovie(dashe_zhanli);
        //bool ischangep=false;
        //闪避
        shanbi = new QMovie(bashen_shanbi);
        c_shanbi = new QMovie(dashe_shanbi);

        //腿（攻）
        tui = new QMovie(bashen_tui);
        c_tui = new QMovie(dashe_tui);

        //奔跑
        benpao = new QMovie(bashen_benpao);


        ENDCHARA = new QMovie(bashen_shengli);
        ENDC_CHARA = new QMovie(dashe_shibai);
        ENDCHARA2 = new QMovie(bashen_shibai);
        ENDC_CHARA2 = new QMovie(dashe_shengli);
        //bool ischangep=false;
       
       

    }

    }

}


void QtWidgetsApplication1::timeOut()
{


    //// 根据方向改变坐标
    //switch (direction) {
    //case directions::left:
    //    characterX -= m_speed;
    //    break;
    //case directions::right:
    //    characterX += m_speed;
    //    break;
    //case directions::up:
    //    characterY -= m_speed;
    //    break;
        //characterY -= vy;
       // vy += jump_speed;
        // 判断是否达到最高点，如果是则切换为下降阶段
        //if (vy <= 0) {
      //      direction = directions::down;
      //      vy = 0;
      //  }
      //  break;
    //case directions::down:
    //    vy += Gravity;
    //    characterY += vy;
    //    // 判断是否触地，如果是则停止跳跃
    //    if (characterY >= characterY0) {
    //        characterY = characterY0;
    //        // 更新角色的位置
    //        characterLabel->move(characterX, characterY);
    //        jumpTimer->stop();
    //        direction = directions::none;
    //    }
        // 根据需要调整跳起的速度
       //break;

        // 其他方向的情况...


        //characterLabel->move(characterX, characterY);
        // 检查坐标是否越界

            // 根据方向改变坐标
    switch (direction01) {
    case directions::left:
    {
        characterX -= m_speed;
        break;

    }
    case directions::right:
    {
        characterX += m_speed;
        break;
    }

    default:
        break; // 加上default分支
    }

    switch (direction02)
    {
    case directions::up:
    {mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);
        // 更新垂直速度和位置
        vy -= gravity;
        characterY -= vy;
        // 如果角色落地，停止跳跃
        if (characterY >= characterY0)
        {
            characterY = characterY0;
            jumpTimer->stop();
            // 设置角色的动画
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            characterMovie->start();
            direction02 = directions::none;
        }

        break;
    }

    default:
        break; // 加上default分支
    }

    // 更新垂直位置
    //characterY += vy;
    // 检查坐标是否越界
    if (characterX < 0) characterX = 0;
    if (characterX > m_width - 100) characterX = m_width - 100;
    if (characterY < 0) characterY = 0;
    if (characterY > m_height - 300) characterY = m_height - 300;


    //移动
    characterLabel->move(characterX, characterY);
    //加载血条 能量条
    if (c_characterX)c_isjumping = false;
    if (characterX)isjumping = false;



    healthBar->setValue(healthValue);    // 根据实际血量值进行更新
    energyBar->setValue(energyValue);  // 根据实际能量值进行更新
    distance = abs(characterX - c_characterX);


    

}

void QtWidgetsApplication1::timeOut02()
{
    //Player2
            // 根据方向改变坐标
    switch (c_direction01) {
    case directions::left:
    {
        c_characterX -= m_speed;
        break;

    }
    case directions::right:
    {
        c_characterX += m_speed;
        break;
    }

    // case directions::down: {
    //     // 下落时更新垂直速度
    //     
    //     vy -= jump_speed;
    //     // 判断是否触地，如果是则停止跳跃
    //     if (characterY >= jumpHeight) {
    //         characterY = jumpHeight;
    //         vy = 0.0;
    //         jumpTimer->stop();
    //         direction = directions::none;
    //         // 记录触地状态
    ////         isLanded = true;
    //     }
    //     // 根据需要调整跳起的速度
    //     break; 
    // }
    default:
        break; // 加上default分支
    }

    switch (c_direction02)
    {
    case directions::up:
    {mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);
        // 更新垂直速度和位置
        c_vy -= gravity;
        c_characterY -= c_vy;
        // 如果角色落地，停止跳跃
        if (c_characterY >= c_characterY0)
        {
            c_characterY = c_characterY0;
            c_jumpTimer->stop();
            // 设置角色的动画
            c_characterLabel->clear();
            c_characterLabel->setMovie(c_characterMovie);
            c_characterMovie->start();
            c_direction02 = directions::none;
        }

        break;
    }

    default:
        break; // 加上default分支
    }
    //Player02 越界判断
    if (c_characterX < 0) c_characterX = 0;
    if (c_characterX > m_width - 100) c_characterX = m_width - 100;
    if (c_characterY < 0) c_characterY = 0;
    if (c_characterY > m_height - 300) c_characterY = m_height - 300;
    // 移动角色标签
    if (c_characterX)c_isjumping = false;
    if (characterX)isjumping = false;
    c_characterLabel->move(c_characterX, c_characterY);


    distance=abs(characterX-c_characterX);

}

void QtWidgetsApplication1::updateEnergy()
{

    if (c_healthValue <= 0)
    {
        c_healthValue = 0;
        mciSendString(L"play resources/music/kuangxiao.wav", 0, 0, 0);
        mciSendString(L"play resources/cao_music/beijidao.wav", 0, 0, 0);
        ENDC();
    }
    if (healthValue <= 0)
    {
        healthValue = 0;
        mciSendString(L"play resources/dashe_music/win.wav", 0, 0, 0);
        mciSendString(L"play resources/cao_music/beijidao.wav", 0, 0, 0);
        ENDC2();
    }


    if (c_healthValue > 100)
    {
        c_healthValue = 100;
       
    }
    if (healthValue > 100)
    {
        healthValue = 100;
      
    }



    energyValue += 0.1;
    energyBar->setValue(energyValue);
    //healthValue -= 1;
    healthBar->setValue(healthValue);
    c_energyValue += 0.1;
    if (energyValue > 100)energyValue = 100;
    if (c_energyValue > 100)c_energyValue = 100;

    c_energyBar->setValue(c_energyValue);
   // c_healthValue -= 1;
    c_healthBar->setValue(c_healthValue);
    //QPalette palette = healthBar->palette();
    //QLinearGradient gradient(0, 0, healthBar->width(), 0);
    //gradient.setColorAt(0.0, Qt::green);
    //gradient.setColorAt(0.5, Qt::yellow);
    //gradient.setColorAt(1.0, Qt::red);
    //palette.setBrush(QPalette::Highlight, gradient);
    //healthBar->setPalette(palette);
    if (healthValue >= 75 && healthValue <= 100) {
        healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 red, stop:0.25 orange,stop:0.5 yellow, stop:1 #00FF00);"
            "}");
    }
    else if (healthValue >= 60 && healthValue < 75)
    {
        healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 red, stop:0.5 orange,stop:0.9 yellow, stop:0.95 #99FF00);"
            "}");
    }
    else if (healthValue >= 50 && healthValue < 60)
    {
        healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 red, stop:0.5 orange,stop:0.9 yellow, stop:0.95 #FFFF00);"
            "}");
    }
    else if (healthValue >= 25 && healthValue < 50)
    {
        healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 red,stop:0.5 #FF6600, stop:1 yellow);"
            "}");
    }
    else if (healthValue >= 0 && healthValue < 25)
    {
        healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 red, stop:1 red);"
            "}");
    }
    if (energyValue >= 75 && energyValue <= 100) {
        energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 #000080, stop:0.25 #0000FF,stop:0.5 #0000CD, stop:1 #FFFFFF);"
            "}");
    }
    else if (energyValue >= 60 && energyValue < 75)
    {
        energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 #000080, stop:0.5 #0000CD,stop:0.9 #F0F8FF, stop:0.95 #FFFFFF);"
            "}");
    }
    else if (energyValue >= 50 && energyValue < 60)
    {
        energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 #000080, stop:0.5 #1E90FF,stop:0.9 #CAE1FF, stop:0.95 #FFFFFF );"
            "}");
    }
    else if (energyValue >= 25 && energyValue < 50)
    {
        energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 #000080,stop:0.5 #0000CD, stop:1 #4169E1);"
            "}");
    }
    else if (energyValue >= 0 && energyValue < 25)
    {
        energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 #000080, stop:1 #000080);"
            "}");
    }
    if (c_healthValue >= 75 && c_healthValue <= 100) {
        c_healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 red, stop:0.75 orange,stop:0.5 yellow, stop:0 #00FF00);"
            "}");
    }
    else if (c_healthValue >= 60 && c_healthValue < 75)
    {
        c_healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 red, stop:0.5 orange,stop:0.1 yellow, stop:0.05 #99FF00);"
            "}");
    }
    else if (c_healthValue >= 50 && c_healthValue < 60)
    {
        c_healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 red, stop:0.5 orange,stop:0.1 yellow, stop:0.05 #FFFF00);"
            "}");
    }
    else if (c_healthValue >= 25 && c_healthValue < 50)
    {
        c_healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 red,stop:0.5 #FF6600, stop:0 yellow);"
            "}");
    }
    else if (c_healthValue >= 0 && c_healthValue < 25)
    {
        c_healthBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 red, stop:0 red);"
            "}");
    }
    if (c_energyValue >= 75 && c_energyValue <= 100) {
        c_energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 #000080, stop:0.75 #0000FF,stop:0.5 #0000CD, stop:0 #FFFFFF);"
            "}");
    }
    else if (c_energyValue >= 60 && c_energyValue < 75)
    {
        c_energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:0 #000080, stop:0.5 #0000CD,stop:0.1 #F0F8FF, stop:0.05 #FFFFFF);"
            "}");
    }
    else if (c_energyValue >= 50 && c_energyValue < 60)
    {
        c_energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 #000080, stop:0.5 #1E90FF,stop:0.1 #CAE1FF, stop:0.05 #FFFFFF );"
            "}");
    }
    else if (c_energyValue >= 25 && c_energyValue < 50)
    {
        c_energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 #000080,stop:0.5 #0000CD, stop:0 #4169E1);"
            "}");
    }
    else if (c_energyValue >= 0 && c_energyValue < 25)
    {
        c_energyBar->setStyleSheet("QProgressBar::chunk {"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
            "stop:1 #000080, stop:0 #000080);"
            "}");
    }
    if (characterX < c_characterX) {
        if (isface)isface = false;
        
        if (isface1)
        {
            if (!isskill) {
                characterMovie->setFileName(bashen_zhanli);

               // entranceMovie->setFileName(bashen_chuchang);

                jump->setFileName("chara_pic_or_gif/bashen/xietiao.gif");
                attackMovie->setFileName(bashen_zhangong);
                jumpMovie->setFileName(bashen_zhitiao);
                crouchMovie->setFileName(bashen_xiadun);
                crouchAttack->setFileName(bashen_dungong);
                forwardMovie->setFileName(bashen_qianjin);
                backwardMovie->setFileName(bashen_houtui);

                skill0->setFileName(bashen_skill0);

                //技能1动画
                skill1->setFileName(bashen_skill1);

                //技能2动画
                skill2->setFileName(bashen_skill2);

                //蹲防
                dunfang->setFileName(bashen_dunfang);

                //站防
                zhanfang->setFileName(bashen_zhanfang);

                //闪避
                shanbi->setFileName(bashen_shanbi);

                //腿（攻）
                tui->setFileName(bashen_tui);

                //奔跑
                benpao->setFileName(bashen_benpao);
                isface1 = false;
                forwardMovie->stop();
                backwardMovie->stop();
                characterMovie->stop();
                crouchAttack->stop();
                crouchMovie->stop();

                crouchAttack->start();
                crouchMovie->start();
                characterMovie->start();
                forwardMovie->start();
                backwardMovie->start();
           }
            
        }

        if (isface2)
        {

                if (!c_isskill) {
                    c_characterMovie->setFileName(dashe_zhanli);
                    //   c_entranceMovie->setFileName(dashe_jinchang);
                    c_jump->setFileName(dashe_xietiao);
                    c_attackMovie->setFileName(dashe_zhangong);
                    c_jumpMovie->setFileName(dashe_zhitiao);
                    c_crouchMovie->setFileName(dashe_xiadun);
                    c_crouchAttack->setFileName(dashe_dungong);
                    c_forwardMovie->setFileName(dashe_houtui);
                    c_backwardMovie->setFileName(dashe_zhanli);
                    c_skill0->setFileName(dashe_skill0);
                    c_skill1->setFileName(dashe_skill1);
                    c_skill2->setFileName(dashe_skill2);
                    c_dunfang->setFileName(dashe_xiadun);
                    c_zhanfang->setFileName(dashe_zhanli);
                    c_shanbi->setFileName(dashe_shanbi);
                    c_tui->setFileName(dashe_tui);
                    //ENDC_CHARA2->setFileName(dashe_shibai);
                    isface2 = false;


                c_crouchMovie->stop();
               
                c_crouchAttack->stop();
                c_forwardMovie->stop();
                c_backwardMovie->stop();
                c_characterMovie->stop();

                c_characterMovie->start();
               
              
                c_forwardMovie->start();
                c_backwardMovie->start();
               
                c_crouchMovie->start();
             
                c_crouchAttack->start(); 
                
                }  
        } 
              


    }
    else {

        if (!isface)isface = true;

        if (!isface1) {
            if (!isskill) {

                characterMovie->setFileName(bashen_zhanli1);

                characterMovie->start();

                jump->setFileName("chara_pic_or_gif/bashen1/xietiao.gif");

                attackMovie->setFileName(bashen_zhangong1);

                jumpMovie->setFileName(bashen_zhitiao1);

                crouchMovie->setFileName(bashen_xiadun1);

                crouchAttack->setFileName(bashen_dungong1);

                forwardMovie->setFileName(bashen_houtui1);

                backwardMovie->setFileName(bashen_qianjin1);

                skill0->setFileName(bashen_skill01);

                //技能1动画
                skill1->setFileName(bashen_skill11);

                //技能2动画
                skill2->setFileName(bashen_skill21);

                //蹲防
                dunfang->setFileName(bashen_dunfang1);

                //站防
                zhanfang->setFileName(bashen_zhanfang1);

                //bool ischangep=false;
                //闪避
                shanbi->setFileName(bashen_shanbi1);

                //腿（攻）
                tui->setFileName(bashen_tui1);

                //奔跑
                benpao->setFileName(bashen_benpao1);
                isface1 = true;

                //胜利
               // ENDCHARA->setFileName(bashen_shengli1);
                //失败
               // ENDC_CHARA->setFileName(bashen_shibai1);
                forwardMovie->stop();
                backwardMovie->stop();
                characterMovie->stop();
                crouchAttack->stop();
                crouchMovie->stop();

                crouchAttack->start();
                crouchMovie->start();
                characterMovie->start();
                forwardMovie->start();
                backwardMovie->start();
            }
        }


        if (!isface2) {

            if (!c_isskill) {
                c_characterMovie->setFileName(dashe_zhanli1);
                // c_entranceMovie->setFileName(dashe_jinchang1);
                c_jump->setFileName(dashe_xietiao1);
                c_attackMovie->setFileName(dashe_zhangong1);
                c_jumpMovie->setFileName(dashe_zhitiao1);
                c_crouchMovie->setFileName(dashe_xiadun1);
                c_crouchAttack->setFileName(dashe_dungong1);
                c_forwardMovie->setFileName(dashe_zhanli1);
                c_backwardMovie->setFileName(dashe_houtui1);
                c_skill0->setFileName(dashe_skill01);
                c_skill1->setFileName(dashe_skill11);
                c_skill2->setFileName(dashe_skill21);
                c_dunfang->setFileName(dashe_xiadun1);
                c_zhanfang->setFileName(dashe_zhanli1);
                c_shanbi->setFileName(dashe_shanbi1);
                c_tui->setFileName(dashe_tui1);
               // ENDC_CHARA2->setFileName(dashe_shibai1);
                isface2 = true;
                c_crouchMovie->stop();

                c_crouchAttack->stop();
                c_forwardMovie->stop();
                c_backwardMovie->stop();
                c_characterMovie->stop();

                c_characterMovie->start();

                c_forwardMovie->start();
                c_backwardMovie->start();

                c_crouchMovie->start();

                c_crouchAttack->start();
            }

        }
           
        }
       
}

void QtWidgetsApplication1::castK()
{
    // 设置标志位为 true，表示正在释放技能
    cantmove = true;
    isskill = true;
    // boolskill0 = true;
    // 暂停其他动作，如攻击和移动
    // ...
    // 播放技能动画 
    characterLabel->clear();
    moveTimer->stop();

    characterLabel->setGeometry(characterX-91, characterY -24, m_width, m_height);
    characterLabel->setMovie(tui);
    tui->start();

    // 获取技能动画的帧数
    int totalFrames = tui->frameCount();
    healthValue += 15;
    energyValue -= 20;
    // 连接 frameChanged 信号到槽函数

    connection = connect(tui, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = tui->currentFrameNumber();

        // 判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            cantmove = false;
            isskill = false;
           // boolskill0 = false;
            characterLabel->clear();

            characterLabel->setMovie(characterMovie);
            tui->stop();
            //还原角色位置
            //characterX += 600;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            disconnect(connection);
        }
        });
}

void QtWidgetsApplication1::jatt()
{

    // 设置标志位为 true，表示正在释放技能
    //cantmove = true;
    //boolskill2 = true;
    // 暂停其他动作，如攻击和移动
    // ...

    // 播放技能动画 


    //characterLabel->clear();
    //moveTimer->stop();
    //characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
    //characterLabel->setMovie(skill2);
    //skill2->start();
    isskill = true;
    atkdetc = true;
    // 获取技能动画的帧数
    int jframe = attackMovie->frameCount();

    // 连接 frameChanged 信号到槽函数
    jconnection = connect(attackMovie, &QMovie::frameChanged, this, [this, jframe]() {
        // 获取当前帧数
        int jcframe = attackMovie->currentFrameNumber();

        // 帧数


        if (jcframe == 6) {//第一拳

            isAttacking = false;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            characterMovie->start();
            attackMovie->stop();
           // cantmove = false;
            atkdetc = false;
            isskill = false;
            disconnect(atkconnection);
            disconnect(jconnection);
        }
        else if (jcframe == 13) {//第一脚

            isAttacking = false;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
           // cantmove = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            characterMovie->start();
            attackMovie->stop();
            atkdetc = false;
            isskill = false;
            disconnect(atkconnection);
            disconnect(jconnection);
        }
        else if (jcframe == 23) {//第一抓

            isAttacking = false;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            //cantmove = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            characterMovie->start();
            attackMovie->stop();
            atkdetc = false;
            isskill = false;
            disconnect(atkconnection);
            disconnect(jconnection);
        }
        else if (jcframe == 34) {//第一踢腿

            isAttacking = false;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            //cantmove = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            characterMovie->start();
            attackMovie->stop();
            atkdetc = false;
            isskill = false;
            disconnect(atkconnection);
            disconnect(jconnection);
        }
        });

}

void QtWidgetsApplication1::castL()
{
    // 设置标志位为 true，表示正在释放技能
    isskill = true;
    cantmove = true;
    // boolskill0 = true;
    // 暂停其他动作，如攻击和移动
    // ...
    // 播放技能动画 
    characterLabel->clear();
    moveTimer->stop();
    //characterLabel->setGeometry(characterX, characterY - 70, m_width, m_height);
    if(!isface)characterLabel->setMovie(shanbi);

    else {
        characterLabel->setGeometry(characterX-200, characterY, m_width, m_height);
        characterLabel->setMovie(shanbi);
    }
    shanbi->start();
    // 获取技能动画的帧数
    int totalFrames = shanbi->frameCount();
    // 连接 frameChanged 信号到槽函数
    connection = connect(shanbi, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = shanbi->currentFrameNumber();
        // 判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            cantmove = false;
            isskill = false;
            // boolskill0 = false;
            characterLabel->clear();

            characterLabel->setMovie(characterMovie);
            shanbi->stop();
            //还原角色位置
            if (!isface)
            {
                characterX += 250;
                characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            }
            else
            {
                characterX -= 200;
                characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            }
            disconnect(connection);
        }
        });
}

void QtWidgetsApplication1::c_cast3()
{
    // 设置标志位为 true，表示正在释放技能
    c_isskill = true;
    c_cantmove = true;
    // 暂停其他动作，如攻击和移动
    // ...
    // 播放技能动画 
    c_characterLabel->clear();
    c_moveTimer->stop();
    // c_characterLabel->setGeometry(c_characterX - 200, c_characterY - 30, m_width, m_height);
     //c_characterLabel->setGeometry(c_characterX - 120, c_characterY - 115, m_width, m_height);
    c_characterLabel->setMovie(c_shanbi);
    c_shanbi->start();
    if (!isface)c_characterLabel->setGeometry(c_characterX - 206, c_characterY , m_width, m_height);

    // 获取技能动画的帧数
    int c_totalFrames = c_shanbi->frameCount();

    // 连接 frameChanged 信号到槽函数
    c_connection = connect(c_shanbi, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // 获取当前帧数
        int c_currentFrame = c_shanbi->currentFrameNumber();

        // 判断是否达到总帧数
        if (c_currentFrame == c_totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();

            c_characterLabel->setMovie(c_characterMovie);
            c_shanbi->stop();
            //还原角色位置
            if (!isface) c_characterX-=213;
            else c_characterX += 163;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(c_connection);
        }
        });
}

void QtWidgetsApplication1::showup()
{
    // 设置标志位为 true，表示正在动画不能移动
    cantmove = true;
    c_cantmove = true;
    // 播放技能动画
    characterLabel->clear();
    c_characterLabel->clear();


    characterLabel->setMovie(entranceMovie);
    c_characterLabel->setGeometry(m_width - 355, 100, m_width, m_height);

    c_characterLabel->setMovie(c_entranceMovie);
    entranceMovie->start();
    c_entranceMovie->start();

    // 获取技能动画的帧数
    int totalFrames = entranceMovie->frameCount();
    int c_totalFrames = c_entranceMovie->frameCount();
    // 连接 frameChanged 信号到槽函数
    connection = connect(entranceMovie, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = entranceMovie->currentFrameNumber();

        // 判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            cantmove = false;
            characterLabel->clear();


            characterLabel->setMovie(characterMovie);
            characterMovie->start();

            disconnect(connection);
        }

        });
    c_connection = connect(c_entranceMovie, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // 获取当前帧数
        int c_currentFrame = c_entranceMovie->currentFrameNumber();

        // 判断是否达到总帧数
        if (c_currentFrame == c_totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            c_cantmove = false;
            c_characterLabel->clear();
            c_characterLabel->setGeometry(m_width - 300, 175, m_width, m_height);

            c_characterLabel->setMovie(c_characterMovie);
            c_characterMovie->start();

            disconnect(c_connection);
        }

        });


}

void QtWidgetsApplication1::castSkill0()
{
    // 设置标志位为 true，表示正在释放技能
    cantmove = true;
    boolskill0 = true;
    isskill = true;
    // 暂停其他动作，如攻击和移动
    // ...

    // 播放技能动画 


    characterLabel->clear();
    moveTimer->stop();

    if(!isface)characterLabel->setGeometry(characterX - 120, characterY - 115, m_width, m_height);
    else characterLabel->setGeometry(characterX - 500, characterY - 115, m_width, m_height);
    characterLabel->setMovie(skill0);
    skill0->start();
    // 获取技能动画的帧数
    int totalFrames = skill0->frameCount();

    // 连接 frameChanged 信号到槽函数

    connection = connect(skill0, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = skill0->currentFrameNumber();
        if (currentFrame == 23) {
            skill0d = characterX + 50;
            skill0t->start();
        }
        // 判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画

            cantmove = false;
            boolskill0 = false;
            isskill = false;
            characterLabel->clear();

            characterLabel->setMovie(characterMovie);
            skill0->stop();
            //还原角色位置
            if(!isface)characterX += 45;
            else characterX -= 95;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);


            skill0n = 0;
            disconnect(connection);
        }
        });
}

void QtWidgetsApplication1::skill0dmove() {
    if(!isface)skill0d += 5;
    else skill0d -= 5;
    skill0n++;

    if (isface)
    { 
        if (skill0d<c_characterX + 2.5 && skill0d>c_characterX - 2.5) {
            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
            
            c_healthValue -= 10;
        }

    }

    if (!isface) {
        if (skill0d<c_characterX + 2.5 && skill0d>c_characterX - 2.5) {
            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);

            c_healthValue -= 10;
        }
    }




    if (skill0n == 100)skill0t->stop();
}

void QtWidgetsApplication1::castSkill1()
{
    // 设置标志位为 true，表示正在释放技能
    cantmove = true;
    isskill = true;
    // 暂停其他动作，如攻击和移动
    // ...

    // 播放技能动画
    characterLabel->clear();
    moveTimer->stop();
    //characterLabel->setGeometry(characterX - 120, characterY - 120, m_width, m_height);
    if (isface)characterLabel->setGeometry(characterX - 460, characterY, m_width, m_height);

    characterLabel->setMovie(skill1);
    skill1->start();

    if (!isface)skill1d = characterX + 50;
    else skill1d = characterX;
   // else 

    skill1t->start();
    // 获取技能动画的帧数
    int totalFrames = skill1->frameCount();

    // 连接 frameChanged 信号到槽函数
    connection = connect(skill1, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = skill1->currentFrameNumber();

        // 判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画

            cantmove = false;
            isskill = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            skill1->stop();
            skill1t->stop();

            if(isface)characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            disconnect(connection);
        }
        });
}

void QtWidgetsApplication1::skill1dmove() {
   
    if(!isface)skill1d += 5.846153;
    else skill1d -= 5.846153;
    if (isface)
    {
        if (skill1d<c_characterX + 5.846153 && skill1d>c_characterX - 5.846153) {
            c_healthValue -= 7;
            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);

        }
    }
    if (!isface)
    {
        if (skill1d<c_characterX + 5.846153 && skill1d>c_characterX - 5.846153) {
            c_healthValue -= 7;
            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);

        }
    }
}

void QtWidgetsApplication1::castSkill2()
{
    // 设置标志位为 true，表示正在释放技能
    isskill = true;
    cantmove = true;
    boolskill2 = true;
    // 暂停其他动作，如攻击和移动
    // ...

    // 播放技能动画 


    characterLabel->clear();
    moveTimer->stop();

    if(!isface)characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
    else characterLabel->setGeometry(characterX - 150, characterY - 130, m_width, m_height);
    characterLabel->setMovie(skill2);
    skill2->start();


    // 获取技能动画的帧数
    int totalFrames = skill2->frameCount();

    // 连接 frameChanged 信号到槽函数
    connection = connect(skill2, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = skill2->currentFrameNumber();
        if (currentFrame == 6) {
            if (distance <= 315) {
                c_healthValue -= 7;
                mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
            }
        }
        // 判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            cantmove = false;
            isskill = false;
            boolskill2 = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            skill2->stop();
            //还原角色位置
            if(!isface)characterX += 75;
           // else 
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            disconnect(connection);
        }
        });

}

void QtWidgetsApplication1::skill2dmove() {
};

void QtWidgetsApplication1::c_castSkill0()
{
    // 设置标志位为 true，表示正在释放技能
    c_isskill = true;
    c_cantmove = true;
    // 暂停其他动作，如攻击和移动
    // ...
    // 播放技能动画 
    c_characterLabel->clear();
    c_moveTimer->stop();
    if(!isface)   c_characterLabel->setGeometry(c_characterX - 420, c_characterY - 45, m_width, m_height);
    else c_characterLabel->setGeometry(c_characterX - 50, c_characterY - 50, m_width, m_height);
    c_characterLabel->setMovie(c_skill0);
    c_skill0->start();
    // 获取技能动画的帧数
   // if(!isface)c_skill0d = c_characterX - 35;
    if (!isface)c_skill0d = c_characterX;
    if(isface) c_skill0d = c_characterX + 135;
    
    int c_totalFrames = c_skill0->frameCount();
   
    // 连接 frameChanged 信号到槽函数
    c_connection = connect(c_skill0, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // 获取当前帧数
        int c_currentFrame = c_skill0->currentFrameNumber();
       
        if (c_currentFrame ==14)c_skill0t->start();

        // 判断是否达到总帧数
        if (c_currentFrame == c_totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();
           
           // std::cout<< n;
            c_characterLabel->setMovie(c_characterMovie);
            c_skill0->stop();
           // std::cout << n;
            c_skill0t->stop();
            //还原角色位置
            if(!isface)c_characterX += 55;
            if (isface)c_characterX -= 55;

            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(c_connection);
        }
        });
}

void QtWidgetsApplication1::c_skill0dmove()
{
    if (!isface)c_skill0d -= 4.8559322;
    else c_skill0d += 3.8559322;
     //n++;
    if (!isface) {
        if (abs(characterX - c_skill0d) < (4.8559322 / 2))
        {
            if (!is6)healthValue -= 15;
            else healthValue -= 30;
            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
        }
    }
    else {
        if (c_skill0d<characterX + 1.9279661 && c_skill0d > characterX - 1.9279661)
        {
            if (!is6)healthValue -= 15;
            else healthValue -= 30;
            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
        }
    }

}

void QtWidgetsApplication1::c_skill1dmove()
{
    
}

void QtWidgetsApplication1::c_castSkill2()
{
    // 设置标志位为 true，表示正在释放技能
    c_cantmove = true;
    c_isskill = true;
    // 暂停其他动作，如攻击和移动
    // ...
    // 播放技能动画 
    c_characterLabel->clear();
    c_moveTimer->stop();
    c_characterLabel->setGeometry(c_characterX - 100, c_characterY, m_width, m_height);
    c_characterLabel->setMovie(c_skill2);
    c_skill2->start();
    c_healthValue -= 20;
    c_energyValue -= 20;
        mciSendString(L"play resources/dashe_music/skill3.wav", 0, 0, 0);

    // 获取技能动画的帧数
    int c_totalFrames = c_skill2->frameCount();

    // 连接 frameChanged 信号到槽函数
    c_connection = connect(c_skill2, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // 获取当前帧数
        int c_currentFrame = c_skill2->currentFrameNumber();

        // 判断是否达到总帧数
        if (c_currentFrame == c_totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();

            c_characterLabel->setMovie(c_characterMovie);
            c_skill2->stop();
            //还原角色位置
            //c_characterX += 45;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(c_connection);
        }
        });
}
void QtWidgetsApplication1::c_castSkill1()
{
    // 设置标志位为 true，表示正在释放技能
    c_cantmove = true;
    c_isskill = true;
    // 暂停其他动作，如攻击和移动
    // ...

    // 播放技能动画
    c_characterLabel->clear();
    c_moveTimer->stop();
    if(!isface)c_characterLabel->setGeometry(c_characterX - 130, c_characterY - 15, m_width, m_height); 
    if(isface)c_characterLabel->setGeometry(c_characterX - 30, c_characterY - 15, m_width, m_height);
   // if (isface)c_characterLabel->setGeometry(c_characterX - 100, c_characterY - 15, m_width, m_height);

    c_characterLabel->setMovie(c_skill1);

    c_skill1->start();
    if(!isface)c_skill1d = c_characterX-170;
    else c_skill1d=c_characterX +130 ;
    // 获取技能动画的帧数
    int c_totalFrames = c_skill1->frameCount();

    // 连接 frameChanged 信号到槽函数
    c_connection = connect(c_skill1, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // 获取当前帧数
        int c_currentFrame = c_skill1->currentFrameNumber();

        if (c_currentFrame == 13) {
            if (!isface)
            { 
                if (abs(characterX - c_skill1d) < 90)
                {
                    if (!is6)healthValue -= 25;
                    else healthValue -= 40;
                    mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);

                }
            }
            else 
            {
                if (abs(characterX - c_skill1d) < 80)
                {
                    if (!is6)healthValue -= 25;
                    else healthValue -= 40;
                    mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);

                }
            }
        }
        // 判断是否达到总帧数
        if (c_currentFrame == c_totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();
            c_characterLabel->setMovie(c_characterMovie);
            c_skill1->stop();
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            c_skill1t->stop();    
            disconnect(c_connection);
        }
        });
}
void QtWidgetsApplication1::c_cast2()
{
    // 设置标志位为 true，表示正在释放技能
    c_isskill = true;
    c_cantmove = true;
    // 暂停其他动作，如攻击和移动
    // ...
    // 播放技能动画 
    c_characterLabel->clear();
    c_moveTimer->stop();
    if(isface)c_characterLabel->setGeometry(c_characterX - 200, c_characterY - 35, m_width, m_height);
   if(!isface)c_characterLabel->setGeometry(c_characterX-110, c_characterY - 35, m_width, m_height);
    //c_characterLabel->setGeometry(c_characterX - 120, c_characterY - 115, m_width, m_height);
   if (!isface)c_tuid = c_characterX-140;
   if (isface)c_tuid = c_characterX + 120;
    c_characterLabel->setMovie(c_tui);
    c_tui->start();
    // 获取技能动画的帧数
    int c_totalFrames = c_tui->frameCount();

    // 连接 frameChanged 信号到槽函数
    c_connection = connect(c_tui, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // 获取当前帧数
        int c_currentFrame = c_tui->currentFrameNumber();

        if (c_currentFrame == 3) {
            if (!isface)
            { 
                if (abs(characterX - c_tuid) < 100) {
                    if (!is6) healthValue -= 10;
                    else healthValue -= 20;
                    mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
                }
            }
            else 
            { 
                if (abs(characterX - c_tuid) < 100) {
                    if (!is6) healthValue -= 10;
                    else healthValue -= 20;
                    mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
                }
            }
        }
        // 判断是否达到总帧数
        if (c_currentFrame == c_totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();

            c_characterLabel->setMovie(c_characterMovie);
            c_tui->stop();
            //还原角色位置
          //  c_characterX += 45;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(c_connection);
        }
        });
}

void QtWidgetsApplication1::modifySize(QMovie* characterMovie)
{
    characterMovie->jumpToFrame(0); // 跳转到第一帧以确保获取当前帧
    int gifWidth0 = characterMovie->currentPixmap().width();
    int gifHeight0 = characterMovie->currentPixmap().height();
    double widthRatio = gif_size / gifWidth0;
    double heightRatio = gif_size / gifHeight0;
    double scaleRatio = qMin(widthRatio, heightRatio);
    int gifWidth1 = qRound(gifWidth0 * scaleRatio);
    int gifHeight1 = qRound(gifHeight0 * scaleRatio);
    characterMovie->setScaledSize(QSize(gifWidth1, gifHeight1));
}

void QtWidgetsApplication1::playGif(QMovie* characterMovie)
{
    characterLabel->setMovie(characterMovie);
    characterMovie->start();
}

void QtWidgetsApplication1::CenterInitGraph()
{
    // 获取屏幕分辨率
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // 计算initgraph窗口的大小
    int width = WIDTH;
    int height = HEIGHT;

    // 计算initgraph窗口应该出现在屏幕中央的位置
    int x = (screenWidth - width) / 2;
    int y = (screenHeight - height) / 2;

    // 初始化图形界面，并将窗口移动到计算出的位置
    initgraph(width, height);
    HWND hwnd = GetHWnd();
    SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
}

void QtWidgetsApplication1::Interface(wchar_t* text)
{

    //下面注释的内容是弹出提示窗口，至于是否使用，可根据实际情况而定。
    /*HWND hwnd;
    hwnd = GetHWnd();
    int is_ok = MessageBox(hwnd, _T(""), _T("提示"), MB_OK);
    flushmessage(EM_MOUSE);*/
    initgraph(1024, 640, NOCLOSE | NOMINIMIZE);
    IMAGE img;
    CenterInitGraph();
    loadimage(&img, _T("E:\\MVandP\\p\\th.jpg"), 1024, 640);
    putimage(0, 0, &img);
    wchar_t Arr[] = _T("退出游戏");
    setlinecolor(YELLOW);
    settextcolor(BLACK);
    settextstyle(25, 0, _T("楷体"));
    setbkmode(TRANSPARENT);
    wchar_t arr[50] = { 0 };
    wcscpy_s(arr, text);
    fillroundrect(300, 200, 400 + textwidth(arr), 300 + textheight(arr), 50, 50);
    outtextxy(350, 250, arr);
    setlinecolor(YELLOW);
    settextcolor(BLACK);
    settextstyle(25, 0, _T("楷体"));
    setbkmode(TRANSPARENT);
    fillroundrect(600, 200, 700 + textwidth(Arr), 300 + textheight(Arr), 50, 50);
    outtextxy(650, 250, Arr);
    MOUSEMSG msg;
    int a = 1;
    GetMouseMsg();
    while (a)
    {

        if (MouseHit())
        {
            msg = GetMouseMsg();
            switch (msg.uMsg)
            {
            case WM_LBUTTONDOWN: {
                if (msg.x > 300 && msg.x < 400 + textwidth(arr) && msg.y>200 && msg.y < 300 + textheight(arr))
                {
                    closegraph();
                    a = 0;
                    break;
                }

                else if (msg.x > 600 && msg.x < 700 + textwidth(Arr) && msg.y>200 && msg.y < 300 + textheight(Arr))
                {
                    cleardevice();
                    settextcolor(WHITE);
                    outtextxy(0, 0,_T("将在三秒钟后退出"));
                    Sleep(3000);
                    closegraph();
                    exit(0);
                }

            }
            default: {
                break;
            }
            }
        }
    }


}

void QtWidgetsApplication1::DHS_DISPLAY()
{


    initgraph(WIDTH, HEIGHT);
    // CenterInitGraph();



    loadimage(0, _T("resources/chara_pic/interface.jpg"), WIDTH, HEIGHT);
    //按钮状态图
    IMAGE MenuBtn01, MenuBtn11, MenuBtn00, MenuBtn10;
    loadimage(&MenuBtn00, _T("resources/chara_pic/MenuBtn00.png"), 725, 75);
    loadimage(&MenuBtn01, _T("resources/chara_pic/MenuBtn01.png"), 725, 75);
    loadimage(&MenuBtn10, _T("resources/chara_pic/MenuBtn10.png"), 725, 80);
    loadimage(&MenuBtn11, _T("resources/chara_pic/MenuBtn11.png"), 725, 80);
    mciSendStringA("open resources/music/WHU！.mp3 alias BGM", 0, 0, 0);
    mciSendStringA("play BGM ", 0, 0, 0);
    //鼠标监听
    MOUSEMSG msg;
    GetMouseMsg();
    bool MenuStatus = true;
    while (MenuStatus)
    {
        if (MouseHit())
        {
            msg = GetMouseMsg();
            //实现鼠标悬浮按钮，按钮样式改变
            switch (msg.uMsg)
            {
            case WM_MOUSEMOVE:
            {
                if (msg.x > 150 && msg.x < 875 && msg.y>435 && msg.y < 510)
                {
                    putimage(150, 435, &MenuBtn01);
                    putimage(150, 540, &MenuBtn10);
                }
                else if (msg.x > 150 && msg.x < 875 && msg.y>540 && msg.y < 620)
                {
                    putimage(150, 540, &MenuBtn11);
                    putimage(150, 435, &MenuBtn00);
                }
                else
                {
                    putimage(150, 435, &MenuBtn00);
                    putimage(150, 540, &MenuBtn10);
                }
                break;
            }
            //实现鼠标点击按钮，跳转到游戏界面
            case WM_LBUTTONDOWN:

                if (msg.x > 150 && msg.x < 875 && msg.y>435 && msg.y < 510)
                {
                    cleardevice();
                    closegraph();
                    choice = 1;
                    mciSendStringA("close BGM ", 0, 0, 0);
                    //单人游戏按钮
                }
                else if (msg.x > 150 && msg.x < 875 && msg.y>540 && msg.y < 620)
                {
                    cleardevice();
                    closegraph();
                    choice = 2;
                    mciSendStringA("close BGM ", 0, 0, 0);
                    //多人游戏按钮
                }
                else
                {
                }
                MenuStatus = false;
                break;
            }
        }
    }

}

void QtWidgetsApplication1::victory()
{
    initgraph(1024, 640, SHOWCONSOLE);
    IMAGE VICTORY;
    loadimage(&VICTORY, _T("C:\\Users\\86156\\Documents\\Tencent Files\\1973570506\\FileRecv\\QtWidgetsApplication1\\resources\\chara_pic\\BASHENAN.jpeg"), 1024, 640);
    putimage(0, 0, &VICTORY);
    /*settextcolor(YELLOW);
    setlinecolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(60, 40, _T("宋体"));
    wchar_t text[50] = _T("八神庵获得胜利！");
    outtextxy(512 - textwidth(text)/2, 320 - textheight(text)/2, text);*/
    Sleep(5000);
    closegraph();
}

void QtWidgetsApplication1::fail()
{
    initgraph(1024, 640, SHOWCONSOLE);
    IMAGE FAIL;
    loadimage(&FAIL, _T("C:\\Users\\86156\\Documents\\Tencent Files\\1973570506\\FileRecv\\QtWidgetsApplication1\\resources\\chara_pic\\CAOTIJING.jpg"), 1024, 640);
    putimage(0, 0, &FAIL);
    /*settextcolor(YELLOW);
    setlinecolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(60, 40, _T("宋体"));
    wchar_t text[50] = _T("草雉京获得胜利！");
    outtextxy(512 - textwidth(text) / 2, 320 - textheight(text) / 2, text);
    Sleep(5000);*/
    Sleep(5000);
    closegraph();
}

void QtWidgetsApplication1::ENDC()
{
    // 设置标志位为 true，表示正在释放技能
    cantmove = true;
    c_cantmove = true;
    boolENDCHARA = true;
    // 暂停其他动作，如攻击和移动
    // ...

    // 播放技能动画 

    c_characterLabel->clear();
    characterLabel->clear();
    moveTimer->stop();
    c_moveTimer->stop();
    //mciSendString(L"play resources/music/ko.wav", 0, 0, 0);
    c_characterLabel->setGeometry(c_characterX - 500, c_characterY -130, m_width, m_height);
    c_characterLabel->setMovie(ENDC_CHARA);

    characterLabel->setGeometry(characterX - 50, characterY - 50, m_width, m_height);
   
    characterLabel->setMovie(ENDCHARA);

    ENDCHARA->start();

    ENDC_CHARA->start();
    // 获取技能动画的帧数
    int totalFrames = ENDC_CHARA->frameCount();
    // 连接 frameChanged 信号到槽函数
    connection = connect(ENDC_CHARA, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = ENDC_CHARA->currentFrameNumber();
        if (currentFrame == 10) {
            ENDC_CHARA->stop();
            delete ENDC_CHARA;
        }
       //  判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            cantmove = false;
            isskill = false;
          //  boolskill2 = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            //skill2->stop();
            //还原角色位置
            c_characterX += 1005;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(connection);
        }
        });

}

void QtWidgetsApplication1::ENDC2()
{
    // 设置标志位为 true，表示正在释放技能
    cantmove = true;
    c_cantmove = true;
    boolENDCHARA = true;
    boolENDCHARA2 = true;
    // 暂停其他动作，如攻击和移动
    // ...

    // 播放技能动画 
    //mciSendString(L"play resources/music/ko.wav", 0, 0, 0);

    c_characterLabel->clear();
    characterLabel->clear();
    moveTimer->stop();
    c_moveTimer->stop();
    c_characterLabel->setGeometry(c_characterX-50, c_characterY , m_width, m_height);
    c_characterLabel->setMovie(ENDC_CHARA2);

    characterLabel->setGeometry(characterX - 400, characterY - 90, m_width, m_height);
    //ENDCHARA2->setFileName(bashen_shibai1);
    characterLabel->setMovie(ENDCHARA2);
    ENDCHARA2->start();
    ENDC_CHARA2->start();

    // 获取技能动画的帧数
    int totalFrames = ENDCHARA2->frameCount();
    // 连接 frameChanged 信号到槽函数
    connection = connect(ENDCHARA2, &QMovie::frameChanged, this, [this, totalFrames]() {
        // 获取当前帧数
        int currentFrame = ENDCHARA2->currentFrameNumber();
        if (currentFrame == 30) {
            ENDCHARA2->stop();
            delete ENDCHARA2;
           // characterLabel->setGeometry(characterX+1000, characterY+1000, m_width, m_height);
        }
        // 判断是否达到总帧数
        if (currentFrame == totalFrames - 1) {
            // 动画播放完一遍，停止技能动画
            cantmove = false;
            isskill = false;
           // boolskill2 = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
          //  skill2->stop();
            //还原角色位置
            characterX += 1005;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            disconnect(connection);
        }
        });

  
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

