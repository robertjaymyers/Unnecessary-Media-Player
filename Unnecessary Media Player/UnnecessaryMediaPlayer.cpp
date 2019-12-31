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

UnnecessaryMediaPlayer::UnnecessaryMediaPlayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	layout.get()->setMargin(0);
	ui.centralWidget->setLayout(layout.get());

	playerProgressSlider.get()->setOrientation(Qt::Horizontal);
	playerProgressSlider.get()->setStyleSheet(styleSheetSliderLight);
	playerUiSliderVolume.get()->setOrientation(Qt::Horizontal);
	playerUiSliderVolume.get()->setStyleSheet(styleSheetSliderLight);
	playerUiSliderVolume.get()->setRange(0, 100);
	playerUiSliderVolume.get()->setMaximumWidth(100);

	styleLightPalette.setColor(QPalette::Window, QColor("#F0F0F0"));
	styleLightPalette.setColor(QPalette::WindowText, QColor("#000000"));
	styleLightPalette.setColor(QPalette::Text, QColor("#000000"));
	styleLightPalette.setColor(QPalette::ButtonText, QColor("#000000"));
	this->setPalette(styleLightPalette);

	styleNightPalette.setColor(QPalette::Window, QColor("#000000"));
	styleNightPalette.setColor(QPalette::WindowText, QColor("#FFC000"));
	styleNightPalette.setColor(QPalette::Text, QColor("#FFC000"));
	styleNightPalette.setColor(QPalette::ButtonText, QColor("#FFC000"));

	QPalette videoWidgetPalette = palette();
	videoWidgetPalette.setColor(QPalette::Window, Qt::black);
	videoWidget.get()->setPalette(videoWidgetPalette);
	videoWidget.get()->setAttribute(Qt::WA_OpaquePaintEvent);
	videoWidget.get()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	layout.get()->addWidget(videoWidget.get());
	layout.get()->addWidget(playerProgressSlider.get());

	playerUiSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	playerUiLabelMediaLengthPassed->setObjectName(QStringLiteral("playerUiLabelMediaLengthPassed"));
	playerUiLabelMediaLengthPassed->setText("| 00:00:00 / ");
	playerUiLabelMediaLengthTotal->setObjectName(QStringLiteral("playerUiLabelMediaLengthTotal"));
	playerUiLabelMediaLengthTotal->setText("00:00:00");

	playerUiLabelDividerPlayback->setObjectName(QStringLiteral("playerUiLabelDividerPlayback"));
	playerUiLabelDividerPlayback->setText(labelDividerText);
	playerUiLabelDividerPlayback->setMargin(labelDividerMargin);
	playerUiLabelDividerMedia->setObjectName(QStringLiteral("playerUiLabelDividerMedia"));
	playerUiLabelDividerMedia->setText(labelDividerText);
	playerUiLabelDividerMedia->setMargin(labelDividerMargin);
	playerUiLabelDividerStyle->setObjectName(QStringLiteral("playerUiLabelDividerStyle"));
	playerUiLabelDividerStyle->setText(labelDividerText);
	playerUiLabelDividerStyle->setMargin(labelDividerMargin);

	playerUiBtnPlayPause->setObjectName(QStringLiteral("playerUiBtnPlayPause"));
	playerUiBtnPlayPause->setText("Play");
	playerUiBtnStop->setObjectName(QStringLiteral("playerUiBtnStop"));
	playerUiBtnStop->setText("Stop");
	playerUiBtnMute->setObjectName(QStringLiteral("playerUiBtnMute"));
	playerUiBtnMute->setText("Mute");
	playerUiBtnPrevious->setObjectName(QStringLiteral("playerUiBtnPrevious"));
	playerUiBtnPrevious->setText("Previous");
	playerUiBtnNext->setObjectName(QStringLiteral("playerUiBtnNext"));
	playerUiBtnNext->setText("Next");
	playerUiBtnPlaybackMode->setObjectName(QStringLiteral("playerUiBtnPlaybackMode"));
	playerUiBtnPlaybackMode->setText("Loop");
	playerUiBtnAddMedia->setObjectName(QStringLiteral("playerUiBtnAddMedia"));
	playerUiBtnAddMedia->setText("Add To Playlist");
	playerUiBtnRemoveMedia->setObjectName(QStringLiteral("playerUiBtnRemoveMedia"));
	playerUiBtnRemoveMedia->setText("Remove From Playlist");
	playerUiBtnLoadPlaylist->setObjectName(QStringLiteral("playerUiBtnLoadPlaylist"));
	playerUiBtnLoadPlaylist->setText("Load Playlist");
	playerUiBtnSavePlaylist->setObjectName(QStringLiteral("playerUiBtnSavePlaylist"));
	playerUiBtnSavePlaylist->setText("Save Playlist");
	playerUiBtnToggleStyle->setObjectName(QStringLiteral("playerUiBtnToggleStyle"));
	playerUiBtnToggleStyle->setText("Toggle Night Light");
	playerUiBtnFullscreen->setObjectName(QStringLiteral("playerUiBtnFullscreen"));
	playerUiBtnFullscreen->setText("Fullscreen");

	playerUi->setParent(this);
	playerUi->setObjectName(QStringLiteral("playerInterfaceToolBar"));
	this->addToolBar(Qt::BottomToolBarArea, playerUi.get());
	playerUi->setMovable(false);

	playerUi->addWidget(playerUiLabelMediaLengthPassed.get());
	playerUi->addWidget(playerUiLabelMediaLengthTotal.get());

	playerUi->addWidget(playerUiLabelDividerPlayback.get());
	playerUi->addAction(playerUiBtnPlayPause.get());
	playerUi->addAction(playerUiBtnStop.get());
	playerUi->addAction(playerUiBtnMute.get());
	playerUi->addWidget(playerUiSliderVolume.get());
	playerUi->addAction(playerUiBtnPrevious.get());
	playerUi->addAction(playerUiBtnNext.get());
	playerUi->addAction(playerUiBtnPlaybackMode.get());

	playerUi->addWidget(playerUiLabelDividerMedia.get());
	playerUi->addAction(playerUiBtnAddMedia.get());
	playerUi->addAction(playerUiBtnRemoveMedia.get());
	playerUi->addAction(playerUiBtnLoadPlaylist.get());
	playerUi->addAction(playerUiBtnSavePlaylist.get());

	playerUi->addWidget(playerUiLabelDividerStyle.get());
	playerUi->addAction(playerUiBtnToggleStyle.get());

	playerUi->addWidget(playerUiSpacer.get());
	playerUi->addAction(playerUiBtnFullscreen.get());

	playlist->setPlaybackMode(QMediaPlaylist::Loop);
	player->setPlaylist(playlist.get());
	videoWidget->setAspectRatioMode(Qt::KeepAspectRatio);
	player->setVideoOutput(videoWidget.get());
	videoWidget->show();

	if (validCmdLineIsRead())
	{
		player->play();
	}
	else
	{
		setWindowState(Qt::WindowMaximized);
		player->stop();
	}

	playlistUpdateUi();
	setIconsByStyle();

	connect(this->playlist.get(), &QMediaPlaylist::mediaInserted, this, &UnnecessaryMediaPlayer::playlistUpdateUi);
	connect(this->playlist.get(), &QMediaPlaylist::mediaRemoved, this, &UnnecessaryMediaPlayer::playlistUpdateUi);

	connect(this->player.get(), &QMediaPlayer::positionChanged, this, &UnnecessaryMediaPlayer::playerUpdateMediaLengthPassed);
	connect(this->player.get(), &QMediaPlayer::durationChanged, this, &UnnecessaryMediaPlayer::playerUpdateMediaLengthTotal);
	connect(playerProgressSlider.get(), &QSlider::sliderMoved, this, &UnnecessaryMediaPlayer::playerUpdateMediaSliderMoved);
	connect(playerProgressSlider.get(), &QSlider::sliderReleased, this, &UnnecessaryMediaPlayer::playerUpdateMediaSliderReleased);

	connect(this->playerUiBtnPlayPause.get(), &QAction::triggered, this, [=]() {
		if (player->state() == QMediaPlayer::StoppedState || player->state() == QMediaPlayer::PausedState)
			player->play();
		else if (player->state() == QMediaPlayer::PlayingState)
			player->pause();
	});

	connect(this->playerUiBtnStop.get(), &QAction::triggered, this, [=]() {
		if (player->state() == QMediaPlayer::PlayingState || player->state() == QMediaPlayer::PausedState)
		{
			player->stop();
			playerUiBtnPlayPause->setText("Play");
			playerUiBtnPlayPause->setIcon(QIcon(styleIconPlay.arg(styleIconMap.at(styleCurrent))));
		}
	});

	connect(this->player.get(), &QMediaPlayer::stateChanged, this, [=]() {
		if (player->state() == QMediaPlayer::StoppedState || player->state() == QMediaPlayer::PausedState)
		{
			playerUiBtnPlayPause->setText("Play");
			playerUiBtnPlayPause->setIcon(QIcon(styleIconPlay.arg(styleIconMap.at(styleCurrent))));
		}
		else if (player->state() == QMediaPlayer::PlayingState)
		{
			playerUiBtnPlayPause->setText("Pause");
			playerUiBtnPlayPause->setIcon(QIcon(styleIconPause.arg(styleIconMap.at(styleCurrent))));
		}
	});

	connect(this->playerUiBtnMute.get(), &QAction::triggered, this, [=]() {
		if (player->isMuted())
		{
			player->setMuted(false);
			playerUiBtnMute->setText("Mute");
			playerUiBtnMute->setIcon(QIcon(styleIconMute.arg(styleIconMap.at(styleCurrent))));
		}
		else
		{
			player->setMuted(true);
			playerUiBtnMute->setText("Unmute");
			playerUiBtnMute->setIcon(QIcon(styleIconMuted.arg(styleIconMap.at(styleCurrent))));
		}
	});

	connect(this->playerUiSliderVolume.get(), &QSlider::valueChanged, this, &UnnecessaryMediaPlayer::playerUpdateVolume);

	connect(this->playerUiBtnPrevious.get(), &QAction::triggered, this, [=]() {
		playlist->previous();
	});

	connect(this->playerUiBtnNext.get(), &QAction::triggered, this, [=]() {
		playlist->next();
	});

	connect(this->playerUiBtnPlaybackMode.get(), &QAction::triggered, this, [=]() {
		if (playlist->playbackMode() == QMediaPlaylist::Loop)
		{
			playlist->setPlaybackMode(QMediaPlaylist::Random);
			playerUiBtnPlaybackMode->setText("Shuffle");
			playerUiBtnPlaybackMode->setIcon(QIcon(styleIconShuffle.arg(styleIconMap.at(styleCurrent))));
		}
		else if (playlist->playbackMode() == QMediaPlaylist::Random)
		{
			playlist->setPlaybackMode(QMediaPlaylist::Sequential);
			playerUiBtnPlaybackMode->setText("Sequential");
			playerUiBtnPlaybackMode->setIcon(QIcon(styleIconSequential.arg(styleIconMap.at(styleCurrent))));
		}
		else if (playlist->playbackMode() == QMediaPlaylist::Sequential)
		{
			playlist->setPlaybackMode(QMediaPlaylist::Loop);
			playerUiBtnPlaybackMode->setText("Loop");
			playerUiBtnPlaybackMode->setIcon(QIcon(styleIconLoop.arg(styleIconMap.at(styleCurrent))));
		}
	});

	connect(this->playerUiBtnAddMedia.get(), &QAction::triggered, this, [=]() {
		QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Open"), fileDirLastOpened, tr("Video Files (*.wmv *.gif *.mp4 *.avi *.mp3 *.webm *.m4a *.wav);;AllFiles (*)"));
		if (!filenames.isEmpty())
		{
			for (auto& file : filenames)
			{
				playlist->addMedia(QUrl::fromLocalFile(file));
			}
			fileDirLastOpened = QFileInfo(filenames[0]).path();
		}
	});

	connect(this->playerUiBtnRemoveMedia.get(), &QAction::triggered, this, [=]() {
		if (QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier))
		{
			const QMessageBox::StandardButton ret
				= QMessageBox::warning(this, tr("Delete Playlist"),
					tr("Are you sure you want to remove everything from the playlist?"),
					QMessageBox::Yes | QMessageBox::No);

			if (ret == QMessageBox::Yes)
				playlist->clear();
		}
		else
		{
			std::map<QString, int> mediaUrlsMap;
			QStringList mediaUrls;
			for (int i = 0; i < playlist->mediaCount(); i++)
			{
				QString mediaKey = playlist->media(i).canonicalUrl().fileName();
				mediaUrlsMap.insert
				(
					std::pair<QString, int>
					(
						mediaKey,
						i
						)
				);
				mediaUrls.append(mediaKey);
			}

			bool ok;
			QString mediaToRemove = QInputDialog::getItem(
				this,
				tr("Playlist"),
				tr("Playlist Item:"),
				mediaUrls,
				0,
				false,
				&ok,
				Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

			if (ok && !mediaToRemove.isEmpty())
			{
				playlist->removeMedia(mediaUrlsMap.at(mediaToRemove));
			}
		}
	});

	connect(this->playerUiBtnSavePlaylist.get(), &QAction::triggered, this, [=]() {
		QFileDialog dialog(this, tr("Save As"), fileDirLastSaved, tr("Playlist Files (*.m3u)"));
		dialog.setWindowModality(Qt::WindowModal);
		dialog.setAcceptMode(QFileDialog::AcceptSave);
		if (dialog.exec() == QFileDialog::Accepted)
		{
			if (playlist->save(QUrl::fromLocalFile(dialog.selectedFiles().first()), "m3u"))
				qDebug("Playlist saved.");
			else
				qDebug("Playlist failed to save.");
			fileDirLastSaved = QFileInfo(dialog.selectedFiles().first()).path();
		}
	});

	connect(this->playerUiBtnLoadPlaylist.get(), &QAction::triggered, this, [=]() {
		QString filename = QFileDialog::getOpenFileName(this, tr("Open"), fileDirLastOpened, tr("Playlist Files (*.m3u)"));
		if (!filename.isEmpty())
		{
			playlist->load(QUrl::fromLocalFile(filename));
			fileDirLastOpened = filename;
		}
	});

	connect(this->playerUiBtnToggleStyle.get(), &QAction::triggered, this, [=]() {
		if (styleCurrent == StyleName::LIGHT)
		{
			styleCurrent = StyleName::NIGHT;
			this->setPalette(styleNightPalette);
			playerProgressSlider.get()->setStyleSheet(styleSheetSliderNight);
			playerUiSliderVolume.get()->setStyleSheet(styleSheetSliderNight);
			setIconsByStyle();
		}
		else if (styleCurrent == StyleName::NIGHT)
		{
			styleCurrent = StyleName::LIGHT;
			this->setPalette(styleLightPalette);
			playerProgressSlider.get()->setStyleSheet(styleSheetSliderLight);
			playerUiSliderVolume.get()->setStyleSheet(styleSheetSliderLight);
			setIconsByStyle();
		}
	});

	connect(this->playerUiBtnFullscreen.get(), &QAction::triggered, this, [=]() {
		if (this->isFullScreen())
		{
			exitFullscreen();
		}
		else
		{
			if (windowState() == Qt::WindowMaximized)
				fullscreenPrevState = FullScreenPrevState::MAXIMIZED;
			else
				fullscreenPrevState = FullScreenPrevState::NORMAL;
			this->showFullScreen();
			playerUiBtnFullscreen->setIcon(QIcon(styleIconFullscreenOn.arg(styleIconMap.at(styleCurrent))));
		}
	});

	connect(this->shortcutFullscreenExit.get(), &QShortcut::activated, this, [=]() {
		if (this->isFullScreen())
		{
			exitFullscreen();
		}
	});

	connect(this->shortcutMovePositionLeft.get(), &QShortcut::activated, this, [=]() {
		if (player->position() - 1000 >= 0)
		{
			player->setPosition(player->position() - 1000);
		}
	});

	connect(this->shortcutMovePositionRight.get(), &QShortcut::activated, this, [=]() {
		if (player->position() + 1000 <= player->duration())
		{
			player->setPosition(player->position() + 1000);
		}
	});

	connect(this->shortcutPauseMedia.get(), &QShortcut::activated, this, [=]() {
		if (player->state() == QMediaPlayer::PausedState)
			player->play();
		else if (player->state() == QMediaPlayer::PlayingState)
			player->pause();
	});
}

