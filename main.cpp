#include "QtWidgetsApplication2.h"
//#include"GameControl.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    
    QApplication app(argc, argv);
    QtWidgetsApplication1 mainWindow; 
    mainWindow.setWindowTitle("KOF_97");
    //GameControl game;
	//game.play(&mainWindow);
    mainWindow.show();
	
	
    return app.exec();
}