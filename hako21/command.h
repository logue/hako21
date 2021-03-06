#ifndef COMMAND_H
#define COMMAND_H

#include<fstream.h>

#include"hako_io.h"
#include"info.h"
#include"value.h"

class Com;
class Land;
class Island;

class Command {
public:
    static Com *coms;
    static void alloc();
    static void initialize();
    static void jsOut();
    static void input(ifstream *);
    static void output(ofstream *);
    static void exec(Island *, int);
};

class Com {
public:
    // R}hÌíÞ
    // ®nn
    static const int Prepare    = 01; // ®n
    static const int Prepare2   = 02; // nÏµ
    static const int Reclaim    = 03; // §
    static const int Destroy     = 04; // @í
    static const int SellTree   = 05; // °Ì
    static const int Widen      = 06; // Ìyg£

    // Ýn
    static const int Plant      = 21; // AÑ
    static const int Farm       = 22; // _ê®õ
    static const int Factory    = 23; // HêÝ
    static const int Mountain   = 24; // Ì@ê®õ
    static const int Base       = 25; // ~TCînÝ
    static const int DBase      = 26; // hq{ÝÝ
    static const int SBase      = 27; // CêînÝ
    static const int Monument   = 28; // LOè¢
    static const int Haribote   = 29; // n{eÝu

    // Rn
    static const int MissileNM  = 41; // ~TC­Ë
    static const int MissilePP  = 42; // PP~TC­Ë
    static const int MissileLD  = 43; // ¤njóe­Ë
    static const int MissileIS  = 44; // e¹~TC­Ë
    static const int Monster    = 45; // öbh­

    // ^cn
    static const int DoNothing  = 61; // àJè
    static const int Sell       = 62; // H¿Ao
    static const int Money      = 63; // à
    static const int Food       = 64; // H¿
    static const int Propaganda = 65; // Uv®
    static const int Giveup     = 66; // Ìúü
    static const int Move       = 67; // _ÏX

    int getCost();
    static int getCost(int);

    // ep[^
    int kind;
    int target;
    int x;
    int y;
    int amount;
    void initialize();
    void jsOut();
    void input(ifstream *);
    void output(ofstream *);

    int exec(Island *, int);
    int buildCommand(Island *, Land *, int, int, int, int, int,
		     int, int, int, int, int, int);
    inline void log(int, int, int, int, 
		    int = 0, int = 0, int = 0, int = 0, int = 0);
};

#endif
