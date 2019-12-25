#include "UnnecessaryMediaPlayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/Icon\\app-icon-unnecessary-media-player.ico"));
	UnnecessaryMediaPlayer w;
	w.show();
	return a.exec();
}