// private:

bool UnnecessaryMediaPlayer::validCmdLineIsRead()
{
	if (QApplication::arguments().size() > 1)
	{
		QStringList validSuffixes = { "wmv", "gif", "mp4", "avi", "mp3", "webm", "m4a", "wav" };
		QString path = QApplication::arguments().at(1);
		if (!path.isEmpty() && player->isAvailable())
		{
			if (validSuffixes.contains(QFileInfo(path).suffix()))
			{
				playlist->addMedia(QUrl::fromLocalFile(path));
				fileDirLastOpened = QFileInfo(path).path();
				return true;
			}
			else
				QMessageBox::warning(this, tr("Media Not Loaded"), "You may be trying to load something from double-click that is not media, or is not considered standard.");
		}
	}

	return false;
}

void UnnecessaryMediaPlayer::exitFullscreen()
{
	if (fullscreenPrevState == FullScreenPrevState::MAXIMIZED)
		this->showMaximized();
	else if (fullscreenPrevState == FullScreenPrevState::NORMAL)
		this->showNormal();
	playerUiBtnFullscreen->setIcon(QIcon(styleIconFullscreenOff.arg(styleIconMap.at(styleCurrent))));
}

QTime UnnecessaryMediaPlayer::getMillisecondsAsTime(const qint64 &millisecondsTime)
{
	int seconds = (millisecondsTime / 1000) % 60;
	int minutes = (millisecondsTime / 60000) % 60;
	int hours = (millisecondsTime / 3600000) % 24;

	return QTime(hours, minutes, seconds);
}

