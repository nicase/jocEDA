#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME nicase


struct PLAYER_NAME : public Player {

    /**
     * Factory: returns a new instance of this class.
     * Do not modify this function.
     */
    static Player* factory () {
        return new PLAYER_NAME;
    }

    /**
     * Types and attributes for your player can be defined here.
     */

    typedef vector<int> VE;
    typedef pair<int,int> parell;
    /*
    #define nfiles 60;
    #define ncolumnes 60;*/

    typedef vector<VE> Matriu;

    typedef vector<vector<bool> > Matriubool;
//typedef Matriu (nfiles,VE(n))
    typedef pair<Pos,int> parellidist;

    struct nivells {
        //posicio de la cel·la amb aigua mes propera i la distancia a la que esta
        Pos aiguamespropera;
        int distaigua;

        //pos de la ciutat mes propera i la dist a la que esta
        Pos ciutatmespropera;
        int distciutat;

    };

    vector<vector<nivells> > Mnivells;

    bool needwater = false;
    bool needfood = false;
    bool goingtoatack = false;



    /* *
     * Aquesta funció retorna un parell pos,dis amb la posicio de l'aigua més propera
     * i la distància a la que es troba
     * */
    parellidist cerca_aigua(int fi, int ci) {

        Pos p = Pos(fi,ci);
        queue<Pos> posicions;
        queue<int> distancies;
        int dist;
        posicions.push(p);
        distancies.push(1);
        Matriubool vis(60, vector<bool>(60, false)); //per saber si els hem visitat

        while (not posicions.empty()) {

            Pos actual = posicions.front();
            int dist = distancies.front();
            int f = actual.i;
            int c = actual.j;

            //mirem que hi ha a totes les caselles del voltant i si son visitables les visitem i posem la pos a la cua

            Pos p2;
            //dreta
            p2 = actual + Right;
            if (pos_ok(p2) and vis[f][c+1] == false and cell(p2).type != Wall) { //mira si la pos esta a la matriu, si no es una paret i si l'hem visitat

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dreta-baix
            p2 = actual + BR;
            if (pos_ok(p2) and vis[f+1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //Abaix
            p2 = actual + Bottom;
            if (pos_ok(p2) and vis[f+1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal baix-esquerra
            p2 = actual + LB;
            if (pos_ok(p2) and vis[f+1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //esquerra
            p2 = actual + Left;
            if (pos_ok(p2) and vis[f][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dalt-esquerra
            p2 = actual + TL;
            if (pos_ok(p2) and vis[f-1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + Top;
            if (pos_ok(p2) and vis[f-1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + RT;
            if (pos_ok(p2) and vis[f-1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Water) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }
            posicions.pop();
            distancies.pop();
        }
    }

    /* *
     * Aquesta funció retorna un parell pos,dis amb la posicio de la ciutat més propera
     * */
    parellidist cerca_ciutat(int fi, int ci) {
        Pos p = Pos(fi,ci);
        queue<Pos> posicions;
        queue<int> distancies;
        int dist;
        posicions.push(p);
        distancies.push(1);
        Matriubool vis(60, vector<bool>(60, false)); //per saber si els hem visitat

        while (not posicions.empty()) {

            Pos actual = posicions.front();
            int dist = distancies.front();
            int f = actual.i;
            int c = actual.j;

            //mirem que hi ha a totes les caselles del voltant i si son visitables les visitem i posem la pos a la cua

            Pos p2;
            //dreta
            p2 = actual + Right;
            if (pos_ok(p2) and vis[f][c+1] == false and cell(p2).type != Wall) { //mira si la pos esta a la matriu, si no es una paret i si l'hem visitat

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dreta-baix
            p2 = actual + BR;
            if (pos_ok(p2) and vis[f+1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //Abaix
            p2 = actual + Bottom;
            if (pos_ok(p2) and vis[f+1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal baix-esquerra
            p2 = actual + LB;
            if (pos_ok(p2) and vis[f+1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //esquerra
            p2 = actual + Left;
            if (pos_ok(p2) and vis[f][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dalt-esquerra
            p2 = actual + TL;
            if (pos_ok(p2) and vis[f-1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + Top;
            if (pos_ok(p2) and vis[f-1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + RT;
            if (pos_ok(p2) and vis[f-1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }
            posicions.pop();
            distancies.pop();
        }

    }

    /**
     * Aquesta funció retorna un parell pos,dis amb la posicio de la ciutat més propera aliada
     *
     * */
    parellidist cerca_ciutat_amiga(int fi, int ci) {
        Pos p = Pos(fi,ci);
        queue<Pos> posicions;
        queue<int> distancies;
        int dist;
        posicions.push(p);
        distancies.push(1);
        Matriubool vis(60, vector<bool>(60, false)); //per saber si els hem visitat

        while (not posicions.empty()) {

            Pos actual = posicions.front();
            int dist = distancies.front();
            int f = actual.i;
            int c = actual.j;

            //mirem que hi ha a totes les caselles del voltant i si son visitables les visitem i posem la pos a la cua

            Pos p2;
            //dreta
            p2 = actual + Right;
            if (pos_ok(p2) and vis[f][c+1] == false and cell(p2).type != Wall) { //mira si la pos esta a la matriu, si no es una paret i si l'hem visitat

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dreta-baix
            p2 = actual + BR;
            if (pos_ok(p2) and vis[f+1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //Abaix
            p2 = actual + Bottom;
            if (pos_ok(p2) and vis[f+1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal baix-esquerra
            p2 = actual + LB;
            if (pos_ok(p2) and vis[f+1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //esquerra
            p2 = actual + Left;
            if (pos_ok(p2) and vis[f][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dalt-esquerra
            p2 = actual + TL;
            if (pos_ok(p2) and vis[f-1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + Top;
            if (pos_ok(p2) and vis[f-1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + RT;
            if (pos_ok(p2) and vis[f-1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner == me()) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }
            posicions.pop();
            distancies.pop();
        }

    }
    /**
     *Aquesta funció retorna un parell pos,dis amb la posicio de la ciutat més propera enemiga
     * */
    parellidist cerca_ciutat_enemiga(int fi, int ci) {
        Pos p = Pos(fi,ci);
        queue<Pos> posicions;
        queue<int> distancies;
        int dist;
        posicions.push(p);
        distancies.push(1);
        Matriubool vis(60, vector<bool>(60, false)); //per saber si els hem visitat

        while (not posicions.empty()) {

            Pos actual = posicions.front();
            int dist = distancies.front();
            int f = actual.i;
            int c = actual.j;

            //mirem que hi ha a totes les caselles del voltant i si son visitables les visitem i posem la pos a la cua

            Pos p2;
            //dreta
            p2 = actual + Right;
            if (pos_ok(p2) and vis[f][c+1] == false and cell(p2).type != Wall) { //mira si la pos esta a la matriu, si no es una paret i si l'hem visitat

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dreta-baix
            p2 = actual + BR;
            if (pos_ok(p2) and vis[f+1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //Abaix
            p2 = actual + Bottom;
            if (pos_ok(p2) and vis[f+1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal baix-esquerra
            p2 = actual + LB;
            if (pos_ok(p2) and vis[f+1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //esquerra
            p2 = actual + Left;
            if (pos_ok(p2) and vis[f][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dalt-esquerra
            p2 = actual + TL;
            if (pos_ok(p2) and vis[f-1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + Top;
            if (pos_ok(p2) and vis[f-1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + RT;
            if (pos_ok(p2) and vis[f-1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == City and cell(p2).owner != me()) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }
            posicions.pop();
            distancies.pop();
        }

    }

    bool nexttowater(Pos p) {
        Pos p2;

        p2 = p + Right;
        if (cell(p).type == Water) return true;
        p2 = p + Right;
        if (cell(p).type == Water) return true;
        p2 = p + Right;
        if (cell(p).type == Water) return true;
        p2 = p + Right;
        if (cell(p).type == Water) return true;
        p2 = p + Right;
        if (cell(p).type == Water) return true;
        p2 = p + Right;
        if (cell(p).type == Water) return true;
        p2 = p + Right;
        if (cell(p).type == Water) return true;
        p2 = p + Right;
        if (cell(p).type == Water) return true;

        return false;



    }

    bool incity(Pos p) {
        if (cell(p).type == City) return true;
        return false;
    }

    /*
    void move_cars() {

        VE C = cars(me()); //vector amb els identificadors de cotxes

        int n = C.size(); //numero de cotxes que tenim

        if (n > 0) {

            for (int i=0; i<n; ++i) {
                //accions a realitzar per cada cotxe depenent de la seva situacio

                Pos p = unit(C[i]).pos;

                if (pos_ok(p) and cell(p).type == Road) {

                    Pos p2;

                    p2= p + Right;
                    if (pos_ok(p2) and cell(p2).id != -1) command(C[id],Right);

                    p2= p + Left;
                    if (pos_ok(p2) and cell(p2).id != -1) command(C[id],Left);

                    p2= p + Top;
                    if (pos_ok(p2) and cell(p2).id != -1) command(C[id],Top);

                    p2= p + Bottom;
                    if (pos_ok(p2) and cell(p2).id != -1) command(C[id],Bottom);

                    else {
                    p2= p + Right;
                    if (pos_ok(p2) and cell(p2).type != Road) command(C[id],Right);

                      p2= p + Left;
                    if (pos_ok(p2) and cell(p2).type != Road) command(C[id],Left);

                     p2= p + Top;
                    if (pos_ok(p2) and cell(p2).type != Road) command(C[id],Top);

                     p2= p + Bottom;
                    if (pos_ok(p2) and cell(p2).type != Road) command(C[id],Bottom);

                    }



                }

            }
        }
    }*/

    //TODO: fer un bfs per el menjar i fer un if com el de l'aigua

    void move_warriors() {
        if (round()% 4 != me()) return; // This line makes a lot of sense.

        VE W = warriors(me());

        int n = W.size();

        int id;
        bool end;

        for(int i=0; i<n; ++i) {

            id = W[i];

            Pos p = unit(id).pos;


            //FIXME: contemplar el cas en que es dos nivells son baixos


            //mirem si necessita aigua
            if (unit(id).water == Mnivells[p.i][p.j].distaigua + 7) {
                needwater = true;
            }

            //mirem si necessita menjar i si la ciutat mes propera es aliada (per menjar)
            Pos aux1 = Mnivells[p.i][p.j].ciutatmespropera;
            if (cell(aux1.i,aux1.j).owner == me()) {
                if (unit(id).food == Mnivells[p.i][p.j].distciutat + 7) {
                    needfood = true;
                }
            }
            else {
                //la ciutat mes propera no es aliada
                parellidist menjaux = cerca_ciutat_amiga(p.i,p.j);
                if (menjaux.second <= unit(id).food + 7)
                    needfood = true;
            }



            if (nexttowater(p)) needwater = false;
            if (incity(p)) needfood = false;

            /**
             * El seguent if es per decidir que hem de fer si els dos nivells (menjar i aigua) son baixos
             * */
            if (needwater and needfood) {
                if (unit(id).food > unit(id).water) {
                    needfood= false;
                }
                else if (unit(id).water > unit(id).food) {
                    needwater = false;
                }
                else {//si entra aqui es que water==food
                    needfood = false;
                    //prioritzem l'aigua perquè està sempre disponible i no ens cal fer cap
                    //bfs extra
                }
            }

            if (needwater) {



                Pos p2;
                Pos aux;


                //Dreta
                p2 = p + Right;
                /*if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua)*/ aux = Pos(p2.i,p2.j);

                //BR
                p2 = p + BR;
                if (pos_ok(p2)) {
                    if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua) {
                        if (Mnivells[p2.i][p2.j].distaigua < Mnivells[aux.i][aux.j].distaigua) aux = p2;
                    }
                }

                //Bottom
                p2 = p + Bottom;
                if (pos_ok(p2)) {
                    if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua) {
                        if (Mnivells[p2.i][p2.j].distaigua < Mnivells[aux.i][aux.j].distaigua) aux = p2;
                    }
                }

                //LB
                p2 = p + LB;
                if (pos_ok(p2)) {
                    if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua) {
                        if (Mnivells[p2.i][p2.j].distaigua < Mnivells[aux.i][aux.j].distaigua) aux = p2;
                    }
                }

                //Left
                p2 = p + LB;
                if (pos_ok(p2)) {
                    if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua) {
                        if (Mnivells[p2.i][p2.j].distaigua < Mnivells[aux.i][aux.j].distaigua) aux = p2;
                    }
                }

                //TL
                p2 = p + TL;
                if (pos_ok(p2)) {
                    if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua) {
                        if (Mnivells[p2.i][p2.j].distaigua < Mnivells[aux.i][aux.j].distaigua) aux = p2;
                    }
                }

                //Top
                p2 = p + Top;
                if (pos_ok(p2)) {
                    if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua) {
                        if (Mnivells[p2.i][p2.j].distaigua < Mnivells[aux.i][aux.j].distaigua) aux = p2;
                    }
                }

                //RT
                p2 = p + RT;
                if (pos_ok(p2)) {
                    if (Mnivells[p2.i][p2.j].distaigua < Mnivells[p.i][p.j].distaigua) {
                        if (Mnivells[p2.i][p2.j].distaigua < Mnivells[aux.i][aux.j].distaigua) aux = p2;
                    }
                }

                //movem el warrior

                if (aux == p + Top) command(id, Top);
                else if (aux == p + RT) command(id,RT);
                else if (aux == p + Right) command(id,Right);
                else if (aux == p + BR) command(id,BR);
                else if (aux == p + Bottom) command(id,Bottom);
                else if (aux == p + LB) command(id,LB);
                else if (aux == p + Left) command(id,Left);
                else if (aux == p + TL) command(id,TL);
                return;
            }

            else if (needfood) {

                Pos aux2 = Mnivells[p.i][p.j].ciutatmespropera;
                if (cell(aux2.i,aux2.j).owner == me()) {
                    //la ciutat mes propera es aliada
                    Pos p2;
                    Pos aux;


                    //Dreta
                    p2 = p + Right;
                    /*if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat)*/ aux = Pos(p2.i,p2.j);

                    //BR
                    p2 = p + BR;
                    if (pos_ok(p2)) {
                        if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat) {
                            if (Mnivells[p2.i][p2.j].distciutat < Mnivells[aux.i][aux.j].distciutat) aux = p2;
                        }
                    }

                    //Bottom
                    p2 = p + Bottom;
                    if (pos_ok(p2)) {
                        if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat) {
                            if (Mnivells[p2.i][p2.j].distciutat < Mnivells[aux.i][aux.j].distciutat) aux = p2;
                        }
                    }

                    //LB
                    p2 = p + LB;
                    if (pos_ok(p2)) {
                        if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat) {
                            if (Mnivells[p2.i][p2.j].distciutat < Mnivells[aux.i][aux.j].distciutat) aux = p2;
                        }
                    }

                    //Left
                    p2 = p + LB;
                    if (pos_ok(p2)) {
                        if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat) {
                            if (Mnivells[p2.i][p2.j].distciutat < Mnivells[aux.i][aux.j].distciutat) aux = p2;
                        }
                    }

                    //TL
                    p2 = p + TL;
                    if (pos_ok(p2)) {
                        if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat) {
                            if (Mnivells[p2.i][p2.j].distciutat < Mnivells[aux.i][aux.j].distciutat) aux = p2;
                        }
                    }

                    //Top
                    p2 = p + Top;
                    if (pos_ok(p2)) {
                        if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat) {
                            if (Mnivells[p2.i][p2.j].distciutat < Mnivells[aux.i][aux.j].distciutat) aux = p2;
                        }
                    }

                    //RT
                    p2 = p + RT;
                    if (pos_ok(p2)) {
                        if (Mnivells[p2.i][p2.j].distciutat < Mnivells[p.i][p.j].distciutat) {
                            if (Mnivells[p2.i][p2.j].distciutat < Mnivells[aux.i][aux.j].distciutat) aux = p2;
                        }
                    }

                    //movem el warrior

                    if (aux == p + Top) command(id, Top);
                    else if (aux == p + RT) command(id,RT);
                    else if (aux == p + Right) command(id,Right);
                    else if (aux == p + BR) command(id,BR);
                    else if (aux == p + Bottom) command(id,Bottom);
                    else if (aux == p + LB) command(id,LB);
                    else if (aux == p + Left) command(id,Left);
                    else if (aux == p + TL) command(id,TL);
                    return;



                }
            }
            else {
                //la ciutat mes propera es enemiga, hem de trobar la ciutat aliada mes propera
                int auxdist = 100000;

                parellidist menjarmesproper = cerca_ciutat_amiga(p.i, p.j);
                //TODO: Fer un algoritme que quan vegi que la distanca es mes gran que el menjar,
                //no vagi a buscar menjar (moriria pel camí així que és igual)
                Pos aux;
                Pos p2;
                //Dreta
                p2 = p + Right;
                if (pos_ok(p2)) {
                    /*if (distmenjarmesproper.second < Mnivells[p.i][p.j].distaigua)*/
                    aux = Pos(p2.i,p2.j);
                    auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;


                }
                else {
                    aux = Pos(p2.i, p2.j-1);
                }

                //BR
                p2 = p + BR;
                parellidist distmenjarmesproper = cerca_ciutat_amiga(p2.i, p2.j);
                if (pos_ok(p2)) {
                    if (distmenjarmesproper.second < menjarmesproper.second) {
                        if (distmenjarmesproper.second < auxdist) {
                            aux = p2;
                            auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;
                        }
                    }
                }

                //Bottom
                p2 = p + Bottom;
                distmenjarmesproper = cerca_ciutat_amiga(p2.i, p2.j);
                if (pos_ok(p2)) {
                    if (distmenjarmesproper.second < menjarmesproper.second) {
                        if (distmenjarmesproper.second < auxdist) {
                            aux = p2;
                            auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;
                        }
                    }
                }

                //LB
                p2 = p + LB;
                distmenjarmesproper = cerca_ciutat_amiga(p2.i, p2.j);
                if (pos_ok(p2)) {
                    if (distmenjarmesproper.second < menjarmesproper.second) {
                        if (distmenjarmesproper.second < auxdist) {
                            aux = p2;
                            auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;
                        }
                    }
                }

                //Left
                p2 = p + Left;
                distmenjarmesproper = cerca_ciutat_amiga(p2.i, p2.j);
                if (pos_ok(p2)) {
                    if (distmenjarmesproper.second < menjarmesproper.second) {
                        if (distmenjarmesproper.second < auxdist) {
                            aux = p2;
                            auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;
                        }
                    }
                }

                //TL
                p2 = p + TL;
                distmenjarmesproper = cerca_ciutat_amiga(p2.i, p2.j);
                if (pos_ok(p2)) {
                    if (distmenjarmesproper.second < menjarmesproper.second) {
                        if (distmenjarmesproper.second < auxdist) {
                            aux = p2;
                            auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;
                        }
                    }
                }

                //Top
                p2 = p + Top;
                distmenjarmesproper = cerca_ciutat_amiga(p2.i, p2.j);
                if (pos_ok(p2)) {
                    if (distmenjarmesproper.second < menjarmesproper.second) {
                        if (distmenjarmesproper.second < auxdist) {
                            aux = p2;
                            auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;
                        }
                    }
                }

                //RT
                p2 = p + RT;
                distmenjarmesproper = cerca_ciutat_amiga(p2.i, p2.j);
                if (pos_ok(p2)) {
                    if (distmenjarmesproper.second < menjarmesproper.second) {
                        if (distmenjarmesproper.second < auxdist) {
                            aux = p2;
                            auxdist = cerca_ciutat_amiga(aux.i, aux.j).second;
                        }
                    }
                }

                //movem el warrior

                if (aux == p + Top) command(id, Top);
                else if (aux == p + RT) command(id,RT);
                else if (aux == p + Right) command(id,Right);
                else if (aux == p + BR) command(id,BR);
                else if (aux == p + Bottom) command(id,Bottom);
                else if (aux == p + LB) command(id,LB);
                else if (aux == p + Left) command(id,Left);
                else if (aux == p + TL) command(id,TL);
                return;


            }

            /**
            * Si arribem aquí es que no necessitem ni aigua ni
            * */
            //tenim recursos, anem a conquerir ciutat
            Pos p2;
            int distaux = cerca_ciutat_enemiga(p.i,p.j).second;


            /*
            *TODO: Mirem si estem al costat d'una ciutat
            *
            * */

            /*
             * Si arribem aquí es que estem anant a una ciutat i no en tenim cap al costat
             *
             *
             * */

            //BR
            p2 = p + BR;
            if (pos_ok(p2) and cerca_ciutat_enemiga(p.i+1,p.j+1).second < distaux)  {
                command(id, BR);
            }

            //RT
            p2 = p + RT;
            if (pos_ok(p2) and cerca_ciutat_enemiga(p.i-1,p.j+1).second < distaux) {
                command(id,RT);
            }

            //TL
            p2 = p + TL;
            if (pos_ok(p2) and cerca_ciutat_enemiga(p.i-1,p.j-1).second < distaux) {
                command(id,TL);
            }


            //LB
            p2 = p+LB;
            if (pos_ok(p2) and cerca_ciutat_enemiga(p.i+1,p.j-1).second < distaux) {
                command(id,LB);
            }

            //Right
            p2 = p+Right;
            if (pos_ok(p2) and cerca_ciutat_enemiga(p.i,p.j+1).second < distaux) {
                command(id, Right);
            }

            //Top
            p2 = p + Top;
            if (pos_ok(p2) and cerca_ciutat_enemiga(p.i-1,p.j).second < distaux) {
                command(id, Top);
            }

            //Bottom
            p2 = p + Bottom;
            if (pos_ok(p2) and cerca_ciutat_enemiga(p.i+1,p.j).second < distaux) {
                command(id, Bottom);
            }

            //Left
            else {
                p2 = p + Left;
                if (pos_ok(p2)) {
                    command(id, Left);
                }
            }
        }
    }

    /**
     * Play method, invoked once per each round.
     */
    virtual void play () {

        if (round() == 0) {

            /**
             * Posem a la matriu Mnivells(de la mateixa mida del tauler) una struct
             * nivells amb l'aigua més propera (pos i dist) i la ciutat més propera.
             * Això ens pot servir per trobar de manera més ràpid una ciutat enemiga per conquerir
             * o una ciutat amiga per menjar
             * */
            vector<vector<nivells> > Mnivells2(60,vector<nivells>(60));
            Mnivells = Mnivells2;
            for (int i=0; i<60; ++i) {
                for (int j=0; j<60; ++j) {
                    parellidist aux;
                    aux = cerca_aigua(i,j);
                    Mnivells[i][j].aiguamespropera = aux.first;
                    Mnivells[i][j].distaigua = aux.second;
                    aux = cerca_ciutat(i,j);
                    Mnivells[i][j].ciutatmespropera = aux.first;
                    Mnivells[i][j].distciutat = aux.second;
                }
            }
        }

        move_warriors();
        //move_cars();
        /*parellidist h = cerca_aigua(0,0);
        Pos j = h.first;
        int dist = h.second;

        cout << j << "dist = " << dist << endl;
        cout << endl << endl;*/
        /*if (round() == 499) {
            for (int k=0; k<60; ++k) {
                for (int l =0; l<60; ++l) {
                        Pos j = Maigua[k][l].first;
                        int dist = Maigua[k][l].second;
                    cout <<  j << dist << " ";
                }
                cout << endl;
            }
        }*/
    }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
