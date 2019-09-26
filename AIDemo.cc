#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Demo

// DISCLAIMER: The following Demo player is *not* meant to do anything
// sensible. It is provided just to illustrate how to use the API.
// Please use AINull.cc as a template for your player.

struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }
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

                if (cell(p2).type == Station) {
                    return parellidist(p2,dist);
                }
                vis[f][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dreta-baix
            p2 = actual + BR;
            if (pos_ok(p2) and vis[f+1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Station) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c+1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //Abaix
            p2 = actual + Bottom;
            if (pos_ok(p2) and vis[f+1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Station) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal baix-esquerra
            p2 = actual + LB;
            if (pos_ok(p2) and vis[f+1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Station) {
                    return parellidist(p2,dist);
                }
                vis[f+1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //esquerra
            p2 = actual + Left;
            if (pos_ok(p2) and vis[f][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Station) {
                    return parellidist(p2,dist);
                }
                vis[f][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            //diagonal dalt-esquerra
            p2 = actual + TL;
            if (pos_ok(p2) and vis[f-1][c-1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Station) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c-1] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + Top;
            if (pos_ok(p2) and vis[f-1][c] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Station) {
                    return parellidist(p2,dist);
                }
                vis[f-1][c] = true;
                posicions.push(p2);
                distancies.push(dist+1);
            }

            p2 = actual + RT;
            if (pos_ok(p2) and vis[f-1][c+1] == false and cell(p2).type != Wall) {

                if (cell(p2).type == Station) {
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
   * Types and attributes for your player can be defined here.
   */

  typedef vector<int> VE;

  map<int, int> kind; // For cars: 0 -> random, 1 -> Top.

  void move_warriors() {
    if (round()% 4 != me()) return; // This line makes a lot of sense.

    VE W = warriors(me());
    int n = W.size();
    VE perm = random_permutation(n);
    for (int i = 0; i < n; ++i) {
      // id is an own warrior. For some reason (or not) we treat our warriors in random order.
      int id = W[perm[i]];
      if (random(0, 2) == 0) command(id, Right); // With probability 1/3, we move right.
      else { // Otherwise, ...
        bool city = false;
        for (int k = 0; not city and k < 8; ++k) {
          Pos p = unit(id).pos;
          if (pos_ok(p) and cell(p).type == City) { // if we are next to a city cell, we try to move there.
            city = true;
            command(id, Dir(k));
          }
        }
        // Finally, the following code does several things, most of them stupid.
        // It's just to show that there are many possibilities.
        if (not city) {
          if (round() < 40) command(id, Left);
          else if (round() < 120) command(id, None);
          else if (random(0, 1)) {
            set<Pos> S;
            while ((int)S.size() < 4) S.insert(Pos(random(0, 59), random(0, 59)));
            vector<Pos> V(S.begin(), S.end());
            if (V[random(0, 3)].i >= 30 ) command(id, Bottom);
            else command(id, RT);
          }
          else if (status(0) > 0.8) command(id, Left);
          else if (total_score(1) > 10000) command(id, TL);
          else if (cell(4, 2).id != -1 and unit(cell(4, 2).id).type == Car) command(id, BR);
          else if (unit(id).food < 20) command(id, Dir(2*random(0, 3)));
          else if (unit(id).water > 10) command(id, Left);
          else if (cell(10, 20).owner == 2) command(id, None);
          else if (num_cities(3) == 1) command(id, LB);
          else cerr << unit(id).pos << endl; // You can print to cerr to debug.
        }
      }
    }
  }

  void move_cars() {
    vector<int> C = cars(me());
    for (int id : C) {
      if (kind.find(id) == kind.end()) kind[id] = random(0, 1);
      if (can_move(id)) { // This also makes sense.
        if (kind[id] == 0) command(id, Dir(random(0, 7)));
        else command(id, Top);
      }
   }
  }


  /**
   * Play method, invoked once per each round.
   */
  void play () {
    move_warriors();
    move_cars();
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
