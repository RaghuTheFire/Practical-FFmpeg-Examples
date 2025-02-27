#include <iostream>
#include <cstdlib>

int main() 
{
    std::string rtspUrl = "rtsp://your_camera_url";
    std::string outputFile = "output.mp4";
    std::string zoomInFilter = "zoompan=z='if(gte(zoom,1.5),1.5,zoom+0.01)':x='iw/2-(iw/zoom/2)':y='ih/2-(ih/zoom/2)':d=1";
    std::string zoomOutFilter = "zoompan=z='if(lte(zoom,1),1,zoom-0.01)':x='iw/2-(iw/zoom/2)':y='ih/2-(ih/zoom/2)':d=1";
    std::string command = "ffmpeg -i " + rtspUrl + " -vf \"" + zoomInFilter + ", " + zoomOutFilter + "\" -c:v libx264 -preset fast -crf 22 -y " + outputFile;
    //std::string command = "ffmpeg -i rtsp://your_camera_url -vf \"zoompan=z='if(gte(zoom,1.5),zoom-0.01,zoom+0.01)':x='iw/2-(iw/zoom/2)':y='ih/2-(ih/zoom/2)':d=1:s=640x480\" -c:v libx264 -preset fast -f flv rtmp://your_output_url";
    int result = std::system(command.c_str());
    if (result != 0) 
    {
        std::cerr << "Error executing ffmpeg command." << std::endl;
    }
    return 0;
}
