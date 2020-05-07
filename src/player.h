#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <mpd/playlistmodel.h>
#include <mpd/mpdplaybackstatus.h>
#include <mpd/networkaccess.h>
#include <localdb/imagedatabase.h>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PlaylistModel* playlist READ playlist NOTIFY playlistChanged)
    Q_PROPERTY(MPDPlaybackStatus* playbackStatus READ playbackStatus NOTIFY playbackStatusChanged)

    PlaylistModel* m_playlist;

    MPDPlaybackStatus* m_playbackStatus;

    NetworkAccess* m_netAccess;
    ImageDatabase* m_imgDB;

public:
    explicit Player(QObject *parent = nullptr);
    Player(NetworkAccess* netAccess, ImageDatabase* imgDB, QObject *parent = nullptr);


    PlaylistModel* playlist() const
    {
        return m_playlist;
    }

    MPDPlaybackStatus* playbackStatus() const
    {
        return m_playbackStatus;
    }


signals:

    void playlistChanged();
    void playbackStatusChanged(MPDPlaybackStatus* playbackStatus);

    void play();
    void stop();
    void next();
    void previous();
    void setVolume(int value);
    void seek(int value);
    void setShuffle(bool value);
    void setRepeat(bool value);
    void setConsume(bool value);

public slots:
};

#endif // PLAYER_H
