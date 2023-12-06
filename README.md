# TP de Synthèse – Ensea in the Shell

**Mayane GUILLON et Rania DOUIA**

## Question 1 : Affichage d’un message d’accueil, suivi d’un prompt simple
*Objectif: Créer un shell ensea et afficher un message d'acceuil : "$ ./enseashBienvenue dans le Shell ENSEA.Pour quitter, tapez 'exit'.enseash %"*

Pour cela, on utilise la fonction *write* dans la console(STDOUT_FILENO).

![Q1](img/q1shell.png)

## Question 2 : Exécution de la commande saisie et retour au prompt (REPL : read–eval–print loop)
*Objectif: Créer un échange entre l'utilisateur (depuis le clavier) et notre programme*

Pour cela, on utilise les étapes suivants :

* **Lecture de la commande :** Capture une commande depuis l'entrée standard, transforme la saisie en une chaîne de caractères C.

* **Création d'un processus fils :** Utilise fork() pour créer un nouveau processus fils, qui est une réplique du processus parent.

* **Exécution de la commande dans le processus fils :** Dans le processus fils, la commande est exécutée à l'aide de la fonction execlp(), remplaçant ainsi le programme en cours d'exécution par la commande spécifiée.

* **Gestion du processus fils et écriture dans la sortie standard dans le processus parent :** Le processus parent attend la fin du processus fils avec wait(&status) et écrit une chaîne prédéfinie (ENSEA) dans la sortie standard.

Cette question repose sur la création d'un processus fils pour exécuter une commande envoyé dans la console. Une fois créer on attend que le processus fils se termine (et se détruise), puis une chaîne de caractères est écrit dans la sortie standard. Pour cela on utilise un fork() qui facilite l'exécution de la commande dans un contexte séparé du processus parent.

![Q2](img/q2shell.png) 

## Question 3 : Gestion de la sortie du shell avec la commande “exit” ou un <ctrl>+d
*Objectif: Créer une condition d'arrêt des commandes écritent dans la console*

Pour créer cette condition d'arrêt, on a conservé le code précédent en ajoutant un test qui va comparer à l'aide de la fonction strcmp(), la chaîne de caractère écrite dans la console avec l'instruction 'exit' ou ''. 

Si ces deux chaînes de caractère sont identiques, alors on écrit un message de sortie dans la console.

![Q3](img/q3shell.png)

## Question 4 : Affichage du code de retour (ou du signal) de la commande précédente dans le prompt 
*Objectif:*

![Q4a](img/q4shell.png)
![Q4b](img/q4terminal1.png)
![Q4c](img/q4Terminal2.png)
## Question 5 : Mesure du temps d’exécution de la commande en utilisant l’appel clock_gettime 
*Objectif:*

![Q5](img/q5shell.png)
## Question 6 : Exécution d’une commande complexe (avec arguments) 
*Objectif:*

![Q6a](img/q6shell.png)
![Q6b](img/q6debugger.png)
## Question 7 : Gestion des redirections vers stdin et stdout avec ‘<’ et ‘>’ 
*Objectif:*

## Réflexions personnelles
### Mayane GUILLON
### Rania DAOUIA 
