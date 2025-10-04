#include "Logger.h"
#include "imgui/imgui.h"

#include <iostream>

static Logger* instance;
std::string fullLog = "";

Logger::Logger() {}

Logger& Logger::GetInstance() {

    if (!instance) {
        instance = new Logger();
    }

    return *instance;
}

void Logger::GameStartUp() {}

void Logger::RenderGame() {

    //ImGui::ShowDemoWindow();
    //ImGui::ShowDebugLogWindow();

    ImGui::Begin("Game Log");

    ImGui::Text(fullLog.c_str());

    ImGui::LogFinish();

    ImGui::End();
}

void Logger::LogInfo(const std::string info) {
    fullLog += "[info] " + info + '\n';
}

void Logger::LogGameEvent(const std::string gameEvent) {
    fullLog += "[game event] " + gameEvent + '\n';
}