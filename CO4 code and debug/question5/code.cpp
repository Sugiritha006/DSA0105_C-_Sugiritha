
#include <iostream>
using namespace std;

class RawSocket {
public:
    void openPort(int port) {
        cout << "Port " << port << " opened." << endl;
    }

    void closePort() {
        cout << "Port closed." << endl;
    }
};

class SecureChannel {
private:
    RawSocket socket;

public:
    void establishEncryptedTunnel(int port) {
        socket.openPort(port);

        cout << "Tunnel encrypted with TLS 1.3"
             << endl;
    }

    void closeConnection() {
        socket.closePort();
    }
};

int main() {
    SecureChannel channel;

    channel.establishEncryptedTunnel(443);
    channel.closeConnection();

    return 0;
}
