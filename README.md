Exercice 1 : Implémentation du patron Singleton</br>
<img width="788" height="539" alt="Capture d&#39;écran 2026-11-10 174952" src="https://github.com/user-attachments/assets/94968cb3-9449-4a40-baad-7847315931f1" /></br>
Question:</br>
1. Pourquoi le constructeur doit-il être privé ?</br>
Le constructeur doit être privé pour interdire toute instanciation directe de la classe par le code extérieur.</br>
2. Quelles sont les limites de ce patron dans les environnements multithreadés ?
-Condition de concurrence (Race Condition) lors de l'initialisation </br>
-Verrous d'accès aux données (Thread Safety lors de la modification) </br>
-Goulot d'étranglement (Bottleneck) </br>
-Problèmes de couplage et de testabilité </br>
Exercice 2 : Utilisation du patron Fabrique (Factory Method)</br>
<img width="797" height="302" alt="Capture d&#39;écran 2026-11-10 175204" src="https://github.com/user-attachments/assets/12c714e9-4d29-49df-92e6-41a89f7ef598" /></br>
Question:</br>
1. Quelle est l’utilité du pattern Factory dans un contexte d’extension future ?
Le patron Factory Method offre plusieurs avantages clés en matière de maintenabilité et d'extensibilité :
-Respect du principe Ouvert/Fermé (OCP - Open/Closed Principle)</br>
-Découplage fort</br>
2. Comment rendre le système plus modulaire avec une classe abstraite FabriqueAbstraite ?</br>
L'introduction d'une classe FabriqueAbstraite (Abstract Factory) permet de créer des familles d'objets apparentés sans spécifier leurs classes concrètes.</br>
Exercice 3 : Application du patron Observateur (Observer)</br>
<img width="751" height="491" alt="Capture d&#39;écran 2026-11-11 113624" src="https://github.com/user-attachments/assets/a544550f-27e5-4157-84e6-7f81dd9ce832" /></br>
Question:</br>
1. Comment éviter une forte dépendance entre le sujet et les observateurs ?
-Découplage par l'abstraction (Interface)</br>
-Inversion de dépendance (DIP - Dependency Inversion Principle)</br>
2. Quelle alternative moderne offre la bibliothèque standard pour cela ?</br>
La bibliothèque standard C++ propose l'utilisation des pointeurs de fonctions et fonctions anonymes via std::function combined avec des fonctions lambdas ou std::bind.</br>
Exercice 4 : Mise en œuvre du patron Stratégie (Strategy)</br>
<img width="1020" height="288" alt="Capture d&#39;écran 2026-11-11 113950" src="https://github.com/user-attachments/assets/2b367eb1-189c-484f-9403-ebb921da0fe9" />