void UnnecessaryMediaPlayer::setIconsByStyle()
{
	QString styleIconCurrent = styleIconMap.at(styleCurrent);

	if (player->state() == QMediaPlayer::PlayingState)
		playerUiBtnPlayPause->setIcon(QIcon(styleIconPause.arg(styleIconCurrent)));
	else if (player->state() == QMediaPlayer::PausedState || player->state() == QMediaPlayer::StoppedState)
		playerUiBtnPlayPause->setIcon(QIcon(styleIconPlay.arg(styleIconCurrent)));

	playerUiBtnStop->setIcon(QIcon(styleIconStop.arg(styleIconCurrent)));

	if (player->isMuted())
		playerUiBtnMute->setIcon(QIcon(styleIconMuted.arg(styleIconCurrent)));
	else
		playerUiBtnMute->setIcon(QIcon(styleIconMute.arg(styleIconCurrent)));

	playerUiBtnPrevious->setIcon(QIcon(styleIconPrevious.arg(styleIconCurrent)));
	playerUiBtnNext->setIcon(QIcon(styleIconNext.arg(styleIconCurrent)));

	if (playlist->playbackMode() == QMediaPlaylist::Loop)
		playerUiBtnPlaybackMode->setIcon(QIcon(styleIconLoop.arg(styleIconCurrent)));
	else if (playlist->playbackMode() == QMediaPlaylist::Random)
		playerUiBtnPlaybackMode->setIcon(QIcon(styleIconShuffle.arg(styleIconCurrent)));
	else if (playlist->playbackMode() == QMediaPlaylist::Sequential)
		playerUiBtnPlaybackMode->setIcon(QIcon(styleIconSequential.arg(styleIconCurrent)));

	playerUiBtnAddMedia->setIcon(QIcon(styleIconAddMedia.arg(styleIconCurrent)));
	playerUiBtnRemoveMedia->setIcon(QIcon(styleIconRemoveMedia.arg(styleIconCurrent)));
	playerUiBtnLoadPlaylist->setIcon(QIcon(styleIconOpenPlaylist.arg(styleIconCurrent)));
	playerUiBtnSavePlaylist->setIcon(QIcon(styleIconSavePlaylist.arg(styleIconCurrent)));
	playerUiBtnToggleStyle->setIcon(QIcon(styleIconToggleStyle.arg(styleIconCurrent)));

	if (this->isFullScreen())
		playerUiBtnFullscreen->setIcon(QIcon(styleIconFullscreenOn.arg(styleIconCurrent)));
	else
		playerUiBtnFullscreen->setIcon(QIcon(styleIconFullscreenOff.arg(styleIconCurrent)));
}

