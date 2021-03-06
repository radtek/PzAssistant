#ifndef TABLES_H
#define TABLES_H

#include <QString>

//账户信息表(AccountInfo) 该表的每行代表一个账户的信息
//CREATE TABLE AccountInfo(id INTEGER PRIMARY KEY, code INTEGER, name TEXT, value TEXT)
const QString tbl_accInfo     = "AccountInfo";
const QString fld_acci_code   = "code";     //账户信息字段的枚举编号（code INTEGER）
const QString fld_acci_name   = "name";     //账户信息字段名（name TEXT）
const QString fld_acci_value  = "value";    //账户信息字段值（value TEXT）
const int ACCINFO_CODE  = 1;
const int ACCINFO_NAME  = 2;
const int ACCINFO_VALUE = 3;

//账户属性名常量
const QString ACCINFO_VNAME_CODE    = "accountCode";
const QString ACCINFO_VNAME_SNAME   = "shortName";
const QString ACCINFO_VNAME_LNAME   = "longName";
const QString ACCINFO_VNAME_SUBSYS  = "subType";
const QString ACCINFO_VNAME_DBVERSION = "db_version";
//const QString ACCINFO_VNAME_LOGFILENAME = "logFileName";
//const QString ACCINFO_VNAME_LASTTIME= "lastAccessTime";

//帐套表accountSuites，从accountInfo表内读取有关帐套的数据进行初始化
//字段名
const QString tbl_accSuites      = "accountSuites";
const QString fld_accs_year      = "year";         //帐套所属年份（integer）
const QString fld_accs_subSys    = "subSys";       //帐套所用的科目系统代码（integer）
const QString fld_accs_isCur     = "isCurrent";    //是否是当前帐套（integer）
const QString fld_accs_recentMonth = "recentMonth";//最近打开月份
const QString fld_accs_name      = "name";         //帐套名（text）
const QString fld_accs_startMonth= "startMonth";   //帐套开始月份
const QString fld_accs_endMonth  = "endMonth";     //帐套结束月份
const QString fld_accs_isClosed  = "isClosed";     //帐套是否已关账
//字段索引
const int ACCS_YEAR         = 1;
const int ACCS_SUBSYS       = 2;
const int ACCS_ISCUR        = 3;
const int ACCS_RECENTMONTH  = 4;
const int ACCS_NAME         = 5;
const int ACCS_STARTMONTH   = 6;
const int ACCS_ENDMONTH     = 7;
const int ACCS_ISCLOSED     = 8;



//*************************币种表*************************//
//CREATE TABLE MoneyTypes(id INTEGER PRIMARY KEY, code INTEGER, sign TEXT, name TEXT)
//字段名
const QString tbl_moneyType     = "MoneyTypes";
const QString fld_mt_isMaster   = "isMaster";   //是否是母币
const QString fld_mt_code       = "code";       //币种代码
const QString fld_mt_name       = "name";       //币种名称
const QString fld_mt_sign       = "sign";       //币种符号
//字段索引
const int MT_MASTER = 1;
const int MT_CODE   = 2;
const int MT_NAME   = 3;
const int MT_SIGN   = 4;


//*************************汇率表***********************************//
//CREATE TABLE ExchangeRates(id INTEGER PRIMARY KEY, year INTEGER, month INTEGER, usd2rmb REAL)
//字段名（注意：汇率字段的命名规则：币种符号 + “2” + 本币符号（rmb））
const QString tbl_rateTable  = "ExchangeRates";
const QString fld_rt_year    = "year";
const QString fld_rt_month   = "month";
//字段索引
const int RT_YEAR   = 1;
const int RT_MONTH  = 2;

//银行表(Banks)
//字段名
const QString tbl_bank           = "Banks";
const QString fld_bank_isMain    = "IsMain";    //是否基本户(bool)
const QString fld_bank_name      = "name";      //开户行简称(TEXT)
const QString fld_bank_lname     = "lname";     //全称(TEXT)
//字段索引
const int BANK_ISMAIN = 1;
const int BANK_NAME   = 2;
const int BANK_LNAME  = 3;

//银行账户表--在银行下开设的与币种相关的银行账户
//字段名
const QString tbl_bankAcc         = "BankAccounts";
const QString fld_bankAcc_bankId  = "bankID";    //账户所属的银行ID（INTEGER）
const QString fld_bankAcc_mt      = "mtID";      //账户币种ID INTEGER）
const QString fld_bankAcc_accNum  = "accNum";    //帐号（TEXT）
const QString fld_bankAcc_nameId   = "nameId";     //该账户对应的名称条目id
//字段索引
const int BA_BANKID = 1;
const int BA_MT     = 2;
const int BA_ACCNUM = 3;
const int BA_ACCNAME= 4;


//*************************一级科目类别表*************************//
//create table FstSubClasses(id integer primary key, subSys integer, code integer, name text)
//字段名
const QString tbl_fsclass    = "FstSubClasses";
const QString fld_fsc_subSys = "subSys";
const QString fld_fsc_code   = "code";      //类别代码(INTEGER)
const QString fld_fsc_name   = "name";      //类别名称(TEXT)
//字段索引
const int FSCLS_SUBSYS   = 1;
const int FSCLS_CODE     = 2;
const int FSCLS_NAME     = 3;

//*************************一级科目表*********************************//
//CREATE TABLE FirSubjects(id INTEGER PRIMARY KEY, subSys INTEGER, subCode varchar(4),
//remCode varchar(10), belongTo integer, jdDir integer, isView integer,
//isUseWb INTEGER, weight integer, subName varchar(10))
//字段名
//const QString tbl_fsub         = "FirSubjects";
//const QString fld_fsub_subSys  = "subSys";       //科目系统代码（INTEGER）


//const int FSUB_SUBSYS     =  1;

