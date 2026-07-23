# Tom Ritchford

- http://github.com/rec
- tom.ritchford@gmail.com
- +33 07 56 40 90 29
- 3 Rue de la Roche, 76000 Rouen, France

Développement rapide de solutions hautement fiables, performantes, évolutives et minimales.
Des solutions claires et durables aux problèmes difficiles.

Des décennies d'expérience ! Une multitude de projets menés de leur conception à leur réalisation.
production, emballage et distribution.

Expert en Python et C++, et connaissant bien de nombreux autres langages.

Gestionnaire de LLM productif mais méticuleux.

* audio et traitement numérique du signal
* contrôle en temps réel
* backend
  * search
* Fintech : modélisation d’options, registres comptables, gestion de positions
* mégadonnées
* systèmes distribués
* et plus encore

Nous sommes installés à Rouen et nous n'avons pas l'intention de déménager, mais je ne
travaille à distance que depuis 2016.

## Expérience sélectionnée

### Développeur unique, `recs` (avril 2026 – aujourd'hui)

Il y a plusieurs années, j'ai commencé à écrire `recs`, un système d'enregistrement
audio hautement fiable, automatique et sans intervention, destiné aux consoles de mixage
numériques des salles de concert et des studios, bars et clubs, et pour les archivistes
audio professionnels ou amateurs, même juste pour Capture de vieilles cassettes audio.

Je l'utilise depuis quelques années pour mes propres besoins, mais mon adoption récente
de Le codage assisté par LLM a entraîné une explosion de la qualité et de l'utilité. Une
version publique est prévu pour septembre 2026.

### Ingénieur logiciel senior, Quansight/OpenTeams (mai 2024 - décembre 2025)

Quansight et OpenTeams sont des sociétés de conseil sœurs américaines qui travaillent
exclusivement sur logiciel open source. J'ai été embauché par Quansight pour développer
en Python et C++ dans le cadre de leur contrat de longue durée avec Meta pour la
maintenance du projet vital PyTorch.

J'ai ajouté les décompositions d'opérateurs PyTorch, les annotations de type et leur
première unit test de vérification de type (une catégorie qui est devenu par la
suite une batterie de tests de ce type) et beaucoup de tests, de qualité et Travail de
concierge : particulièrement amusant un ensemble de tâches d’amélioration continue pour
améliorer la qualité qui ont servi de progression graduelle dans une direction, analyse
des fichiers Python pour détecter la documentation manquante ou l'utilisation de types
déconseillés.

OpenTeams a décidé de lever des fonds pour entrer en bourse, et j'y ai été transféré en
mai.  December 2025, la levée de fonds ne s'est pas bien déroulée, Meta n'a pas renouvelé
certains contrats, et et j'ai été licencié.

### <span>Programmeur principal, SuperDuperDB</span> <span>(mai 2023 - sept. 2023)</span>

https://github.com/SuperDuperDB/superduperdb

SuperDuperDB n'était pas une base de données, mais un système Python intégrant des bases
de données existantes avec Outils d'IA comme la recherche vectorielle et les LLM.

J'ai été chargé de rendre le code source Python fonctionnel « professionnel » afin qu'il
puisse être diffusé à la bibliothèque publique, et c'est exactement ce que j'ai fait, en
écrivant de nombreux tests `pytest`, en ajoutant typage quasi complet imposé avec
`mypy`, refactorisation, renommage et suppression des inepties, et bien sûr la rédaction
de liasses de documentation lisible pour les classes, les méthodes et les fonctions.

J'ai rédigé les documents de conception, vraiment ma partie préférée : pour la
journalisation structurée, la surveillance, et journalisation (une petite API très utile
qui permettait des calculs répétables avec un effort supplémentaire assez marginal) ; et
pour un serveur REST entièrement typé (y compris un petit démo) avec une
spécification OpenAPI générée automatiquement.

### CTO, Engora (avril 2021 - février 2023)

Engora était un moteur de recherche innovant pour les ingénieurs en mécanique.

Le fondateur a créé une bonne démo, puis a levé des fonds grâce au financement
participatif. Je suis arrivé.  Quelques mois après ma prise de fonction en tant que
directeur technique : j’étais impliqué dans tout, mais voici les éléments que j’ai
écrits moi-même, seul (Python, PostgreSQL, SqlAlchemy) :

* Un robot d'exploration de pièces détachées parcourt plus de deux douzaines de sites
disparates et un million de pièces

* Une grande base de données PostgreSQL contenant les informations clés de chaque page
de pièce

* Un entrepôt de données redondant, basé sur S3, utilisant plusieurs fournisseurs

