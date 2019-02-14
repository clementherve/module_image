###########################################
#####								  #####
#####			MODULE IMAGE		  #####
#####								  #####
###########################################





======================================
===				Sommaire		   ===
======================================

1/ A propos des auteurs
2/ Que fait cette application ?
3/ Prérequis
4/ Installation
5/ Compilation
6/ Exécution
7/ Organisation









======================================
===		A propos des auteurs	   ===
======================================

Cette application a été crée par trois étudiants en deuxième année de licence d'informatique
durant l'un de leurs cours (LIFAP4) sous la supervision des encadrants de l'UE.


11208117 - BRUNET Gauthier
11414551 - TEIXEIRA MAGALHAES Tiago
11615530 - HERVE Clément









======================================
===	 Que fait cette application ?  ===
======================================

Le module image est une application permettant de créer, ouvrir, modifier et sauvegarder
des fichiers .ppm

Un fichier ppm encode une image en utilisant la valeur de chaque pixel au format RGB stocké (parfois au format ascii) dans un fichier.
Le tout est lisible par un humain.









======================================
===	 		   Prérequis  		   ===
======================================

* Un ordinateur avec linux
	=> Testé, compilé et fonctionnel avec Ubuntu 18.04 et Fedora 28

* La librairie SDL 2.0 installée pour l'affichage graphique
	=> Voir la rubrique **installation**









======================================
===	 		  installation   	   ===
======================================

La librairie SDL est nécessaire pour l'affichage des images.

* SDL 2.0
	=> sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev









======================================
===	 		  compilation   	   ===
======================================


make bin/affichage
	=> compile le module chargé uniquement d'afficher une image générée à la volée.

make bin/Test
	=> compile le module chargé des tests de régression.


make bin/exemple
	=> compile le module qui génère une image à la volée, puis utilise les fonctions de 
		sauvegarde sur le disque et d'ouverture.

make (all)
	=> génère tous les fichiers cités ci-dessus

make clean
	=> supprime tous les fichiers intermédiaires liés à la compilation
		(situés dans les repertoires obj/ et bin/)






======================================
===	 		 	 exécution   	   ===
======================================

* exécuter src/mainAffichage.cpp
	=> make bin/affichage (cf etape precedente)
	=> bin/affichage

* exécuter src/mainTest.cpp
	=> make bin/test (cf etape precedente)
	=> bin/test

* exécuter src/mainExemple.cpp
	=> make bin/exemple (cf etape precedente)
	=> bin/exemple






======================================
===	 	organisation du module	   ===
======================================

*********************
** Le repertoire
*********************

Le repertoire du module est organisé de la façon suivante:

|
|--- bin/ ==> contient les executables
|
|
|--- data/ ==> contient les images generees par le programme
|
|
|--- doc/ --- html/ ==> contient le site genere par doxygen
|		/
|	    / --- image.doxy	==> permet de generer le site de documentation
|
|
|--- obj/ ==> contient les fichiers de compilation intermédiaires
|
|
|--- src/ ==> contient les fichiers sources
|


*********************
** Les classes
*********************

Le module est organisé de la façon suivante (cf diagramme de classe):

La classe de base est Pixel.

La classe Image fait appel à pixel pour créer et gérer le tableau

Les trois fichiers commençant main[...].cpp permettent la génération de trois exécutables 
resp. bin/test, bin/affichage et bin/exemple appellant la classe Image