//*************************一级科目id表******************************//
const QString tbl_fsub_ids = "FstSubIDs";
//*************************一级科目表*********************************//
//一级科目表名前缀
const QString tbl_fsub_prefix = "FstSubs_";
const QString fld_fsub_fid     = "fid";          //外键，连接到表“FstSubMaps”的id字段
const QString fld_fsub_subcode = "subCode";      //一级科目代码（国标）(varchar(4))
const QString fld_fsub_remcode = "remCode";      //科目助记符(varchar(10))
const QString fld_fsub_class   = "clsId";        //所属类别（integer)
const QString fld_fsub_jddir   = "jdDir";        //科目的借贷方向判定方法（integer）
                                        //（1：增加在借方，减少在贷方；0：增加在贷方，减少在借方）
const QString fld_fsub_isEnalbed  = "isEnabled";       //是否启用该科目(integer)(1：启用，0：不启用)
const QString fld_fsub_isUseWb = "isUseWb";      //是否需要使用外币
const QString fld_fsub_weight  = "weight";       //科目使用的权重值(integer)
const QString fld_fsub_name    = "subName";      //科目名(varchar(10))
//字段索引
const int FSUB_FID        =  1;
const int FSUB_SUBCODE    =  2;
const int FSUB_REMCODE    =  3;
const int FSUB_CLASS      =  4;
const int FSUB_DIR        =  5;
const int FSUB_ISVIEW     =  6;
const int FSUB_ISUSEWB    =  7;
const int FSUB_WEIGHT     =  8;
const int FSUB_SUBNAME    =  9;
//*************************名称条目类别表*************************//
//二级科目类别表
//字段名
const QString tbl_nameItemCls = "NameItemClass";
const QString fld_nic_order   = "viewOrder";    //显示顺序
const QString fld_nic_clscode = "clsCode";      //类别代码（INTEGER）
const QString fld_nic_name    = "name";         //名称（TEXT）
const QString fld_nic_explain = "explain";      //简要说明（TEXT）
//字段索引
const int NICLASS_ORDER   = 1;
const int NICLASS_CODE    = 2;
const int NICLASS_NAME    = 3;
const int NICLASS_EXPLAIN = 4;

//*************************名称条目表*************************//
//名称条目表
//字段名
const QString tbl_nameItem    = "nameItems";
const QString fld_ni_name     = "sName";         //简称（TEXT）
const QString fld_ni_lname    = "lName";         //全称（TEXT）
const QString fld_ni_remcode  = "remCode";       //助记符（TEXT）
const QString fld_ni_class    = "classId";       //名称类别代码（INTEGER）
const QString fld_ni_crtTime  = "createdTime";   //创建时间（TEXT）（TimeStamp NOT NULL DEFAULT (datetime('now','localtime'))）
const QString fld_ni_creator  = "creator";       //创建者（INTEGER）
//字段索引
const int NI_NAME        = 1;
const int NI_LNAME       = 2;
const int NI_REMCODE     = 3;
const int NI_CALSS       = 4;
const int NI_CREATERTIME = 5;
const int NI_CREATOR     = 6;

//名称条目别名表（别名：即名称条目曾经使用过、或其他等同的名称）
//该表中有一类无主别名（即不始于任何名称对象），主要用于在导入当月收入/成本发票时作为新客户匹配用
const QString tbl_nameAlias = "nameAlias";
const QString fld_nia_niCode = "niCode";        //连接到名称条目表的id
const QString fld_nia_name = "sName";           //简称
const QString fld_nia_lname = "lName";          //全称
const QString fld_nia_remcode = "remCode";      //助记符
const QString fld_nia_crtTime = "createdTime";  //创建日期(INTEGER)
const QString fld_nia_disTime = "disabledTime"; //禁用日期(INTEGER)
const int FI_NIA_NICODE = 1;
const int FI_NIA_NAME = 2;
const int FI_NIA_LNAME = 3;
const int FI_NIA_REMCODE = 4;
const int FI_NIA_CRTTIME = 5;
const int FI_NIA_DISTIME = 6;

//*************************二级科目表*************************//
//字段名
const QString tbl_ssub        = "SndSubject";
const QString fld_ssub_fid     = "fid";           //所属的一级科目ID（INTEGER）
const QString fld_ssub_nid     = "nid";           //对应的名称条目中的ID（INTEGER）
const QString fld_ssub_code    = "subCode";       //科目代码（用户根据行业特点自定义的）（TEXT）
const QString fld_ssub_weight  = "weight";        //科目的使用权重（INTEGER）
const QString fld_ssub_enable  = "isEnabled";     //是否在账户中启用（INTEGER）
const QString fld_ssub_disTime = "disabledTime";  //禁用时间（TEXT）
const QString fld_ssub_crtTime = "createdTime";   //创建时间（TEXT）（NOT NULL DEFAULT (datetime('now','localtime'))）
const QString fld_ssub_creator = "creator";       //创建者（INTEGER）
const QString fld_ssub_subsys  = "subSys";        //所属科目系统（TEXT）多个科目系统代码用逗号隔开
//字段索引
const int SSUB_FID         = 1;
const int SSUB_NID         = 2;
const int SSUB_SUBCODE     = 3;
const int SSUB_WEIGHT      = 4;
const int SSUB_ENABLED     = 5;
const int SSUB_DISABLETIME = 6;
const int SSUB_CREATETIME  = 7;
const int SSUB_CREATOR     = 8;
const int SSUB_SUBSYS      = 9;

//******************凭证表*********************************//
//字段名
const QString tbl_pz        = "PingZhengs";
const QString fld_pz_date   = "date";       //凭证日期（TEXT）
const QString fld_pz_number = "number";     //凭证总号（INTEGER）
const QString fld_pz_zbnum  = "zbNum";      //凭证自编号（INTEGER）
const QString fld_pz_jsum   = "jsum";       //借方合计（REAL）
const QString fld_pz_dsum   = "dsum";       //贷方合计（REAL）
const QString fld_pz_class  = "isForward";  //凭证类别(INTEGER)
const QString fld_pz_encnum = "encNum";     //凭证附件张数（INTEGER）
const QString fld_pz_state  = "pzState";    //凭证状态（INTEGER） -1：作废态，1：初始录入态，2：已审核态，3：记账态，
const QString fld_pz_vu     = "vuid";       //审核凭证的用户的ID（INTEGER）
const QString fld_pz_ru     = "ruid";       //录入凭证的用户的ID（INTEGER）
const QString fld_pz_bu     = "buid";       //凭证入账的用户ID（INTEGER）
//字段索引
const int PZ_DATE    = 1;
const int PZ_NUMBER  = 2;
const int PZ_ZBNUM   = 3;
const int PZ_JSUM    = 4;
const int PZ_DSUM    = 5;
const int PZ_CLS     = 6;
const int PZ_ENCNUM  = 7;
const int PZ_PZSTATE = 8;
const int PZ_VUSER   = 9;
const int PZ_RUSER   = 10;
const int PZ_BUSER   = 11;

