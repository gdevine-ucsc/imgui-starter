# imgui-starter - Logger Assignment - Aegis Michael

### Windows build

For this assignment, I started off by uncommenting the code creating an instance of the Logger class and banging my head into the wall trying to set up a header file and cpp for a Logger class. While doing this, I had to make sure to use a singleton framework, which I had some familiarity with in C# in Unity, as the Application.cpp calls for GetInstance() and it makes sense that there should only be one instance of the Logger class. To finish setting up the file, I made sure to go into the makefile and add my new Logger.cpp.

While working out the logic of the Logger class, I started by getting it to open a window in the ImGui application, using the Application.cpp file as reference. After that, I looked through the imgui.h file as a reference for what ImGui functions I could call (for lack of documentation as far as I could find?) to print out the basic logs from the Application.cpp file. To do this, I maintained a string that contained the entire log, using linebreaks to split up each log.

After printing the text, I wanted to be able to choose a specific color for each line, so that warnings and errors could be yellow and red respectively, but I was a little lost without proper imgui documentation so I asked in the discord! Divine recommended using the PushStyleColor() function, but I messed around with it for a long time and couldn't get it working. In the process, however, I found the ColoredText() function, which I was able to get working. To do that, I made a struct to keep track of the text and color of each individual line. As a final detail, I decided to expand my struct to contain the index of each line.

Lastly, I set up test buttons for each time of message, a clear button, and basic fstream printing to an output text file.
