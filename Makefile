debug:
	gcc -Wall -g quicksort.c -o quicksort
fast:
	gcc -Wall -Ofast quicksort.c -o quicksort
clean:
	rm -f quicksort