//*********************凭证备注信息表**************************************//
//字段名
const QString tbl_pz_meminfos   = "pzMemInfos";
const QString fld_pzmi_pid      = "pid";
const QString fld_pzmi_info     = "infos";
//字段索引
const int PZMI_PID = 1;
const int PZMI_INFO= 2;

//会计分录表
//字段名
const QString tbl_ba         = "BusiActions";
const QString fld_ba_pid     = "pid";           //所属的凭证ID（INTEGER）连接到凭证表的外键
const QString fld_ba_summary = "summary";       //业务活动摘要（TEXT）
const QString fld_ba_fid     = "fid";           //一级科目（ INTEGER）
const QString fld_ba_sid     = "sid";           //二级科目（INTEGER）
const QString fld_ba_mt      = "mt";            //货币类型（INTEGER）
const QString fld_ba_value   = "value";         //金额（REAL）
const QString fld_ba_dir     = "dir";           //借贷方向（1：借，-1：贷）（INTEGER）
const QString fld_ba_number  = "numInPz";       //该业务活动在凭证业务活动表中的序号（INTEGER）
                                                //（序号决定了在表中的具体位置，基于1）
//字段索引
const int BACTION_PID     = 1;
const int BACTION_SUMMARY = 2;
const int BACTION_FID     = 3;
const int BACTION_SID     = 4;
const int BACTION_MTYPE   = 5;
const int BACTION_VALUE   = 6;
const int BACTION_DIR     = 7;
const int BACTION_NUMINPZ = 8;


//**************************老主目余额表（以原币计）*****************************/
//（各科目的字段名由代表科目类别的字母代码加上科目国标代码组成）
//A（资产类）B（负债类）C（共同类）D（所有者权益类）E（成本类）F（损益类）
//CREATE TABLE SubjectExtras(id INTEGER PRIMARY KEY, year INTEGER, month INTEGER,
//state INTEGER, mt INTEGER, A1001 REAL...)
const QString tbl_se        = "SubjectExtras";
const QString fld_se_year   = "year";
const QString fld_se_month  = "month";
const QString fld_se_state  = "state";     //余额是否有效（即最近一次保存此余额后凭证集是否做了影响统计余额的操作）
const QString fld_se_mt     = "mt" ;       //币种代码

const int SE_YEAR     = 1;  //(year INTEGER)
const int SE_MONTH    = 2;  //(month INTEGER) （如果month=12，则表示是年度余额）
const int SE_STATE    = 3;  //（state INTEGER）余额结转状态
const int SE_MT       = 4;  //（mt  INTEGER） 币种代码
const int SE_SUBSTART = 5;  //第一个科目所对应的字段索引号
// ......

//***********************主科目外币（转换为本币）余额表************************
/* CREATE TABLE SubjectMmtExtras(id INTEGER PRIMARY KEY, year INTEGER,
   month INTEGER,mt INTEGER,A1002 REAL,A1131 REAL,B2121 REAL)            */
//字段名
const QString tbl_sem       = "SubjectMmtExtras";
const QString fld_sem_year  = "year" ;  //
const QString fld_sem_month = "month";  //
const QString fld_sem_mt    = "mt" ;    //币种代码
const QString fld_sem_bank  = "A1002";  //银行
const QString fld_sem_ys    = "A1131";  //应收
const QString fld_sem_yf    = "B2121";  //应付
const QString fld_sem_yuf   = "A1151";  //预付
const QString fld_sem_yus   = "B2131";  //预收

//字段索引
const int SEM_YEAR  = 1;
const int SEM_MONTH = 2;
const int SEM_MT    = 3;
const int SEM_BANK  = 4;
const int SEM_YS    = 5;
const int SEM_YF    = 6;
const int SEM_YUF   = 7;
const int SEM_YUS   = 8;

//***********************子科目外币（转换为本币）余额表************************
/*  CREATE TABLE detailMmtExtras(id integer primary key,seid integer,
    fsid integer,value REAL)                              */
//字段名
const QString tbl_sdem       = "detailMmtExtras";
const QString fld_sdem_seid  = "seid";  //连接到SubjectMmtExtras表的id
const QString fld_sdem_fsid  = "fsid";  //连接到FSAgent表的id
const QString fld_sdem_value = "value";
//字段索引
const int SDEM_SEID  = 1;
const int SDEM_FSID  = 2;
const int SDEM_VALUE = 3;

//账户信息表(AccountInfo) 该表的每行代表一个账户的信息
//CREATE TABLE AccountInfo(id INTEGER PRIMARY KEY, code INTEGER, name TEXT, value TEXT)
//字段名
//const QString tbl_account   = "AccountInfo";
//const QString fld_acc_code  = "code";   //账户信息字段的枚举编号（INTEGER）
//const QString fld_acc_name  = "name";   //账户信息字段名（TEXT）
//const QString fld_acc_value = "value";  //账户信息字段值（TEXT）
////字段索引
//const int ACCOUNT_CODE    = 1;
//const int ACCOUNT_NAME    = 2;
//const int ACCOUNT_VALUE   = 3;


//凭证集状态表
//CREATE TABLE PZSetStates(id INTEGER PRIMARY KEY, year INTEGER, month INTEGER, state INTEGER)
//字段名
const QString tbl_pzsStates  = "PZSetStates";
const QString fld_pzss_year  = "year";
const QString fld_pzss_month = "month";
const QString fld_pzss_state = "state";
//字段索引
const int PZSS_YEAR  = 1;
const int PZSS_MONTH = 2;
const int PZSS_STATE = 3;

