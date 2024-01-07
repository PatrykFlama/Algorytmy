[Wróć](../../../../../../)

# Sortowanie kubelkowe (bucket sort)
W tym sortowaniu zakładamy że elementy są rozłożone w przedziale _[0, 1)_ zgodnie z rozkładem jednostajnym.  
Złożoność: O(n)

Aby posortować listę elementów tworzymy _n_ kubełków, gdzie _n_ to liczba elementów. Następnie przechodzimy po liście i wrzucamy elementy do odpowiednich kubełków. Na koniec sortujemy każdy kubełek (np. przez sortowanie przez wstawianie) i łączymy je w jedną listę.


