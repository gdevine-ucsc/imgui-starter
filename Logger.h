#pragma once

#include <string>

// this class uses a singleton structure! i learned about them here:
// https://refactoring.guru/design-patterns/singleton/cpp/example

class Logger {

    private:
        Logger();

        //static Logger* instance;

    public:
        //Logger(Logger &other) = delete; // prevent using constructor in other classes
        //void operator=(const Logger &) = delete; // prevent assigning of instance to something else

        static Logger& GetInstance();

        void GameStartUp();
        void RenderGame();
        
        void LogInfo(const std::string info);
        void LogGameEvent(const std::string gameEvent);
        void ClearLog();

};
