// Coloque seu código aqui.

void bubblesort(int* a, int N) {
	int i, j, aux;
	for (j = N - 1; j > 0; j--) {
		for (i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				aux = a[i + 1]; //
				a[i + 1] = a[i];
				a[i] = aux;
			}
		}
	}
}
