#ifndef DELEGATES3_H
#define DELEGATES3_H

#include <QItemDelegate>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QListWidget>
#include <QComboBox>
#include <QToolButton>
#include <QLineEdit>
#include <QShortcut>
#include <QCheckBox>
#include <QDoubleSpinBox>

#include "commdatastruct.h"
#include "cal.h"

//class PAComboBox;
class FirstSubject;
class SecondSubject;
class SubjectManager;
class SubjectNameItem;
class Money;
class StatUtil;

enum BaTableColumnIndex{
    BT_SUMMARY = 0,   //摘要列
    BT_FSTSUB  = 1,   //总账科目列
    BT_SNDSUB  = 2,   //明细科目列
    BT_MTYPE   = 3,   //币种列
    BT_JV      = 4,   //借方金额列
    BT_DV      = 5,   //贷方金额列
    BT_DIR     = 6,   //借贷方向
    BT_ID      = 7,   //业务活动的ID列
    BT_PID     = 8,   //业务活动所属凭证ID列
    BT_NUM     = 9,   //业务活动在凭证中的序号列
    BT_ALL     = 10
};


//显示和编辑业务活动的摘要
class SummaryEdit : public QLineEdit
{
    Q_OBJECT
public:
    SummaryEdit(int row,int col,QWidget* parent = 0);

signals:
    //当编辑器的数据修改完成后，触发此信号，
    //参数col表示编辑器所在列索引，isMove指示是否将输入焦点移动到下一个项目
    void dataEditCompleted(int col, bool isMove);
    void copyPrevShortcutPressed(int r,int c); //向外传播请求复制上一条会计分录，参数r和c表示按下快捷方式时的单元格行列索引

private slots:
    void summaryEditingFinished();
    //void shortCutActivated();

protected:
    //bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    int row,col;         //编辑器打开时所处的行列位置

    //QShortcut* shortCut;
};

//编辑和显示明细科目
class SndSubComboBox : public QWidget
{
    Q_OBJECT
public:
    SndSubComboBox(SecondSubject* ssub, FirstSubject* fsub, SubjectManager* subMgr, int row=0, int col=0, QWidget *parent = 0);
    void setSndSub(SecondSubject* ssub);
    SecondSubject* subject(){return ssub;}
protected:
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void itemSelected(QListWidgetItem* item);
    void nameTextChanged(const QString& text);
    void nameTexteditingFinished();
    void subSelectChanged(const int index);
signals:
    void newMappingItem(FirstSubject* fsub, SubjectNameItem* ni, SecondSubject*& ssub,int row, int col);
    void newSndSubject(FirstSubject* fsub, SecondSubject*& ssub, QString name, int row, int col);
    void dataEditCompleted(int col, bool isMove);
private:
    bool processArrowKey(bool up);
    void hideList(bool isHide);
    void filterListItem();

    int row,col;       //编辑器所处的行列位置
    QString* keys;     //接收到的字母或数字键（数字表示科目代码，字母表示科目助记符）
    SortByMode sortBy;
    FirstSubject* fsub;              //二级科目所属的一级科目
    SecondSubject* ssub;             //当前选定的二级科目对象    
    SubjectManager *subMgr;          //
    QList<SubjectNameItem*> allNIs;  //所有名称条目
    QComboBox* com;       //显示当前一级科目下的可选的二级科目的组合框
    QListWidget* lw;      //智能提示列表框（显示所有带有指定前缀的名称条目）
};

//编辑和显示币种
class MoneyTypeComboBox : public QComboBox
{
    Q_OBJECT
public:
    MoneyTypeComboBox(QHash<int,Money*> mts, QWidget* parent = 0);
    void setCell(int row, int col);
    Money* getMoney();
protected:
    void keyPressEvent(QKeyEvent* e );
signals:
    void dataEditCompleted(int col, bool isMove);
    void editNextItem(int row, int col);   //这一信号仅用于设置明细科目余额值的表中
private:
    QHash<int,Money*> mts;
    int row,col;
};


//编辑和显示借贷金额
class MoneyValueEdit : public QLineEdit
{
    Q_OBJECT
public:
    MoneyValueEdit(int row, int witch = 0,Double v = Double(), QWidget* parent = 0);
    void setValue(Double v);
    Double getValue();
    void setCell(int row, int col){this->row = row;this->col = col;}
protected:
    bool eventFilter(QObject *obj, QEvent *e);
signals:
    void dataEditCompleted(int col, bool isMove);
    void nextRow(int row);  //在贷方列按下回车键时触发此信号
    void editNextItem(int row, int col);   //这一信号仅用于设置明细科目余额值的表中
private:
    int witch; //用于编辑贷方还是借方（1：借，0：贷）
    Double v;
    int row,col;   //编辑器所处的行号和列
    QDoubleValidator* validator;
};


