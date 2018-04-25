#ifndef UITITLEBAR_H
#define UITITLEBAR_H

#include "../Utils/config.h"
#include "uiimagebutton.h"

enum ButtonType
{
    MIN_BUTTON = 0,         // 最小化和关闭按钮;
    MIN_MAX_BUTTON ,        // 最小化、最大化和关闭按钮;
    ONLY_CLOSE_BUTTON       // 只有关闭按钮;
};

class UITitleBar : public QWidget
{
    Q_OBJECT
public:
    /** 创建时必须指明父窗口*/
    UITitleBar(QWidget *parent);
    ~UITitleBar();
private:
    void Initial();
    void initView();
    void initConnect();
public:
    /** 设置标题栏背景色及是否设置标题栏背景色透明*/
    void setBackgroundColor(int r, int g, int b , bool isTransparent = false);
    /** 设置标题栏高度*/
    void setTitleHeight(int height);
    /** 设置标题栏图标*/
    void setTitleIcon(QString filePath , QSize IconSize = QSize(25 , 25));
    /** 设置标题内容*/
    void setTitleContent(QString titleContent , int titleFontSize = 9);
    /** 设置标题颜色*/
    void setTitleColor(const QColor &color);
    /** 设置标题栏上按钮类型*/
    void setButtonType(ButtonType buttonType);
    /** 设置标题栏中的标题是否会滚动;具体可以看效果*/
    void setTitleRoll();
    /** 设置窗口边框宽度*/
    void setWindowBorderWidth(int borderWidth);
    /** 保存最大化前窗口的位置及大小*/
    void saveRestoreInfo(const QPoint point, const QSize size);
    /** 获取最大化前窗口的位置及大小*/
    void getRestoreInfo(QPoint& point, QSize& size);
    /** 设置窗口最大化时是否允许拖动,默认是可以拖动的*/
    void setMaxScreenDrag(bool drag);
private:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void signalButtonMinClicked();
    void signalButtonRestoreClicked();
    void signalButtonMaxClicked();
    void signalButtonCloseClicked();
private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();
    void onRollTitle();

private:
    QLabel*         m_pIcon;               // 标题栏图标;
    QLabel*         m_pTitleContent;       // 标题栏内容;
    UiImageButton*  m_pButtonMin;          // 最小化按钮;
    UiImageButton*  m_pButtonRestore;      // 最大化还原按钮;
    UiImageButton*  m_pButtonMax;          // 最大化按钮;
    UiImageButton*  m_pButtonClose;        // 关闭按钮;

    int m_colorR;// 标题栏背景色;
    int m_colorG;
    int m_colorB;
    // 最大化，最小化变量;
    QPoint m_restorePos;
    QSize m_restoreSize;
    // 移动窗口的变量;
    bool m_isPressed;
    QPoint m_startMovePos;
    // 标题栏跑马灯效果时钟;
    QTimer m_titleRollTimer;
    // 标题栏内容;
    QString m_titleContent;
    // 按钮类型;
    ButtonType m_buttonType;
    // 窗口边框宽度;
    int m_windowBorderWidth;
    // 标题栏是否透明;
    bool m_isTransparent;
    bool m_isDrag;
};

#endif // UITITLEBAR_H
