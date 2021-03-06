#pragma once
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include "PacketCodes.h"

class StateGame;

class NetworkManager
{
    public:
        static const unsigned short PORT = 54320;

        NetworkManager(StateGame* stategame);

        bool connect(char nick[16], sf::IpAddress address, unsigned short port);
        bool disconnect();
        inline bool isConnected() { return connected; };
        //All send functions
        inline bool sendPacket(sf::Packet p)
        {
            if (connected)
                return socket.send(p, server, PORT) == sf::Socket::Done;
            return false;
        }
        bool askForChunk(sf::Vector2i chunk);
        bool sendBlockBuild(sf::Vector2i pos, unsigned short block);
        bool sendBlockBreak(sf::Vector2i pos);
        bool sendGroundChange(sf::Vector2i pos, unsigned short ground);
        bool sendInteractEvent(sf::Vector2i pos);
        //Receive functions
        inline sf::Packet syncReceive()
        {
            sf::Packet p;
            sf::IpAddress sender;
            unsigned short port;
            socket.receive(p, sender, port);
            std::cout << "Received something\n";
            if (sender != server || port != PORT)
            {
                std::cout << "Warning : it was not from the server\n";
                std::cout << "Server : " << server << ":" << PORT << "\n";
                std::cout << "Sender : " << sender << ":" << port << "\n";
            }
            return p;
        };

        inline unsigned int getPlayerID() { return playerID; };

    private:
        sf::UdpSocket socket;
        sf::IpAddress server;

        bool connected = false;
        bool oneCodeSend(int code);

        sf::Thread receiveThread;   //Functions to receive data
        void receive();

        StateGame* game;

        unsigned int playerID = 0;


};
