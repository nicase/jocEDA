struct atributs {
    Pos from = NULL;
    bool vist = false;
    int dist = 999;
    bool cami = false;
};

typedef vector<vector<atributs> > Matriuatributs;

Matriuatributs cerca_ciutat_enemiga(Pos p) {

        //TODO: Fer que al mirar les adjacencies no vagin contra una paret
        //      Fer que no es matin entre ells
        //      Fer que entrin a la ciutat i no es quedin devant com gilipolles

        Matriuatributs Matributs(60,vector<atributs>(60));
        //tenim una matriu de la mateixa mida del tauler amb atributs necessaris pel dijkstra

        Matributs[p.i][p.j].dist = 0;
        queue<Pos> pQ;
        pQ.push(p);
        while(not pQ.empty() and cell(pQ.front()).id != -1 and unit(cell(pQ.front()).id).player != me()) {
            Pos newp = pQ.front();
            pQ.pop();

            if (Matributs[newp.i][newp.j].vist == false) { //si encara no hem visitat aquesta posicio

                Matributs[newp.i][newp.j].vist = true;

                //mirem totes les adjacencies

                Pos aux;

                if (cell(newp).type == Road) {
                    //Top
                    aux = newp+Top;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //Right
                    aux = newp+Right;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //Bottom
                    aux = newp+Bottom;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //Left
                    aux = newp+Left;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //BR
                    aux = newp+BR;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //RT
                    aux = newp+RT;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //TL
                    aux = newp+TL;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //LB
                    aux = newp+LB;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 1 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +1;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }
                }

                else {
                        //Top
                    aux = newp+Top;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //Right
                    aux = newp+Right;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //Bottom
                    aux = newp+Bottom;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //Left
                    aux = newp+Left;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //BR
                    aux = newp+BR;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //RT
                    aux = newp+RT;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //TL
                    aux = newp+TL;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }

                    //LB
                    aux = newp+LB;
                    if (podemmoure(aux)) {
                        if (Matributs[newp.i][newp.j].dist + 4 < Matributs[aux.i][aux.j].dist) {
                            Matributs[aux.i][aux.j].dist = Matributs[newp.i][newp.j].dist +4;
                            Matributs[aux.i][aux.j].from = newp;
                            pQ.push(aux);
                        }
                    }
                }
                


            }
        }

        if (cell(pQ.front()).id != -1 and unit(cell(pQ.front()).id).player != me()) {

            Pos p1 = pQ.front();

            Pos p2 = p1;
            while (p1 != p) {
                //Right
                p2 = p1 + Right;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }

                //Bottom
                p2 = p1 + Bottom;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }

                //Left
                p2 = p1 + Left;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }

                //Top
                p2 = p1 + Top;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }

                //RT
                p2 = p1 + RT;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }

                //BR
                p2 = p1 + BR;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }

                //LB
                p2 = p1 + LB;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }

                //TL
                p2 = p1 + TL;
                if (pos_ok(p2)) {
                    if (cell(p2).type == Road) {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 1) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                    else {
                        if (Matributs[p2.i][p2.j].dist == Matributs[p1.i][p1.j].dist - 4) {
                            Matributs[p2.i][p2.j].cami = true;
                            p1 = p2;
                        }
                    }
                }
            }
        }

        return Matributs;
    }    