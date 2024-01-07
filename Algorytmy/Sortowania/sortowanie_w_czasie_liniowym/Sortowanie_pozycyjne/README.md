[Wróć](../../../../../../)

# Sortowanie pozycyjne (radix sort)
W tym algorytmie ważne jest to, aby nasze sortowanie było stabilne - elementy o tej samej wartości powinny skończyć w tej samej kolejności jak przed sortowaniem. Sortować możemy dowolny element, który da się zapisać w postaci liczby całkowitej w dowolnym systemie.  
Złożoność: O(d(n+k)), gdzie d to liczba cyfr, n to liczba elementów, a k to maksymalna wartość cyfry.  
Posortowanie polega na przejściu po kolejnych cyfrach liczb (zaczynając od cyfr jedności) i sortowaniu elementów po tej cyfrze.    
pseuodkod:  

