void Rotate(int a[], int n) 
{
	int x = a[0];
	for (int i = 1; i < n; i++)
		a[i - 1] = a[i];
	a[n - 1] = x;
}

void rotate_v2(int a[], int n, bool clockwise = false) 
{
    if (clockwise) 
    {
        int* temp = (a + n - 1);
        for (int* p = a; p - a < n - 1; p++) {
            int swap = *p;
            *p = *temp;
            *temp = swap;
        }
        return;
    }

    int start = *a;
    for (int* p = a; p - a < n - 1; p++) {
        *p = *(p + 1);
    }
    *(a + n - 1) = start;
}