////////////////////////////新余额表系列//////////////////////////////////////////////
//余额指针表
//字段名
const QString tbl_nse_point   = "SE_Point";
const QString fld_nse_year    = "year";
const QString fld_nse_month   = "month";
const QString fld_nse_mt      = "mt";
const QString fld_nse_state   = "state";
//字段索引
const int NSE_POINT_YEAR  = 1;
const int NSE_POINT_MONTH = 2;
const int NSE_POINT_MT    = 3;
const int NSE_POINT_STATE = 4;

//新余额表
const QString tbl_nse_p_f = "SE_PM_F";   //一级科目原币余额
const QString tbl_nse_m_f = "SE_MM_F";   //一级科目本币余额
const QString tbl_nse_p_s = "SE_PM_S";   //二级科目原币余额
const QString tbl_nse_m_s = "SE_MM_S";   //二级科目本币余额
//字段名
const QString fld_nse_pid =    "pid";   //余额指针
const QString fld_nse_sid =    "sid";   //科目id
const QString fld_nse_value =  "value"; //余额值
const QString fld_nse_dir =    "dir" ;  //余额方向（保存本币余额的表不包含本字段）
//字段索引
const int NSE_E_PID   = 1;
const int NSE_E_SID   = 2;
const int NSE_E_VALUE = 3;
const int NSE_E_DIR   = 4;







//明细账视图过滤条件表
//字段名
const QString tbl_dvfilters     = "DVFilters";
const QString fld_dvfs_suite    = "suiteId";    //帐套id（每个帐套的过滤条件是相互独立的）
const QString fld_dvfs_isDef    = "isDef";      //是否是系统默认的
const QString fld_dvfs_isCur    = "isCur";      //是否是最后关闭窗口时应用的过滤条件
const QString fld_dvfs_isFstSub = "isFst";      //科目范围是一级科目还是二级科目
const QString fld_dvfs_curFSub  = "curFSubId";  //当前选择的一级科目id
const QString fld_dvfs_curSSub  = "curSSubId";  //当前选择的二级科目id
const QString fld_dvfs_mt       = "moneyType";  //当前选择的币种代码
const QString fld_dvfs_name     = "name";       //名称
const QString fld_dvfs_startDate= "startDate";  //开始时间
const QString fld_dvfs_endDate  = "endDate";    //结束时间
const QString fld_dvfs_subIds   = "subIds";     //选定的科目代码列表
//字段索引
const int DVFS_SUITEID      = 1;
const int DVFS_ISDEF        = 2;
const int DVFS_ISCUR        = 3;
const int DVFS_ISFST        = 4;
const int DVFS_CURFSUB      = 5;
const int DVFS_CURSSUB      = 6;
const int DVFS_MONEYTYPE    = 7;
const int DVFS_NAME         = 8;
const int DVFS_STARTDATE    = 9;
const int DVFS_ENDDATE      = 10;
const int DVFS_SUBIDS       = 11;


//科目系统衔接时一级科目的映射配置表（此表已弃用，一级科目的映射参考基本库的相应表）
const QString tbl_ssjc_pre     = "subSysJoin";
const QString fld_ssjc_sSub    = "sSub";        //源一级科目id
const QString fld_ssjc_dSub    = "dSub";        //目的一级科目id
const QString fld_ssjc_isMap   = "isMap";       //是否建立映射
const QString fld_ssjc_ssubMaps= "ssubMaps";    //子目的映射列表
const int SSJC_SSUB     = 1;
const int SSJC_DSUB     = 2;
const int SSJC_ISMAP    = 3;
const int SSJC_SSUBMaps = 4;

//账户配置变量表
const QString tbl_cfgVariable = "configVariables";
//const QString fld_cfgv_type  = "vtype"; //值类型（布尔型、整形、浮点型、字符串）
const QString fld_cfgv_name  = "vname"; //配置变量名
const QString fld_cfgv_value = "value"; //变量值
//const int CFGV_TYPE  = 1;
const int CFGV_NAME  = 1;
const int CFGV_VALUE = 2;

//转移表（transfers）
//create table transfers(id integer primary key, smid integer, dmid integer,
//state integer, outTime text, inTime text)
//字段名
const QString tbl_transfer      = "transfers";
const QString fld_trans_smid    = "smid";
const QString fld_trans_dmid    = "dmid";
const QString fld_trans_state   = "state";
const QString fld_trans_outTime = "outTime";
const QString fld_trans_inTime  = "inTime";
//字段索引
const int TRANS_SMID     = 1;
const int TRANS_DMID     = 2;
const int TRANS_STATE    = 3;
const int TRANS_OUTTIME  = 4;
const int TRANS_INTIME   = 5;

//转移动作情况描述表（transferDescs）
//create table transferDescs(id integer primary key, tid integer, outDesc text, inDesc text)
//字段名
const QString tbl_transferDesc  = "transferDescs";
const QString fld_transDesc_tid = "tid";
const QString fld_transDesc_out = "outDesc";
const QString fld_transDesc_in  = "inDesc";
//字段索引
const int TRANSDESC_TID  = 1;
const int TRANSDESC_OUT  = 2;
const int TRANSDESC_IN   = 3;

//二级科目对接表（sndSubJoin）
//当科目系统升级时，有些老科目可能要并入新科目，这样就必须将原属于老主目的
//子目并入新主目中，并入的规则是如果原有子目在新主目中有对应的，即使用了相同的名称条目
//则可以直接对应，否则要使用这个名称条目在新主目下创建一个新子目并建立对应，这个表就是保存
//了这些对应关系，它应用在
//（1）当读取采用新科目系统的帐套的期初数据时，用来转换余额
//（2）当升级帐套时，要使用它来替换分录中的一二级科目，并转换它们的余额。
const QString tbl_sndsub_join_pre = "sndSubJoin";
const QString fld_ssj_s_fsub = "sFSubId";   //源一级科目id
const QString fld_ssj_s_ssub = "sSSubId";   //源二级科目id
const QString fld_ssj_d_fsub = "dFSubId";   //对接一级科目id
const QString fld_ssj_d_ssub = "dSSubId";   //对接二级科目id
const int SSJ_SF_SUB = 1;
const int SSJ_SS_SUB = 2;
const int SSJ_DF_SUB = 3;
const int SSJ_DS_SUB = 4;

