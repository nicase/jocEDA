//dijkstra


struct atributs {
    Pos from = NULL;
    bool vist = false;
    int dist = 999;
    bool cami = false;
};

typedef vector<vector<atributs> > Matriuatributs;

Matriuatributs cerca_ciutat_enemiga(Pos p) {

    Matriuatributs Matributs(60,vector<atributs>(60));
    //tenim una matriu de la mateixa mida del tauler amb atributs necessaris pel dijkstra

    Matributs[p.i][p.j].dist = 0;
    priority_queue<Pos> pQ;
    pQ.push(p);
    while(not pQ.empty() and cell(pQ.top()).type != City and cell(pQ.top()).owner != me()) {
        Pos newp = pQ.top();
        pQ.pop();

        if (Matributs[newp.i][newp.j].vist == false) { //si encara no hem visitat aquesta posicio

            Matributs[newp.i][newp.j].vist = true;

            //mirem totes les adjacencies

            Pos aux;
            //Top
            aux = newp+Top;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }

            //Right
            aux = newp+Right;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }

            //Bottom
            aux = newp+Bottom;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }

            //Left
            aux = newp+Left;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }

            //BR
            aux = newp+BR;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }

            //RT
            aux = newp+RT;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }

            //TL
            aux = newp+TL;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }

            //LB
            aux = newp+LB;
            if (pos_ok(aux)) {
                if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                    Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                    Matributs[aux.i][aux.j].from = newp;
                    pQ.push(aux);
                }
            }


        }
    }

    if (pQ.top().type == City and pQ.top().owner != me()) {

        Pos p1 = pQ.top();

        Pos p2 = p1;
        while (p1 != p) {
            //Right
            p2 = p1 + Right;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }

            //Bottom
            p2 = p1 + Bottom;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }

            //Left
            p2 = p1 + Left;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }

            //Top
            p2 = p1 + Top;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }

            //RT
            p2 = p1 + RT;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }

            //BR
            p2 = p1 + BR;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }

            //LB
            p2 = p1 + LB;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }

            //TL
            p2 = p1 + TL;
            if (pos_ok(p2)) {
                if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                    M[p1.i][p2.j].cami = true;
                }
            }
        }
    }













    return Matributs;
}       