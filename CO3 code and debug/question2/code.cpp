
#include <iostream>
using namespace std;

class AudioBuffer {
public:
    int *samples;
    int capacity;

    AudioBuffer(int cap) {
        capacity = cap;
        samples = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            samples[i] = (i + 1) * 10;
        }

        cout << "Buffer allocated at "
             << samples << endl;
    }

    // Deep copy constructor
    AudioBuffer(const AudioBuffer &other) {
        capacity = other.capacity;
        samples = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            samples[i] = other.samples[i];
        }

        cout << "Copied buffer allocated at "
             << samples << endl;
    }

    ~AudioBuffer() {
        cout << "Deallocating buffer at "
             << samples << endl;

        delete[] samples;
    }
};

void processAudio(AudioBuffer buf) {
    cout << "Processing sample 0: "
         << buf.samples[0] << endl;
}

int main() {
    AudioBuffer track(5);

    processAudio(track);

    cout << "Back in main, sample 0: "
         << track.samples[0] << endl;

    return 0;
}
