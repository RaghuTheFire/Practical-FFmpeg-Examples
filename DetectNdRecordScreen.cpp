#include <iostream>
#include <string>
#include <cstdlib>

int main() 
{
    // Command to detect screens
    std::string detectScreensCommand = "ffmpeg -list_devices true -f dshow -i dummy";
    std::system(detectScreensCommand.c_str());

    // Command to record multiple screens
    std::string recordScreensCommand = "ffmpeg -f gdigrab -framerate 30 -i desktop -f gdigrab -framerate 30 -i 1 -c:v libx264 output.mp4";
    std::system(recordScreensCommand.c_str());

    return 0;
}
