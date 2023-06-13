#pragma once
#include "QtWidgetsApplication2.h"
#include"KeyPressEvent.h"
#include"KeyReleaseEvent.h"

void QtWidgetsApplication1::facing(int characterX, int c_characterX)
{
    if (c_characterX < characterX)
    {
        // ��תGIF2��ʹ�����GIF1
        QImage image = characterMovie->currentImage();
        QImage mirroredImage = image.mirrored(true, false);
        QPixmap pixmap = QPixmap::fromImage(mirroredImage);
        c_characterLabel->setPixmap(pixmap);
        c_characterLabel->setGeometry(characterX - (c_characterX - characterX), c_characterY, characterMovie->scaledSize().width(), characterMovie->scaledSize().height());
    }
    else if (c_characterX > characterX) {
        // ��תGIF1��ʹ�����GIF2
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
        //��������ģʽ
    case(1):
    {

        // break;
    }

    //����˫��ģʽ
    case(2): {

        // closegraph(); 
        closegraph();
        QMovie* backgroundMovie;

        //�����ͼ
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

        // ������ɫ�� QMovie ����
        //QFileInfo fileInfo("chara_pic_or_gif/bashen/zhanli.gif");
        //QString absolutePath = fileInfo.absoluteFilePath();

        //��׽�����¼�
        //installEventFilter(this);
        // ������ɫ�� QLabel ����

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

        characterLabel->setGeometry(150, 175, m_width, m_height); // ���ó�ʼλ�úʹ�С
        c_characterLabel->setGeometry(m_width - 300, 175, m_width, m_height);
        // modifySize(characterMovie);

        // playGif(characterMovie);
        characterLabel->setMovie(characterMovie);
        c_characterLabel->setMovie(c_characterMovie);
        // �ڹ��캯�����ʼ��������...

        // ������ɫ�ĳ�������
        //QMovie* entranceMovie;
        entranceMovie = new QMovie(bashen_chuchang);
        c_entranceMovie = new QMovie(dashe_jinchang);
        jump = new QMovie("chara_pic_or_gif/bashen/xietiao.gif");
       // mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);

        c_jump = new QMovie(dashe_xietiao);
        // ������������
        //c_characterLabel->setGeometry(850,-100, m_width, m_height);

        showup();
        //c_characterLabel->setGeometry(m_width - 300, 175, m_width, m_height);

      //  c_characterLabel->setGeometry(m_width - 300, 175, m_width, m_height);

        // �� characterLabel ָ�븳ֵΪ������ QLabel ����
        this->characterLabel = characterLabel;
        this->c_characterLabel = c_characterLabel;
        // ��ʼ�� characterX ����Ϊ��ɫ�ĳ�ʼ x ����
        characterX = characterLabel->x();
        c_characterX = m_width - 300;
        // ��ʼ�� characterY0 ����Ϊ��ɫ�ĳ�ʼ y ���� 
        characterY0 = characterLabel->y();
        characterY = characterLabel->y();

        c_characterY0 = 175;
        c_characterY = 175;

        direction01 = directions::none;
        direction02 = directions::none;

        c_direction01 = directions::none;
        c_direction02 = directions::none;

        // ������ʱ��
        moveTimer = new QTimer(this);
        jumpTimer = new QTimer(this);

        c_moveTimer = new QTimer(this);
        c_jumpTimer = new QTimer(this);

        c_skill0t = new QTimer(this);
        c_skill0t->setInterval(10);
      


        // ����ÿ֡ 22 ����
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
        // �����źźͲ�
        connect(moveTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut);
        connect(jumpTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut);

        connect(c_moveTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut02);
        connect(c_jumpTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut02);

        //connect(downTimer, &QTimer::timeout, this, &QtWidgetsApplication1::timeOut);
        // ������ʼ������...

        // ��ʼ���Ž�ɫ�Ķ���
        characterMovie->start();
        c_characterMovie->start();

        // ����Ѫ����ǩ��Ѫ���ؼ�
        healthLabel = new QLabel("", this);
        healthLabel->setGeometry(10, 10, 50, 20);
        healthBar = new QProgressBar(this);
        healthBar->setGeometry(70, 10, 300, 30);
        healthBar->setTextVisible(true);
        healthBar->setMaximum(100);
        healthBar->setMinimum(0);
        // �����ı��ֺź���ɫ
        healthBar->setStyleSheet("QProgressBar {"
            "    text-align: right;"    // ���ж���
            "}");

        // �޸�Ѫ������ʽΪ����ȭ�ʵ���ʽ
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


        // ������������ǩ���������ؼ�
        energyLabel = new QLabel("", this);
        energyLabel->setGeometry(10, 40, 50, 20);
        energyBar = new QProgressBar(this);
        energyBar->setGeometry(70, 60, 100, 20);
        energyBar->setTextVisible(true);

        // �޸�����������ɫΪ��ɫ
        energyBar->setStyleSheet("QProgressBar::chunk { background-color: blue; }");


        // ��ʼ��Ѫ��������ֵ
        healthValue = 100;
        energyValue = 0;
        // ����Ѫ��������������ֵ
        healthBar->setValue(healthValue);    // ����ʵ��Ѫ��ֵ���и���
        energyBar->setValue(energyValue);  // ����ʵ������ֵ���и���
        healthBar->raise(); healthBar->raise();



        energyTimer = new QTimer(this);
        energyTimer->start(100);
        connect(energyTimer, &QTimer::timeout, this, &QtWidgetsApplication1::updateEnergy);
        energyBar->setMaximum(100);
        energyBar->setMinimum(0);



        bar = new QLabel(this);
        QPixmap barImage("chara_pic_or_gif/bashen/bar.png"); // ʹ����Դ·������ͼ��

        QPixmap scaledbarImage = barImage.scaled(1250, 750, Qt::KeepAspectRatio);
        bar->setPixmap(scaledbarImage);
        bar->setGeometry(0, 0, scaledbarImage.width(), scaledbarImage.height());
        healthBar->setGeometry(133.75, 51.25, 428.75, 14); // Ѫ��ƫ��
        energyBar->setGeometry(219, 94, 166, 14.5); // ������ƫ��
        bar->lower();
        backgroundLabel->lower(); backgroundLabel->lower();



        //��ɫ222222222222222222222222Ѫ��������
        // ����Ѫ����ǩ��Ѫ���ؼ�
        c_healthLabel = new QLabel("", this);
        c_healthLabel->setGeometry(10, 10, 50, 20);
        c_healthBar = new QProgressBar(this);
        c_healthBar->setGeometry(70, 10, 300, 30);
        c_healthBar->setTextVisible(true);
        c_healthBar->setMaximum(100);
        c_healthBar->setMinimum(0);
        // �����ı��ֺź���ɫ
        c_healthBar->setStyleSheet("QProgressBar {"
            "    text-align: right;"    // ���ж���
            "}");

        // �޸�Ѫ������ʽΪ����ȭ�ʵ���ʽ
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

        // ������������ǩ���������ؼ�
        c_energyLabel = new QLabel("", this);
        c_energyLabel->setGeometry(10, 40, 50, 20);
        c_energyBar = new QProgressBar(this);
        c_energyBar->setGeometry(70, 60, 100, 20);
        c_energyBar->setTextVisible(true);

        // �޸�����������ɫΪ��ɫ
        c_energyBar->setStyleSheet("QProgressBar::chunk { background-color: blue; }");



        // ����Ѫ��������������ֵ
        c_healthBar->setValue(healthValue);    // ����ʵ��Ѫ��ֵ���и���
        c_energyBar->setValue(energyValue);  // ����ʵ������ֵ���и���
        c_healthBar->raise(); healthBar->raise();
        c_energyBar->setMaximum(100);
        c_energyBar->setMinimum(0);
        // ��ʼ��Ѫ��������ֵ
        c_healthValue = 100;
        c_energyValue = 0;

        //��ת��ʾ
        c_healthBar->setInvertedAppearance(true);
        c_energyBar->setInvertedAppearance(true);

        c_healthBar->setGeometry(692, 51.25, 428.75, 14); // Ѫ��ƫ��
        c_energyBar->setGeometry(870, 94, 166, 14.5); // ������ƫ��


        c_healthBar->setAlignment(Qt::AlignHCenter);
        c_energyBar->setAlignment(Qt::AlignHCenter);
        healthBar->setAlignment(Qt::AlignHCenter);
        energyBar->setAlignment(Qt::AlignHCenter);

        // վ��
        attackMovie = new QMovie(bashen_zhangong);
        c_attackMovie = new QMovie(dashe_zhangong);
        // modifySize(attackMovie);

         //noMovie = new QMovie(" ");
         // ��ʼ������״̬
        isAttacking = false;
        c_isAttacking = false;

        //ֱ��
        jumpMovie = new QMovie(bashen_zhitiao);
        c_jumpMovie = new QMovie(dashe_zhitiao);
        //modifySize(jumpMovie);

        //�¶׶���
        crouchMovie = new QMovie(bashen_xiadun);
        c_crouchMovie = new QMovie(dashe_xiadun);
        //modifySize(crouchMovie);

        //�׹�
        crouchAttack = new QMovie(bashen_dungong);
        c_crouchAttack = new QMovie(dashe_dungong);
        // modifySize(crouchAttack);

         //ǰ������

        forwardMovie = new QMovie(bashen_qianjin);
        c_forwardMovie = new QMovie(dashe_houtui);
       
         //���˶���
        backwardMovie = new QMovie(bashen_houtui);
        c_backwardMovie = new QMovie(dashe_zhanli);
        // modifySize(backwardMovie);

         //����0����

        skill0 = new QMovie(bashen_skill0);
        c_skill0 = new QMovie(dashe_skill0);
        //����1����
        skill1 = new QMovie(bashen_skill1);
        c_skill1 = new QMovie(dashe_skill1);
        //����2����
        skill2 = new QMovie(bashen_skill2);
        c_skill2 = new QMovie(dashe_skill2);
        //�׷�
        dunfang = new QMovie(bashen_dunfang);
        c_dunfang = new QMovie(dashe_xiadun);
        //վ��
        zhanfang = new QMovie(bashen_zhanfang);
        c_zhanfang = new QMovie(dashe_zhanli);
        //bool ischangep=false;
        //����
        shanbi = new QMovie(bashen_shanbi);
        c_shanbi = new QMovie(dashe_shanbi);

        //�ȣ�����
        tui = new QMovie(bashen_tui);
        c_tui = new QMovie(dashe_tui);

        //����
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


    //// ���ݷ���ı�����
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
        // �ж��Ƿ�ﵽ��ߵ㣬��������л�Ϊ�½��׶�
        //if (vy <= 0) {
      //      direction = directions::down;
      //      vy = 0;
      //  }
      //  break;
    //case directions::down:
    //    vy += Gravity;
    //    characterY += vy;
    //    // �ж��Ƿ񴥵أ��������ֹͣ��Ծ
    //    if (characterY >= characterY0) {
    //        characterY = characterY0;
    //        // ���½�ɫ��λ��
    //        characterLabel->move(characterX, characterY);
    //        jumpTimer->stop();
    //        direction = directions::none;
    //    }
        // ������Ҫ����������ٶ�
       //break;

        // ������������...


        //characterLabel->move(characterX, characterY);
        // ��������Ƿ�Խ��

            // ���ݷ���ı�����
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
        break; // ����default��֧
    }

    switch (direction02)
    {
    case directions::up:
    {mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);
        // ���´�ֱ�ٶȺ�λ��
        vy -= gravity;
        characterY -= vy;
        // �����ɫ��أ�ֹͣ��Ծ
        if (characterY >= characterY0)
        {
            characterY = characterY0;
            jumpTimer->stop();
            // ���ý�ɫ�Ķ���
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            characterMovie->start();
            direction02 = directions::none;
        }

        break;
    }

    default:
        break; // ����default��֧
    }

    // ���´�ֱλ��
    //characterY += vy;
    // ��������Ƿ�Խ��
    if (characterX < 0) characterX = 0;
    if (characterX > m_width - 100) characterX = m_width - 100;
    if (characterY < 0) characterY = 0;
    if (characterY > m_height - 300) characterY = m_height - 300;


    //�ƶ�
    characterLabel->move(characterX, characterY);
    //����Ѫ�� ������
    if (c_characterX)c_isjumping = false;
    if (characterX)isjumping = false;



    healthBar->setValue(healthValue);    // ����ʵ��Ѫ��ֵ���и���
    energyBar->setValue(energyValue);  // ����ʵ������ֵ���и���
    distance = abs(characterX - c_characterX);


    

}

