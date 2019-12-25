#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UnnecessaryMediaPlayer.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QPushButton>
#include <QToolbar>
#include <QLabel>
#include <QGridLayout>
#include <QSlider>
#include <QScreen>
#include <QSound>
#include <QStatusBar>
#include <QDebug>
#include <QDirIterator>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QDateTime>
#include <memory>
#include <map>

class UnnecessaryMediaPlayer : public QMainWindow
{
	Q_OBJECT

public:
	UnnecessaryMediaPlayer(QWidget *parent = Q_NULLPTR);

private:
	Ui::UnnecessaryMediaPlayerClass ui;

	const QString appExecutablePath = QCoreApplication::applicationDirPath();
	QString fileDirLastOpened = appExecutablePath;
	QString fileDirLastSaved = appExecutablePath;

	const QString tooltipPlaylistEmpty = "The playlist is empty.";
	const QString tooltipPlaylistContains = "The playlist has %1 items in it.";
	const QString textLabelMediaLengthPassed = "| %1 / ";

	std::unique_ptr<QGridLayout> layout = std::make_unique<QGridLayout>();
	std::unique_ptr<QMediaPlaylist> playlist = std::make_unique<QMediaPlaylist>();
	std::unique_ptr<QMediaPlayer> player = std::make_unique<QMediaPlayer>();
	std::unique_ptr<QVideoWidget> videoWidget = std::make_unique<QVideoWidget>();
	std::unique_ptr<QPushButton> playerNextBtn = std::make_unique<QPushButton>();
	std::unique_ptr<QSlider> playerProgressSlider = std::make_unique<QSlider>(this);
	std::unique_ptr<QToolBar> playerUi = std::make_unique<QToolBar>();
	std::unique_ptr<QWidget> playerUiSpacer = std::make_unique<QWidget>();
	std::unique_ptr<QLabel> playerUiLabelMediaLengthPassed = std::make_unique<QLabel>();
	std::unique_ptr<QLabel> playerUiLabelMediaLengthTotal = std::make_unique<QLabel>();
	const QString labelDividerText = "|";
	const int labelDividerMargin = 4;
	std::unique_ptr<QLabel> playerUiLabelDividerPlayback = std::make_unique<QLabel>();
	std::unique_ptr<QLabel> playerUiLabelDividerMedia = std::make_unique<QLabel>();
	std::unique_ptr<QLabel> playerUiLabelDividerStyle = std::make_unique<QLabel>();
	std::unique_ptr<QAction> playerUiBtnPlayPause = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnStop = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnMute = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnPrevious = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnNext = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnPlaybackMode = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnAddMedia = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnRemoveMedia = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnLoadPlaylist = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnSavePlaylist = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnToggleStyle = std::make_unique<QAction>();
	std::unique_ptr<QAction> playerUiBtnFullscreen = std::make_unique<QAction>();

	enum class StyleName { LIGHT, NIGHT };
	StyleName styleCurrent = StyleName::LIGHT;

	QPalette styleLightPalette = palette();
	QPalette styleNightPalette = palette();

	const QString styleSheetSliderLight =
		"QSlider::handle:horizontal{"
		"background-color: #F7947B;"
		"border-width: 2px;"
		"border-style: solid;"
		"border-color: #000000;"
		"}"
		"QSlider::handle:horizontal:hover{"
		"background-color: #D8C0A8;"
		"border-width: 2px;"
		"border-style: solid;"
		"border-color: #000000;"
		"}"
		"QSlider::handle:horizontal:hover:pressed{"
		"background-color: #000000;"
		"border-width: 2px;"
		"border-style: solid;"
		"border-color: #000000;"
		"}"
		;

	const QString styleSheetSliderNight =
		"QSlider::handle:horizontal{"
		"background-color: #FFC000;"
		"border-width: 2px;"
		"border-style: solid;"
		"border-color: #FFC000;"
		"}"
		"QSlider::handle:horizontal:hover{"
		"background-color: #7F5F00;"
		"border-width: 2px;"
		"border-style: solid;"
		"border-color: #7F5F00;"
		"}"
		"QSlider::handle:horizontal:hover:pressed{"
		"background-color: #7F5F00;"
		"border-width: 2px;"
		"border-style: solid;"
		"border-color: #FFC000;"
		"}"
		;

	const std::map<StyleName, QString> styleIconMap =
	{
		{StyleName::LIGHT, "-light"},
		{StyleName::NIGHT, "-night"}
	};

	const QString styleIconPlay = ":/UnnecessaryMediaPlayer/Resources/icon-play%1.png";
	const QString styleIconPause = ":/UnnecessaryMediaPlayer/Resources/icon-pause%1.png";
	const QString styleIconStop = ":/UnnecessaryMediaPlayer/Resources/icon-stop%1.png";
	const QString styleIconMute = ":/UnnecessaryMediaPlayer/Resources/icon-mute%1.png";
	const QString styleIconMuted = ":/UnnecessaryMediaPlayer/Resources/icon-muted%1.png";
	const QString styleIconPrevious = ":/UnnecessaryMediaPlayer/Resources/icon-previous%1.png";
	const QString styleIconNext = ":/UnnecessaryMediaPlayer/Resources/icon-next%1.png";
	const QString styleIconLoop = ":/UnnecessaryMediaPlayer/Resources/icon-loop%1.png";
	const QString styleIconShuffle = ":/UnnecessaryMediaPlayer/Resources/icon-shuffle%1.png";
	const QString styleIconAddMedia = ":/UnnecessaryMediaPlayer/Resources/icon-add-to-playlist%1.png";
	const QString styleIconRemoveMedia = ":/UnnecessaryMediaPlayer/Resources/icon-remove-from-playlist%1.png";
	const QString styleIconOpenPlaylist = ":/UnnecessaryMediaPlayer/Resources/icon-open-playlist%1.png";
	const QString styleIconSavePlaylist = ":/UnnecessaryMediaPlayer/Resources/icon-save-playlist%1.png";
	const QString styleIconToggleStyle = ":/UnnecessaryMediaPlayer/Resources/icon-style-light%1.png";
	const QString styleIconFullscreenOff = ":/UnnecessaryMediaPlayer/Resources/icon-fullscreen-off%1.png";
	const QString styleIconFullscreenOn = ":/UnnecessaryMediaPlayer/Resources/icon-fullscreen-on%1.png";

	bool validCmdLineIsRead();
	QTime getMillisecondsAsTime(const qint64 &millisecondsTime);
	void setIconsByStyle();

private slots:
	void playlistUpdateUi();
	void playerUpdateMediaLengthPassed();
	void playerUpdateMediaLengthTotal();
	void playerUpdateMediaSliderMoved();
	void playerUpdateMediaSliderReleased();
};
