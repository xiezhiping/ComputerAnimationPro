#include "qtquick2applicationviewer.h"
#include <QtGui/QGuiApplication>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QtQuick2ApplicationViewer viewer;
	viewer.setMainQmlFile(QStringLiteral("main.qml"));
	viewer.showExpanded();

	return app.exec();
}
