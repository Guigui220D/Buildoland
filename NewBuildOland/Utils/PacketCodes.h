#pragma once
//This file should be the same in the game and in the server

enum MainCodes
{
    //Client -> Server
    disconnect = 0,
    requestConnection = 1,
    requestWorld = 2,
    //Both directions
    edition = 3,             //Break block, build block or change ground
    //Server -> Client
    sendWorld = 4
};

enum RefuseCodes
{
    //Server -> Client
    null = 0,
    serverNotReady = 1,
    serverFull = 2,
    nickAlreadyTaken = 3,
    invalidNick = 4,
    banned = 5,
    alreadyConnected = 6
};

enum EditionCodes
{
    //Client->Server
    blockBreak = 0,
    blockBuild = 1,
    groundChange = 2,
    //Server ->Client
    setBlock = 3,
    setGround = 4
};
