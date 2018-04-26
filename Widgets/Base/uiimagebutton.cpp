#include "uiimagebutton.h"
#include <qDebug>
#include <QPainter>
#include <QMouseEvent>

UiImageButton::UiImageButton(QWidget *parent) :
    UIPushButton(parent)
{
    btnState = ENUM_BTNSTATE_NORMAL;
    setBtnBackImgFile(":/skin/images/common/button/btn_bg_normal.png",
                      ":/skin/images/common/button/btn_bg_hover.png",
                      ":/skin/images/common/button/btn_bg_down.png",
                      ":/skin/images/common/button/btn_bg_disable.png");
}

void UiImageButton::setBtnBackImgFile(const QString &qstrNormal, const QString &qstrHover,
                                    const QString &qstrPress, const QString &qstrDisable)
{
    qstrBackImgFile[ENUM_BTNSTATE_NORMAL] = qstrNormal;
    qstrBackImgFile[ENUM_BTNSTATE_HOVER] = qstrHover;
    qstrBackImgFile[ENUM_BTNSTATE_PRESS] = qstrPress;
    qstrBackImgFile[ENUM_BTNSTATE_DISABLE] = qstrDisable;

    qclrCaption[ENUM_BTNSTATE_NORMAL] = QColor::fromRgb(0x44, 0x44, 0x44);
    qclrCaption[ENUM_BTNSTATE_HOVER] = QColor::fromRgb(0x11, 0x11, 0x11);
    qclrCaption[ENUM_BTNSTATE_PRESS] = QColor::fromRgb(0x77, 0x77, 0x77);
    qclrCaption[ENUM_BTNSTATE_DISABLE] = QColor::fromRgb(0x6e, 0x6a, 0x6a);
    update();
}

void UiImageButton::setLogo(const QString &logo)
{
    qstrLogo = logo;
}

void UiImageButton::setEnabled(bool enabled)
{
    QPushButton::setEnabled(enabled);
    btnState = enabled ? ENUM_BTNSTATE_NORMAL : ENUM_BTNSTATE_DISABLE;
    update();
}

void UiImageButton::paintEvent(QPaintEvent *event)
{
    //QPushButton::paintEvent(event);
    QPainter painter(this);

    if (!qstrCoverImgFile.isEmpty() &&
        (btnState == ENUM_BTNSTATE_HOVER ||
         btnState == ENUM_BTNSTATE_PRESS) )
    {
        QImage img(qstrCoverImgFile);
        painter.drawImage(rect(), img);
    }

    if (btnState >= ENUM_BTNSTATE_NORMAL && btnState < ENUM_BTNSTATE_COUNT)
    {
        if (!(qstrBackImgFile[btnState].isEmpty()))
        {
            QRect drawrc(2, 2, rect().width() - 4, rect().height() - 4);
            QImage image(qstrBackImgFile[btnState]);
            painter.drawImage(drawrc, image);
        }
    }

    int logopos = 0;
    if (!qstrLogo.isEmpty())
    {
        QImage img(qstrLogo);
        logopos = 10 + img.width();
        if (qstrCaption.isEmpty())
            painter.drawImage( (width()-img.width())/2, (height()-img.height())/2, img);
        else
            painter.drawImage( 10, (height()-img.height())/2, img);
    }

    if(!qstrCaption.isEmpty())
    {
        painter.setPen(qclrCaption[btnState]);
        painter.drawText(rect().adjusted(logopos, 0, 0, 0), Qt::AlignCenter, qstrCaption);
    }


}

void UiImageButton::enterEvent(QEvent *ev)
{
    QPushButton::enterEvent(ev);
    if (btnState != ENUM_BTNSTATE_DISABLE)
        btnState = ENUM_BTNSTATE_HOVER;
}

void UiImageButton::leaveEvent(QEvent *ev)
{
    QPushButton::leaveEvent(ev);
    if (btnState != ENUM_BTNSTATE_DISABLE)
        btnState = ENUM_BTNSTATE_NORMAL;
}

void UiImageButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && btnState != ENUM_BTNSTATE_DISABLE)
        btnState = ENUM_BTNSTATE_PRESS;

    emit signMousePress();
    QPushButton::mousePressEvent(event);
}

void UiImageButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && btnState != ENUM_BTNSTATE_DISABLE)
        btnState = ENUM_BTNSTATE_HOVER;

    emit signMouseRelease();
    QPushButton::mouseReleaseEvent(event);
}

