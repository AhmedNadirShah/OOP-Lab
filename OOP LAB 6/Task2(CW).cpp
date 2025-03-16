#include <iostream>
#include <string>

using namespace std;

class MediaFile {
protected:
    string file_path;
    int size;
public:
    MediaFile(string fp, int s) : file_path(fp), size(s) {}

    virtual void play() = 0;
    virtual void stop() = 0;

    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
public:
    VisualMedia(string fp, int s) : MediaFile(fp, s) {}

    void play() override {
        cout << "Start visual media: " << file_path << " of size " << size << endl;
    }

    void stop() override {
        cout << "Stop visual media: " << file_path << " of size " << size << endl;
    }
};

class AudioMedia : virtual public MediaFile {
public:
    AudioMedia(string fp, int s) : MediaFile(fp, s) {}

    void play() override {
        cout << "Start audio media: " << file_path << " of size " << size << endl;
    }

    void stop() override {
        cout << "Stop audio media: " << file_path << " of size " << size << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string fp, int s) 
        : MediaFile(fp, s), VisualMedia(fp, s), AudioMedia(fp, s) {}

    void play() override {
        cout << "Playing video: " << file_path << " (Size: " << size << " MB)" << endl;
    }

    void stop() override {
        cout << "Stopping video: " << file_path << endl;
    }
};

int main() {
    MediaFile* files[3];

    files[0] = new VisualMedia("Image.jpg", 5);
    files[1] = new AudioMedia("Song.mp3", 3);
    files[2] = new VideoFile("Movie.mp4", 700);

    for (int i = 0; i < 3; i++) {
        files[i]->play();
        files[i]->stop();
    }

    for (int i = 0; i < 3; i++) {
        delete files[i];
    }

    return 0;
}

