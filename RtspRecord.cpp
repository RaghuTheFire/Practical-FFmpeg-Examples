#include <iostream>
#include <cstdlib>

int main() 
{
    std::string rtspUrl = "rtsp://your_rtsp_stream";
    std::string outputFile = "output.mp4";
    std::string command = "ffmpeg -i " + rtspUrl + " -vf \"drawtext=text='%{eif\:n\:d}':x=10:y=10:fontsize=24:fontcolor=white\" -c:v libx264 -preset fast -crf 23 -c:a aac -b:a 192k " + outputFile;
    int result = std::system(command.c_str());
    return result;
}
