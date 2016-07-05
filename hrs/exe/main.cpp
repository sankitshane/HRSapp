#include "Application.h"

#include <string>
#include <dbaccess/dbAccess.h>

#ifdef ALOGGER
#include <logger/Logger.h>
#endif

int main()
{

  dbaccess::DBAccess::setDSNName("hrsdsn");
  dbaccess::DBAccess::setUserName("scott");
  dbaccess::DBAccess::setPassword("tiger");

#ifdef ALOGGER
  logger::Logger::getInstance("hrs.log", logger::Logger::LevelDebug);
  logger::Logger::getInstance().info("Starting HRS application...");
#endif
  Application theApp;
  return theApp.run();
}
