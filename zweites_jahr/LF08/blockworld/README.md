# Erläuterungen

### __private
<p>kein Zugriff außerhalb der Klasse</p>

### _protected 
<p>Zugriff nur innerhalb einer Klasse und ihren Sub-Klassen, die von ihr erben</p>

### public
<p>Member können auch außerhalb der Klasse zugegriffen werden</p>

### Schutz umgehen

in Python kann man auf private oder protected Funktionen/Variablen trotzdem zugreifen. Gleichwohl ist davon abzuraten.

Auf private Variablen/Funktionen zugreifen:
    
    'Objekt._Klasse__Variable'
    
    'Objekt._Klasse__Funktion'
    
Auf protected Variablen/Funktionen zugreifen:
    
    'Objekt._Variable'
    
    'Objekt._Funktion'


## Klassendiagramm

- Pfeile

    ->  Vererbung
    
    -<> Aggregation (hat)

- Sichtbarkeit

    '+ public'
    
    '# protected'
    
    '- private' 
