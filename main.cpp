/*
   ____  ___  ____      ____  _     _____ ____ ____      _   _  ___      ____  _   _  ____ 
  / ___|/ _ \|  _ \    | __ )| |   | ____/ ___/ ___|    | \ | |/ _ \    | __ )| | | |/ ___|
 | |  _| | | | | | |   |  _ \| |   |  _| \___ \___ \    |  \| | | | |   |  _ \| | | | |  _ 
 | |_| | |_| | |_| |   | |_) | |___| |___ ___) |__) |   | |\  | |_| |   | |_) | |_| | |_| |
  \____|\___/|____/    |____/|_____|_____|____/____/    |_| \_|\___/    |____/ \___/ \____|
                                                                                     
*/

#include "bank.h"
#include "bankserver.h"

#include <QApplication>
#include <QDebug>

bankServer bankserver;

int main(int argc, char *argv[])
{
  //qDebug()<<("程序开始\n");
  QApplication a(argc, argv);

  bank w;
  w.show();

  return a.exec();
}
