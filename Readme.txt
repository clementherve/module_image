###########################################
#####
#####	MEMO GITHUB
#####
###########################################



valgrind --leak-check=full --num-callers=50 --suppressions=./valgrind_lif7.supp --show-reachable=yes -v bin/test


valgrind --tool=memcheck --suppressions=./valgrind_lif7.supp --leak-check=summary bin/test
'', '--suppressions=./valgrind_lif7.supp', '--show-reachable=yes', '--leak-check=summary'


******************
1.1 - Reprendre son travail
******************

Avant de recommencer à travailler sur le projet:

git pull https://github.com/cl6ment/module_image.git
(recupere les fichiers mis a jour par les autres)



******************
1.2 - Sauvegarder vos changements
*****************

Si vous faites des changements peu risqués:

git add <nom des fichiers changés>
git commit -m "explication de ce que vous avez fait"
git push https://github.com/cl6ment/module_image.git master



******************
1.3 - Sauvegarder des changements risqués
******************

Si vous considérez que vos changements sont risqués,
ne les mettez pas sur le master ! Créez une branche avec votre prénom :

git checkout -b <votre prenom>

puis: 

git add <nom des fichiers changés>
git commit -m "explication de ce que vous avez fait"
git push https://github.com/cl6ment/module_image.git master




****************
1.4 - Sauvegarder ses identifiants + url
****************

git remote add origin https://github.com/cl6ment/module_image.git
git config credential.helper store




###########################################
#####
#####	MEMO DOXYGEN
#####
###########################################


******************
1.1 - mettre à jour la doc
******************

doxygen doc/image.doxy





###########################################
#####
#####	TODO
#####
###########################################


- continuer à se documenter sur :
	
	* valgrind
	* la SDL
	* gdb
	* doxygen
	* dia (diagrammes de classes)


- eventuellement, remplir le readme





###########################################
#####
#####	Etudiants
#####
###########################################

HERVE Clément 11615530
BRUNET Gautier 11208117
TEIXEIRA MAGALHAES Tiago 11414551
