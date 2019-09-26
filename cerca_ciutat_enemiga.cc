

struct node {
    Pos p;
    vector<Pos> adj;
    int dist = 999;
    Pos from;
}

vector<vector<node> > Matnodes;
vector<vector<bool> > Vis;

cerca_ciutat_enemiga(Matnodes,Pos p) { //p:pos inicial
    int fi = p.i;
    int ci = p.j;
    Matnodes[fi][ci].dist = 0;

    PriorityQueue <pair<int,Pos> > pQ; //distancia a la que estem de l'orígen i posicio en la que estem
    pQ.push({0,p});

    /*
     * Mirem que la cua no estigui buida i que no haguem arribat a una ciutat enemiga
     */
    while(not pQ.empty() and cell(pQ.top().second).type != City and cell(pQ.top().second).owner != me()) {
        Pos newpos = pQ.top().second;

        /*for (int i=0; i<newnode.adj.size(); ++i) {
            Pos aux = Matnodes[p.i][p.j].
        }*/
        //sempre tenim com a maxim 8 adjacències i com a mínim 3 (cantonada)

        //Right
        Pos p2 = newpos + Right;
        if (pos_ok(p2)) {
            if()
        }


    }

}