#include <stdio.h>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/SimpleLayout.hh>

#define LOGFILE "./test.txt"

int main()
{
    /*Setting up Appender, layout and Category*/
    log4cpp::Appender *appender = new log4cpp::FileAppender("FileAppender",LOGFILE);
    log4cpp::Layout *layout = new log4cpp::SimpleLayout();
    log4cpp::Category& category = log4cpp::Category::getInstance("Category");

    appender->setLayout(layout);
    category.setAppender(appender);
    category.setPriority(log4cpp::Priority::INFO);

    /*The actual logging*/
    category.info("This is for tracing the flow");
    category.notice("This is to notify certain events");
    category.warn("This is to generate certain warnings");
}
// g++ -I/usr/local/include/log4cpp -L/usr/local/lib/ -llog4cpp -lpthread log.cc 
// LD_LIBRARY_PATH=/usr/local/lib ./a.out
