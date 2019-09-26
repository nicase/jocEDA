void cerca_cami (Unit u) {
        //Cua de pairs --> cost + Pos de la casella
        priority_queue < pair <int,Pos>, vector <pair <int,Pos> >, greater<pair <int,Pos> > > Q;
        Q.push(make_pair(0, u.pos));
        map <Pos, int> dist;
        map <Pos, Pos> previ; // Posició + la posició previa
        map <Pos, bool> vist;
        dist.insert(make_pair(u.pos, 0));
        vist.insert(make_pair(u.pos, false));

        bool unitatTrobada = false;
        Pos posUnitatTrobada = Pos(4,4);

        while (not Q.empty() and not unitatTrobada) {
            pair<int,Pos> actual = Q.top();
            int distActual = actual.first;
            Pos posActual = actual.second;
            int idActual = cell(posActual).id;
            Q.pop();

            if (distActual > limitCalculCotxes) {
                //    cout << "massa lluny " << round() << endl;
                moure_cotxe_centre(u);
                break;
            }


            if (idActual != -1 and unit(idActual).player != me() and unit(idActual).type == Warrior) {
                unitatTrobada = true;
                posUnitatTrobada = posActual;
            }
          
            if (not vist[posActual]) {
                vist[posActual] = true;
                for (int x = 0; x < 8; ++x) {
                    Pos posCelaVeina = celesVeines[x]; //Repetim per cada cela adjacent
                    if (pos_ok(posCelaVeina + Pos(0,marge)) and pos_ok(posCelaVeina + Pos(0, 0 - marge)) and
                            pos_ok(posCelaVeina + Pos(marge,0)) and pos_ok(posCelaVeina + Pos(0 - marge,0))) {
                        Cell celaVeina = cell(posCelaVeina);
                        if (dist.find(posCelaVeina) == dist.end()) {
                            vist.insert(make_pair(posCelaVeina, false));
                            dist.insert(make_pair(posCelaVeina, infinit));
                        }
                        if (not aliatAprop(posCelaVeina, u.pos)) { //Esquivem aliats o cotxes
                            if (celaVeina.type == Road) {
                                if (dist[posCelaVeina] > dist[posActual] + 1) {
                                    dist[posCelaVeina] = dist[posActual] + 1;
                                    previ.insert(make_pair(posCelaVeina, posActual));
                                    Q.push(make_pair(dist[posCelaVeina], posCelaVeina));
                                }
                            }
                            else if (celaVeina.type == Desert) {
                                if (dist[posCelaVeina] > dist[posActual] + 4) {
                                    dist[posCelaVeina] = dist[posActual] + 4;
                                    previ.insert(make_pair(posCelaVeina, posActual));
                                    Q.push(make_pair(dist[posCelaVeina], posCelaVeina));
                                }
                            }
                        }
                    }
                }
            }
        }

        if (unitatTrobada) {
            Pos resultat = posUnitatTrobada;
            Pos moviment = resultat;
            while (resultat != u.pos) {
                moviment = resultat;
                resultat = previ[resultat];
            }
            moure_unitat(u, moviment);
        }
    }
