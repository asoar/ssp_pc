#ifndef UIIMAGEBUTTON_H
#define UIIMAGEBUTTON_H

#include <QPushButton>
#include <QString>

class UiImageButton : public QPushButton
{
    Q_OBJECT
public:
    explicit UiImageButton(QWidget *parent = 0);

    enum ENUM_BTNSTATE
    {
        ENUM_BTNSTATE_NORMAL = 0,
        ENUM_BTNSTATE_HOVER,
        ENUM_BTNSTATE_PRESS,
        ENUM_BTNSTATE_DISABLE,
        ENUM_BTNSTATE_COUNT
    };

    void setBtnBackImgFile(const QString&, const QString&, const QString&, const QString&);
    void setCaption(const QString& caption)
    {
        qstrCaption = caption;
        update();
    }
    QString GetCaption()
    {
        return qstrCaption;
    }

    void setBtnCoverImgFile(const QString& file)
    {
        qstrCoverImgFile = file;
    }

    void setLogo(const QString& logo);

    void setEnabled(bool);

signals:
    void signMousePress();
    void signMouseRelease();
private:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private:
    QString qstrBackImgFile[ENUM_BTNSTATE_COUNT];
    QColor  qclrCaption[ENUM_BTNSTATE_COUNT];
    ENUM_BTNSTATE btnState;
    QString qstrCaption;
    QString qstrCoverImgFile;
    QString qstrLogo;
};

#endif // UIIMAGEBUTTON_H
