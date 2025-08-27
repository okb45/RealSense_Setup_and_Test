#include <librealsense2/rs.hpp>   // RealSense API
#include <iostream>
#include <thread>                 // for sleep
#include <chrono>                 // for timing

#define DISTANCE 1.0
// Example alert function
void trigger_alert(float distance) {
    std::cout << "Alert! Object " << distance << " meters away!" << std::endl;
    // Add beep/vibration logic here
}

int main() try
{
    rs2::pipeline pipeline;
    pipeline.start();

    while (true) {
        rs2::frameset frames = pipeline.wait_for_frames();
        rs2::depth_frame depth = frames.get_depth_frame();

        int width = depth.get_width();
        int height = depth.get_height();

        // Define ROI (center 1/3rd of frame)
        int x1 = width / 3, x2 = 2 * width / 3;
        int y1 = height / 3, y2 = 2 * height / 3;

        float min_dist = 10.0f; // start with large value
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                float d = depth.get_distance(x, y);
                if (d > 0 && d < min_dist) min_dist = d;
            }
        }

        if (min_dist < DISTANCE) {
            trigger_alert(min_dist);
        }

        // Slow down loop a bit (e.g., 50ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
catch (const rs2::error & e)
{
    std::cerr << "RealSense error: " << e.what() << std::endl;
    return EXIT_FAILURE;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}
