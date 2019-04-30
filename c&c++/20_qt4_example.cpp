/* PREREQUISITE:
 * Ubuntu / Debian: sudo apt install qt4-dev-tools libqtgui4 libqtcore4
 *
 * REFERENCE:
 * [Book] C++ GUI Programming with Qt 4
 *
 * COMPILATION:
 * g++ -o qt_gui 20_qt4_example.cpp -I /usr/include/qt4/ -lQtGui -lQtCore
 */
#include <QtGui/QApplication>
#include <QtGui/QLabel>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  QLabel *label = new QLabel("Hello Qt!");
  label->setFixedSize(200,150);
  label->show();

  app.exec();
  return 0;
}