void QtWidgetsApplication1::timeOut02()
{
    //Player2
            // ���ݷ���ı�����
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
    //     // ����ʱ���´�ֱ�ٶ�
    //     
    //     vy -= jump_speed;
    //     // �ж��Ƿ񴥵أ��������ֹͣ��Ծ
    //     if (characterY >= jumpHeight) {
    //         characterY = jumpHeight;
    //         vy = 0.0;
    //         jumpTimer->stop();
    //         direction = directions::none;
    //         // ��¼����״̬
    ////         isLanded = true;
    //     }
    //     // ������Ҫ����������ٶ�
    //     break; 
    // }
    default:
        break; // ����default��֧
    }

    switch (c_direction02)
    {
    case directions::up:
    {mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);
        // ���´�ֱ�ٶȺ�λ��
        c_vy -= gravity;
        c_characterY -= c_vy;
        // �����ɫ��أ�ֹͣ��Ծ
        if (c_characterY >= c_characterY0)
        {
            c_characterY = c_characterY0;
            c_jumpTimer->stop();
            // ���ý�ɫ�Ķ���
            c_characterLabel->clear();
            c_characterLabel->setMovie(c_characterMovie);
            c_characterMovie->start();
            c_direction02 = directions::none;
        }

        break;
    }

    default:
        break; // ����default��֧
    }
    //Player02 Խ���ж�
    if (c_characterX < 0) c_characterX = 0;
    if (c_characterX > m_width - 100) c_characterX = m_width - 100;
    if (c_characterY < 0) c_characterY = 0;
    if (c_characterY > m_height - 300) c_characterY = m_height - 300;
    // �ƶ���ɫ��ǩ
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

                //����1����
                skill1->setFileName(bashen_skill1);

                //����2����
                skill2->setFileName(bashen_skill2);

                //�׷�
                dunfang->setFileName(bashen_dunfang);

                //վ��
                zhanfang->setFileName(bashen_zhanfang);

                //����
                shanbi->setFileName(bashen_shanbi);

                //�ȣ�����
                tui->setFileName(bashen_tui);

                //����
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

                //����1����
                skill1->setFileName(bashen_skill11);

                //����2����
                skill2->setFileName(bashen_skill21);

                //�׷�
                dunfang->setFileName(bashen_dunfang1);

                //վ��
                zhanfang->setFileName(bashen_zhanfang1);

                //bool ischangep=false;
                //����
                shanbi->setFileName(bashen_shanbi1);

                //�ȣ�����
                tui->setFileName(bashen_tui1);

                //����
                benpao->setFileName(bashen_benpao1);
                isface1 = true;

                //ʤ��
               // ENDCHARA->setFileName(bashen_shengli1);
                //ʧ��
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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    cantmove = true;
    isskill = true;
    // boolskill0 = true;
    // ��ͣ�����������繥�����ƶ�
    // ...
    // ���ż��ܶ��� 
    characterLabel->clear();
    moveTimer->stop();

    characterLabel->setGeometry(characterX-91, characterY -24, m_width, m_height);
    characterLabel->setMovie(tui);
    tui->start();

    // ��ȡ���ܶ�����֡��
    int totalFrames = tui->frameCount();
    healthValue += 15;
    energyValue -= 20;
    // ���� frameChanged �źŵ��ۺ���

    connection = connect(tui, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = tui->currentFrameNumber();

        // �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            cantmove = false;
            isskill = false;
           // boolskill0 = false;
            characterLabel->clear();

            characterLabel->setMovie(characterMovie);
            tui->stop();
            //��ԭ��ɫλ��
            //characterX += 600;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            disconnect(connection);
        }
        });
}

