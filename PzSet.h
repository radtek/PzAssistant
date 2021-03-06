#ifndef PZSET_H
#define PZSET_H

#include "QList"

#include "common.h"
#include "commdatastruct.h"

class DbUtil;
class PingZheng;
class Account;
class StatUtil;
class QUndoStack;
class FirstSubject;
class SubjectManager;
struct CurAuthCostInvoiceInfo;

const int MAXUNDOSTACK = 100;    //Undo栈的最大容量

/**
 * @brief 帐套管理类，用于管理该帐套内所有的凭证集
 */
class AccountSuiteManager : public QObject
{
    Q_OBJECT
public:
    //保存凭证集的哪个部分
    enum SaveWitch{
        SW_ALL   = 1,   //所有
        SW_PZS   = 2,   //仅凭证
        SW_STATE = 3    //凭证集状态和余额状态
    };



    AccountSuiteManager(AccountSuiteRecord* as, Account* account,QObject* parent = 0);
    ~AccountSuiteManager();
    Account* getAccount(){return account;}
    AccountSuiteRecord* getSuiteRecord(){return suiteRecord;}
    bool isSuiteClosed(){return suiteRecord->isClosed;} //是否已关账
    bool closeSuite();
    SubjectManager* getSubjectManager();
    int getSubSysCode(){return suiteRecord->subSys;}
    bool open(int m);
    bool isSuiteEditable();
    bool isPzSetEditable(int m=0);
    bool isPzSetOpened();
    bool isDirty();
    void closePzSet();
    void rollback();
    int newPzSet();
    void clearPzSetCaches();
    StatUtil* getStatUtil(){return statUtil;}
    QUndoStack* getUndoStack(){return undoStack;}
    PingZheng* getCurPz(){return curPz;}

    int year(){return suiteRecord->year;}
    int month(){return curM;}
    int getMaxZbNum(){return maxZbNum;}
    bool resetPzNum(int by = 1);
    PzsState getState(int curM=0);
    void setState(PzsState state, int m=0);
    bool getExtraState(int m=0);
    void setExtraState(bool state, int m=0);
    bool getPzSet(int m, QList<PingZheng *> &pzs);
    QList<PingZheng*> getPzSpecRange(QSet<int> nums);
    bool contains(int pid, int y=0, int m=0);
    PingZheng* readPz(int pid, bool &in);
    int getStatePzCount(PzState state);
    bool isAllInstat();

    int verifyAll(User* user);
    int instatAll(User* user);
    bool inspectPzError(QList<PingZhengError *> &errors);

    //bool saveExtra();
    //bool readExtra();
    //bool readPreExtra();
    bool getRates(QHash<int, Double> &rates, int m=0);
    bool setRates(QHash<int,Double> rates, int m=0);

    //导航方法
    PingZheng* first();
    PingZheng* next();
    PingZheng* previou();
    PingZheng* last();
    PingZheng* seek(int num);
    bool seek(PingZheng* pz);
    bool isFirst(){return curIndex == 0;}
    bool isLast(){return !pzs || (curIndex == pzs->count()-1);}

    //返回凭证数的方法
    void getPzCountForMonth(int m,int& repealNum, int& recordingNum, int& verifyNum, int& instatNum);
    int getPzCount();
    int getRecordingCount(){return c_recording;}
    int getVerifyCount(){return c_verify;}
    int getInstatCount(){return c_instat;}
    int getRepealCount(){return c_repeal;}
    QList<PingZheng*> getAllJzhdPzs();

    PingZheng* appendPz(PzClass pzCls=Pzc_Hand);
    bool append(PingZheng* pz);
    bool insert(PingZheng* pz);
    bool insert(int index, PingZheng* pz);
    bool remove(PingZheng* pz);
    bool restorePz(PingZheng *pz);
    PingZheng* getPz(int num);
    void setCurPz(PingZheng *pz);
    bool savePz(PingZheng* pz);

    bool save(SaveWitch witch=SW_ALL);

    //期末处理方法
    bool crtGatherPz(int y, int m, QList<PingZheng*> &createdPzs, bool isIncome=true);
    bool crtJzhdsyPz(int y, int m, QList<PingZheng*>& createdPzs,
                      QHash<int,Double> sRate,QHash<int,Double> erate, User* user);
    void getJzhdsyPz(QList<PingZheng*>& pzLst);
    int  getJzhdsyMustPzNums();
    bool crtJzsyPz(int y, int m, QList<PingZheng*>& createdPzs);
    void getJzsyPz(QList<PingZheng*>& pzLst);
    bool crtJzlyPz(int y, int m, PingZheng* pz);
    bool crtJtpz(QList<JtpzDatas *> datas, QList<PingZheng *> &pzLst);
    PingZheng* crtJxTaxPz(QList<CurAuthCostInvoiceInfo*> caIncoices);

    bool crtGdzcPz();
    bool crtDtfyImpPz(int y, int m, QList<PzData *> pzds);
    bool crtDtfyTxPz();
    bool delDtfyPz();


    void finishAccount();

    bool stat();
    static bool stat(int y, int m);
    bool getDetList();
    static bool getDetList(int y, int sm, int em);
    bool getTotalList();
    static bool getTotalList(int y,int sm, int em);
    bool find();
    static bool find(int y, int sm, int em);

    QList<PingZheng *> getHistoryPzSet(int m);

