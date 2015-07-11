#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <ring.h>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	qmlRegisterType<Ring>("Ring", 1, 0, "Ring");

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

	return app.exec();
}
