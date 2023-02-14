
#include <iostream>
#include <stdio.h>

#include <opentimelineio/clip.h>
#include <opentimelineio/timeline.h>

namespace otio = opentimelineio::OPENTIMELINEIO_VERSION;

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file.otio>" << std::endl;
        return 1;
    }

    // This is the file we will load
    std::string path(argv[1]);

    // Load the timeline into memory
    otio::ErrorStatus error_status;
    auto timeline = dynamic_cast<otio::Timeline*>(
        otio::Timeline::from_json_file(path, &error_status));

    // Check for errors
    if (!timeline || otio::is_error(error_status)) {
        std::cerr << "Error loading: " << path << " : "
                  << otio::ErrorStatus::outcome_to_string(error_status.outcome)
                  << ": " << error_status.details << std::endl;
        return 2;
    }

    // Display information about what was loaded
    std::cout << "Loaded OTIO file: " << path << std::endl
              << "Timeline name: " << timeline->name() << std::endl
              << "Timeline duration: " << timeline->duration().to_timecode()
              << std::endl;

    std::cout << "Video Tracks:" << std::endl;
    if (timeline->video_tracks().size() == 0) {
        std::cout << "  No video tracks" << std::endl;
    } else {
        for (const auto& track : timeline->video_tracks()) {
            std::cout << "  Track: " << track->name() << std::endl
                      << "    Kind: " << track->kind() << std::endl
                      << "    Duration: " << track->duration().to_timecode()
                      << std::endl;
        }
    }

    std::cout << "Audio Tracks:" << std::endl;
    if (timeline->audio_tracks().size() == 0) {
        std::cout << "  No audio tracks" << std::endl;
    } else {
        for (const auto& track : timeline->audio_tracks()) {
            std::cout << "  Track: " << track->name() << std::endl
                      << "    Kind: " << track->kind() << std::endl
                      << "    Duration: " << track->duration().to_timecode()
                      << std::endl;
        }
    }

    // Print some info about all the clips in the timeline
    // Note: timeline>find_clips() will recurse into all nested compositions
    std::cout << "All Clips:" << std::endl;
    for (const auto& clip : timeline->find_clips()) {
        std::cout << "  Clip: " << clip->name() << std::endl
                  << "    Duration: " << clip->duration().to_timecode()
                  << std::endl;
    }

    return 0;
}