    //发票有关方法
    void scanYsYfForMonth(int month,QList<InvoiceRecord *> &incomes, QList<InvoiceRecord *> &costs, QStringList &errors,bool scanXf=false,bool reserved=true);
    void scanYsYfForMonth2(int month,QList<InvoiceRecord *> &incomeAdds, QList<InvoiceRecord *> &incomeCancels, QList<InvoiceRecord *> &costAdds, QList<InvoiceRecord *> &costCancels, QStringList &errors);
    void scanYsYfForInit(QList<InvoiceRecord *> &incomes, QList<InvoiceRecord *> &costs, QStringList &errors);
    InvoiceRecord *searchYsYfInvoice(bool isYs, QString inum);
    CurInvoiceRecord *searchICInvoice(bool isIncome, QString inum);
    bool saveYsYf();
    void loadYsYf();
    QList<InvoiceRecord *> getYsInvoiceStats();
    QList<InvoiceRecord *> getYfInvoiceStats();
    void setYsInvoiceStats(QList<InvoiceRecord *> datas){ysInvoices=datas;}
    void setYfInvoiceStats(QList<InvoiceRecord *> datas){yfInvoices=datas;}

    //收入/成本发票管理方法
    bool saveInCost();
    void loadInCost();
    bool clearInCost(int scope);
    QList<CurInvoiceRecord*> *getCurInvoiceRecords(bool isIncome=true);
    int verifyCurInvoice(QString invoiceNumber, Double wbMoney, BusiAction* ba,bool isGather,bool isIncome=true);
    bool verifyCurInvoices(QString &errInfo);

    //扫描本月发票
    void scanInvoice(QList<InvoiceRecord *> &incomes, QList<InvoiceRecord *> &costs, QStringList &errors);
    void scanInvoiceGatherIncome(PingZheng* pz, QList<InvoiceRecord *> &incomes, QStringList &errors);
    void scanInvoiceGatherCost(PingZheng* pz, QList<InvoiceRecord *> &costs, QStringList &errors);
    bool isGatherIncomePz(PingZheng* pz, bool &ok);
    bool isGatherCostPz(PingZheng* pz, bool &ok);


//    QList<InvoiceRecord*> getYsInvoices();
//    QList<InvoiceRecord*> getYfInvoices();



public slots:
    void rateChanged(int month=0);
private slots:
    void needRestat();
    void pzChangedInSet(PingZheng* pz);
    void pzStateChanged(PzState oldState, PzState newState);
signals:
    void currentPzChanged(PingZheng* newPz, PingZheng* oldPz);
    void pzCountChanged(int count); //凭证总数或处于不同状态的凭证数的改变
    void pzSetChanged();//包括凭证集内凭证数和凭证内容的改变，用于通知其他窗口有未保存的修改
    void pzSetStateChanged(PzsState newState);
    void pzExtraStateChanged(bool newState);
private:
    bool _savePzSet();
    void watchPz(PingZheng* pz, bool en=true);
    void cachePz(PingZheng* pz);
    bool isZbNumConflict(int num);
    void scanPzCount(int& repealNum, int& recordingNum, int& verifyNum, int& instatNum, QList<PingZheng*>* pzLst);
    void _determinePzSetState(PzsState& state);
    void _determineCurPzChanged(PingZheng* oldPz);
    bool _inspectDirEngageError(FirstSubject* fsud, MoneyDirection dir, PzClass pzc, QString& eStr);
    bool _removeInvoice(QString invoiceNum, QList<CurInvoiceRecord *> &invoiceNums);

    void pzsNotOpenWarning();

private:
    QString errorStr;
    //与本期统计相关
    QHash<int,Double> preExtra,preDetExtra; //期初主目和子目余额
    QHash<int,MoneyDirection> preDir,preDetDir;     //期初主目和子目余额方向
    QHash<int,Double> curHpJ,curHpD;        //当期借方和贷方发生额
    QHash<int,Double> endExtra,endDetExtra; //期末主目和子目余额
    QHash<int,MoneyDirection>    endDir,endDetDir;     //期末主目和子目余额方向


    QHash<int,QList<PingZheng*> > pzSetHash;  //保存所有已经装载的凭证集（键为月份）
    QHash<int,PzsState> states; //凭证集状态（键同上）
    QHash<int,bool> extraStates;//凭证集余额状态（键同）
    QList<PingZheng*>* pzs;      //当前打开的凭证集对象列表
    QList<PingZheng*> pz_dels;  //已被删除的凭证对象列表
    QList<PingZheng*> cachedPzs; //保存被删除后执行了保存操作的凭证对象（用以支持恢复任何情况下被删除的凭证对象）
    QList<PingZheng*> historyPzs;//历史凭证

    //应收应付发票缓存，记录本帐套未销账的应收应付发票
    QList<InvoiceRecord*> ysInvoices,yfInvoices;//应收发票号
    bool isYsYfLoaded;	//应收发票是否装载完成（从发票表中装载）

    //收入/成本发票缓存，记录当月发生的收入/成本发票
    QList<CurInvoiceRecord*> incomes,costs;
    bool isICLoader;    //收入/成本发票是否装载完成


    int curM;                     //当前以编辑方式打开的凭证集所属月份
    PingZheng* curPz;             //当前显示在凭证编辑窗口内的凭证对象
    int curIndex;                 //当前凭证索引
    int maxPzNum;                           //最大可用凭证号
    int maxZbNum;                           //最大可用自编号
    int c_recording,c_verify,c_instat,c_repeal;      //录入态、审核态、入账态和作废的凭证数
    bool dirty;                   //只记录除凭证外的所有对凭证集的更改（凭证集状态、余额状态等）
    Account* account;
    AccountSuiteRecord* suiteRecord;
    DbUtil* dbUtil;
    StatUtil* statUtil;
    QUndoStack* undoStack;
};

#endif // PZSET_H
