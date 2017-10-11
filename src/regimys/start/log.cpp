
#include "main.hpp"

UNS


/**Principal log*/
static ofstream *rlog;
/**Error log*/
static ofstream *rerrLog;


bool initLogStream() {

    mkdir(LOG_PATH);

    rlog = new ofstream(LOG_PATH + "log.txt");
    rerrLog = new ofstream(LOG_PATH + "errLog.txt");

    if (!*rlog) {
        cout << "Unable to open the log." << endl;
        return false;
    }
    if (!*rerrLog) {
        cout << "Unable to open the error log" << endl;
        return false;
    }
    return true;
}


void oplog(const string &toSay, bool error){
    std::ofstream *logStream = error ? rerrLog : rlog;

    *logStream << "[T = " << ticks.getElapsedTime().asMilliseconds() << "] - " << toSay << endl;
}
