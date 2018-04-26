#ifndef LOGINEDITWIDGET_H
#define LOGINEDITWIDGET_H

#include "../Base/uilabel.h"
#include "../Base/uilineedit.h"


class LoginEditWidget : public QWidget
{
    Q_OBJECT
public:
    LoginEditWidget(QWidget *parent);
private:
    void initial();
    void initView();
    void initLayout();
    void initConnect();
private:
    void resizeEvent(QResizeEvent *size);
public:
    /** 设置编辑内容字体颜色和字体大小*/
    void setTextColor(QColor color, int fontSize);
    /** 设置编辑Placeholder内容*/
    void setTextPlaceholder(QString text);
    /** 设置编辑框前面的icon*/
    void setIcon(QString filePath , QSize IconSize = QSize(25 , 25));
    /** 设置编辑框的正则*/
    void setTextRegExp(QRegExp reg);
    /** 设置为密码输入模式*/
    void setPasswordMode();
    /** 获取编辑框内容*/
    QString text();
private:
    UILabel     *m_iconL;
    UILineEdit  *m_contentEdit;

    QSize        m_iconSize;
};

#endif // LOGINEDITWIDGET_H
