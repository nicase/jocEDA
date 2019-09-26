#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME nico

struct PLAYER_NAME : public Player {

    /**
     * Factory: returns a new instance of this class.
     * Do not modify this function.
     */
    static Player* factory () {
        return new PLAYER_NAME;
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

    bool esunwarriorenemic(Pos p) {
        if (cell(p).id != -1) {
            if (unit(cell(p).id).player != me()) {
                if (unit(cell(p).id).type == Warrior) {
                    return true;
                }
            }
        }
        return false;
    }

    bool esunaliat(Pos p) {
        if (cell(p).id != -1) {
            if (unit(cell(p).id).player == me()) return true;
        }
        return false;
    }

    void cerca_cami (Unit u) {
        //Cua de pairs --> cost + Pos de la casella

        map <Pos, int> dist;
        map <Pos, Pos> posicioanterior;
        map <Pos, bool> visitat;

        dist.insert(make_pair(u.pos, 0));

        priority_queue < pair <int,Pos>, vector <pair <int,Pos> >, greater<pair <int,Pos> > > Q;
        Q.push(make_pair(0, u.pos));
        visitat.insert(make_pair(u.pos, false));
        bool found = false;
        Pos posUnitatTrobada = Pos(4,4);

        while (not Q.empty() and not found) {
            pair<int,Pos> actual = Q.top();
            int distActual = actual.first;
            Pos posActual = actual.second;
            int idActual = cell(posActual).id;
            Q.pop();

            if (esunwarriorenemic(Q.top().second)) {
                found = true;
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

        if (found) {
            Pos resultat = posUnitatTrobada;
            Pos last = resultat;
            while (resultat != u.pos) {
                last = resultat;
                resultat = posicioanterior[resultat];
            }

            moure_cotxes(u, last);
        }
    }


    void move_cars() {
        vector<int> C = cars(me());
        //identificadors dels cotxes en el vector C
        int n = C.size();
        //n: num de cotxes que tenim

        for(int i=0; i<n; ++i) {
            int id = C[i];
            cerca_cami(unit(id));
        }
    }

    virtual void play () {

        move_cars();
    }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);