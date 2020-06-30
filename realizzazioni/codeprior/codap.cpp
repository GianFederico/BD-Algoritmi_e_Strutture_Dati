/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "codap.h"
#include <iostream>

using namespace std;

int main () {
  CodaP < int > C;

  C.inserisci (1);
  C.inserisci (12);
  C.inserisci (19);
  C.inserisci (7);
  cout << "[1,12,19,7]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();
  C.inserisci (0);
  C.inserisci (11);
  cout << "[12,19,7,0,11]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();
  C.inserisci (5);
  C.inserisci (21);
  C.inserisci (18);
  cout << "[12,19,7,11,5,21,18]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();
  C.inserisci (3);
  cout << "[12,19,7,11,21,18,3]" << endl;
  cout << "Min: " << C.min() << endl;
  C.cancellaMin ();
}
