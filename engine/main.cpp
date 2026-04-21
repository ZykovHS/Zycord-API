#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include "ratelimit.cpp"
int main() {
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    sockaddr_un addr{.sun_family = AF_UNIX};
    snprintf(addr.sun_path, sizeof(addr.sun_path), "/tmp/engine.sock");
    unlink("/tmp/engine.sock");
    bind(fd, (sockaddr*)&addr, sizeof(addr));
    listen(fd, 128);
    while (true) {
        int client = accept(fd, NULL, NULL);
        Packet p;
        if (read(client, &p, sizeof(Packet)) > 0) {
            if (p.type == 1) {
                bool ok = acquire_token(p.route_hash);
                p.type = 3;
                p.data[0] = ok ? 1 : 0;
                write(client, &p, sizeof(Packet));
            }
        }
        close(client);
    }
    return 0;
}
