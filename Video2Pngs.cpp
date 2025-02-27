#include <iostream>
#include <cstdlib>

int main() 
{
    std::string videoFile = "input.mp4"; // Replace with your video file
    std::string outputPattern = "output_%04d.png"; // Output pattern for PNG files

    std::string command = "ffmpeg -i " + videoFile + " " + outputPattern;
    int result = std::system(command.c_str());

    if (result == 0) 
    {
        std::cout << "Conversion completed successfully." << std::endl;
    } 
    else 
    {
        std::cout << "Error during conversion." << std::endl;
    }

    return 0;
}
