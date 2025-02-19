# Philosophe - Simulation en C

## Description
Ce projet simule le problème des philosophes en programmation concurrente. Plusieurs philosophes sont assis autour d'une table avec un bol de spaghetti et des fourchettes. Chaque philosophe passe alternativement par trois états : manger, penser et dormir. 

## Règles du Jeu
- Chaque philosophe doit manger et ne doit jamais mourir de faim.
- Un philosophe utilise deux fourchettes pour manger : une à gauche et une à droite.
- Après avoir mangé, il repose ses fourchettes et dort avant de recommencer à penser.
- Les philosophes ne communiquent pas entre eux et ne savent pas si un autre est sur le point de mourir.
- La simulation s'arrête lorsqu'un philosophe meurt de faim ou si tous ont mangé un certain nombre de fois (optionnel).

## Implémentation
Le programme prend les arguments suivants :
```sh
./philosophe nombre_de_philosophes temps_avant_mort temps_pour_manger temps_pour_dormir [nombre_de_repas]
```
- `nombre_de_philosophes` : Nombre de philosophes (et de fourchettes).
- `temps_avant_mort` (ms) : Temps avant qu'un philosophe meure s'il ne mange pas.
- `temps_pour_manger` (ms) : Temps nécessaire pour manger.
- `temps_pour_dormir` (ms) : Temps pendant lequel un philosophe dort.
- `nombre_de_repas` (optionnel) : Nombre de repas à effectuer avant d'arrêter la simulation.

### Gestion des Philosophes et Fourchettes
- Chaque philosophe est un thread.
- Chaque paire de philosophes partage une fourchette entre eux.
- L'état des fourchettes est protégé par un mutex pour éviter les accès concurrents.

### Logs de la Simulation
Chaque changement d'état d'un philosophe est affiché sous la forme suivante :
```sh
[timestamp] X a pris une fourchette
[timestamp] X mange
[timestamp] X dort
[timestamp] X pense
[timestamp] X est mort
```
- `timestamp` est le temps actuel en millisecondes.
- `X` est le numéro du philosophe.
- Le message de mort d'un philosophe doit être affiché au maximum 10 ms après sa mort.

## Contraintes Techniques
- Aucune variable globale n'est autorisée.
- Aucune condition de compétition (`data race`) ne doit exister.
- Les philosophes doivent éviter de mourir en optimisant la gestion des fourchettes.


## Auteur
Projet développé par **[Aurelien Fontaine]**.

