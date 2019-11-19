#ifndef SETTINGS_H
#define SETTINGS_H

#include "precompiled.h"

struct Config {
    QString host;
    QString port;
    QString rpcuser;
    QString rpcpassword;
};

struct ToFields;
struct Tx;

struct PaymentURI {
    QString addr;
    QString amt;
    QString memo;

    // Any errors are stored here
    QString error;
};

class Settings
{
public:
    static  Settings* init();
    static  Settings* getInstance();

    Config  getSettings();
    void    saveSettings(const QString& host, const QString& port, const QString& username, const QString& password);

    bool    isTestnet();
    void    setTestnet(bool isTestnet);
            
    bool    isSaplingAddress(QString addr);
    bool    isSproutAddress(QString addr);
            
    bool    isValidSaplingPrivateKey(QString pk);

    bool    isSyncing();
    void    setSyncing(bool syncing);

    int     getVcoindVersion();
    void    setVcoindVersion(int version);
    
    void    setUseEmbedded(bool r) { _useEmbedded = r; }
    bool    useEmbedded() { return _useEmbedded; }

    void    setHeadless(bool h) { _headless = h; }
    bool    isHeadless() { return _headless; }

    int     getBlockNumber();
    void    setBlockNumber(int number);
            
    bool    getSaveZtxs();
    void    setSaveZtxs(bool save);

    bool    getAutoShield();
    void    setAutoShield(bool allow);

    bool    getAllowCustomFees();
    void    setAllowCustomFees(bool allow);

    bool    getAllowFetchPrices();
    void    setAllowFetchPrices(bool allow);

    bool    getCheckForUpdates();
    void    setCheckForUpdates(bool allow);

    QString get_theme_name();
    void set_theme_name(QString theme_name);

    bool    isSaplingActive();

    void    setUsingVcoinConf(QString confLocation);
    const   QString& getVcoindConfLocation() { return _confLocation; }

    void    setVCCPrice(double p) { vccPrice = p; }
    double  getVCCPrice();

    void    setPeers(int peers);
    int     getPeers();
       
    // Static stuff
    static const QString txidStatusMessage;
    
    static void saveRestore(QDialog* d);
    static void saveRestoreTableHeader(QTableView* table, QDialog* d, QString tablename) ;

    static void openAddressInExplorer(QString address);
    static void openTxInExplorer(QString txid);

    static PaymentURI parseURI(QString paymentURI);
    static QString    paymentURIPretty(PaymentURI);

    static bool    isZAddress(QString addr);
    static bool    isTAddress(QString addr);

    static QString getDecimalString(double amt);
    static QString getUSDFormat(double usdAmt);

    static QString getUSDFromVccAmount(double bal);
    static QString getVCCDisplayFormat(double bal);
    static QString getVCCUSDDisplayFormat(double bal);

    static QString getTokenName();
    static QString getDonationAddr();

    static double  getMinerFee();
    static double  getZboardAmount();
    static QString getZboardAddr();

    static int     getMaxMobileAppTxns() { return 30; }
    
    static bool    isValidAddress(QString addr);

    static bool    addToVcoinConf(QString confLocation, QString line);
    static bool    removeFromVcoinConf(QString confLocation, QString option);

    static const QString labelRegExp;

    static const int     updateSpeed         = 20 * 1000;        // 20 sec
    static const int     quickUpdateSpeed    = 5  * 1000;        // 5 sec
    static const int     priceRefreshSpeed   = 60 * 60 * 1000;   // 1 hr

private:
    // This class can only be accessed through Settings::getInstance()
    Settings() = default;
    ~Settings() = default;

    static Settings* instance;

    QString _confLocation;
    QString _executable;
    bool    _isTestnet        = false;
    bool    _isSyncing        = false;
    int     _blockNumber      = 0;
    int     _vcoindVersion    = 0;
    bool    _useEmbedded      = false;
    bool    _headless         = false;
    int     _peerConnections  = 0;
    
    double  vccPrice          = 0.0;
};

#endif // SETTINGS_H