// private slots:

void UnnecessaryMediaPlayer::playlistUpdateUi()
{
	if (playlist->mediaCount() <= 0)
	{
		playerUiBtnPlayPause->setDisabled(true);
		playerUiBtnPlayPause->setToolTip(tooltipPlaylistEmpty);
		playerUiBtnPlayPause->setIcon(QIcon(styleIconPlay.arg(styleIconMap.at(styleCurrent))));
		playerUiBtnStop->setDisabled(true);
		playerUiBtnPrevious->setDisabled(true);
		playerUiBtnNext->setDisabled(true);
		playerUiBtnRemoveMedia->setDisabled(true);
		playerUiBtnSavePlaylist->setDisabled(true);
		playerUiBtnRemoveMedia->setToolTip("Nothing in the playlist to remove.");
	}
	else if (playlist->mediaCount() >= 1)
	{
		playerUiBtnPlayPause->setDisabled(false);
		playerUiBtnPlayPause->setToolTip(tooltipPlaylistContains.arg(QString::number(playlist->mediaCount())));
		playerUiBtnStop->setDisabled(false);
		playerUiBtnPrevious->setDisabled(false);
		playerUiBtnNext->setDisabled(false);
		playerUiBtnRemoveMedia->setDisabled(false);
		playerUiBtnRemoveMedia->setToolTip("Shift-click to remove all items.");
		playerUiBtnSavePlaylist->setDisabled(false);
		playerUiSliderVolume.get()->setValue(player->volume());
	}
}