//子窗口状态表（subWinInfos）
//字段名
const QString tbl_subWinInfo = "subWinInfos";
const QString fld_swi_enum  = "winEnum";  //字窗口类别枚举值（INTEGER）
const QString fld_swi_stateInfo = "tblInfo";//子窗体内自定义状态信息（tblInfo）
const int FI_SWI_ENUM   = 1;
const int FI_SWI_STATE  = 6;


//笔记表
const QString tbl_Notes = "notes";
const QString fld_notes_title = "title";
const QString fld_notes_createTime = "createTime";
const QString fld_notes_lastEditTime = "lastEditTime";
const QString fld_notes_content = "content";
const int FI_NOTE_TITLE = 1;
const int FI_NOTE_CREATETIME = 2;
const int FI_NOTE_LASTTIME = 3;
const int FI_NOTE_CONTENT = 4;

//包含型子目智能适配配置表
const QString tbl_SmartSSubAdapter = "SmartSSubAdapters";
const QString fld_ssa_subSys = "subSys";    //科目系统代码
const QString fld_ssa_fsub = "fsub";        //一级科目id
const QString fld_ssa_subStr = "keySubStr"; //包含的文本（如有多个，则用中文的逗号分隔）
const QString fld_ssa_ssub = "ssub";        //二级科目id
const int FI_SSA_SUBSYS = 1;
const int FI_SSA_FSUB = 2;
const int FI_SSA_SUBSTR = 3;
const int FI_SSA_SSUB = 4;


//账户数据库中可能驻留的临时表
const QString tbl_tem_appcfg = "tem_app_cfg";
const QString fld_tem_appcfg_obj = "objText";   //保存序列化对象后的文本
const int FI_TEM_APPCFG_VERTYPE = 1;
const int FI_TEM_APPCFG_VERNAME = 2;
const int FI_TEM_APPCFG_MASTER = 3;
const int FI_TEM_APPCFG_SECOND = 4;
const int FI_TEM_APPCFG_OBJECT = 5;

//承销企业收入/成本发票使用情况记录表
const QString tbl_invoiceRecords = "invoiceRecords";
const QString fld_ir_date = "date";             //日期
const QString fld_ir_number = "InvoiceNumber";  //发票号
const QString fld_ir_isCommon = "isCommon";     //是否普票
const QString fld_ir_isIncome = "isIncome";     //收入/成本i
const QString fld_ir_customer = "customer";     //关联客户
const QString fld_ir_pzNumber = "pzNumer";      //凭证号（有效使用该发票的所在凭证）
const QString fld_ir_baRID = "baRID";           //分录记录的id
const QString fld_ir_money = "money";           //账面金额（本币金额）
const QString fld_ir_taxMoney = "taxMoney";      //税金
const QString fld_ir_wmoney = "wmoney";         //外币金额
const QString fld_ir_mt = "moneyType";          //外币币种（通常是美金）
const QString fld_ir_state = "caState";         //发票销账状态
const int FI_IR_DATE = 1;
const int FI_IR_NUMBER = 2;
const int Fi_IR_ISCOMMON = 3;
const int FI_IR_ISINCOME = 4;
const int FI_IR_CUSTOMER = 5;
const int FI_IR_PZNUMBER = 6;
const int FI_IR_BARID = 7;
const int FI_IR_MONEY = 8;
const int FI_IR_TAXMONEY = 9;
const int FI_IR_WMONEY = 10;
const int FI_IR_MONTYTYPE = 11;
const int FI_IR_STATE = 12;

//分录模板暂存表（用于在输入发票聚合类分录时，不能一次完成的情形下提供暂时存储）
const QString tbl_baTemTable = "BaTemSaveRecords";
const QString fld_btt_invoice = "invoiceNum";
const QString fld_btt_money = "money";
const QString fld_btt_taxMoney = "taxMoney";
const QString fld_btt_wMoney = "wMoney";
const QString fld_btt_sname = "sName";
const QString fld_btt_lname = "lName";
const QString fld_btt_remCode = "remCode";
//与上表对应的表示在暂存区中存储的模板类型（应收聚合或应付聚合），只有一个记录
const QString tbl_baTemType = "BaTemplateType";
const QString fld_btt_type = "type";

//当月应收发票开具、成本发票使用记录表
const QString tbl_cur_invoices = "curInvoices";
const QString fld_ci_ym = "belongDate";         //1、所属年月（高四位年份，低两位月份）
const QString fld_ci_iClass = "iCalss";         //2、收入/成本
const QString fld_ci_number = "number";         //3、序号
const QString fld_ci_iType = "iType";           //4、1专票/0普票
const QString fld_ci_date = "date";             //5、发票开具日期
const QString fld_ci__iNumber = "iNumber";      //6、发票号
const QString fld_ci_client = "client";         //7、单位名称
const QString fld_ci_match_name = "matchedName";//8、匹配的名称对象id
const QString fld_ci_money = "money";           //9、发票金额
const QString fld_ci_wbMoney = "wbMoney";       //10、外币金额
const QString fld_ci_taxMoney = "taxMoney";     //11、税额
const QString fld_ci_state = "state";           //12、发票性质（1正常、2作废、3冲红）
const QString fld_ci_skState = "skState";       //13、收款情况（这个只作为原始记录）
const QString fld_ci_isProcess = "isProcess";   //14、是否已在本期处理（比如作为收入/应收处理，或作为成本/应付处理）
const int FI_CI_YM = 1;
const int FI_CI_CLASS = 2;
const int FI_CI_NUM = 3;
const int FI_CI_TYPE = 4;
const int FI_CI_DATE = 5;
const int FI_CI_INUMBER = 6;
const int FI_CI_CLIENT = 7;
const int FI_CI_MATCHEDNAME = 8;
const int FI_CI_MONEY = 9;
const int FI_CI_WBMONEY = 10;
const int FI_CI_TAXMONEY = 11;
const int FI_CI_STATE = 12;
const int FI_CI_SKSTATE = 13;
const int FI_CI_ISPROCESS = 14;

