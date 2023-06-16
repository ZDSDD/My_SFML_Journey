#include "Headers/Game.h"


int main(int argc, char* argv[]) {
    // Default window size
    int windowWidth = 800;
    int windowHeight = 600;

    // Check if command-line arguments are provided
    if (argc >= 3) {
        // Loop through the arguments to find "-window"
        for (int i = 1; i < argc - 1; i++) {
            if (std::string(argv[i]) == "-window") {
                // Extract the window size value
                std::string windowSize = argv[i + 1];

                // Split the window size value into width and height components
                size_t delimiterPos = windowSize.find('x');
                if (delimiterPos != std::string::npos) {
                    // Extract width and height strings
                    std::string widthStr = windowSize.substr(0, delimiterPos);
                    std::string heightStr = windowSize.substr(delimiterPos + 1);

                    // Convert width and height to integers
                    windowWidth = std::stoi(widthStr);
                    windowHeight = std::stoi(heightStr);
                }
                break;
            }
        }
    }

    Game game(windowWidth,windowHeight);

    while(game.getWindow().isOpen()){
        game.update();
        game.render();
    }

    return 0;
}
