# HASHOWANIE
## Działanie ogółem
Hashowanie słów polega na przypisaniu im liczby, dzięki której słowo *prawie* zawsze będzie rozróżnialne od innego. 

## Działanie konkretniej
Hash tak na prawdę jest wielomianem, o stopniu równym długości słowa. Taki wielomian szybko stanie się większy od 2e9, aby temu zapobiec bierzemy z niego modulo odgórnie ustalonej liczby pierwszej (najpopularniejsza jest **1e9+7**).
Kolejna stała to *x* wielomianu. Powinien on być większy od największej wartości litery (np z = '26'), aby uniknąć zbyt łatwych powtórzeń ('2' + 2\*'12' == '26').
Zarazem litery nie powinny być równe 0.

## Złożoność czasowa
T(O) = długość wyrazu

## Złożoność pamięciowa
