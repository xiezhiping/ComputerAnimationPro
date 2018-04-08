#ifndef QTQUICK2APPLICATIONVIEWER_H
#define QTQUICK2APPLICATIONVIEWER_H

#include <QtQuick/QQuickView>

class QtQuick2ApplicationViewer : public QQuickView
{
	Q_OBJECT

public:
	explicit QtQuick2ApplicationViewer(QWindow *parent = 0);
	virtual ~QtQuick2ApplicationViewer();

	void setMainQmlFile(const QString &file);
	void addImportPath(const QString &path);

	void showExpanded();

private:
	class QtQuick2ApplicationViewerPrivate *d;
};

#endif // QTQUICK2APPLICATIONVIEWER_H
