
/*
 * Aquesta funció mou la unitat de la posicio p cap a la ciutat enemiga mes propera
 *
 */



void movem_ciutat_enemiga (int id, int dist, Pos p) {

    Pos p2;

    //*************************************************************************************************//
    p2 = p + BR;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }

    //********************************************************************************************************//
    p2 = p + RT;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }

    //********************************************************************************************************//
    p2 = p + TL;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }

    //********************************************************************************************************//
    p2 = p + LB;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }

    //********************************************************************************************************//
    p2 = p + Top;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }


    //********************************************************************************************************//
    p2 = p + Left;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }
    //********************************************************************************************************//
    p2 = p + Bottom;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }

    //********************************************************************************************************//
    p2 = p + Right;
    //mirem si hi ha una unitat abans
    if (cell(p2).id == -1) { 
        //si no hi ha unitat ens movem
        if (cell(p2).owner != me() and cell(p2).owner != -1) {command(id,Top); return;} //si ja estem a la ciutat
        else {
            //la cell de p2 es una casella que no es una ciutat enemiga ni una unitat
            if (cell(p2).type != Wall and cell(p2).type != Water) {

                if (cerca_ciutat_enemiga(p2.i,p2.j).second < dist) {command(id,Top);return;}

            }
        }


    }
    else {
        //hi ha una unitat
        int id2 = cell(p2).id;
        if (unit(id2).player != me()) {
            //es un enemic
            if (unit(id2).type == Warrior and min(unit(id2).food, unit(id2).water) < min(unit(id).food,unit(id).water)) {
                command(id,TOP);
                return;
            }
        }
    }
}