//进项税历史缓存表（保存当月进成本但又未认证的专票）
const QString tblJxTax = "jxTaxHistorys";
const QString fld_jt_pz = "pzNum";               //记录该发票的凭证（xxxx年xx月xxx#）
const QString fld_jt_ba = "baId";                //与发票对应的分录id
const QString fld_jt_invoice    = "invoiceNum";  //发票号
const QString fld_jt_sndSub = "subject";         //发票客户对应的应付账款下的二级科目
const QString fld_jt_date = "date";              //开票日期
const QString fld_jt_tax    = "taxMoney";        //进项税额
const QString fld_jt_money = "money";            //发票金额
const int FI_JX_PZ = 1;
const int FI_JX_BA = 2;
const int FI_JX_INVOICE = 3;
const int FI_JX_SUB = 4;
const int FI_JX_DATE = 5;
const int FI_JX_TAX = 6;
const int FI_JX_MONEY = 7;

//本月认证成本发票暂存表
const QString tblCurAuthInvoices = "curAuthCostInvoices";
//前三字段分别是id，year，month
const QString fld_caci_num = "inum";            //发票号
const QString fld_caci_taxMoney = "taxMoney";   //税额
const QString fld_caci_money = "money";         //发票金额
const QString fld_caci_cni = "cni";             //发票对应客户的名称对象id
const QString fld_caci_isCur = "isCur";         //1：当月成本发票，0：以前月份调整计入的成本发票
const int FI_CACI_NUM = 3;
const int FI_CACI_TAXMONEY = 4;
const int FI_CACI_MONEY = 5;
const int FI_CACI_CLIENT = 6;
const int FI_CACI_ISCUR = 7;
const QString fld_taxamount_tag = "TAX AMOUNT";     //该表存放每月认证进项税额合计值记录的标记发票号字段


//原始流水账表（journals）
const QString tbl_journals = "journals";
const QString fld_jo_priNum  = "priNum";       //原始序号
const QString fld_jo_date = "date";            //日期
const QString fld_jo_bank = "bankID";          //银行账号/现金子目id
const QString fld_jo_isIncome = "isIncome";    //收入/支出
const QString fld_jo_summary = "summary";      //摘要
const QString fld_jo_value = "value";          //金额
const QString fld_jo_balance = "balance";      //余额
const QString fld_jo_invoice = "invoices";     //发票号
const QString fld_jo_remark = "remark";        //备注
const QString fld_jo_vtag = "vtag";            //审核标志（初值为0，1：表通过）
const int FI_JO_PRINUM = 1;
const int FI_JO_DATE = 2;
const int FI_JO_BANK = 3;
const int FI_JO_ISINCOME = 4;
const int FI_JO_SUMMARY = 5;
const int FI_JO_VALUE = 6;
const int FI_JO_BALANCE = 7;
const int FI_JO_INVOICE = 8;
const int FI_JO_REMARK = 9;
const int FI_JO_VTAG = 10;

//由流水账生成的分录缓存表（journalizings）
const QString tbl_journalizings = "journalizings";
const QString fld_jol_gid = "gid";                  //组id--每条流水账对应一组分录，可以作为外键，指向流水账表的id
const QString fld_jol_gnum = "gnum";                //组序号--表征实际的导入顺序，也是在此从分录缓存表中读入时保留原始的导入顺序的保证
const QString fld_jol_numInGroup = "numInGroup";    //组内序号
const QString fld_jol_pnum = "pnum";                //虚拟凭证号
const QString fld_jol_summary = "summary";          //摘要
const QString fld_jol_fid = "fid";                  //主目
const QString fld_jol_sid = "sid";                  //子目
const QString fld_jol_mt = "mt";                    //币种
const QString fld_jol_dir = "dir";                  //借贷方向
const QString fld_jol_value = "value";               //金额
const int FI_JOL_GID = 1;
const int FI_JOL_GNUM = 2;
const int FI_JOL_NUMINGROUP = 3;
const int FI_JOL_PNUM = 4;
const int FI_JOL_SUMMARY = 5;
const int FI_JOL_FID = 6;
const int FI_JOL_SID = 7;
const int FI_JOL_MT = 8;
const int FI_JOL_DIR = 9;
const int FI_JOL_VALUE = 10;


//////////*****************基本库数据表********************************//////////
//币种类别表
const QString tbl_base_mt = "MoneyTypes";
const QString fld_base_mt_code = "code";
const QString fld_base_mt_sign = "sign";
const QString fld_base_mt_name = "name";
const int BASE_MT_CODE = 1;
const int BASE_MT_SIGN = 2;
const int BASE_MT_NAME = 3;

//凭证状态名表
//CREATE TABLE pzStateNames(id INTEGER PRIMARY KEY, code INTEGER, state TEXT)
//字段名
const QString tbl_pzStateName = "pzStateNames";
const QString fld_pzsn_code   = "code";
const QString fld_pzsn_name   = "state";
//字段索引
const int PZSN_CODE = 1;
const int PZSN_NAME = 2;


//凭证集状态名表
//CREATE TABLE "pzsStateNames"(id INTEGER PRIMARY KEY, code INTEGER, state TEXT, desc TEXT)
//字段名
const QString tbl_pzsStateNames = "pzsStateNames";
const QString fld_pzssn_code    = "code";
const QString fld_pzssn_sname   = "state";
const QString fld_pzssn_lname   = "desc";
//字段索引
const int PZSSN_CODE  = 1;
const int PZSSN_SNAME = 2;
const int PZSSN_LNAME = 3;

/**
 *  配置表（configs）
 */