void QtWidgetsApplication1::jatt()
{

    // ���ñ�־λΪ true����ʾ�����ͷż���
    //cantmove = true;
    //boolskill2 = true;
    // ��ͣ�����������繥�����ƶ�
    // ...

    // ���ż��ܶ��� 


    //characterLabel->clear();
    //moveTimer->stop();
    //characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
    //characterLabel->setMovie(skill2);
    //skill2->start();
    isskill = true;
    atkdetc = true;
    // ��ȡ���ܶ�����֡��
    int jframe = attackMovie->frameCount();

    // ���� frameChanged �źŵ��ۺ���
    jconnection = connect(attackMovie, &QMovie::frameChanged, this, [this, jframe]() {
        // ��ȡ��ǰ֡��
        int jcframe = attackMovie->currentFrameNumber();

        // ֡��


        if (jcframe == 6) {//��һȭ

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
        else if (jcframe == 13) {//��һ��

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
        else if (jcframe == 23) {//��һץ

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
        else if (jcframe == 34) {//��һ����

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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    isskill = true;
    cantmove = true;
    // boolskill0 = true;
    // ��ͣ�����������繥�����ƶ�
    // ...
    // ���ż��ܶ��� 
    characterLabel->clear();
    moveTimer->stop();
    //characterLabel->setGeometry(characterX, characterY - 70, m_width, m_height);
    if(!isface)characterLabel->setMovie(shanbi);

    else {
        characterLabel->setGeometry(characterX-200, characterY, m_width, m_height);
        characterLabel->setMovie(shanbi);
    }
    shanbi->start();
    // ��ȡ���ܶ�����֡��
    int totalFrames = shanbi->frameCount();
    // ���� frameChanged �źŵ��ۺ���
    connection = connect(shanbi, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = shanbi->currentFrameNumber();
        // �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            cantmove = false;
            isskill = false;
            // boolskill0 = false;
            characterLabel->clear();

            characterLabel->setMovie(characterMovie);
            shanbi->stop();
            //��ԭ��ɫλ��
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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    c_isskill = true;
    c_cantmove = true;
    // ��ͣ�����������繥�����ƶ�
    // ...
    // ���ż��ܶ��� 
    c_characterLabel->clear();
    c_moveTimer->stop();
    // c_characterLabel->setGeometry(c_characterX - 200, c_characterY - 30, m_width, m_height);
     //c_characterLabel->setGeometry(c_characterX - 120, c_characterY - 115, m_width, m_height);
    c_characterLabel->setMovie(c_shanbi);
    c_shanbi->start();
    if (!isface)c_characterLabel->setGeometry(c_characterX - 206, c_characterY , m_width, m_height);

    // ��ȡ���ܶ�����֡��
    int c_totalFrames = c_shanbi->frameCount();

    // ���� frameChanged �źŵ��ۺ���
    c_connection = connect(c_shanbi, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // ��ȡ��ǰ֡��
        int c_currentFrame = c_shanbi->currentFrameNumber();

        // �ж��Ƿ�ﵽ��֡��
        if (c_currentFrame == c_totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();

            c_characterLabel->setMovie(c_characterMovie);
            c_shanbi->stop();
            //��ԭ��ɫλ��
            if (!isface) c_characterX-=213;
            else c_characterX += 163;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(c_connection);
        }
        });
}

void QtWidgetsApplication1::showup()
{
    // ���ñ�־λΪ true����ʾ���ڶ��������ƶ�
    cantmove = true;
    c_cantmove = true;
    // ���ż��ܶ���
    characterLabel->clear();
    c_characterLabel->clear();


    characterLabel->setMovie(entranceMovie);
    c_characterLabel->setGeometry(m_width - 355, 100, m_width, m_height);

    c_characterLabel->setMovie(c_entranceMovie);
    entranceMovie->start();
    c_entranceMovie->start();

    // ��ȡ���ܶ�����֡��
    int totalFrames = entranceMovie->frameCount();
    int c_totalFrames = c_entranceMovie->frameCount();
    // ���� frameChanged �źŵ��ۺ���
    connection = connect(entranceMovie, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = entranceMovie->currentFrameNumber();

        // �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            cantmove = false;
            characterLabel->clear();


            characterLabel->setMovie(characterMovie);
            characterMovie->start();

            disconnect(connection);
        }

        });
    c_connection = connect(c_entranceMovie, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // ��ȡ��ǰ֡��
        int c_currentFrame = c_entranceMovie->currentFrameNumber();

        // �ж��Ƿ�ﵽ��֡��
        if (c_currentFrame == c_totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    cantmove = true;
    boolskill0 = true;
    isskill = true;
    // ��ͣ�����������繥�����ƶ�
    // ...

    // ���ż��ܶ��� 


    characterLabel->clear();
    moveTimer->stop();

    if(!isface)characterLabel->setGeometry(characterX - 120, characterY - 115, m_width, m_height);
    else characterLabel->setGeometry(characterX - 500, characterY - 115, m_width, m_height);
    characterLabel->setMovie(skill0);
    skill0->start();
    // ��ȡ���ܶ�����֡��
    int totalFrames = skill0->frameCount();

    // ���� frameChanged �źŵ��ۺ���

    connection = connect(skill0, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = skill0->currentFrameNumber();
        if (currentFrame == 23) {
            skill0d = characterX + 50;
            skill0t->start();
        }
        // �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���

            cantmove = false;
            boolskill0 = false;
            isskill = false;
            characterLabel->clear();

            characterLabel->setMovie(characterMovie);
            skill0->stop();
            //��ԭ��ɫλ��
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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    cantmove = true;
    isskill = true;
    // ��ͣ�����������繥�����ƶ�
    // ...

    // ���ż��ܶ���
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
    // ��ȡ���ܶ�����֡��
    int totalFrames = skill1->frameCount();

    // ���� frameChanged �źŵ��ۺ���
    connection = connect(skill1, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = skill1->currentFrameNumber();

        // �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���

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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    isskill = true;
    cantmove = true;
    boolskill2 = true;
    // ��ͣ�����������繥�����ƶ�
    // ...

    // ���ż��ܶ��� 


    characterLabel->clear();
    moveTimer->stop();

    if(!isface)characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
    else characterLabel->setGeometry(characterX - 150, characterY - 130, m_width, m_height);
    characterLabel->setMovie(skill2);
    skill2->start();


    // ��ȡ���ܶ�����֡��
    int totalFrames = skill2->frameCount();

    // ���� frameChanged �źŵ��ۺ���
    connection = connect(skill2, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = skill2->currentFrameNumber();
        if (currentFrame == 6) {
            if (distance <= 315) {
                c_healthValue -= 7;
                mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
            }
        }
        // �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            cantmove = false;
            isskill = false;
            boolskill2 = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            skill2->stop();
            //��ԭ��ɫλ��
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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    c_isskill = true;
    c_cantmove = true;
    // ��ͣ�����������繥�����ƶ�
    // ...
    // ���ż��ܶ��� 
    c_characterLabel->clear();
    c_moveTimer->stop();
    if(!isface)   c_characterLabel->setGeometry(c_characterX - 420, c_characterY - 45, m_width, m_height);
    else c_characterLabel->setGeometry(c_characterX - 50, c_characterY - 50, m_width, m_height);
    c_characterLabel->setMovie(c_skill0);
    c_skill0->start();
    // ��ȡ���ܶ�����֡��
   // if(!isface)c_skill0d = c_characterX - 35;
    if (!isface)c_skill0d = c_characterX;
    if(isface) c_skill0d = c_characterX + 135;
    
    int c_totalFrames = c_skill0->frameCount();
   
    // ���� frameChanged �źŵ��ۺ���
    c_connection = connect(c_skill0, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // ��ȡ��ǰ֡��
        int c_currentFrame = c_skill0->currentFrameNumber();
       
        if (c_currentFrame ==14)c_skill0t->start();

        // �ж��Ƿ�ﵽ��֡��
        if (c_currentFrame == c_totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();
           
           // std::cout<< n;
            c_characterLabel->setMovie(c_characterMovie);
            c_skill0->stop();
           // std::cout << n;
            c_skill0t->stop();
            //��ԭ��ɫλ��
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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    c_cantmove = true;
    c_isskill = true;
    // ��ͣ�����������繥�����ƶ�
    // ...
    // ���ż��ܶ��� 
    c_characterLabel->clear();
    c_moveTimer->stop();
    c_characterLabel->setGeometry(c_characterX - 100, c_characterY, m_width, m_height);
    c_characterLabel->setMovie(c_skill2);
    c_skill2->start();
    c_healthValue -= 20;
    c_energyValue -= 20;
        mciSendString(L"play resources/dashe_music/skill3.wav", 0, 0, 0);

    // ��ȡ���ܶ�����֡��
    int c_totalFrames = c_skill2->frameCount();

    // ���� frameChanged �źŵ��ۺ���
    c_connection = connect(c_skill2, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // ��ȡ��ǰ֡��
        int c_currentFrame = c_skill2->currentFrameNumber();

        // �ж��Ƿ�ﵽ��֡��
        if (c_currentFrame == c_totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();

            c_characterLabel->setMovie(c_characterMovie);
            c_skill2->stop();
            //��ԭ��ɫλ��
            //c_characterX += 45;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(c_connection);
        }
        });
}
void QtWidgetsApplication1::c_castSkill1()
{
    // ���ñ�־λΪ true����ʾ�����ͷż���
    c_cantmove = true;
    c_isskill = true;
    // ��ͣ�����������繥�����ƶ�
    // ...

    // ���ż��ܶ���
    c_characterLabel->clear();
    c_moveTimer->stop();
    if(!isface)c_characterLabel->setGeometry(c_characterX - 130, c_characterY - 15, m_width, m_height); 
    if(isface)c_characterLabel->setGeometry(c_characterX - 30, c_characterY - 15, m_width, m_height);
   // if (isface)c_characterLabel->setGeometry(c_characterX - 100, c_characterY - 15, m_width, m_height);

    c_characterLabel->setMovie(c_skill1);

    c_skill1->start();
    if(!isface)c_skill1d = c_characterX-170;
    else c_skill1d=c_characterX +130 ;
    // ��ȡ���ܶ�����֡��
    int c_totalFrames = c_skill1->frameCount();

    // ���� frameChanged �źŵ��ۺ���
    c_connection = connect(c_skill1, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // ��ȡ��ǰ֡��
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
        // �ж��Ƿ�ﵽ��֡��
        if (c_currentFrame == c_totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
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
    // ���ñ�־λΪ true����ʾ�����ͷż���
    c_isskill = true;
    c_cantmove = true;
    // ��ͣ�����������繥�����ƶ�
    // ...
    // ���ż��ܶ��� 
    c_characterLabel->clear();
    c_moveTimer->stop();
    if(isface)c_characterLabel->setGeometry(c_characterX - 200, c_characterY - 35, m_width, m_height);
   if(!isface)c_characterLabel->setGeometry(c_characterX-110, c_characterY - 35, m_width, m_height);
    //c_characterLabel->setGeometry(c_characterX - 120, c_characterY - 115, m_width, m_height);
   if (!isface)c_tuid = c_characterX-140;
   if (isface)c_tuid = c_characterX + 120;
    c_characterLabel->setMovie(c_tui);
    c_tui->start();
    // ��ȡ���ܶ�����֡��
    int c_totalFrames = c_tui->frameCount();

    // ���� frameChanged �źŵ��ۺ���
    c_connection = connect(c_tui, &QMovie::frameChanged, this, [this, c_totalFrames]() {
        // ��ȡ��ǰ֡��
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
        // �ж��Ƿ�ﵽ��֡��
        if (c_currentFrame == c_totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            c_cantmove = false;
            c_isskill = false;
            c_characterLabel->clear();

            c_characterLabel->setMovie(c_characterMovie);
            c_tui->stop();
            //��ԭ��ɫλ��
          //  c_characterX += 45;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(c_connection);
        }
        });
}

void QtWidgetsApplication1::modifySize(QMovie* characterMovie)
{
    characterMovie->jumpToFrame(0); // ��ת����һ֡��ȷ����ȡ��ǰ֡
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
    // ��ȡ��Ļ�ֱ���
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // ����initgraph���ڵĴ�С
    int width = WIDTH;
    int height = HEIGHT;

    // ����initgraph����Ӧ�ó�������Ļ�����λ��
    int x = (screenWidth - width) / 2;
    int y = (screenHeight - height) / 2;

    // ��ʼ��ͼ�ν��棬���������ƶ����������λ��
    initgraph(width, height);
    HWND hwnd = GetHWnd();
    SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
}

void QtWidgetsApplication1::Interface(wchar_t* text)
{

    //����ע�͵������ǵ�����ʾ���ڣ������Ƿ�ʹ�ã��ɸ���ʵ�����������
    /*HWND hwnd;
    hwnd = GetHWnd();
    int is_ok = MessageBox(hwnd, _T(""), _T("��ʾ"), MB_OK);
    flushmessage(EM_MOUSE);*/
    initgraph(1024, 640, NOCLOSE | NOMINIMIZE);
    IMAGE img;
    CenterInitGraph();
    loadimage(&img, _T("E:\\MVandP\\p\\th.jpg"), 1024, 640);
    putimage(0, 0, &img);
    wchar_t Arr[] = _T("�˳���Ϸ");
    setlinecolor(YELLOW);
    settextcolor(BLACK);
    settextstyle(25, 0, _T("����"));
    setbkmode(TRANSPARENT);
    wchar_t arr[50] = { 0 };
    wcscpy_s(arr, text);
    fillroundrect(300, 200, 400 + textwidth(arr), 300 + textheight(arr), 50, 50);
    outtextxy(350, 250, arr);
    setlinecolor(YELLOW);
    settextcolor(BLACK);
    settextstyle(25, 0, _T("����"));
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
                    outtextxy(0, 0,_T("���������Ӻ��˳�"));
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
    //��ť״̬ͼ
    IMAGE MenuBtn01, MenuBtn11, MenuBtn00, MenuBtn10;
    loadimage(&MenuBtn00, _T("resources/chara_pic/MenuBtn00.png"), 725, 75);
    loadimage(&MenuBtn01, _T("resources/chara_pic/MenuBtn01.png"), 725, 75);
    loadimage(&MenuBtn10, _T("resources/chara_pic/MenuBtn10.png"), 725, 80);
    loadimage(&MenuBtn11, _T("resources/chara_pic/MenuBtn11.png"), 725, 80);
    mciSendStringA("open resources/music/WHU��.mp3 alias BGM", 0, 0, 0);
    mciSendStringA("play BGM ", 0, 0, 0);
    //������
    MOUSEMSG msg;
    GetMouseMsg();
    bool MenuStatus = true;
    while (MenuStatus)
    {
        if (MouseHit())
        {
            msg = GetMouseMsg();
            //ʵ�����������ť����ť��ʽ�ı�
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
            //ʵ���������ť����ת����Ϸ����
            case WM_LBUTTONDOWN:

                if (msg.x > 150 && msg.x < 875 && msg.y>435 && msg.y < 510)
                {
                    cleardevice();
                    closegraph();
                    choice = 1;
                    mciSendStringA("close BGM ", 0, 0, 0);
                    //������Ϸ��ť
                }
                else if (msg.x > 150 && msg.x < 875 && msg.y>540 && msg.y < 620)
                {
                    cleardevice();
                    closegraph();
                    choice = 2;
                    mciSendStringA("close BGM ", 0, 0, 0);
                    //������Ϸ��ť
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
    settextstyle(60, 40, _T("����"));
    wchar_t text[50] = _T("�����ֻ��ʤ����");
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
    settextstyle(60, 40, _T("����"));
    wchar_t text[50] = _T("���������ʤ����");
    outtextxy(512 - textwidth(text) / 2, 320 - textheight(text) / 2, text);
    Sleep(5000);*/
    Sleep(5000);
    closegraph();
}

void QtWidgetsApplication1::ENDC()
{
    // ���ñ�־λΪ true����ʾ�����ͷż���
    cantmove = true;
    c_cantmove = true;
    boolENDCHARA = true;
    // ��ͣ�����������繥�����ƶ�
    // ...

    // ���ż��ܶ��� 

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
    // ��ȡ���ܶ�����֡��
    int totalFrames = ENDC_CHARA->frameCount();
    // ���� frameChanged �źŵ��ۺ���
    connection = connect(ENDC_CHARA, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = ENDC_CHARA->currentFrameNumber();
        if (currentFrame == 10) {
            ENDC_CHARA->stop();
            delete ENDC_CHARA;
        }
       //  �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            cantmove = false;
            isskill = false;
          //  boolskill2 = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
            //skill2->stop();
            //��ԭ��ɫλ��
            c_characterX += 1005;
            c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
            disconnect(connection);
        }
        });

}

void QtWidgetsApplication1::ENDC2()
{
    // ���ñ�־λΪ true����ʾ�����ͷż���
    cantmove = true;
    c_cantmove = true;
    boolENDCHARA = true;
    boolENDCHARA2 = true;
    // ��ͣ�����������繥�����ƶ�
    // ...

    // ���ż��ܶ��� 
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

    // ��ȡ���ܶ�����֡��
    int totalFrames = ENDCHARA2->frameCount();
    // ���� frameChanged �źŵ��ۺ���
    connection = connect(ENDCHARA2, &QMovie::frameChanged, this, [this, totalFrames]() {
        // ��ȡ��ǰ֡��
        int currentFrame = ENDCHARA2->currentFrameNumber();
        if (currentFrame == 30) {
            ENDCHARA2->stop();
            delete ENDCHARA2;
           // characterLabel->setGeometry(characterX+1000, characterY+1000, m_width, m_height);
        }
        // �ж��Ƿ�ﵽ��֡��
        if (currentFrame == totalFrames - 1) {
            // ����������һ�飬ֹͣ���ܶ���
            cantmove = false;
            isskill = false;
           // boolskill2 = false;
            characterLabel->clear();
            characterLabel->setMovie(characterMovie);
          //  skill2->stop();
            //��ԭ��ɫλ��
            characterX += 1005;
            characterLabel->setGeometry(characterX, characterY, m_width, m_height);
            disconnect(connection);
        }
        });

  
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

