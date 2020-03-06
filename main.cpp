
#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLNativeWidget.h>


#include "shape.h"

// int main(int argc, char *argv[])
// {
//   QApplication a(argc, argv);
//   shape w;
//   w.show();
//   return a.exec();
// }


int main(int argc, char *argv[]) {
  // before initializing QApplication, set the default surface format.
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

  QApplication app(argc, argv);

  ShapeApp window;
  window.show();

  return app.exec();
}