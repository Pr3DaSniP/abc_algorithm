# Artificial Bee Colony Algorithme

![language](https://img.shields.io/badge/Language-C++-blue.svg)

L’algorithme de colonie d’abeilles est l’un des algorithmes (swarm), inspiré par le comportement collectif des colonies sociales d’insectes et d’autres sociétés animales.

Les propriétés du méthode SWARM : 
* Auto-organisation:
→ L’organisation d’une colonie est faite automatiquement, et cette intelligence de chaque individu collabore pour le résultat final.

* La division du travail:
→ Les tâches sont effectuées simultanément, et chaque travailleur a son rôle bien précis.

Cet algorithme modélise le comportement des abeilles à miel et peut servir à rechercher des solutions à des problèmes complexes. Les abeilles à miel jouent différents rôles dans leurs colonies, il y a des abeilles qui sont encore jeunes, et des abeilles adultes travailleuses. Parmi ces abeilles travailleuses, chaque abeilles doit exécuter une tâche bien précise. Ces abeilles travailleuses sont groupées dans 3 types principaux selon le type de tâche à accomplir.

* Employed Bees
* Onlooker Bees
* Scout Bees

Plus d'infos dans notre rapport de projet, [ici](ABC_Rapport.pdf).

## Installation

 - Créer un projet Code::blocks version 20.03 avec le compilateur "GNU GCC Compiler"
 - Prendre les sources et copier coller dans le dossier des sources (à l'endroit du main.cpp)
 - Lancer le programme

On peut changer la fonction objectif dans le fichier OptUHA.cpp en début du fichier à la place de "Griewank".
Ne pas oublier de changer LOWER_LIMIT et UPPER_LIMIT dans le fichier OptUHA.h.

Griewank = -600, 600
Sphere = -100, 100
Rastrigin = -5, 5
Rasenbrock = -100, 100

## Auteurs

* GEILLER Valentin, Université de Haute Alsace, L3 Informatique
* MUHIRWA GABO Oreste, Université de Haute Alsace, L3 Informatique