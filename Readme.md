
petit programme tournant sur une carte teensy LC
https://www.pjrc.com/teensy/teensyLC.html

l'objectif est de faire un controleur à pied  emulant des commande du type clavier (espace, TAB,azerty, ...etc...)

d'un point de vue hardware: 
le systeme est composé de 8 poussoirs(NO) cablés en matrice 2lignes/4colonnes.

Dans le code:
on peut changer la taille de la matrice de bp, nb de colonne et/ou ligne.
on peut changer et rajouter des commandes pour chaque bouton de la matrice. pour la liste des commandes possibles: https://www.pjrc.com/teensy/td_keyboard.html

enjoy! 