//提供编辑会计分录各项的项目代理类
class ActionEditItemDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ActionEditItemDelegate(SubjectManager* subMgr, QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option,
                              const QModelIndex& index) const;
    void destroyEditor(QWidget * editor, const QModelIndex & index) const;

    void setReadOnly(bool readOnly){isReadOnly=readOnly;}
    void setVolidRows(int rows){validRows=rows;}
    int getVolidRows(){return validRows;}
    //void watchExtraException();
    void userConfirmed(){canDestroy=true;}

private slots:
    void commitAndCloseEditor(int colIndex, bool isMove);
    void newNameItemMapping(FirstSubject* fsub, SubjectNameItem* ni, SecondSubject*& ssub,int row, int col);
    void newSndSubject(FirstSubject* fsub, SecondSubject*& ssub, QString name, int row, int col);

    void nextRow(int row);
    void catchCopyPrevShortcut(int row, int col);

    //void cachedExtraException(BusiAction* ba,Double fv, MoneyDirection fd, Double sv, MoneyDirection sd);

signals:
    //void updateSndSubject(int row, int col, SecondSubject* ssub);
    void crtNewNameItemMapping(int row, int col, FirstSubject *fsub, SubjectNameItem *ni, SecondSubject*& ssbu);
    void crtNewSndSubject(int row, int col, FirstSubject* fsub, SecondSubject*& ssub, QString name);
    void moveNextRow(int row);
    void reqCopyPrevAction(int row);

    //void extraException(BusiAction* ba,Double fv, MoneyDirection fd, Double sv, MoneyDirection sd);

private:
    //int witch;  //代理当前编辑的是业务活动的哪个列
    bool isReadOnly; //表格是否只读的
    int validRows;   //表格的有效行数，这个是为了对无效行不创建编辑器（不包含备用行)
    SubjectManager* subMgr;
    StatUtil* statUtil;    
    bool canDestroy;      //对象是否可以销毁（当创建新科目时，利用此标记延迟对象的销毁）
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief 仅用于简单的从一个下拉列表框中选择一个一级科目（它包含了一个空科目表示没有选取）
 */
class FSubSelectCmb : public QComboBox
{
    Q_OBJECT
public:
    FSubSelectCmb(QHash<QString,QString>subNames, QWidget* parent = 0);
    void setSubCode(QString code);
    QString getSubCode();
};

/**
 * @brief 二选一选择框，它有两组字符串列表，一组用人可理解的文本，一组是用符号图形表示的文本
 *        每组的第一个元素对应“true”，第二个元素对应“false”
 */
class BooleanSelectCmb : public QComboBox{
    Q_OBJECT
public:
    BooleanSelectCmb(QStringList signs, QStringList displays, QWidget* parent = 0);
    bool getValue();
    QString getDisplay();
    QString getSign();
    void setValue(bool v);
private:
    QStringList signs;
    QStringList displays;
};

/**
 * @brief 在科目系统衔接配置窗口内部表格使用的项目代理类
 */
class SubSysJoinCfgItemDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    SubSysJoinCfgItemDelegate(QHash<QString,QString> subNames, QStringList dispStrs, QStringList signStrs, QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option,
                              const QModelIndex& index) const;
    void setReadOnly(bool isReadonly){readOnly = isReadonly;}
private:
    QHash<QString,QString> subNames;
    QStringList slSigns,slDisps;
    bool readOnly;
};

/**
 * @brief 支持4位小数编辑
 * 可指定哪些列支持4位小数
 */
class FourDecimalDoubleDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    FourDecimalDoubleDelegate(QSet<int> cols, QObject *parent = 0):
            QItemDelegate(parent){columns=cols;}
    QList<int> getColumn(){return columns.toList();}
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                               const QModelIndex &index) const
    {
        if(columns.contains(index.column())){
            QDoubleSpinBox* editor = new QDoubleSpinBox(parent);
            editor->setDecimals(4);
            return editor;
        }
        else
            return 0;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const
    {
        double value = index.model()->data(index, Qt::EditRole).toDouble();
        QDoubleSpinBox* ed = static_cast<QDoubleSpinBox*>(editor);
        if(ed)
            ed->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                   const QModelIndex &index) const
    {
        QDoubleSpinBox* ed = static_cast<QDoubleSpinBox*>(editor);
        if(ed){
            double value = ed->value();
            model->setData(index, value, Qt::EditRole);
        }
    }

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        editor->setGeometry(option.rect);
    }
private:
    QSet<int> columns;  //支持4位小数编辑的列
};

#endif // DELEGATES3_H
