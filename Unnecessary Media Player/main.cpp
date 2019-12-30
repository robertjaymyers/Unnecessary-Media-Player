/*
This file is part of UnnecessaryMediaPlayer.
	UnnecessaryMediaPlayer is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	UnnecessaryMediaPlayer is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with UnnecessaryMediaPlayer.  If not, see <https://www.gnu.org/licenses/>.
*/

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
