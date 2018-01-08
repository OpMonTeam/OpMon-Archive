
#include <fstream>
#include "./log.hpp"
#include "./fs.hpp"
#include "./time.hpp"


/**Principal log*/
static std::ofstream *rlog;
/**Error log*/
static std::ofstream *rerrLog;


/* location of the log folder */
#define LOG_PATH std::string("logs/")

namespace Utils{
  namespace Log{

    bool init(){

      Fs::mkdir(LOG_PATH);

      rlog = new std::ofstream(LOG_PATH + "log.txt");
      rerrLog = new std::ofstream(LOG_PATH + "errLog.txt");

      if (!*rlog) {
        std::cout << "Unable to open the log." << std::endl;
        return false;
      }
      if (!*rerrLog) {
        std::cout << "Unable to open the error log" << std::endl;
        return false;
      }
      return true;
    }


    void oplog(const std::string &toSay, bool error){
      std::ofstream *logStream = error ? rerrLog : rlog;

      *logStream << "[T = " << Time::getElapsedMilliseconds() << "] - " << toSay << std::endl;
    }

  }
}