//字段名
const QString tbl_base_Cfg       = "configs";
const QString fld_bconf_type    = "type";       //变量类型
const QString fld_bconf_enum    = "enumCode";   //变量枚举代码
const QString fld_bconf_value   = "value";      //变量值
//字段索引
const int BCONF_TYPE  = 1;
const int BCONF_ENUM  = 2;
const int BCONF_VALUE = 3;

/**
 *本地账户缓存表（LocalAccountCaches)
 */
//字段名
const QString tbl_localAccountCache = "LocalAccountCaches";
const QString fld_lac_code          = "code";               //账户编码
const QString fld_lac_name          = "name";               //账户简称
const QString fld_lac_lname         = "lname";              //账户全称
const QString fld_lac_filename      = "fname";              //账户文件名
const QString fld_lac_isLastOpen    = "isLastOpen";         //是否是最近打开的账户
const QString fld_lac_tranState     = "tstate";             //转移状态
const QString fld_lac_tranInTime    = "tranInTime";         //转入时间
const QString fld_lac_tranSrcMid    = "tranOutMid";         //转出源站ID
const QString fld_lac_tranOutTime   = "tranOutTime";        //转出时间
const QString fld_lac_tranDesMid    = "tranDesMid";         //转入目的站ID
const QString fld_lac_hash          = "hashValue";          //账户文件的Hash值
//字段索引
const int LAC_CODE      = 1;
const int LAC_NAEM      = 2;
const int LAC_LNAME     = 3;
const int LAC_FNAME     = 4;
const int LAC_ISLAST    = 5;
const int LAC_TSTATE    = 6;
const int LAC_INTIME    = 7;
const int LAC_SMAC      = 8;
const int LAC_OUTTIME   = 9;
const int LAC_DMAC      = 10;
const int LAC_HASH      = 11;

/**
 *  科目系统名称表
 */
const QString tbl_subSys        = "subSysNames";
const QString fld_ss_code       = "code";       //科目系统代码（integer）
const QString fld_ss_name       = "name";       //科目系统名称（TEXT）
const QString fld_ss_startTime  = "startTime";  //启用时间
const QString fld_ss_explain    = "explain";    //说明信息（TEXT）
const int SS_CODE   = 1;
const int SS_NAME   = 2;
const int SS_TIME   = 3;
const int SS_EXPLAIN= 4;

//主机表（machines）
//CREATE TABLE machines(id integer primary key, type integer, mid integer,
//isLocal integer, sname text, lname text)
//字段名
const QString tbl_machines      = "machines";
const QString fld_mac_mid       = "mid";
const QString fld_mac_type      = "type";
const QString fld_mac_islocal   = "isLocal";
const QString fld_mac_sname     = "sname";
const QString fld_mac_desc      = "lname";
const QString fld_mac_ostype    = "osType";
//字段索引
const int MACS_MID        = 1;
const int MACS_TYPE       = 2;
const int MACS_ISLOCAL    = 3;
const int MACS_NAME       = 4;
const int MACS_DESC       = 5;
const int MACS_OSTYPE     = 6;

//操作系统类型表
const QString tbl_base_osTypes = "osTypes";
const QString fld_base_osTypes_code = "osCode";     //系统编码
const QString fld_base_osTypes_mName = "masterName";//操作系统系列名
const QString fld_base_osTypes_sName = "secondName";//版本名
//字段索引
const int FI_BASE_OSTYPES_CODE  = 1;
const int FI_BASE_OSTYPES_MN    = 2;
const int FI_BASE_OSTYPES_SN    = 3;

//账户数据库表格创建语句表（tableCrtSqls）
const QString tbl_table_create_sqls = "tableCrtSqls";

//一级科目类别表
const QString tbl_base_fsub_cls = "FirstSubCls";
const QString fld_base_fsub_cls_subSys = "subCls";
const QString fld_base_fsub_cls_clsCode = "code";
const QString fld_base_fsub_cls_name = "name";
const int FI_BASE_FSUB_CLS_SUBSYS = 1;
const int FI_BASE_FSUB_CLS_CODE   = 2;
const int FI_BASE_FSUB_CLS_NAME   = 3;


//一级科目表
const QString tbl_base_fsub         = "FirstSubs";
const QString fld_base_fsub_subsys  = "subCls";
const QString fld_base_fsub_subcode = "subCode";
const QString fld_base_fsub_remcode = "remCode";
const QString fld_base_fsub_subcls  = "belongTo";
const QString fld_base_fsub_jddir   = "jdDir";
const QString fld_base_fsub_isenabled = "isView";
const QString fld_base_fsub_isUseWb = "isReqDet";
const QString fld_base_fsub_weight  = "weight";
const QString fld_base_fsub_subname = "subName";
const QString fld_base_fsub_desc    = "description";
const QString fld_base_fsub_util    = "utils";
const int FI_BASE_FSUB_SUBSYS = 1;
const int FI_BASE_FSUB_SUBCODE= 2;
const int FI_BASE_FSUB_REMCODE= 3;
const int FI_BASE_FSUB_CLS    = 4;
const int FI_BASE_FSUB_JDDIR  = 5;
const int FI_BASE_FSUB_ENABLE = 6;
const int FI_BASE_FSUB_USEDWB = 7;
const int FI_BASE_FSUB_WEIGHT = 8;
const int FI_BASE_FSUB_SUBNAME=9;
const int FI_BASE_FSUB_DESC   = 10;
const int FI_BASE_FSUB_UTILS  = 11;

//名称类别表
const QString tbl_base_nic          = "SecondSubCls";
const QString fld_base_nic_order    = "subCls";         //显示顺序
const QString fld_base_nic_code     = "clsCode";
const QString fld_base_nic_name     = "name";
const QString fld_base_nic_explain  = "explain";
const int FI_BASE_NIC_ORDER     = 1;
const int FI_BASE_NIC_CODE      = 2;
const int FI_BASE_NIC_NAME      = 3;
const int FI_BASE_NIC_EXPLAIN   = 4;

