#include <QtGui/QApplication>
#include <QtDeclarative>
#include <QVector>
#include "qmlapplicationviewer.h"
#include "code/gameengine.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<GameEngine>("Engine",1,0,"GameEngine");

    QmlApplicationViewer viewer;

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/SaveThePrincess/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
