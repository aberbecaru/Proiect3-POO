# Documentatie

Prima clasa creata, **clasa Medii** unde am ilustrat conceptul de **Template** prin functiile **medie_aritmetica**, **medie_geometrica** si **medie_armonica**.
Urmeaza apoi Design Patter-nul **Singleton**, ilustrat prin **clasa Cinema**, in care am setat constructorul clasei privat pentru ca data sa poata fi accesata o singura data, set si get pentru string-ul implementat. Inainte de main instance este initializat cu 0 pentru a folosi functia **getInstance()** si a prelua obiectul.
Ultimul Design Pattern ilustrat este **Abstract Factory**, ilustrat prin **clasa Telefon**. In acest caz am creat **clasa Factory** pentru a putea telefoanele fabricate in Asia sau America, fiecare dintre acestea 2 avand propria clasa mostenita din clasa Telefon. Pentru fiecare telefon de aceste 2 tipuri verificam daca este o marca populara sau nepopulara prin functiile aferente virtuale initializate in clasa mama.
Fluxurile de testare se regasesc in main-ul programului
