
#pragma once

#include <iostream>


namespace Utils{
  namespace Log{
    /**
     * Initialize the log streams.
     *
     * This function must be called before any call to `oplog()`.
     * @return `true` if everything is OK; `false` if there is an error.
     */
    bool init();

    /**
     * Write a log message in a log file.
     *
     * @param toSay message to write.
     * @param bool if `true` the log message will be written in th error log file;
     *   otherwise, it will be written in the regular log file.
     */
    void oplog(const std::string &toSay, bool error = false);

  }
}
