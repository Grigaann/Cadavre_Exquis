//
// Created by Tao SAINT PAUL AMOURDAM on 15/11/2022.
//

#ifndef CADAVRE_EXQUIS_FLECHI_H
#define CADAVRE_EXQUIS_FLECHI_H
#define Mas 1
#define Fem 2
#define InvGen 3

#define SG 10
#define PL 20

#define P1 100
#define P2 200
#define P3 300

#define IPre 1000
#define IImp 2000
#define SPre 3000
// int = PL + P1 + IPRE
// personne ? int%1000 - int%100 == PX


typedef struct cell_f{
    int form;
    char* word;
    struct list_flechi* next;
}cell_flechi;


typedef struct list_flechi{
    cell_flechi* first;
}list_flechi;

#endif //CADAVRE_EXQUIS_FLECHI_H
