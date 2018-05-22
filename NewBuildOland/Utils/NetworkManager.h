#pragma once
#include "SFML/Network.hpp"
#include "SFML/System.hpp"


class NetworkManager
{
    public:
        static const unsigned short PORT = 54321;

        bool connect(char nick[16]);
        bool disconnect();
        inline bool isConnected() { return connected; };
        //All send functions
        inline bool askForWorld()
        {
            return oneCodeSend(REQUEST_WORLD);
        };
        //All synced (not asnychronous) receive functions
        inline sf::Packet syncReceive()
        {
            sf::Packet p;
            server.receive(p);
            return p;
        };
    private:
        sf::TcpSocket server;
        bool connected;
        bool oneCodeSend(int code);

        //All message codes
        static const int DISCONNECT = 0;
        static const int REQUEST_CONNECTION = 1;
        static const int REQUEST_WORLD = 2;

        static const int CONNECT_REFUSED = 0;
        static const int CONNECT_ACCEPT = 1;

        //Connection refused codes
        static const int REASON_NULL = 0;
        static const int REASON_SERVER_NOT_READY = 1;
        static const int REASON_SERVER_FULL = 2;
        static const int REASON_NICK_ALREADY_TAKEN = 3;
        static const int REASON_BANNED = 4;

};