//名称表
const QString tbl_base_ni           = "SecondSubs";
const QString fld_base_ni_name      = "subName";
const QString fld_base_ni_lname     = "subLName";
const QString fld_base_ni_remcode   = "remCode";
const QString fld_base_ni_clsid     = "classID";
const QString fld_base_ni_belongto  = "belongTo";
const int FI_BASE_NI_BELONGTO   = 6;
const int FI_BASE_NI_SNAME      = 2;
const int FI_BASE_NI_LNAME      = 3;
const int FI_BASE_NI_REMCODE    = 4;
const int FI_BASE_NI_CLASS      = 5;
const int FI_BASE_NI_CODE       = 7;

//特定科目代码配置表
const QString tbl_base_sscc  = "specSubCodeConfig";
//字段名
const QString fld_base_sscc_subSys  = "subSys";   //科目系统
const QString fld_base_sscc_enum    = "subEnum";    //特定科目枚举值
const QString fld_base_sscc_code    = "code";       //科目代码
//字段索引
const int FI_BASE_SSCC_SUBSYS = 1;
const int FI_BASE_SSCC_ENUM   = 2;
const int FI_BASE_SSCC_CODE   = 3;

//科目系统对接科目表
const QString tbl_base_subsysjion_pre = "subSysJoin";
const QString fld_base_ssjc_scode = "scode";    //源科目代码
const QString fld_base_ssjc_dcode = "dcode";    //目的科目代码
const QString fld_base_ssjc_isDef = "isDef";    //是否默认对接，即是否有只有一个源科目对接到此科目
//字段索引
const int FI_BASE_SSJC_SCODE = 1;
const int FI_BASE_SSJC_DCODE = 2;
const int FI_BASE_SSJC_ISDEF = 3;

//权限类别表
const QString tbl_base_righttypes = "rightType";
const QString fld_base_rt_pcode = "pcode";      //父类别代码
const QString fld_base_rt_code = "code";
const QString fld_base_rt_name = "name";
const QString fld_base_rt_explain = "explain";
const int FI_BASE_RT_PCODE = 1;
const int FI_BASE_RT_CODE = 2;
const int FI_BASE_RT_NAME = 3;
const int FI_BASE_RT_EXPLAIN = 4;

//权限表
const QString tbl_base_rights = "rights";
const QString fld_base_r_code = "code";
const QString fld_base_r_type = "type";
const QString fld_base_r_name = "name";
const QString fld_base_r_explain = "explain";
const int FI_BASE_R_CODE = 1;
const int FI_BASE_R_TYPE = 2;
const int FI_BASE_R_NAME = 3;
const int FI_BASE_R_EXPLAIN = 4;

//用户组表
const QString tbl_base_usergroups = "groups";
const QString fld_base_g_code = "code";
const QString fld_base_g_name = "name";
const QString fld_base_g_rights = "haveRights"; //组的额外权限
const QString fld_base_g_groups = "ownerGroups";//所属组
const QString fld_base_g_explain = "explain";
const int FI_BASE_G_CODE = 1;
const int FI_BASE_G_NAME = 2;
const int FI_BASE_G_RIGHTS = 3;
const int FI_BASE_G_GROUPS  = 4;
const int FI_BASE_G_EXPLAIN = 5;


//用户表
const QString tbl_base_users = "users";
const QString fld_base_u_name = "name";                         //名称
const QString fld_base_u_password = "password";                 //密码
const QString fld_base_u_groups = "ownerGroups";                //所属组
const QString fld_base_u_accounts = "exclusiveAccounts";        //专属账户列表
const QString fld_base_u_disabled_rights = "disabledRights";    //禁用权限
const QString fld_base_u_isenabled = "isEnabled";               //此用户是否启用
const int FI_BASE_U_NAME = 1;
const int FI_BASE_U_PASSWORD = 2;
const int FI_BASE_U_GROUPS = 3;
const int FI_BASE_U_ACCOUNTS = 4;
const int FI_BASE_U_DISABLED_RIGHTS = 5;
const int FI_BASE_U_ISENABLED = 6;

//外部工具配置表
const QString tbl_base_external_tools = "ExternalTools";
const QString fld_base_et_name = "Name";
const QString fld_base_et_commandline = "Command";
const QString fld_base_et_parameter = "Parameter";
const int FI_BASE_ET_NAME = 1;
const int FI_BASE_ET_COMMANDLINE = 2;
const int FI_BASE_ET_PARAMETER = 3;

//子窗口信息表（subWinInfos）
//字段名
const QString tbl_base_subWinInfo = "subWinInfos";
const QString fld_base_swi_enum  = "winEnum";  //字窗口类别枚举值（INTEGER）
const QString fld_base_swi_x     = "x";        //x,y,w,h是子窗口最后一次关闭时的位置和大小尺寸
const QString fld_base_swi_y     = "y";
const QString fld_base_swi_width = "w";
const QString fld_base_swi_height= "h";
const QString fld_base_swi_stateInfo = "tblInfo";//子窗体内自定义状态信息（tblInfo）

//字段索引
const int   FI_BASE_SWI_ENUM    = 1;
const int   FI_BASE_SWI_X       = 2;
const int   FI_BASE_SWI_Y       = 3;
const int   FI_BASE_SWI_W       = 4;
const int   FI_BASE_SWI_H       = 5;
const int   FI_BASE_SWI_TBL     = 6;

//版本表（versions）
const QString tbl_base_version = "versions";
const QString fld_base_version_typeEnum = "typeEnum";
const QString fld_base_version_typeName = "typeName";
const QString fld_base_version_master = "master";
const QString fld_base_version_second = "second";
//字段索引
const int FI_BASE_VER_TYPEENUM = 1;
const int FI_BASE_VER_TYPENAME = 2;
const int FI_BASE_VER_MASTER = 3;
const int FI_BASE_VER_SECOND = 4;

//常用提示短语表
const QString tbl_base_commonPromptPhrase = "CommonPromptPhrases";
const QString fld_base_cpp_class = "class";     //短语类别
const QString fld_base_cpp_number = "number";   //序号
const QString fld_base_cpp_phrase = "phrase";   //短语
const int FI_BASE_CPP_CLASS = 1;
const int FI_BASE_CPP_NUMBER = 2;
const int FI_BASE_CPP_PHRASE = 3;
#endif // TABLES_H
