#include "Player.hh"

#define PLAYER_NAME ncam2

struct PLAYER_NAME : public Player {


    static Player* factory () {
        return new PLAYER_NAME;
    }

    struct atributs {
        Pos from = Pos(-1,-1);
        bool vist = false;
        int dist = 999;
        bool cami = false;
    };

    typedef vector<vector<atributs> > Matriuatributs;

    typedef vector<int> VE;

    typedef pair<Pos,int> parellidist;

    bool podemmoure(Pos p) {

        if (pos_ok(p) and cell(p).type != Wall and cell(p).type != Water) return true;
        return false;
    }

    bool notaliat(Pos p) {
        if (cell(p).id != -1) {
            if (unit(cell(p).id).player == me() ) return false;
        }
        return true;
    }

    void movem_ciutat_enemiga(Matriuatributs &Mat, Pos p, int id) { 
        Pos p2;
        Unit u = unit(id);

        vector<Pos> adj(8);
        adj[0] = p+Right;
        adj[1] = p+RT;
        adj[2] = p+Top;
        adj[3] = p+TL;
        adj[4] = p+Left;
        adj[5] = p+LB;
        adj[6] = p+Bottom;
        adj[7] = p+BR;

        for (int i=0; i<8; ++i) {
            Pos p2 = adj[i];
            if (pos_ok(p2)) {
                if (cell(p2).type == City and cell(p2).owner != me() and notaliat(p2) ) {moure_cotxes(u,p2); return;}
                if (cell(p2).id != -1 and unit(cell(p2).id).type == Warrior and unit(cell(p2).id).player     != me()) {
                    Unit o = unit(cell(p2).id);
                    if (min(o.food,o.water) < min(u.food,u.water)) {moure_cotxes(u,p2); return;}
                }
                else if (Mat[p2.i][p2.j].cami) {
                    if(notaliat(p2)) moure_cotxes(u,p2);
                }
            }
        }
        
           /* else if (Mat[p2.i][p2.j].cami) {
                if(cell(p2).id != -1 and unit(cell(p2).id).player == me()) return;
                command(id,Right);
                return;*/
           
    }

    Matriuatributs cerca_ciutat_enemiga(Pos p) {

        //TODO: Fer que al mirar les adjacencies no vagin contra una paret
        //      Fer que no es matin entre ells
        //      Fer que entrin a la ciutat i no es quedin devant com gilipolles

        Matriuatributs Matributs(60,vector<atributs>(60));
        //tenim una matriu de la mateixa mida del tauler amb atributs necessaris pel dijkstra

        Matributs[p.i][p.j].dist = 0;
        queue<Pos> Q;
        Q.push(p);
        while(not Q.empty() and (cell(Q.front()).type != City or (cell(Q.front()).type == City and cell(Q.front()).owner == me()))) {
            Pos newp = Q.front();
            Q.pop();

            if (Matributs[newp.i][newp.j].vist == false) { //si encara no hem visitat aquesta posicio

                Matributs[newp.i][newp.j].vist = true;

                //mirem totes les adjacencies

                Pos aux;
                //Top
                aux = newp+Top;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }

                //Right
                aux = newp+Right;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }

                //Bottom
                aux = newp+Bottom;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }

                //Left
                aux = newp+Left;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }

                //BR
                aux = newp+BR;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }

                //RT
                aux = newp+RT;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }

                //TL
                aux = newp+TL;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }

                //LB
                aux = newp+LB;
                if (podemmoure(aux)) {
                    if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                        Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                        Matributs[aux.i][aux.j].from = newp;
                        Q.push(aux);
                    }
                }


            }
        }

        if (cell(Q.front()).type == City and cell(Q.front()).owner != me()) {

            Pos p1 = Q.front();

            Pos p2 = p1;
            while (p1 != p) {
                //Right
                p2 = p1 + Right;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }

                //Bottom
                p2 = p1 + Bottom;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }

                //Left
                p2 = p1 + Left;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }

                //Top
                p2 = p1 + Top;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }

                //RT
                p2 = p1 + RT;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }

                //BR
                p2 = p1 + BR;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }

                //LB
                p2 = p1 + LB;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }

                //TL
                p2 = p1 + TL;
                if (pos_ok(p2)) {
                    if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                        Matributs[p2.i][p2.j].cami = true;
                        p1 = p2;
                    }
                }
            }
        }

        return Matributs;
    }

    bool esunaliat(Pos p) {
        if (cell(p).id != -1) {
            if (unit(cell(p).id).player == me()) return true;
        }
        return false;
    }

    void moure_cotxes(Unit u, Pos p) {
        Pos r = u.pos;
        if (r+Right == p) command(u.id,Right);
        else if (r+Left == p) command(u.id,Left);
        else if (r+Top == p) command(u.id,Top);
        else if (r+Bottom == p) command(u.id,Bottom);
        else if (r+BR == p) command(u.id,BR);
        else if (r+RT == p) command(u.id,RT);
        else if (r+TL == p) command(u.id,TL);
        else if (r+LB == p) command(u.id,LB);
    }
    
    bool eswarriorenemic(Pos p) {
        int id = cell(p).id;
        if(id != -1 and unit(id).player != me() and unit(id).type == Warrior) return true;
        return false;
    }

    void cerca_cami (Unit u) {
        
        //cout << "entro dijkstra" << endl;
        map <Pos, int> dist;
        map <Pos, Pos> posicioanterior;
        map <Pos, bool> visitat;
        dist.insert(make_pair(u.pos, 0));
        visitat.insert(make_pair(u.pos, false));

        priority_queue < pair <int,Pos>, vector <pair <int,Pos> >, greater<pair <int,Pos> > > Q;
        Q.push(make_pair(0, u.pos));

        bool unitatTrobada = false;
        Pos posUnitatTrobada;

        while (not Q.empty() and not unitatTrobada) {
            pair<int,Pos> actual = Q.top();
            int distActual = actual.first;
            Pos posActual = actual.second;
            int idActual = cell(posActual).id;
            Q.pop();

            if (eswarriorenemic(Q.top().second)) {
                unitatTrobada = true;
                posUnitatTrobada = posActual;
            }
          
            else if (not visitat[posActual]) {
                visitat[posActual] = true;

                Pos p2;
                //Mirarem per totes les adjacències
                
                //top
                p2 = posActual + Top;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                        if (c2.type == Road) {
                            if (dist[p2] > dist[posActual] + 1) {
                                dist[p2] = dist[posActual] + 1;
                                posicioanterior.insert(make_pair(p2, posActual));
                                Q.push({dist[p2], p2});
                            }
                        }
                        else if (c2.type == Desert) {
                            if (dist[p2] > dist[posActual] + 4) {
                                dist[p2] = dist[posActual] + 4;
                                posicioanterior.insert(make_pair(p2, posActual));
                                Q.push({dist[p2], p2});
                            }
                        }
                    }
                }

                //Right-Top
                p2 = posActual + RT;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                    if (c2.type == Road) {
                        if (dist[p2] > dist[posActual] + 1) {
                            dist[p2] = dist[posActual] + 1;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    else if (c2.type == Desert) {
                        if (dist[p2] > dist[posActual] + 4) {
                            dist[p2] = dist[posActual] + 4;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    }
                }

                //Right
                p2 = posActual + Right;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                    if (c2.type == Road) {
                        if (dist[p2] > dist[posActual] + 1) {
                            dist[p2] = dist[posActual] + 1;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    else if (c2.type == Desert) {
                        if (dist[p2] > dist[posActual] + 4) {
                            dist[p2] = dist[posActual] + 4;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    }
                }

                //Bottom-Right
                p2 = posActual + BR;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                    if (c2.type == Road) {
                        if (dist[p2] > dist[posActual] + 1) {
                            dist[p2] = dist[posActual] + 1;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    else if (c2.type == Desert) {
                        if (dist[p2] > dist[posActual] + 4) {
                            dist[p2] = dist[posActual] + 4;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    }
                }

                //Bottom
                p2 = posActual + Bottom;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                    if (c2.type == Road) {
                        if (dist[p2] > dist[posActual] + 1) {
                            dist[p2] = dist[posActual] + 1;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    else if (c2.type == Desert) {
                        if (dist[p2] > dist[posActual] + 4) {
                            dist[p2] = dist[posActual] + 4;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    }
                }

                //Left-Bottom
                p2 = posActual + LB;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                    if (c2.type == Road) {
                        if (dist[p2] > dist[posActual] + 1) {
                            dist[p2] = dist[posActual] + 1;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    else if (c2.type == Desert) {
                        if (dist[p2] > dist[posActual] + 4) {
                            dist[p2] = dist[posActual] + 4;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    }
                }

                //left
                p2 = posActual + Left;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                    if (c2.type == Road) {
                        if (dist[p2] > dist[posActual] + 1) {
                            dist[p2] = dist[posActual] + 1;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    else if (c2.type == Desert) {
                        if (dist[p2] > dist[posActual] + 4) {
                            dist[p2] = dist[posActual] + 4;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    }
                }

                //Top-Left
                p2 = posActual + TL;
                if (pos_ok(p2)) {
                    Cell c2 = cell(p2);
                    if (dist.find(p2) == dist.end()) {
                        visitat.insert(make_pair(p2, false));
                            dist.insert(make_pair(p2, 99999));
                    }
                    if (not esunaliat(p2)) {
                    if (c2.type == Road) {
                        if (dist[p2] > dist[posActual] + 1) {
                            dist[p2] = dist[posActual] + 1;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    else if (c2.type == Desert) {
                        if (dist[p2] > dist[posActual] + 4) {
                            dist[p2] = dist[posActual] + 4;
                            posicioanterior.insert(make_pair(p2, posActual));
                            Q.push({dist[p2], p2});
                        }
                    }
                    }
                }

            }
        }

        //cout << "cami trobat, ens movem" << endl;
        if (unitatTrobada) {
            Pos resultat = posUnitatTrobada;
            Pos moviment = resultat;
            while (resultat != u.pos) {
                moviment = resultat;
                resultat = posicioanterior[resultat];
            }
            moure_cotxes(u, moviment);
        }
    }

    void move_cars () {
        VE C = cars(me());
        int n = C.size();

        for (int i=0; i<n; ++i) {
            int id = C[i];
            cerca_cami(unit(id));
            //cout << "acabo dijkstra" << endl;   
        }
    }

    void move_warriors() {
        if (round()% 4 != me()) return; // This line makes a lot of sense.

        VE W = warriors(me());
        int n = W.size();

        for (int i=0; i<n; ++i) {
            int id = W[i];
            Pos p = unit(id).pos;
            Matriuatributs Mat = cerca_ciutat_enemiga(p);
            movem_ciutat_enemiga(Mat, p, id);
        }
    }

    virtual void play () {
        //move_warriors();
        move_cars();
    }

};


RegisterPlayer(PLAYER_NAME);