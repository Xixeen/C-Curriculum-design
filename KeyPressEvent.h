#pragma once
#include "QtWidgetsApplication2.h"
void QtWidgetsApplication1::keyPressEvent(QKeyEvent* event)
{
    //if (cantmove) { return; }

    if (event->key() == Qt::Key_A && cantmove == false&&!isAttacking)
    {
        //if (cantmove);
        // ���� A ���������ƶ�
        isMove = true;
        direction01 = directions::left;
        if (!moveTimer->isActive()) {
            moveTimer->start(20);      // ����ÿ֡ 16 ����
        }
        // ���ý�ɫ�Ķ���
        if (ishit) {//վ��
            characterLabel->clear();
            characterLabel->setMovie(zhanfang);
            zhanfang->start();
        }
        else
            if (!jumpTimer->isActive())
            {
                characterLabel->clear();
                characterLabel->setMovie(backwardMovie);
                backwardMovie->start();
            }
    }

    else if (event->key() == Qt::Key_Left && c_cantmove == false&&!c_isAttacking)
    {
        // ���� <- ���������ƶ�
        c_isMove = true;
        c_direction01 = directions::left;



        if (!c_moveTimer->isActive()) {
            c_moveTimer->start(19);      // ����ÿ֡ 16 ����
        }
        // ���ý�ɫ�Ķ���
         // ���ý�ɫ�Ķ���
        if (c_ishit) {//վ��
            c_characterLabel->clear();
            c_characterLabel->setMovie(c_zhanfang);
            c_zhanfang->start();
        }
        else
            if (!c_jumpTimer->isActive())
            {
                c_characterLabel->clear();
                c_characterLabel->setMovie(c_backwardMovie);
                c_backwardMovie->start();
            }
        /* if (boolskill0)characterLabel->setGeometry(characterX - 120, characterY - 115, m_width, m_height);
         if (boolskill2)    characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);*/

    }

    else if (event->key() == Qt::Key_S && cantmove == false&&!isjumping)
    {
        // ���� S �����¶�

         //�׷�
        if (ishit) {
            characterLabel->clear();
            //characterLabel->setGeometry(characterX + 150, characterY, m_width, m_height);
            characterLabel->setMovie(dunfang);
            dunfang->start();
        }

        else {
            iscrouch = true;
            direction01 = directions::none;
            if (!moveTimer->isActive()) {
                moveTimer->start(22);
            }
            // ���ý�ɫ�Ķ���
            if (!jumpTimer->isActive())
            {
                characterLabel->clear();
                characterLabel->setGeometry(characterX, characterY+750, m_width, m_height);
                characterLabel->setMovie(crouchMovie);
                crouchMovie->start();
            }
        }
    }

    else if (event->key() == Qt::Key_Down && c_cantmove == false&&!c_isjumping && !c_isAttacking)
    {
        // ���� �� �����¶�

        // �׷�
        //if (c_ishit) {
        //    c_characterLabel->clear();
        //    //c_characterLabel->setGeometry(c_characterX + 50, c_characterY, m_width, m_height);
        //    c_characterLabel->setMovie(c_dunfang);
        //    c_dunfang->start();
        //}

       // else {
            c_iscrouch = true;
            c_direction01 = directions::none;
            if (!c_moveTimer->isActive()) {
                c_moveTimer->start(19);
            }
            // ���ý�ɫ�Ķ���
            if (!c_jumpTimer->isActive())
            {
               /* c_characterLabel->clear();
                c_characterLabel->setMovie(c_crouchMovie);
                c_crouchMovie->start();*/
            }
      //  }
    }

    else if (event->key() == Qt::Key_D && cantmove == false &&!isAttacking)
    {
        // ���� D ���������ƶ�
        isMove = true;
        direction01 = directions::right;
        if (!moveTimer->isActive()) {
            moveTimer->start(19);
        }
        // ���ý�ɫ�Ķ���
        if (!jumpTimer->isActive())
        {
            characterLabel->clear();
            characterLabel->setMovie(forwardMovie);
            forwardMovie->start();
        }
        // if(boolskill0==true||boolskill2==true)    characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);

    }

    else if (event->key() == Qt::Key_Right && c_cantmove == false)
    {
        // ���� �� ���������ƶ�
        c_isMove = true;
        c_direction01 = directions::right;
        if (!c_moveTimer->isActive()) {
            c_moveTimer->start(19);
        }
        // ���ý�ɫ�Ķ���
        if (!c_jumpTimer->isActive())
        {
            c_characterLabel->clear();
            c_characterLabel->setMovie(c_forwardMovie);
            c_forwardMovie->start();
        }
    }

    else if (event->key() == Qt::Key_J && cantmove == false&&!jumpTimer->isActive())
    {
        // ����J�������й�������
        if (iscrouch) {
            moveTimer->stop();
            jumpTimer->stop();
            isAttacking = true;
            characterMovie->stop();
            // ��ն�����ǩ����
            characterLabel->clear();
            // �л�Ϊ��������
            characterLabel->setMovie(crouchAttack);
            crouchAttack->start();
        }
        else if (!isAttacking)
        {
            isskill = true;
            isAttacking = true;
            characterMovie->stop();
            if (!jumpTimer->isActive())
            {

                moveTimer->stop();
            }
            // ��ն�����ǩ����
            characterLabel->clear();
            // �л�Ϊ������
            if (!isface) {
                characterLabel->setMovie(attackMovie);
            }
            else {
                characterLabel->setGeometry(characterX - 220, characterY , m_width, m_height);
                characterLabel->setMovie(attackMovie);
            }
            attackMovie->start();
            //cantmove = 1;

            int atkframe = attackMovie->frameCount();

            // ���� frameChanged �źŵ��ۺ���
            atkconnection = connect(attackMovie, &QMovie::frameChanged, this, [this, atkframe]() {
                // ��ȡ��ǰ֡��
                int atkcframe = attackMovie->currentFrameNumber();

                // ֡��


                if (atkcframe == 4) {//��һȭ

                    if (distance <= 300)
                        c_healthValue -= 2;
                    energyValue += 3;
                }
                else if (atkcframe == 9) {//��һ��
                    if (distance <= 300)
                        c_healthValue -= 2;
                    energyValue += 3;

                }
                else if (atkcframe == 16) {//��һץ
                    if (distance <= 300)
                        c_healthValue -= 3;
                    energyValue += 3;

                }
                else if (atkcframe == 27) {//��һ����
                    if (distance <= 300)
                        c_healthValue -= 3;
                    energyValue += 3;

                }

                });




        }
    }

    else if (event->key() == Qt::Key_1 && c_cantmove == false && !c_jumpTimer->isActive())
    {
        // ����1�������й�������
        if (c_iscrouch) {
            mciSendString(L"play resources/cao_music/pinga.wav", 0, 0, 0);
            c_moveTimer->stop();
            c_jumpTimer->stop();
            c_isAttacking = true;
            c_cantmove = true;
            c_characterMovie->stop();
            // ��ն�����ǩ����
            c_characterLabel->clear();
            // �л�Ϊ��������
            c_characterLabel->setMovie(c_crouchAttack);
            c_crouchAttack->start();
            //if(!isface)c_dungongd-=
            if(!isface)c_characterLabel->setGeometry(c_characterX-150, c_characterY, m_width, m_height);
            if (!isface)c_dungongd = c_characterX-200;
            if (isface)c_dungongd = c_characterX + 200;
            // ��ȡ���ܶ�����֡��
            int c_totalFrames = c_crouchAttack->frameCount();

            // ���� frameChanged �źŵ��ۺ���
            c_connection = connect(c_crouchAttack, &QMovie::frameChanged, this, [this, c_totalFrames]() {
                // ��ȡ��ǰ֡��
                int c_currentFrame = c_crouchAttack->currentFrameNumber();
                if (c_currentFrame == 4) {
                    if (!isface) 
                    { 
                        if (abs(characterX - c_dungongd) < 100)
                        {
                            c_energyValue += 3;
                            if(!is6)healthValue -= 3;
                            else healthValue -= 6;
                            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
                        }
                    }
                    else 
                    { 
                        if (abs(characterX - c_dungongd) < 100)
                        { 
                            c_energyValue += 3;
                            if (!is6)healthValue -= 3;
                            else healthValue -= 6;
                            mciSendString(L"play resources/music/shouji.wav", 0, 0, 0);
                        }
                    
                    }
                }
                // �ж��Ƿ�ﵽ��֡��
                if (c_currentFrame == c_totalFrames - 1) {
                    // ����������һ�飬ֹͣ���ܶ���
                    c_cantmove = false;
                    c_isdungong = false;
                    c_isAttacking = false;
                    c_characterLabel->clear();
                    c_characterLabel->setMovie(c_characterMovie);
                    c_characterMovie->start();
                    c_crouchAttack->stop();
                    //��ԭ��ɫλ��
                  //c_characterX += 45;
                    c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
                    disconnect(c_connection);
                }
                });

        }
        else if (!c_isAttacking)
        {
            mciSendString(L"play resources/cao_music/pinga.wav", 0, 0, 0);
            c_isAttacking = true;
            c_iszhangong = true;
            c_cantmove = true;
            c_isskill = true;
            c_characterMovie->stop();
            c_moveTimer->stop();
           
            // ��ն�����ǩ����
            c_characterLabel->clear();
            // �л�Ϊ������
            c_characterLabel->setMovie(c_attackMovie);
            c_attackMovie->start();
            if(!isface)c_characterLabel->setGeometry(c_characterX - 50, c_characterY, m_width, m_height);
            if(isface)c_characterLabel->setGeometry(c_characterX - 60, c_characterY, m_width, m_height);
            if (!isface)c_zhangongd = c_characterX-140;
            if(isface)c_zhangongd = c_characterX+160;

            int c_totalFrames = c_attackMovie->frameCount();

            // ���� frameChanged �źŵ��ۺ���
            c_connection = connect(c_attackMovie, &QMovie::frameChanged, this, [this, c_totalFrames]() {
                // ��ȡ��ǰ֡��
                int c_currentFrame = c_attackMovie->currentFrameNumber();
                if (c_currentFrame == 3) {
                    if (!isface) 
                    { 
                        if (abs(characterX - c_zhangongd) < 100)
                        {
                            if(!is6)healthValue -= 3;
                            else healthValue -= 6;
                            c_energyValue += 3;
                        }
                    }
                    else 
                    { 
                        if (abs(characterX - c_zhangongd) < 100)
                        {
                            if (!is6)healthValue -= 3;
                            else healthValue -= 6;
                            c_energyValue += 3;
                        }

                    }
                }
                // �ж��Ƿ�ﵽ��֡��
                if (c_currentFrame == c_totalFrames - 1) {
                    // ����������һ�飬ֹͣ���ܶ���
                    c_cantmove = false;
                    c_iszhangong = false;
                    c_isskill = false;
                    c_isAttacking = false;
                    c_characterLabel->clear();
                    c_characterLabel->setMovie(c_characterMovie);
                    c_characterMovie->start();
                    c_attackMovie->stop();
                    //��ԭ��ɫλ��
                  //  c_characterX += 45;
                    c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
                    disconnect(c_connection);
                }
                });


        }
    }

    else if (event->key() == Qt::Key_K && cantmove == false && !isjumping)
    { 
        if (!isAttacking)
        {
            // ����U��������skill0����
            if (!jumpTimer->isActive()&&energyValue>=20) {
                // if (boolskill0 == true || boolskill2 == true)    characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
                mciSendString(L"play resources/music/k.wav", 0, 0, 0);
                castK();
            }
        }
    }
   
    else if (event->key() == Qt::Key_L && cantmove == false && !isjumping)
    {
        if (!isAttacking)
        {
            // ����U��������skill0����
            if (!jumpTimer->isActive()) {
                isskill = true;
                // if (boolskill0 == true || boolskill2 == true)    characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
                mciSendString(L"play resources/music/sousoumama.wav", 0, 0, 0);
                castL();
            }
        }
        }
    
    else if (event->key() == Qt::Key_2 && c_cantmove == false)
    {
        if (!isAttacking)
        {
            // ����U��������c_skill0����
            if (!c_jumpTimer->isActive()&&c_energyValue>=8) {
                // if (boolskill0 == true || boolskill2 == true)    characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
                mciSendString(L"play resources/music/dashe2.wav", 0, 0, 0);
                c_energyValue -= 8;
                c_cast2();
            }
        }
    }

    else if (event->key() == Qt::Key_3 && c_cantmove == false)
    {
        if (!c_isAttacking)
        {
            // ����U��������c_skill0����
            if (!c_jumpTimer->isActive()) {
                c_isskill = true;
                // if (boolskill0 == true || boolskill2 == true)    characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
                mciSendString(L"play resources/music/dasheshanbi.wav", 0, 0, 0);
                // mciSendString(L"play resources/music/sousoumama.wav", 0, 0, 0);
                c_cast3();
            }
        }
    }
   
    else if (event->key() == Qt::Key_U && cantmove == false)
    {
        // ����U��������skill0����
        if (!jumpTimer->isActive()&&energyValue>=15) {
            // if (boolskill0 == true || boolskill2 == true)    characterLabel->setGeometry(characterX - 45, characterY - 115, m_width, m_height);
            mciSendString(L"play resources/music/sousoumama.wav", 0, 0, 0);
            energyValue -= 15;
            castSkill0();
        }

    }

    else if (event->key() == Qt::Key_4 && c_cantmove == false)
    {
        // ����4��������skill0����
        if (!c_jumpTimer->isActive()&& c_energyValue >= 10) {
            mciSendString(L"play resources/dashe_music/skill0.wav", 0, 0, 0);
            c_energyValue -= 10;
            c_castSkill0();
        }

    }

    else if (event->key() == Qt::Key_I && cantmove == false)
    {
        // ����U��������skill1����

        if (!jumpTimer->isActive()&& energyValue >= 10) {
            mciSendString(L"play resources/music/skill1.wav", 0, 0, 0);
            energyValue -= 10;
            castSkill1();
        }
    }

    else if (event->key() == Qt::Key_5 && c_cantmove == false)
    {
        // ����5��������c_skill1����
        if (!c_jumpTimer->isActive()&&c_energyValue>=20) {
            mciSendString(L"play resources/dashe_music/skill1.wav", 0, 0, 0);
            c_energyValue -= 20;
            c_castSkill1();
        }
    }

    else if (event->key() == Qt::Key_O && cantmove == false)
    {
        // ����O��������skill2����
        if (!jumpTimer->isActive()&&energyValue >= 10) {
            mciSendString(L"play resources/music/skill2.wav", 0, 0, 0);
            energyValue -= 10;
            castSkill2();
        }

    }

    else if (event->key() == Qt::Key_6 && c_cantmove == false&& c_healthValue >= 20&& c_energyValue >= 20)
    {
        // ����6��������c_skill2����
        if (!c_jumpTimer->isActive()) {
        //    mciSendString(L"play resources/music/skill2.wav", 0, 0, 0);

            is6 = true;
            c_castSkill2();
        }

    }

    else if (event->key() == Qt::Key_Space && cantmove == false)
    {  
        // �����ɫ�ڵ����ϣ�������Ծ
        mciSendString(L"play resources/music/jump.wav", 0, 0, 0);
        if (characterY == characterY0)
        {
            if (isMove)
            {
                isjumping = true;
                characterLabel->clear();
                //"D:\QtWidgetsApplication2\resources\music\tiao.mp3"
                  //  mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);
                characterLabel->setMovie(jump);
                jump->start();
            }
            // ���ý�ɫ�Ķ���
            characterLabel->clear();
            jumpMovie->jumpToFrame(0); // ��ת����һ֡��ȷ����ȡ��ǰ֡
            characterLabel->setMovie(jumpMovie);
           // "D:\QtWidgetsApplication2\resources\music\tiao.wav"
            mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);
            jumpMovie->start();

            // ������Ծ������ٶ�
            direction02 = directions::up;
            vy = jump_speed;
            // ������Ծ��ʱ��
            jumpTimer->start(15);
        }
    }

    else if (event->key() == Qt::Key_0 && c_cantmove == false)
    {
        mciSendString(L"play resources/music/dashejump.wav", 0, 0, 0);

        // �����ɫ�ڵ����ϣ�������Ծ
        if (c_characterY == c_characterY0)
        {
            if (c_isMove)
            {
                c_isjumping = true;
                c_characterLabel->clear();
                c_characterLabel->setMovie(c_jump);
                c_jump->start();
            }
            // ���ý�ɫ�Ķ���
            c_characterLabel->clear();
            c_jumpMovie->jumpToFrame(0); // ��ת����һ֡��ȷ����ȡ��ǰ֡
            c_characterLabel->setMovie(c_jumpMovie);
            c_jumpMovie->start();
            mciSendString(L"play resources/music/tiao.wav", 0, 0, 0);
            // ������Ծ������ٶ�
            c_direction02 = directions::up;
            c_vy = jump_speed;
            // ������Ծ��ʱ��
            c_jumpTimer->start(15);
        }
    }

    /*else if (event->type() == QEvent::KeyRelease) {
       if (event->key() == Qt::Key_A || event->key() == Qt::Key_D) {
           moveTimer->stop();
           direction = directions::none;
       }
   }*/
   // ���½�ɫ��λ��

   //QLabel* characterLabel = this->characterLabel; 
   //characterLabel->move(characterX, characterY);

   // ���ø�����¼�������
    QMainWindow::keyPressEvent(event);

}