#include "Logger.h"
#include "imgui/imgui.h"

#include <iostream>
#include <list>

static Logger* instance;
//std::string fullLog = "";

struct Entry { std::string text; ImU32 color; };

std::list<Entry> fullLog;

Logger::Logger() {}

Logger& Logger::GetInstance() {

    if (!instance) {
        instance = new Logger();
    }

    return *instance;
}

void Logger::GameStartUp() {}

void Logger::RenderGame() {

    ImGui::Begin("Game Log");

    if (ImGui::Button("Clear"))
    {
        ClearLog();
    }

    //ImGui::Text(fullLog.c_str());
    //ImGui::LogFinish();

    RenderText();

    ImGui::End();
}

void Logger::RenderText() {

    for (Entry entry : fullLog) {
        
        ImGui::PushStyleColor(ImGuiCol_Text, entry.color);

        std::string displayText = "";
        displayText += entry.text;
        ImGui::TextUnformatted(displayText.c_str());

        ImGui::PopStyleColor();
    }

    ImGui::LogFinish();

}

void Logger::LogInfo(const std::string info) {
    //fullLog += "[info] " + info + '\n';
    std::string entryText = "[info] " + info + '\n';
    Entry entry = {entryText, 99999};
    fullLog.push_back(entry);
}

void Logger::LogGameEvent(const std::string gameEvent) {

    //fullLog += "[game event] " + gameEvent + '\n';
    std::string entryText = "[game event] " + gameEvent + '\n';
    Entry entry = {entryText, 99950};
    fullLog.push_back(entry);
}

void Logger::ClearLog() {
    //fullLog = "";
}