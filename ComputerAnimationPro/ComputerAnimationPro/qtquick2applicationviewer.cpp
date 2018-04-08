#include "qtquick2applicationviewer.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>

class QtQuick2ApplicationViewerPrivate
{
	QString mainQmlFile;
	friend class QtQuick2ApplicationViewer;
	static QString adjustPath(const QString &path);
};

QString QtQuick2ApplicationViewerPrivate::adjustPath(const QString &path)
{
	return path;
}

QtQuick2ApplicationViewer::QtQuick2ApplicationViewer(QWindow *parent)
	: QQuickView(parent)
	, d(new QtQuick2ApplicationViewerPrivate())
{
	connect(engine(), SIGNAL(quit()), SLOT(close()));
	setResizeMode(QQuickView::SizeRootObjectToView);
}

QtQuick2ApplicationViewer::~QtQuick2ApplicationViewer()
{
	delete d;
}

void QtQuick2ApplicationViewer::setMainQmlFile(const QString &file)
{
	d->mainQmlFile = QtQuick2ApplicationViewerPrivate::adjustPath(file);
	setSource(QUrl::fromLocalFile(d->mainQmlFile));
}

void QtQuick2ApplicationViewer::addImportPath(const QString &path)
{
	engine()->addImportPath(path);
}

void QtQuick2ApplicationViewer::showExpanded()
{
#if defined(Q_WS_SIMULATOR)
	showFullScreen();
#else
	show();
#endif
}