* Un petit index propriétaire bien pratique, mappé en mémoire, pour la recherche directe et
récupération et [Whoosh](https://whoosh.readthedocs.io/en/latest/) pour le texte
recherche.

### Ingénieur logiciel senior chez Ripple (2014-2016)

Ripple est une entreprise de technologie financière possédant sa propre cryptomonnaie éponyme.
J'ai travaillé sur leur application phare `rippled`, la complexe et compliquée
registre cryptographique C++17 qui implémente leur cryptomonnaie XRP, sur le registre
code, déploiement, débogage, DevOps, compilation et surveillance, principalement en C++ avec
du Python.

### CTO, World Wide Woodshed (2009-2014)

J'avais toujours rêvé d'écrire une application audio complète pour ordinateur !

SlowGold de World Wide Woodshed était un leader des logiciels de pratique musicale
depuis les années 1990. J'ai racheté la moitié de la petite entreprise et j'étais le
seul développeur pour un nouveau produit en C++, avec un son de haute qualité et une
interface subtile et intuitive, et des petits détails comme le redémarrage en trois
secondes après l'arrêt.

Nous avions de nombreux clients fidèles, mais pas suffisamment pour justifier la
poursuite de notre activité.  Nous avons donc arrêté le projet et [mis le logiciel en
open source](https://github.com/rec/slow_gold) en 2016.

Ingénieur logiciel chez Google (2004-2009)

J'ai rejoint Google New York quand les bureaux ne faisaient qu'un seul étage avec vue
sur Times Square, et j'y ai travaillé sur le premier système de questions-réponses de
Google, puis son premier moteur de recherche pour la musicque, puis leur moteur de
recherche pour offres immobilières, entièrement en C++.

Cela m'a conduit à GoogleBase, une base de données de dizaines de milliards d'articles
prévus pour des millions d'utilisateurs. À la tête d'une petite équipe en constante
évolution, nous avons construit en deux ans une solution universelle Un framework de
reporting et de calcul en Python que j'avais proposé et conçu : il s'agissait de encore
couramment utilisé des années plus tard.

En récompense de ce labeur, j'ai eu le privilège de travailler sur GWS, le programme
front-end.  Écrit en C++, ce qui a généré toutes les pages de résultats Google, pour
l'internationalisation, la localisation et les traductions, et le cadre
d'expérimentation en direct de GWS.

J'ai interviewé des centaines d'ingénieurs, en me rendant deux fois en Corée et une fois en…
La Hongrie pour ça.

J'ai utilisé C++, Java et Python, ainsi que la panoplie habituelle de technologies Google.

### Développeur logiciel senior, Netomat (2001-2004)

Netomat disposait d'un outil multimédia innovant permettant aux utilisateurs et aux
annonceurs de créer et envoyer des « expériences » Netomat – de petites applets Java
(cela semblait plus raisonnable).  (à l'époque) des minisites avec animation, son et
navigation interne - aux utilisateurs qui pourraient les modifier directement dans le
courriel.

J'ai conçu et développé le moteur d'animation et l'interface utilisateur, ainsi que la
majeure partie de l'animation.  types et le manuel.

L'une de mes astuces préférées, j'ai écrit un outil qui convertissait les « expériences
».  directement dans le bytecode Java, pour une économie de 40 à 80 % sur la taille du
téléchargement et de la mémoire.

## Compétences
- Entièrement optimisé par LLM. Prompteur attentive et systématique. Je réinvestis une
  partie du temps gagné dans nettoyage, clarification et refactorisation minutieux du code
  généré.

- Architecture et conception de haut niveau : épurées, simples, pratiques, à
l’échelle, respectant les 12 facteurs.

- Tests et intégration continue rigoureux et sans concession

- Python : Flask/SQLAlchemy/Django/FastAPI/Pydantic, numpy/PyTorch, nanobind/Cython,
 temps réel, packaging, et plus encore...
- C/C++ : C++11-23 moderne, STL/programmation par modèles, Boost, concurrence, DSP, JUCE, temps réel
- Maîtrise de Javascript, solide connaissance de Linux et du scripting Bash
- Systèmes temps réel : audio numérique et traitement numérique du signal (DSP),
  systèmes de contrôle d’éclairage, MIDI
- Globalisation : Internationalisation, localisation, traduction, Unicode et encodages
- Fintech : systèmes de registres, modèles d’options
- Développement d'outils : consultez mon tableau de bord d'outils sur https://github.com/rec
- .en:N .fr:C1 .nl:B2 .de:B1 .id:A2 .es:A2

## Éducation
Je suis titulaire d'une licence en mathématiques (mention très bien) de l'Université Carleton, au Canada.
