#ifndef MYHELPER_H
#define MYHELPER_H

#include <QApplication>
#include <QDesktopWidget>
#include <QSettings>
#include <QTranslator>
#include <QFile>

#include "frmmessagebox.h"
#include "config.h"

class myHelper: public QObject
{

public:

    //设置为开机启动
    static void AutoRunWithSystem(bool IsAutoRun, QString AppName, QString AppPath)
    {
        QSettings *reg = new QSettings(
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
            QSettings::NativeFormat);

        if (IsAutoRun) {
            reg->setValue(AppName, AppPath);
        } else {
            reg->setValue(AppName, "");
        }
    }

    //设置编码为UTF8
    static void SetUTF8Code()
    {
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
#endif
    }

    //设置皮肤样式
    static void SetStyle(const QString &styleName)
    {
        QString fileName;
        if(AppConfig::getInstance()->getStyleFrom())
            fileName = QString(":/styles/%1.css").arg(styleName);
        else
            fileName = QString("./styles/%1.css").arg(styleName);
        QFile file(fileName);
        if(!file.open(QFile::ReadOnly)){
            ShowMessageBoxError(tr("无法打开样式表文件“%1.css”").arg(styleName));
            return;
        }
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        qApp->setPalette(QPalette(QColor("#F0F0F0")));
        file.close();
    }

    //加载中文字符
    static void SetChinese()
    {
        QTranslator *translator = new QTranslator(qApp);
        translator->load(":/translations/qt_zh_CN.qm");
        qApp->installTranslator(translator);
    }

    //判断是否是IP地址
    static bool IsIP(QString IP)
    {
        QRegExp RegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
        return RegExp.exactMatch(IP);
    }

    //显示信息框,仅确定按钮
    static void ShowMessageBoxInfo(QString info)
    {
        frmMessageBox *msg = new frmMessageBox;
        msg->SetMessage(info, 0);
        msg->exec();
    }

    //显示错误框,仅确定按钮
    static void ShowMessageBoxError(QString info)
    {
        frmMessageBox *msg = new frmMessageBox;
        msg->SetMessage(info, 3);
        msg->exec();
    }

    //显示询问框,确定和取消按钮
    static int ShowMessageBoxQuesion(QString info)
    {
        frmMessageBox *msg = new frmMessageBox;
        msg->SetMessage(info, 1);
        return msg->exec();
    }

    //显示警告框，仅确定按钮
    static int ShowMessageBoxWarning(QString info)
    {
        frmMessageBox *msg = new frmMessageBox;
        msg->SetMessage(info, 2);
        return msg->exec();
    }

    //延时
    static void Sleep(int sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while ( QTime::currentTime() < dieTime ) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    //窗体居中显示
    static void FormInCenter(QWidget *frm)
    {
        int frmX = frm->width();
        int frmY = frm->height();
        QDesktopWidget w;
        int deskWidth = w.width();
        int deskHeight = w.height();
        QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
        frm->move(movePoint);
    }
};

#endif // MYHELPER_H
