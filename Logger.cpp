#include "Logger.h"
#include "imgui/imgui.h"

#include <iostream>

static Logger* instance;

Logger::Logger() {}

Logger& Logger::GetInstance() {

    if (!instance) {
        instance = new Logger();
    }

    return *instance;
}

void Logger::GameStartUp() {}

void Logger::RenderGame() {

    ImGui::ShowDemoWindow();
    //ImGui::ShowDebugLogWindow();

    ImGui::Begin("Game Log");

    ImGui::End();
}

void Logger::LogInfo(const std::string info) {
    ImGui::LogText(info.c_str());
}

void Logger::LogGameEvent(const std::string gameEvent) {
    ImGui::LogText(gameEvent.c_str());
}