void UnnecessaryMediaPlayer::playerUpdateMediaLengthPassed()
{
	qint64 position = player->position();

	if (!playerProgressSlider.get()->isSliderDown())
		playerProgressSlider.get()->setValue(position);

	playerUiLabelMediaLengthPassed->setText(textLabelMediaLengthPassed.arg(getMillisecondsAsTime(position).toString()));
}

void UnnecessaryMediaPlayer::playerUpdateMediaLengthTotal()
{
	qint64 duration = player->duration();

	playerProgressSlider.get()->setRange(0, duration);

	playerUiLabelMediaLengthTotal->setText(getMillisecondsAsTime(duration).toString());
}

void UnnecessaryMediaPlayer::playerUpdateMediaSliderMoved()
{
	qint64 position = playerProgressSlider.get()->sliderPosition();

	playerUiLabelMediaLengthPassed->setText(textLabelMediaLengthPassed.arg(getMillisecondsAsTime(position).toString()));
}

void UnnecessaryMediaPlayer::playerUpdateMediaSliderReleased()
{
	qint64 position = playerProgressSlider.get()->sliderPosition();

	player.get()->setPosition(position);

	playerUiLabelMediaLengthPassed->setText(textLabelMediaLengthPassed.arg(getMillisecondsAsTime(position).toString()));
}

void UnnecessaryMediaPlayer::playerUpdateVolume(const int &volumeSliderValue)
{
	qreal linearVolume = QAudio::convertVolume
	(
		volumeSliderValue / qreal(100.0), 
		QAudio::LogarithmicVolumeScale, 
		QAudio::LinearVolumeScale
	);
	player->setVolume(qRound(linearVolume * 100));
}