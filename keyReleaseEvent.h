#pragma once
#include "QtWidgetsApplication2.h"
void QtWidgetsApplication1::keyReleaseEvent(QKeyEvent* event)
{

    

    if ((event->key() == Qt::Key_A || event->key() == Qt::Key_D) && !cantmove && !isAttacking)
    {
        // 松开 A 或 D 键，停止移动

        moveTimer->stop();
        //jumpTimer->stop();
        //downTimer->start();
        direction01 = directions::none;
        // 设置角色的动画
        characterLabel->clear();
        characterLabel->setMovie(characterMovie);
        characterMovie->start();
        // forwardMovie->stop();
        // backwardMovie->stop(); 
    }
    if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) && !c_cantmove && !c_isAttacking)
    {
        // 松开 ← 或 → 键，停止移动

        c_moveTimer->stop();
        //jumpTimer->stop();
        //downTimer->start();

        c_direction01 = directions::none;

        // 设置角色的动画
        c_characterLabel->clear();
        c_characterLabel->setMovie(c_characterMovie);
        c_characterMovie->start();
        // forwardMovie->stop();
        // backwardMovie->stop(); 
    }

    //松开空格时
    else if (event->key() == Qt::Key_Space && !cantmove)
    {
        if (characterY < characterY0 && vy>0)
        {
        };
        if (characterY >= characterY0 && vy >= jump_speed)
        {
            isjumping = false;
            jumpTimer->stop();
            direction02 = directions::none;
            vy = 0;
        }
    }
    //松开0时
    else if (event->key() == Qt::Key_0 && !c_cantmove)
    {
        if (c_characterY < c_characterY0 && vy>0)
        {
        };
        if (c_characterY >= c_characterY0 && vy >= jump_speed)
        {
            c_isjumping = false;
            c_jumpTimer->stop();
            c_direction02 = directions::none;
            vy = 0;
        }
    }
    else if (event->key() == Qt::Key_J && !cantmove && !event->isAutoRepeat())
    {
        // 松开 J 键，停止攻击
        if (iscrouch) {
            isAttacking = false;
            characterLabel->clear();
            characterLabel->setMovie(crouchMovie);
            characterMovie->start();
        }
        else if (isAttacking) {
            if (!atkdetc)jatt();
        }
    }
    //else if (event->key() == Qt::Key_K && !cantmove)
    //{
    //    // 松开 K 键，停止攻击
    //    /*if (c_iscrouch) {
    //        c_isAttacking = false;
    //        c_characterLabel->clear();
    //        c_characterLabel->setMovie(c_crouchMovie);
    //        c_characterMovie->start();
    //    }*/
    //    if (isAttacking) {
    //        isAttacking = false;
    //        // attackMovie->stop();
    //        characterLabel->clear();
    //        characterLabel->setMovie(characterMovie);
    //        characterMovie->start();
    //    }
    //}
    else if (event->key() == Qt::Key_1 && !c_cantmove)
    {
        // 松开 1 键，停止攻击
        //if (c_iscrouch) {
        //    c_isAttacking = false;
        //    c_characterLabel->clear(); //c_attackMovie->stop();
        //    c_characterLabel->setMovie(c_characterMovie);
        //    c_characterMovie->start();
        //}
       //if (c_isAttacking) {
       //     c_isAttacking = false;
       //     // attackMovie->stop();
       //     c_characterLabel->clear(); c_attackMovie->stop();
       //     c_characterLabel->setMovie(c_characterMovie);
       //     c_characterMovie->start();
       // }
    }

    else if (event->key() == Qt::Key_S && !cantmove)
    {
        isAttacking = false;

        iscrouch = false;
        attackMovie->stop();
        characterLabel->clear();
        //characterLabel->setGeometry(characterX, characterY, m_width, m_height);
        characterLabel->setMovie(characterMovie);
        characterMovie->start();
    }
    else if (event->key() == Qt::Key_Down && !c_cantmove && !c_isAttacking)
    {
        //isAttacking = false;
        c_iscrouch = false;
        c_attackMovie->stop();
        c_characterLabel->clear();
        c_characterLabel->setGeometry(c_characterX, c_characterY, m_width, m_height);
        c_characterLabel->setMovie(c_characterMovie);
        c_characterMovie->start();
    }
    // 调用父类的事件处理函数
    QMainWindow::keyReleaseEvent(event);
}